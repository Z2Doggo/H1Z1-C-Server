// TODO(rhett): custom preprocessor?

#include <stdio.h>
#include <time.h>

#define YOTE_USE_ARENA   1
#define YOTE_USE_ENDIAN  1
#define YOTE_USE_STRING  1
#include "yote.h"
#define YOTE_PLATFORM_USE_SOCKETS  1
#include "yote_platform.h"

#include "game_server.h"

#define LOCAL_PORT          60000
// NOTE(rhett): realistically no more than 100 at once
//#define MAX_SESSIONS_COUNT 16384
#define MAX_SESSIONS_COUNT  16

#include "utility/util.c"
#include "utility/crypt_rc4.c"
#include "session.h"


struct App_State
{
	Platform_Api* platform_api;
	Platform_Socket socket;

	Arena arena_total;
	Arena arena_per_tick;

	i32 rc4_key_decoded_length;
	u8 rc4_key_decoded[256];

	Session_Pool session_pool;

	// TEMPORARY(rhett): 
	Stream fragment_accumulator;
	// TEMPORARY(rhett): 
	Session_Handle pending_session;
};

global u64 global_tick_count;
global u64 global_dump_count;
global b32 global_should_dump_core = TRUE;
#define PACKET_FOLDER  "..\\GAME_PACKETS"


#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE  "Core"
#include "core_protocol.c"
#undef MESSAGE_NAMESPACE

// TEMP
global b32 ignore_packets;
global b32 finished_loading;
global b32 first_login;
global b32 is_ready;

#define MESSAGE_NAMESPACE  "Gateway"
#include "game/external_gateway_api_3.c"
#undef MESSAGE_NAMESPACE
//// TODO(rhett): Client or Zone? Client is the word used by the game, but zone is more clear?
#define MESSAGE_NAMESPACE  "Zone"
#define printf(...)
#include "../schema/output/client_protocol_1087.c"
#undef printf
#include "game/client_protocol_1087.c"
#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE  "Ping"
#include "game/ping_responder.c"
#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE MESSAGE_NAMESPACE_DEFAULT


GATEWAY_TUNNEL_DATA_CALLBACK(on_gateway_tunnel_data)
{
	// TODO(rhett): do something with channel
	protocol_client_packet_route((Buffer) { .size = tunnel_data.data_size, .data = tunnel_data.data }, session_handle, app_state);
}

CORE_DATA_INPUT_CALLBACK(on_core_data_input)
{
	protocol_gateway_packet_route(data_buffer, session_handle, app_state);
}

SESSION_ESTABLISHED_CALLBACK(on_session_established)
{
}

__declspec(dllexport) APP_TICK(server_tick)
{
	global_tick_count = app_memory->tick_count;
	App_State* app_state = app_memory->app_state;
	if (!app_state)
	{
		app_state = app_memory->app_state = arena_bootstrap_push_struct(app_memory->backing_memory.data,
		                                                                app_memory->backing_memory.size,
		                                                                "Total",
		                                                                App_State,
		                                                                arena_total);
		app_state->platform_api = &app_memory->platform_api;

		app_state->arena_per_tick =
			(Arena) {
			.capacity = MB(10),
			.buffer = arena_push_size(&app_state->arena_total, MB(10)),
			.name = "Tick",
		};

		u8 rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
		app_state->rc4_key_decoded_length = util_base64_decode(cast(u8*)rc4_key_encoded,
		                                                       SIZE_OF(rc4_key_encoded) - 1,
		                                                       app_state->rc4_key_decoded);

		app_state->session_pool = session_pool_create(&app_state->arena_total, MAX_SESSIONS_COUNT);
		app_state->fragment_accumulator =
			(Stream) {
			.size = MB(1),
			.data = arena_push_size(&app_state->arena_total, MB(1)),
		};

		app_state->socket = app_state->platform_api->socket_udp_create_and_bind(LOCAL_PORT);
		printf(MESSAGE_CONCAT_INFO("Game server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n"));
	}

#if 0
	Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preload_done =
	{
		.unk_bool = TRUE,
	};

	// TEMPORARY(rhett): 
	local_persist f32 pending_session_accumulator;
	pending_session_accumulator += dt;
	if (pending_session_accumulator > 10.0f)
	{
		pending_session_accumulator = 0.0f;
		if (app_state->pending_session.id)
		{
			printf(MESSAGE_CONCAT_DEBUG("Sending to pending session\n"));
			protocol_client_packet_send(&preload_done, Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(0, Zone_Packet_Kind_ZoneDoneSendingInitialData, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
		}
	}
#endif

	DEFER_SCOPE(0, arena_reset(&app_state->arena_per_tick))
	{
		u8 incoming_buffer[MAX_PACKET_SIZE] = { 0 };
		u32 from_ip;
		u16 from_port;
		i32 receive_result = app_state->platform_api->receive_from(app_state->socket,
		                                                           incoming_buffer,
		                                                           MAX_PACKET_SIZE,
		                                                           &from_ip,
		                                                           &from_port);
		ASSERT(receive_result <= SIZE_OF(incoming_buffer));
		
		if (receive_result)
		{
			printf("\n\n________________________________________ Packet Tick Begin _________________________________________\n");

			Session_Address incoming_session_address =
			{
				.ip = from_ip,
				.port = from_port,
			};

			Session_State* session = 0;
			Session_Handle session_handle = session_get_handle_from_address(&app_state->session_pool, incoming_session_address);
			if (!session_handle.id)
			{
				session_handle = session_acquire(&app_state->session_pool, incoming_session_address);
				if (!session_handle.id)
				{
					NOT_IMPLEMENTED_MSG("No more free session slots");
				}

				session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);

				// NOTE(rhett): address and handle already filled out
				session->protocol_options =
					(Protocol_Options) {
					.crc_seed = 0,
					.crc_size = 0,
					.compression = 0,
					.udp_size = MAX_PACKET_SIZE,
					.use_encryption = FALSE,
				};
				session->acked_in = -1;
				session->sequence_in = -1;
				session->sequence_out = -1;
				crypt_rc4_initialize(&session->rc4_state_in, app_state->rc4_key_decoded, app_state->rc4_key_decoded_length);
				crypt_rc4_initialize(&session->rc4_state_out, app_state->rc4_key_decoded, app_state->rc4_key_decoded_length);
			}

			// NOTE(rhett): session pointer wasn't already received during session init
			if (!session)
			{
				session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);
				ASSERT(session);
			}

			if (!session->handle.id)
			{
				NOT_IMPLEMENTED_MSG("we got the invalid session, something went wrong");
			}

			// NOTE(rhett): Server reload message
			if (should_reload)
			{
				protocol_client_packet_raw_file_send("..\\resources\\server_message_reload.bin",
				                          KB(10),
				                          &app_state->arena_per_tick,
				                          session_handle,
				                          app_state);
			}

			Buffer packet_buffer =
			{
				.size = receive_result,
				.data = cast(u8*)&incoming_buffer
			};

			if (session->kind == Session_Kind_Ping_Responder)
			{
				protocol_ping_packet_route(packet_buffer, session_handle, app_state);
			}
			else
			{
				protocol_core_packet_route(packet_buffer, FALSE, session_handle, app_state);
			}

			if (session->sequence_in > session->acked_in)
			{
				for (i32 ack_iter = 0; ack_iter < (session->sequence_in - session->acked_in); ack_iter++)
				{
					// NOTE(rhett): starts at -1
					session->acked_in++;
					Core_Packet_Ack ack =
					{
						.sequence = cast(u16)session->acked_in,
					};
					protocol_core_packet_send(&ack, Core_Packet_Kind_Ack, session_handle, app_state);
				}
			}

			printf("----------------------------------------- Packet Tick End ------------------------------------------\n");
		}
	}
}




