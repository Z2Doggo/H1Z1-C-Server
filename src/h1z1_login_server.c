#define LOCAL_PORT         20042
#define MAX_FRAGMENTS      12000
#define MAX_PACKET_LENGTH  512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 2


#include "utility/strings.c"
#include "shared/protocol/stream.h"
#include "shared/protocol/fragment_pool.c"
#include "shared/protocol/input_stream.c"
#include "shared/protocol/output_stream.c"
#include "shared/protocol/core_protocol.h"
#include "shared/connection.h"
#include "shared/session.h"
#include "shared/packet_queue.h"
#include "shared/packet_queue.c"

global u64 global_packet_dump_count;

struct Server_State
{
	Platform_Api* platform_api;
	Memory_Arena arena_per_tick;

	Platform_Socket socket;

	u8 rc4_key_decoded[256];
	i32 rc4_key_decoded_length;
	Connection_Args connection_args;

	i32 sessions_capacity;
	Session_State sessions[MAX_SESSIONS_COUNT];
};

internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data);

//#include "shared/protocol/core_protocol.c"
//#include "../schema/output/login_udp_9.c"
//#include "login/login_udp_9.c"
#include "shared/protocol/core_protocol.c"
#include "../schema/output/login_udp_11.c"
#include "login/login_udp_11.c"


internal INPUT_STREAM_CALLBACK_ACK(on_input_stream_ack)
{
	Session_State* session_state = session;
	session_state->ack_next = ack;
}

internal INPUT_STREAM_CALLBACK_DATA(on_input_stream_data)
{
	login_packet_handle(server, session, data, data_length);
}

// TODO(rhett): remove this later
internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data)
{
	UNUSED(server);
	UNUSED(session);
	UNUSED(data);
	UNUSED(data_length);
};

internal OUTPUT_STREAM_CALLBACK_DATA(on_output_stream_data)
{
	Server_State* server_state = server;
	Session_State* session_state = session;

	Data packet =
	{
		.sequence = (u16)sequence,
		.data = data,
		.data_length = data_length,
	};

	if (!is_fragment)
	{
		core_packet_send(server_state->socket, server_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data, &packet);
	}
	else
	{
		core_packet_send(server_state->socket, server_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data_Fragment, &packet);
	}
}

internal void login_tick_run(Program_State* program_state)
{
	Server_State* server_state = program_state->server_state;
	if (!server_state)
	{
		server_state = program_state->server_state = memory_arena_push_struct(&program_state->arena_persist, Server_State);
		server_state->platform_api = program_state->platform_api;

		usize backing_memory_length = MB(10);
		void* backing_memory = memory_arena_push_length(&program_state->arena_persist, backing_memory_length);
		server_state->arena_per_tick = memory_arena_init(backing_memory, backing_memory_length, "Tick");

		u8 rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
		server_state->rc4_key_decoded_length = util_base64_decode((u8*)rc4_key_encoded, sizeof(rc4_key_encoded) - 1, server_state->rc4_key_decoded);

		server_state->connection_args.crc_seed 		= 0;
		server_state->connection_args.crc_length 	= 0;
		server_state->connection_args.udp_length 	= MAX_PACKET_LENGTH;
		server_state->connection_args.encryption	= FALSE;

		server_state->sessions_capacity = MAX_SESSIONS_COUNT;
		server_state->socket = server_state->platform_api->socket_udp_create_and_bind(program_state->platform_state, LOCAL_PORT);
		printf("[Login] Login server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n");
		server_state->platform_api->folder_create("packets");
	}


	u8 incoming_buffer[MAX_PACKET_LENGTH] = { 0 };
	u32 from_ip;
	u16 from_port;
	i32 receive_result = server_state->platform_api->receive_from(
		server_state->socket,
	    incoming_buffer,
	    MAX_PACKET_LENGTH,
	    &from_ip,
	    &from_port
	);

	if (receive_result)
	{
		Session_Address incoming_session_address =
		{
			.ip = from_ip,
			.port = from_port,
		};

		// TODO(rhett): will need cleaned up
		i32 first_free_session = -1;
		i32 known_session = -1;
		for (i32 i = 0; i < server_state->sessions_capacity; i++)
		{
			if (first_free_session == -1 && !server_state->sessions[i].address.full)
			{
				first_free_session = i;
			}

			if (known_session == -1 && incoming_session_address.full == server_state->sessions[i].address.full)
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
				printf("[*] Known client %u.%u.%u.%u:%u re-sent SessionRequest\n",
				       (from_ip & 0xff000000) >> 24,
				       (from_ip & 0x00ff0000) >> 16,
				       (from_ip & 0x0000ff00) >> 8,
				       (from_ip & 0x000000ff),
				       from_port);
			}
			else
			{
				printf("[*] Unknown client %u.%u.%u.%u:%u sent SessionRequest. Beginning session\n",
				       (from_ip & 0xff000000) >> 24,
				       (from_ip & 0x00ff0000) >> 16,
				       (from_ip & 0x0000ff00) >> 8,
				       (from_ip & 0x000000ff),
				       from_port);

				if (first_free_session == -1)
				{
					printf("[!] No free sessions avaliable\n");
				}
				else
				{
					known_session = first_free_session;
					server_state->sessions[first_free_session].address.full = incoming_session_address.full;
					server_state->sessions[first_free_session].ack_next = -1;
					server_state->sessions[first_free_session].ack_previous = -1;

					util_memory_copy(
						(void*)&server_state->sessions[first_free_session].connection_args,
					    (void*)&server_state->connection_args,
					    sizeof(server_state->connection_args)
					);

					// TODO(rhett): These fragment pools will leak memory. this whole system needs refactored
					server_state->sessions[first_free_session].input_fragment_pool = fragment_pool_create(
						MAX_FRAGMENTS,
					    MAX_PACKET_LENGTH,
					    &program_state->arena_persist);

					server_state->sessions[first_free_session].output_fragment_pool = fragment_pool_create(
						MAX_FRAGMENTS,
					    MAX_PACKET_LENGTH - DATA_HEADER_LENGTH,
					    &program_state->arena_persist
					);

					server_state->sessions[first_free_session].input_stream = input_stream_init(&server_state->sessions[first_free_session].input_fragment_pool,
					    server_state->rc4_key_decoded,
					    server_state->rc4_key_decoded_length,
					    FALSE
						);

					server_state->sessions[first_free_session].output_stream = output_stream_init(
						&server_state->sessions[first_free_session].output_fragment_pool,
					    server_state->rc4_key_decoded,
					    server_state->rc4_key_decoded_length,
					    FALSE
					);

					server_state->sessions[first_free_session].input_stream.ack_callback = on_input_stream_ack;
					server_state->sessions[first_free_session].input_stream.data_callback = on_input_stream_data;
					server_state->sessions[first_free_session].output_stream.data_callback = on_output_stream_data;
				}
			}
		}

		if (known_session != -1)
		{
			core_packet_handle(
				server_state,
			    server_state->platform_api,
			    &server_state->sessions[known_session],
			    incoming_buffer,
			    receive_result,
			    FALSE
			);

			if (server_state->sessions[known_session].ack_previous != server_state->sessions[known_session].ack_next)
			{
				// printf("\n[*] Syncing ack...\n");
				server_state->sessions[known_session].ack_previous = server_state->sessions[known_session].ack_next;

				Ack ack =
				{
					.sequence = (u16)server_state->sessions[known_session].ack_next
				};

				core_packet_send(
					server_state->socket,
				    server_state->platform_api,
				    server_state->sessions[known_session].address.ip,
				    server_state->sessions[known_session].address.port,
				    &server_state->sessions[known_session].connection_args,
				    Core_Packet_Kind_Ack,
				    &ack
				);
			}
		}
	}

	// TODO(rhett): maybe double buffer
	memory_arena_reset(&server_state->arena_per_tick);
}
