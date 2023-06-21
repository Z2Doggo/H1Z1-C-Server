#if defined(YOTE_INTERNAL)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#else
static void platform_win_console_write(char *format, ...);
#define printf(s, ...) platform_win_console_write(s, __VA_ARGS__)
#endif // YOTE_INTERNAL

#define YOTE_USE_ARENA 1
#define YOTE_USE_STRING 1
#include "yote.h"
#define YOTE_PLATFORM_USE_SOCKETS 1
#include "yote_platform.h"
#include "game_server.h"

#define LOCAL_PORT 60000
#define MAX_FRAGMENTS 12000
#define MAX_PACKET_LENGTH 512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 16

#include "utility/endian.c"
#include "utility/util.c"
#include "utility/crypt_rc4.c"
#include "utility/character_id_gen.c"
#include "utility/transient_id_gen.c"
#include "shared/protocol/stream.h"
#include "shared/protocol/fragment_pool.c"
#include "shared/protocol/input_stream.c"
#include "shared/protocol/output_stream.c"
#include "shared/protocol/core_protocol.h"
#include "shared/connection.h"
#include "shared/session.h"
#include "shared/packet_queue.h"
#include "shared/packet_queue.c"

// thirdparty utility headers go here
#include "thirdparty_utility/jansson.h"

global u64 global_packet_dump_count;
// HACK(rhett):
global u64 global_tick_count;

typedef struct Stream_Function_Table Stream_Function_Table;
struct Stream_Function_Table
{
	input_stream_callback_ack *game_input_ack;
	input_stream_callback_data *game_input_data;
	output_stream_callback_data *game_output_data;
	input_stream_callback_data *ping_input_data;
};

struct App_State
{
	Stream_Function_Table *stream_function_table;
	f32 *tick_ms;
	f32 *work_ms;
	u64 *tick_count;
	Key_States *key_states;

#if defined(TERMINAL_UI)
	Buffer screen;
#endif // TERMINAL_UI

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

internal void gateway_on_login(App_State *app_state, Session_State *session_state);
internal void gateway_on_tunnel_data_from_client(App_State *app_state, Session_State *session_state, u8 *data, u32 data_length);
internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data);

#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE "Core"
#include "shared/protocol/core_protocol.c"
#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE "Gateway"
#include "game/external_gateway_api_3.c"
#undef MESSAGE_NAMESPACE
// TODO(rhett): Client or Zone? Client is the word used by the game, but zone is more clear?
#define MESSAGE_NAMESPACE "Zone"
#include "../schema/output/client_protocol_1087.c"
#include "../schema/output/login_udp_11.c"
#include "game/client_protocol_1087.c"
#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE MESSAGE_NAMESPACE_DEFAULT

internal void gateway_on_login(App_State *app_state, Session_State *session_state)
{
	printf("[!] Character %llxh trying to login to zone server\n", 0x133742069);

	Zone_Packet_InitializationParameters init_params = 
	{ 
		.environment_length = 9,
		.environment = "LIVE_KOTK",
	};

	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_InitializationParameters, &init_params);

	Zone_Packet_SendZoneDetails send_zone_details = 
	{ 
		.zone_name_length = 9,
		.zone_name = "LoginZone",
		.zone_type = 4,
		.unk_bool = FALSE,
		// set skydata
		.unknownDword1 = 1.0f,
		.fog_density = 0.0001733333f,
		.fog_floor = 10.0f,
		.fog_gradient = 0.0144f,
		.rain = 1.0f,
		.temp = 75.0f,
		.color_gradient = 0.0f,
		.unknown_dword8 = 0.05f,
		.unknown_dword9 = 0.0f,
		.unknown_dword10 = 0.05f,
		.unknown_dword11 = 0.15f,
		.unknown_dword12 = 0.0f,
		.sun_axis_x = 38.0f,
		.sun_axis_y = -15.0f,
		.unknown_dword15 = 0.0f,
		.disable_trees = -1.0f,
		.disable_trees1 = -0.05f,
		.disable_trees2 = -1.0f,
		.wind = 3.0f,
		.unknown_dword20 = 0.0f,
		.unknown_dword21 = 1.0f,
		.name_length = 16,
		.name = "sky_Z_clouds.dds",
		.unknown_dword22 = 0.3f,
		.unknown_dword23 = -0.002f,
		.unknown_dword24 = 0.0f,
		.unknown_dword25 = 1000.0f,
		.unknown_dword26 = 0.2f,
		.unknown_dword27 = 0.0f,
		.unknown_dword28 = 0.002f,
		.unknown_dword29 = 8000.0f,
		.ao_size = 0.0f,
		.ao_gamma = 0.25f,
		.ao_blackpoint = 7.0f,
		.unknown_dword33 = 0.5f,
		.zone_id = 5,
		.zone_id_2 = 5,
		.name_id = 7699,
		.unk_bool2 = TRUE,
		.lighting_length = 15,
		.lighting = "Lighting_Z2.txt",
		.unk_bool3 = FALSE,
		.unk_bool4 = FALSE,
	};

	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_SendZoneDetails, &send_zone_details);

	Zone_Packet_ClientGameSettings game_settings = 
	{ 
		.interact_glow_and_dist = 16,
		.unk_bool = TRUE,
		.timescale = 1.0,
		.enable_weapons = 1,
		.unk_u32_2 = 1,
		.unk_float2 = 15.,
		.damage_multiplier = 11.,
	};

	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientGameSettings, &game_settings);

	Zone_Packet_SendSelfToClient send_self = { .payload_self =
		(struct payload_self_s[1])
		{
			[0] = 
			{ 
				.guid = 0x133742069,
				.transient_id.value = 0x1337420,
				.actor_model_id = 9474,
				.head_actor_length = 26,
				.head_actor = "SurvivorFemale_Head_02.adr",
				.hair_model_length = 32,
				.hair_model = "SurvivorFemale_Hair_ShortBun.adr",
				.is_respawning = FALSE,
				.character_name_length = 5,
				.character_name = "doggo",
				.gender1 = 2,
				.creation_date = 0x133333333,
				.last_login_date = 0x133333333,
				.loadout_id = 3,
				.loadout_slots_array_count = 1,
				.loadout_slots_array =
				(struct loadout_slots_array_s[1])
				{ 	
					[0] = 
					{ 
						.hotbar_slot_id = 0,
						.loadout_id = 3,
						.slot_id = 0,
						.item_def_id4 = 1 || 0,
						.loadout_item_guid = 0x01 || 0,
						.unk_byte_17 = 255,
						.unk_dword_111 = 0,
					},
				},
				.current_slot_id = 7,
				.equipment_slots_count = 1,
				.equipment_slots =
				(struct equipment_slots_s[1])
				{ 	
					[0] = 
					{ 
						.unk_dword_7199 = 0,
						.unk_dword_890 = 0,
						.equipment_slot_id2 = 0,
						.equipment_slot_id3 = 0,
						.guid = 0x0,
						.decal_alias_length = 1,
						.decal_alias = "#" },
				},
				.character_resources_count = 1,
				.character_resources =
				(struct character_resources_s[1])
				{ 	
					[0] = 
					{ 
						.resource_type1 = 1,
						.resource_id = 1,
						.resource_type2 = 1,
						.value = 10000,
					},
				},
				.containers_count = 1,
				.containers =
				(struct containers_s[1])
				{ 	
					[0] = 
					{ 
						.loadout_slot_id = 0,
						.guid = 0x133742069,
						.def_id = 0,
						.associated_character_id = 0x133742069,
						.slots = 14,
						.items2_count = 1,
						.items2 =
						(struct items2_s[1])
						{ 			
							[0] = 
							{ 
								.item_def_id5 = 0,
								.item_def_id6 = 0,
								.tint_id = 0,
								.guid = 0x133742069,
								.count = 14,
								.container_guid = 0x133742069,
								.container_def_id = 14,
								.container_slot_id = 0,
								.base_durability = 10,
								.current_durability = 10 ? 15 : 0,
								.max_durability_from_def = 10,
								.unk_bool_116 = TRUE,
								.owner_character_id = 0x0000000000000001,
								.unk_dword_9 = 1,
								// (doggo)put weapon data here from sendself later...
								.show_bulk = TRUE,
								.unk_dword_133 = 28,
							},
						},
					},
				},
				.is_admin = TRUE,
			},
		},
	};
	// (doggo)if this packet was a person, I would beat the ever-living shit out of it!
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_SendSelfToClient, &send_self);

	Zone_Packet_ContainerInitEquippedContainers init_equipped_containers = 
	{ 
		.ignore_this = 0,
		.character_id = 0x133742069,
		.container_list_count = 1,
		.container_list =
		(struct container_list_s[1])
		{
			[0] = 
			{ 
				.loadout_slot_id = 0,
				.guid_1 = 0x133742069,
				.defs_id = 0,
				.associated_character_id = 0x133742069,
				.slots = 0,
				.items_list_count = 1,
				.items_list =
				(struct items_list_s[1])
				{ 	
					[0] = 
					{ 
						.item_defs_id_1 = 0,
						.item_defs_id_2 = 0,
						.tint_id = 0,
						.guid_2 = 0x133742069,
						.count = 1,
						.unk_qword_1 = 0,
						.unk_dword_1 = 0,
						.unk_dword_2 = 0,
						.container_guid = 0,
						.contain_def_id = 0,
						.container_slot_id = 0,
						.base_durability = 0,
						.current_durability = 0,
						.max_durability_from_defs = 0,
						.unk_bool_1 = FALSE,
						.owner_character_id = 0x133742069,
						.unk_dword_3 = 0,
					},
				},
				.show_bulk = TRUE,
				.max_bulk = 0,
				.unk_dword_4 = 0,
				.bulk_used = 0,
				.has_bulk_limit = TRUE,
			},
		},
	};
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_ContainerInitEquippedContainers, &init_equipped_containers);

	Zone_Packet_UpdateWeatherData updt_weather_data = 
	{	
		.unknownDword1 = 1.0f,
		.fog_density = 0.0001733333f,
		.fog_floor = 10.0f,
		.fog_gradient = 0.0144f,
		.rain = 1.0f,
		.temp = 75.0f,
		.color_gradient = 0.0f,
		.unknown_dword8 = 0.05f,
		.unknown_dword9 = 0.0f,
		.unknown_dword10 = 0.05f,
		.unknown_dword11 = 0.15f,
		.unknown_dword12 = 0.0f,
		.sun_axis_x = 38.0f,
		.sun_axis_y = -15.0f,
		.unknown_dword15 = 0.0f,
		.disable_trees = -1.0f,
		.disable_trees1 = -0.05f,
		.disable_trees2 = -1.0f,
		.wind = 3.0f,
		.unknown_dword20 = 0.0f,
		.unknown_dword21 = 1.0f,
		.name_length = 16,
		.name = "sky_Z_clouds.dds",
		.unknown_dword22 = 0.3f,
		.unknown_dword23 = -0.002f,
		.unknown_dword24 = 0.0f,
		.unknown_dword25 = 1000.0f,
		.unknown_dword26 = 0.2f,
		.unknown_dword27 = 0.0f,
		.unknown_dword28 = 0.002f,
		.unknown_dword29 = 8000.0f,
		.ao_size = 0.0f,
		.ao_gamma = 0.25f,
		.ao_blackpoint = 7.0f,
		.unknown_dword33 = 0.5f,
	};
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_UpdateWeatherData, &updt_weather_data);

	Zone_Packet_Equipment_SetCharacterEquipment set_character_equipment =
	{
		.length_1_length = 1,
		.length_1 =
			(struct length_1_s[1]) {
				[0] = {
					.profile_id = 5,
					.character_id = 0x133742069,
				},
			},
		.unk_dword_1 = 0,
		.unk_string_1_length = 7,
		.unk_string_1 = "Default",
		.unk_string_2_length = 1,
		.unk_string_2 = "#",
		.equipment_slot_array_count = 1,
		.equipment_slot_array = 
		(struct equipment_slot_array_s[1]) {
			[0] =
			{
				.equipment_slot_id_1 = 0,
				.length_2_length = 1,
				.length_2 = (struct length_2_s[1]){
					[0] = {
						.equipment_slot_id_2 = 0,
						.guid = 0, // keep guid as a 0
						.tint_alias_length = 7,
						.tint_alias = "Default",
						.decal_alias_length = 1,
						.decal_alias = "#",
					},
				},
			},
		},

		.attachments_data_1_count = 1,
		.attachments_data_1 = (struct attachments_data_1_s[1]){
			[0] = 
			{
				.model_name_length = 0,
				.model_name = "",
				.texture_alias_length = 0,
				.texture_alias = "",
				.tint_alias_length = 7,
				.tint_alias = "Default",
				.decal_alias_length = 1,
				.decal_alias = "#",
				.slot_id = 0,
			},
		},
		.unk_bool_2 = TRUE,
	};
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_Equipment_SetCharacterEquipment, &set_character_equipment);

	Zone_Packet_Loadout_SetLoadoutSlots ldt_setldtslots = 
	{
		.character_id = 0x133742069,
		.loadout_id = 0,
		.loadout_slot_data_count = 1,
		.loadout_slot_data =
		(struct loadout_slot_data_s[1]) {
			[0] = 
			{
				.hotbar_slot_id = 0,
				.loadout_id_1 = 0,
				.slot_id = 0,
				.item_def_id1 = 0,
				.loadout_item_guid = 0x0,
				.unk_byte_1 = 255,
				.unk_dword_1 = 0,
			},
		},
		.current_slot_id = 0,
	};
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_Loadout_SetLoadoutSlots, &ldt_setldtslots);
}


internal void gateway_on_tunnel_data_from_client(App_State *app_state, Session_State *session_state, u8 *data, u32 data_length)
{
	zone_packet_handle(app_state, session_state, data, data_length);
}

internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data)
{
	UNUSED(server);
	UNUSED(session);
	UNUSED(data);
	UNUSED(data_length);
	// ping_packet_handle(server, session, data, data_length);
}

internal INPUT_STREAM_CALLBACK_ACK(on_input_stream_ack)
{
	Session_State *session_state = session;
	session_state->ack_next = ack;
}

internal INPUT_STREAM_CALLBACK_DATA(on_input_stream_data)
{
	gateway_packet_handle(server, session, data, data_length);
}

internal OUTPUT_STREAM_CALLBACK_DATA(on_output_stream_data)
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

// TODO(rhett): STBSP_SPRINTF breaks if this is less than 4 bytes each? or sanitizer issue
char toggle_state_text[2][4] =
	{
		[FALSE] = "--",
		[TRUE] = "ON",
};

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

#if defined(TERMINAL_UI)
		Buffer screen =
			{
				.size = sizeof(char) * SCREEN_RESOLUTION,
				.data = arena_push_size(&app_state->arena_total,
										screen.size),
			};
		app_state->screen = app_memory->screen = screen;
		// core_memory_fill(app_state->screen.data, ' ', app_state->screen.size);
#endif // TERMINAL_UI

		Buffer per_tick_backing_memory =
			{
				.size = MB(10),
				.data = arena_push_size(&app_state->arena_total,
										per_tick_backing_memory.size),
			};

		app_state->stream_function_table = arena_push_struct(&app_state->arena_total, Stream_Function_Table);
		app_state->stream_function_table->game_input_ack = on_input_stream_ack;
		app_state->stream_function_table->game_input_data = on_input_stream_data;
		app_state->stream_function_table->game_output_data = on_output_stream_data;
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
		// TODO(rhett): encryption should probably be kept disabled initially and toggled on in higher layers
		// app_state->connection_args.use_encryption = FALSE;
		app_state->connection_args.should_dump_core = TRUE;
		app_state->connection_args.should_dump_login = TRUE;
		app_state->connection_args.should_dump_tunnel = TRUE;
		app_state->connection_args.should_dump_gateway = TRUE;
		app_state->connection_args.should_dump_zone = TRUE;

		app_state->sessions_capacity = MAX_SESSIONS_COUNT;
		app_state->socket = app_state->platform_api->socket_udp_create_and_bind(LOCAL_PORT);
		printf(MESSAGE_CONCAT_INFO("Game server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n"));
		app_state->platform_api->folder_create("packets");
	}

	if (should_reload)
	{
		printf(MESSAGE_CONCAT_INFO("Reloading function table...\n"));
		app_state->stream_function_table->game_input_ack = on_input_stream_ack;
		app_state->stream_function_table->game_input_data = on_input_stream_data;
		app_state->stream_function_table->game_output_data = on_output_stream_data;
		app_state->stream_function_table->ping_input_data = on_ping_input_stream_data;
	}

	// app_state->platform_api->buffer_write_to_file("STATE.dump",
	//(u8*)app_state,
	// sizeof(App_State));

	global_tick_count = *app_state->tick_count;

#if defined(TERMINAL_UI)
	core_memory_fill(app_state->screen.data, ' ', app_state->screen.size);
	stbsp_sprintf((char *)app_state->screen.data,
				  "Tick: %llu    %fms/w | %fms/f", *app_state->tick_count, *app_state->work_ms, *app_state->tick_ms);

	i32 pos = 0;
	for (i32 key = 0; key < 0xff; key++)
	{
		pos += stbsp_sprintf((char *)(app_state->screen.data + (SCREEN_WIDTH * 2) + pos),
							 "K%02x %s  ",
							 key,
							 toggle_state_text[(*app_state->key_states)[key]]);
	}

	// pos = SCREEN_WIDTH * 29;
	// pos += stbsp_sprintf((char*)(app_state->screen.data + pos),
	//"cool :)");
#endif // TERMINAL_UI

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

		// TODO(rhett): Before we tackle the problem of multiple clients, let's reliably handle one first
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

					app_state->sessions[first_free_session].input_stream.ack_callback_ptr = &app_state->stream_function_table->game_input_ack;
					app_state->sessions[first_free_session].input_stream.data_callback_ptr = &app_state->stream_function_table->game_input_data;
					app_state->sessions[first_free_session].output_stream.data_callback_ptr = &app_state->stream_function_table->game_output_data;
				}
			}
		}

		if (known_session != -1)
		{
			if (app_state->sessions[known_session].kind == Session_Kind_Ping_Responder)
			{
				// ping_packet_handle(app_state,
				//&app_state->sessions[known_session],
				// incoming_buffer,
				// receive_result);
			}
			else
			{
				core_packet_handle(app_state, app_state->platform_api, &app_state->sessions[known_session], incoming_buffer, receive_result, FALSE);
			}

			// Zone_Packet_ClientUpdatePacketModifyMovementSpeed speed = { .speed = 4.0f, .unk_bool = 1};

			// local_persist b32 do_once_7 = 0;
			// if (!do_once_7++)
			//{
			// DO_ONCE(printf("AAAAAAAAAAAAAAAAA\n\n"); zone_packet_send(app_state, &app_state->sessions[known_session], &app_state->arena_per_tick, KB(1), Zone_Packet_Kind_ClientUpdatePacketModifyMovementSpeed, &speed););
			// }

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

		////// TODO(rhett): SHELVING THIS FOR NOW
		// TODO(rhett): think about when we should process our packet queue
		// TODO(rhett): we also should have a way to time this,
		//              probably through the platform api
		// TODO(rhett): processing one normal packet per tick for now
		// if (app_state->packet_queue.entries_tail > 0)
		//{
		// packet_queue_pop_and_send(&app_state->packet_queue,
		//                     app_state);
		//                     //&app_state->arena_per_frame,
		//                     //app_state->server_packet_send);
		//
		////Packet_Queue_Entry normal_packet_entry = packet_queue_pop(&app_state->packet_queue);
		////zone_packet_send(app_state,
		//			//normal_packet_entry.session_state,
		//			//&app_state->arena_per_frame,
		//			//normal_packet_entry.max_packed_length,
		//			//normal_packet_entry.packet_kind,
		//			//app_state->packet_queue.buffer + normal_packet_entry.buffer_offset);
		//}

		printf("Packet Tick End ==============================================================//\n");
	}

	arena_reset(&app_state->arena_per_tick);
}
