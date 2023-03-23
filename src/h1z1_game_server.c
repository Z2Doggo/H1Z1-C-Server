#define LOCAL_PORT         1117
#define MAX_FRAGMENTS      12000
#define MAX_PACKET_LENGTH  512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 2

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

internal void gateway_on_login(Server_State* server_state, Session_State* session_state, u64 character_id);
internal void gateway_on_tunnel_data_from_client(Server_State* server_state, Session_State* session_state, u8* data, u32 data_length);
internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data);

#include "shared/protocol/core_protocol.c"
#include "game/external_gateway_api_3.c"
#include "../schema/output/client_protocol_298.c"
#include "game/client_protocol_298.c"

// TODO(rhett): hardcoded in gateway protocol for now
internal void gateway_on_login(Server_State* server_state, Session_State* session_state, u64 character_id)
{
	printf("[!] Character %llxh trying to login to zone server\n", character_id);

	Zone_Packet_InitializationParameters init_params =
	{
		.environment_length = 4,
		.environment = "LIVE",
		.unk_string_1_length = 0,
		.unk_string_1 = "",
	};

	Zone_Packet_SendZoneDetails send_zone_details =
	{
		.zone_name_length 	= 2,
		.zone_name 			= "Z1",
		.zone_type 			= 4,
		.unk_bool 			= FALSE,

		// todo: set sky_data
		.name				= "sky_Z_clouds.dds",

		.color_gradient		= 0.,
		.color_gradient		= 0.,
		.unknown_dword8		= 0.05,
		.unknown_dword10	= 0.05,
		.unknown_dword11	= 0.15,
		.wind			 	= 3,
		.unknown_dword21 	= 1,
		.unknown_dword22 	= 0.3,
		.unknown_dword23 	= -0.002,
		.unknown_dword24 	= 0,
		.unknown_dword25 	= 1000,
		.unknown_dword26 	= 0.2,
		.unknown_dword28 	= 0.002,
		.unknown_dword29 	= 8000,
		.ao_size 			= 0,
		.ao_gamma 			= 0.25,
		.ao_blackpoint 		= 7,
		.unknown_dword33 	= 0.5,

		.zone_id			= 5,
		.zone_id_2			= 5,
		.name_id			= 7699,
		.unk_bool2			= TRUE,
		.lighting			= "Lighting.txt",
		.unk_bool3			= FALSE,
	};

	Zone_Packet_CommandItemDefinitions item_defs = 
	{
		.item_def_reply_2 =
			(struct item_def_reply_2_s[1]) {
			[0] =
			{
				.item_defs_count = 1,
				.item_defs =
					(struct item_defs_s[1]) {
					[0] =
					{
						.defs_id = 0,
						
						.bitflags1 = 0,
						.bitflags2 = 0,

						.name_id = 0,
						.description_id = 0,
						.content_id = 0,
						.image_set_id = 0,
						.tint_id = 0,
						.hud_image_set_id = 0,
						.unk_dword_1 = 921,
						.unk_dword_2 = 922,
						.cost = 0,
						.item_class = 0,
						.profile_override = 0,

						.model_name_length = 0,

						.texture_alias_length = 0,

						.gender_usage = 0,
						.item_type = 0,
						.category_id = 0,
						.weapon_trail_effect_id = 0,
						.composite_effect_id = 0,
						.power_rating = 0,
						.min_profile_rank = 0,
						.rarity = 0,
						.activatable_ability_id = 0,
						.activatable_ability_set_id = 0,
						.passive_ability_id = 0,
						.passive_ability_set_id = 0,
						.max_stack_size = 0,
						.min_stack_size = 0,

						.tint_alias_length = 0,

						.tint_group_id = 0,
						.member_discount = 0,
						.vip_rank_required = 0,
						.race_set_id = 0,
						.ui_model_camera_id_1 = 0,
						.equip_count_max = 0,
						.curreny_type = 0,
						.datasheet_id = 0,
						.item_type_1 = 0,
						.skill_set_id = 0,

						.overlay_texture_length = 0,

						.decal_slot_length = 0,

						.overlay_adjustment = 0,
						.trial_duration_sec = 0,
						.next_trial_delay_sec = 0,
						.client_use_requirement = 0,

						.override_appearance_length = 0,

						.override_camera_id = 0,
						.unk_dword_3 = 28,
						.unk_dword_4 = 28,
						.unk_dword_5 = 28,
						.bulk = 0,
						.active_equip_slot_id = 0,
						.passive_equip_slot_id = 0,
						.passive_equip_slot_group_id = 0,
						.unk_dword_6 = 927,
						.grinder_reward_set_id = 0,
						.build_bar_group_id = 0,

						.unk_string_1_length = 13,
						.unk_string_1 = "testStringAAA",

						.unk_bool_1 = TRUE,
						.is_armor = FALSE,
						.unk_dword_7 = 28,
						.param1 = 0,
						.param2 = 0,
						.param3 = 0,

						.string_param1_length = 0,
							
						.ui_model_camera_id_2 = 0,
						.unk_dword_8 = 932,
						.scrap_value_override = 0,

						.stats_item_def_2_count = 1,
						.stats_item_def_2 =
							(struct stats_item_def_2_s[1]) {
							[0] =
							{
								.unk_dword_9 = 0,

								.stat_id = 0,
								.base = 0,
								.modifier = 0,

								.unk_dword_10 = 0,
							},
						},
					},
				},
			},
		},
	};

	/*
	Zone_Packet_ReferenceDataWeaponDefinitions weapon_defs =
	{

	};
	*/

	Zone_Packet_ClientGameSettings game_settings =
	{
		.interact_glow_and_dist 	= 16,
		.unk_bool 					= TRUE,
		.timescale 					= 1.0,
		.enable_weapons 			= 1,
		.unk_u32_2					= 1,
		.unk_float2 				= 15.,
		.damage_multiplier 			= 11.,
	};

	/*
	(doggo)todo: unfinished.. going to redo sendself

	Zone_Packet_SendSelfToClient send_self = 
	{
		.payload_self =
			(struct payload_self_s[1]) {
			[0] =
			{
				.guid_1 = 0x66778899,
				.character_id_1 = 0xaabbccdd11223344,
				.unk_uint2b.value = 52,
				.actor_model_id = 176,
				.head_actor_length = 25,
				.head_actor = "Head_Female_Caucasian.adr",
				.head_id = 5,
			},
		},
	};
	*/

	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_InitializationParameters, &init_params);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_SendZoneDetails, &send_zone_details);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_CommandItemDefinitions, &item_defs);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientGameSettings, &game_settings);
	//zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(40), Zone_Packet_Kind_SendSelfToClient, &send_self);

	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "1.bin");
	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "2.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(40), "C:\\Users\\Lane\\Desktop\\send_self\\" "3.bin");
	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "4.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(40), "C:\\Users\\Lane\\Desktop\\send_self\\" "5.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "6.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "7.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "8.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "9.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "10.bin");
}

internal void gateway_on_tunnel_data_from_client(Server_State* server_state, Session_State* session_state, u8* data, u32 data_length)
{
	zone_packet_handle(server_state, session_state, data, data_length);
}

internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data)
{
	//ping_packet_handle(server, session, data, data_length);
}

internal INPUT_STREAM_CALLBACK_ACK(on_input_stream_ack)
{
	Session_State* session_state = session;
	session_state->ack_next = ack;
}

internal INPUT_STREAM_CALLBACK_DATA(on_input_stream_data)
{
	gateway_packet_handle(server, session, data, data_length);
}

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

internal void game_tick_run(Program_State* program_state)
{
	Server_State* server_state = program_state->server_state;
	if (!server_state)
	{
		//server_state = program_state->server_state = server_state_create(&program_state->persist_arena,
		                                                                 //&program_state->platform_api);
		server_state = program_state->server_state = memory_arena_push_struct(&program_state->arena_persist,
		                                                                      Server_State);
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
		printf("[*] Game server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n");
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
					from_port
				);
			}
			else
			{
				printf("[*] Unknown client %u.%u.%u.%u:%u sent SessionRequest. Beginning session\n",
					(from_ip & 0xff000000) >> 24,
					(from_ip & 0x00ff0000) >> 16,
					(from_ip & 0x0000ff00) >> 8,
					(from_ip & 0x000000ff),
					from_port
				);

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
					server_state->sessions[first_free_session].input_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
					                                                                                      MAX_PACKET_LENGTH,
					                                                                                      &program_state->arena_persist);
					server_state->sessions[first_free_session].output_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
					                                                                                       MAX_PACKET_LENGTH - DATA_HEADER_LENGTH,
					                                                                                       &program_state->arena_persist);
					server_state->sessions[first_free_session].input_stream = input_stream_init(&server_state->sessions[first_free_session].input_fragment_pool,
					                                                                            server_state->rc4_key_decoded,
					                                                                            server_state->rc4_key_decoded_length,
					                                                                            FALSE);
					server_state->sessions[first_free_session].output_stream = output_stream_init(&server_state->sessions[first_free_session].output_fragment_pool,
					                                                                              server_state->rc4_key_decoded,
					                                                                              server_state->rc4_key_decoded_length,
					                                                                              FALSE);

					server_state->sessions[first_free_session].input_stream.ack_callback = on_input_stream_ack;
					server_state->sessions[first_free_session].input_stream.data_callback = on_input_stream_data;
					server_state->sessions[first_free_session].output_stream.data_callback = on_output_stream_data;
				}
			}
		}

		if (known_session != -1)
		{
			if (server_state->sessions[known_session].kind == Session_Kind_Ping_Responder)
			{
				//ping_packet_handle(server_state,
				                   //&server_state->sessions[known_session],
				                   //incoming_buffer,
				                   //receive_result);
			}
			else
			{
				core_packet_handle(server_state, server_state->platform_api, &server_state->sessions[known_session], incoming_buffer, receive_result, FALSE);
			}

			if (server_state->sessions[known_session].ack_previous != server_state->sessions[known_session].ack_next)
			{
				server_state->sessions[known_session].ack_previous = server_state->sessions[known_session].ack_next;

				Ack ack =
				{
					.sequence = (u16)server_state->sessions[known_session].ack_next
				};

				core_packet_send(server_state->socket,
				                 server_state->platform_api,
				                 server_state->sessions[known_session].address.ip,
				                 server_state->sessions[known_session].address.port,
				                 &server_state->sessions[known_session].connection_args,
				                 Core_Packet_Kind_Ack,
				                 &ack);
			}
		}
		
		////// TODO(rhett): SHELVING THIS FOR NOW
		// TODO(rhett): think about when we should process our packet queue
		// TODO(rhett): we also should have a way to time this,
		//              probably through the platform api
		// TODO(rhett): processing one normal packet per tick for now
		//if (server_state->packet_queue.entries_tail > 0)
		//{
			//packet_queue_pop_and_send(&server_state->packet_queue,
			     //                     server_state);
			     //                     //&server_state->arena_per_frame,
			     //                     //server_state->server_packet_send);
//
			////Packet_Queue_Entry normal_packet_entry = packet_queue_pop(&server_state->packet_queue);
			////zone_packet_send(server_state,
								//			//normal_packet_entry.session_state,
								//			//&server_state->arena_per_frame,
								//			//normal_packet_entry.max_packed_length,
								//			//normal_packet_entry.packet_kind,
								//			//server_state->packet_queue.buffer + normal_packet_entry.buffer_offset);
		//}
	}

	memory_arena_reset(&server_state->arena_per_tick);
}
