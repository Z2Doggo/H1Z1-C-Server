#define CLIENT_TO_PROXY_PORT 20042
#define MAX_PACKET_LENGTH    512
#define DATA_HEADER_LENGTH   4
#define MAX_FRAGMENTS        12000


#include "shared/protocol/stream.h"
#include "shared/protocol/fragment_pool.c"
#include "shared/protocol/input_stream.c"
#include "shared/protocol/output_stream.c"
#include "shared/connection.h"
#include "shared/session.h"


typedef struct Proxy_Memory Proxy_Memory;
typedef struct Proxy_State Proxy_State;

struct Proxy_Memory
{
	Platform_State* platform_state;
	Platform_Api* platform_api;
	Memory_Arena arena_persist;
	Proxy_State* proxy_state;
};

struct Proxy_State
{
	Platform_Api* platform_api;
	Memory_Arena  arena_per_frame;

	Platform_Socket client_to_proxy_socket;
	Session_State client_to_proxy_session;

	u8 rc4_key_decoded[256];
	i32 rc4_key_decoded_length;
	Connection_Args connection_args;
};


// TODO(rhett): I'm unsure about how I'm handling this memory/state stuff right now
void proxy_tick_run(Proxy_Memory* proxy_memory)
{
	Proxy_State* proxy_state = proxy_memory->proxy_state;

	if (!proxy_state)
	{
		proxy_state = proxy_memory->proxy_state = memory_arena_push_struct(&proxy_memory->arena_persist, Proxy_State);
		proxy_state->platform_api = proxy_memory->platform_api;

		void* backing_buffer = memory_arena_push_length(&proxy_memory->arena_persist, MB(10));
		usize backing_buffer_length = MB(10);
		proxy_state->arena_per_frame = memory_arena_init(backing_buffer,
		                                                 backing_buffer_length,
		                                                 "Per Frame");

		char rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
		proxy_state->rc4_key_decoded_length = util_base64_decode((u8*)rc4_key_encoded,
		                                                         sizeof(rc4_key_encoded) - 1,
		                                                         proxy_state->rc4_key_decoded);

		proxy_state->connection_args.udp_length = MAX_PACKET_LENGTH;
		// TODO(rhett): encryption should probably be kept disabled initially and toggled on in higher layers
		//proxy_state->connection_args.use_encryption = FALSE;
		proxy_state->connection_args.should_dump_core = TRUE;
		proxy_state->connection_args.should_dump_login = TRUE;
		proxy_state->connection_args.should_dump_tunnel = TRUE;
		proxy_state->connection_args.should_dump_gateway = TRUE;
		proxy_state->connection_args.should_dump_zone = TRUE;

		proxy_state->client_to_proxy_socket = proxy_state->platform_api->socket_udp_create_and_bind(proxy_memory->platform_state, CLIENT_TO_PROXY_PORT);
		printf("[*] ClientToProxy socket bound to " STRINGIFY(CLIENT_TO_PROXY_PORT) "\n\n");
	}

	u8 incoming_buffer[MAX_PACKET_LENGTH] = { 0 };
	u32 from_ip;
	u16 from_port;
	i32 receive_result = proxy_state->platform_api->receive_from(proxy_state->client_to_proxy_socket,
	                                                             incoming_buffer,
	                                                             MAX_PACKET_LENGTH,
	                                                             &from_ip,
	                                                             &from_port);

	if (receive_result)
	{
		Session_Address incoming_address =
		{
			.ip = from_ip,
			.port = from_port,
		};

		if (!proxy_state->client_to_proxy_session.address.full)
		{
			// NOTE(rhett): Session slot free, create session
			printf("[*] New session from %u.%u.%u.%u:%u\n",
			       (from_ip & 0xff000000) >> 24,
			       (from_ip & 0x00ff0000) >> 16,
			       (from_ip & 0x0000ff00) >> 8,
			       (from_ip & 0x000000ff),
			       from_port);

			proxy_state->client_to_proxy_session.address.full = incoming_address.full;
			proxy_state->client_to_proxy_session.ack_next = -1;
			proxy_state->client_to_proxy_session.ack_previous = -1;

			util_memory_copy((void*)&proxy_state->client_to_proxy_session.connection_args,
			                 (void*)&proxy_state->connection_args,
			                 sizeof(proxy_state->connection_args));

			proxy_state->client_to_proxy_session.input_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
			                                                                                MAX_PACKET_LENGTH,
			                                                                                &proxy_memory->arena_persist);
			proxy_state->client_to_proxy_session.output_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
			                                                                                 MAX_PACKET_LENGTH - DATA_HEADER_LENGTH,
			                                                                                 &proxy_memory->arena_persist);
			proxy_state->client_to_proxy_session.input_stream = input_stream_init(&proxy_state->client_to_proxy_session.input_fragment_pool,
			                                                                      proxy_state->rc4_key_decoded,
			                                                                      proxy_state->rc4_key_decoded_length,
			                                                                      FALSE);
			proxy_state->client_to_proxy_session.output_stream = output_stream_init(&proxy_state->client_to_proxy_session.input_fragment_pool,
			                                                                        proxy_state->rc4_key_decoded,
			                                                                        proxy_state->rc4_key_decoded_length,
			                                                                        FALSE);
		}
		else
		{
			printf("[*] New session from %u.%u.%u.%u:%u, but no avaliable slot\n",
						 (from_ip & 0xff000000) >> 24,
						 (from_ip & 0x00ff0000) >> 16,
						 (from_ip & 0x0000ff00) >> 8,
						 (from_ip & 0x000000ff),
						 from_port);
		}
	}

}
