// C Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define YOTE_USE_ARENA	// Use memory arena
#define YOTE_USE_STRING // Use strings
#include "yote.h"

#define YOTE_PLATFORM_USE_SOCKETS // Use sockets for server
#include "yote_platform.h"
#include "game_server.h"

#define LOCAL_PORT 1115
#define MAX_FRAGMENTS 0xffff
#define MAX_PACKET_LENGTH 512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 16

// Utilities
#include "utils/endian.c"
#include "utils/util.c"
#include "utils/crypt_rc4.c"

// SoE and SoE protocol related
#include "soe/stream.h"
#include "soe/fragment_pool.c"
#include "soe/input_stream.c"
#include "soe/output_stream.c"
#include "soe/core_protocol.h"
#include "soe/connection.h"
#include "soe/session.h"
#include "soe/packet_queue.h"
#include "soe/packet_queue.c"

// WiP SOE Related
#include "soe/newSOE/inputStream.c"

// HACK(rhett):
u64 global_tick_count = 0;

typedef struct Stream_Function_Table
{
	input_stream_callback_ack *login_input_ack;
	input_stream_callback_data *login_input_data;
	output_stream_callback_data *login_output_data;
	input_stream_callback_data *ping_input_data;
} Stream_Function_Table;

struct App_State
{
	Stream_Function_Table *stream_function_table;
	f32 *tick_ms;
	f32 *work_ms;
	u64 *tick_count;
	Key_States *key_states;
	Arena arena_total;
	Platform_Api *platform_api;
	Arena arena_per_tick;
	Platform_Socket socket;
	u8 rc4_key_decoded[256];
	i32 rc4_key_decoded_length;
	Connection_Args connection_args;
	i32 sessions_capacity;
	Session_State sessions[MAX_SESSIONS_COUNT];
};

INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data);

#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE "Core"
#include "soe/core_protocol.c"
#include "core/core.c"
#include "core/classes/base.h"
#include "core/entities/core_base_full_character.h"
#include "core/entities/core_base_entity.h"
#include "core/classes/grid_cell.h"
#include "core/core_server.h"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE "Login"
#include "../schema/output/kotk_login_udp_11.c" // Packet structures
#include "login/login_udp_11.c"					// Sending login packets structures' data
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE MESSAGE_NAMESPACE_DEFAULT // Default

INPUT_STREAM_CALLBACK_ACK(on_input_stream_ack)
{
	Session_State *session_state = session;
	session_state->ack_next = ack;
}

INPUT_STREAM_CALLBACK_DATA(on_input_stream_data)
{
	login_packet_handle(server, session, data, data_length);
}

// TODO(rhett): remove this later
INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data)
{
	UNUSED(server);
	UNUSED(session);
	UNUSED(data);
	UNUSED(data_length);
};

OUTPUT_STREAM_CALLBACK_DATA(on_output_stream_data)
{
	App_State *app_state = server;
	Session_State *session_state = session;

	Data packet =
		{
			.sequence = (u16)sequence,
			.data = data,
			.data_length = data_length,
		};

	if (!is_fragment)
	{
		core_packet_send(app_state->socket, app_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data, &packet);
	}
	else
	{
		core_packet_send(app_state->socket, app_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data_Fragment, &packet);
	}
}

__declspec(dllexport) APP_TICK(server_tick)
{
	App_State *app_state = app_memory->app_state;
	if (!app_state)
	{
		app_state = app_memory->app_state = arena_bootstrap_push_struct(app_memory->backing_memory.data,
																		app_memory->backing_memory.size,
																		"Total",
																		App_State,
																		arena_total);
		app_state->platform_api = &app_memory->platform_api;
		app_state->tick_ms = &app_memory->tick_ms;
		app_state->work_ms = &app_memory->work_ms;
		app_state->tick_count = &app_memory->tick_count;
		app_state->key_states = &app_memory->key_states;

		Buffer per_tick_backing_memory =
			{
				.size = MB(10),
				.data = arena_push_size(&app_state->arena_total,
										per_tick_backing_memory.size),
			};

		app_state->stream_function_table = arena_push_struct(&app_state->arena_total, Stream_Function_Table);
		app_state->stream_function_table->login_input_ack = on_input_stream_ack;
		app_state->stream_function_table->login_input_data = on_input_stream_data;
		app_state->stream_function_table->login_output_data = on_output_stream_data;
		app_state->stream_function_table->ping_input_data = on_ping_input_stream_data;

		app_state->arena_per_tick =
			(Arena){
				.buffer = per_tick_backing_memory.data,
				.capacity = per_tick_backing_memory.size,
				.name = "Tick",
			};

		u8 rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
		app_state->rc4_key_decoded_length = util_base64_decode((u8 *)rc4_key_encoded,
															   sizeof(rc4_key_encoded) - 1,
															   app_state->rc4_key_decoded);

		app_state->connection_args.udp_length = MAX_PACKET_LENGTH;
		app_state->connection_args.should_dump_core = TRUE;
		app_state->connection_args.should_dump_login = TRUE;
		app_state->connection_args.should_dump_tunnel = TRUE;
		app_state->connection_args.should_dump_gateway = TRUE;
		app_state->connection_args.should_dump_zone = TRUE;

		app_state->sessions_capacity = MAX_SESSIONS_COUNT;
		app_state->socket = app_state->platform_api->socket_udp_create_and_bind(LOCAL_PORT);
		printf(MESSAGE_CONCAT_INFO("Login server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n"));
		app_state->platform_api->folder_create("packets");
	}

	global_tick_count = *app_state->tick_count;
	u8 incoming_buffer[MAX_PACKET_LENGTH] = {0};
	u32 from_ip;
	u16 from_port;

	i32 receive_result = app_state->platform_api->receive_from(app_state->socket,
															   incoming_buffer,
															   MAX_PACKET_LENGTH,
															   &from_ip,
															   &from_port);
	if (receive_result)
	{
		printf("\n\nPacket Tick Begin ============================================================\\\\\n");

		Session_Address incoming_session_address =
			{
				.ip = from_ip,
				.port = from_port,
			};

		// TODO(rhett): will need cleaned up
		i32 first_free_session = -1;
		i32 known_session = -1;
		for (i32 i = 0; i < app_state->sessions_capacity; i++)
		{
			if (first_free_session == -1 && !app_state->sessions[i].address.full)
			{
				first_free_session = i;
			}

			if (known_session == -1 && incoming_session_address.full == app_state->sessions[i].address.full)
			{
				known_session = i;
			}

			if (first_free_session != -1 && known_session != -1)
			{
				break;
			}
		}

		if (core_packet_get_kind(incoming_buffer, receive_result) == Core_Packet_Kind_Session_Request)
		{
			if (known_session != -1)
			{
				printf(MESSAGE_CONCAT_INFO("Known client %u.%u.%u.%u:%u re-sent SessionRequest\n"),
					   (from_ip & 0xff000000) >> 24,
					   (from_ip & 0x00ff0000) >> 16,
					   (from_ip & 0x0000ff00) >> 8,
					   (from_ip & 0x000000ff),
					   from_port);
			}
			else
			{
				printf(MESSAGE_CONCAT_INFO("Unknown client %u.%u.%u.%u:%u sent SessionRequest. Beginning session\n"),
					   (from_ip & 0xff000000) >> 24,
					   (from_ip & 0x00ff0000) >> 16,
					   (from_ip & 0x0000ff00) >> 8,
					   (from_ip & 0x000000ff),
					   from_port);

				if (first_free_session == -1)
				{
					printf(MESSAGE_CONCAT_WARN("No free sessions avaliable\n"));
				}
				else
				{
					known_session = first_free_session;
					app_state->sessions[first_free_session].address.full = incoming_session_address.full;
					app_state->sessions[first_free_session].ack_next = -1;
					app_state->sessions[first_free_session].ack_previous = -1;

					base_memory_copy((void *)&app_state->sessions[first_free_session].connection_args,
									 (void *)&app_state->connection_args,
									 sizeof(app_state->connection_args));

					// TODO(rhett): These fragment pools will leak memory. this whole system needs refactored
					app_state->sessions[first_free_session].input_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
																									   MAX_PACKET_LENGTH,
																									   &app_state->arena_total);
					app_state->sessions[first_free_session].output_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
																										MAX_PACKET_LENGTH - DATA_HEADER_LENGTH,
																										&app_state->arena_total);
					app_state->sessions[first_free_session].input_stream = input_stream_init(&app_state->sessions[first_free_session].input_fragment_pool,
																							 app_state->rc4_key_decoded,
																							 app_state->rc4_key_decoded_length,
																							 FALSE);
					app_state->sessions[first_free_session].output_stream = output_stream_init(&app_state->sessions[first_free_session].output_fragment_pool,
																							   app_state->rc4_key_decoded,
																							   app_state->rc4_key_decoded_length,
																							   FALSE);
					app_state->sessions[first_free_session].input_stream.ack_callback_ptr = &app_state->stream_function_table->login_input_ack;
					app_state->sessions[first_free_session].input_stream.data_callback_ptr = &app_state->stream_function_table->login_input_data;
					app_state->sessions[first_free_session].output_stream.data_callback_ptr = &app_state->stream_function_table->login_output_data;
				}
			}
		}

		if (known_session != -1)
		{
			core_packet_handle(app_state,
							   app_state->platform_api,
							   &app_state->sessions[known_session],
							   incoming_buffer,
							   receive_result,
							   FALSE);

			if (app_state->sessions[known_session].ack_previous != app_state->sessions[known_session].ack_next)
			{
				printf(MESSAGE_CONCAT_INFO("Syncing ack...\n"));
				app_state->sessions[known_session].ack_previous = app_state->sessions[known_session].ack_next;

				Ack ack =
					{
						.sequence = (u16)app_state->sessions[known_session].ack_next};

				core_packet_send(app_state->socket,
								 app_state->platform_api,
								 app_state->sessions[known_session].address.ip,
								 app_state->sessions[known_session].address.port,
								 &app_state->sessions[known_session].connection_args,
								 Core_Packet_Kind_Ack,
								 &ack);
			}
		}

		printf("Packet Tick End ==============================================================//\n");
	}

	// TODO(rhett): maybe double buffer
	arena_reset(&app_state->arena_per_tick);
}
