#define ZONE_PACKET_ID_SIZE 2
#define ZONE_PACKET_RESERVED_SIZE (CORE_DATA_FRAGMENT_EXTRA_SIZE + GATEWAY_PACKET_ID_SIZE)

global b32 ignore_packets;

// TODO(rhett): return the actual size used?
void protocol_client_packet_send(void *packet_ptr,
								 Zone_Packet_Kind packet_kind,
								 u32 zone_part_reserved_size,
								 Arena *arena,
								 Session_Handle session_handle,
								 App_State *app_state)
{
	// IMPORTANT(rhett): reserve space for lower layer ids
	u32 total_reserved_size = ZONE_PACKET_RESERVED_SIZE + zone_part_reserved_size;
	u8 *total_buffer = arena_push_size(arena, total_reserved_size);

	u8 *zone_part_buffer = ZONE_PACKET_RESERVED_SIZE + total_buffer;
	u32 zone_part_size = zone_packet_pack(packet_kind, packet_ptr, zone_part_buffer);

	u32 total_size = ZONE_PACKET_RESERVED_SIZE + zone_part_size;
	arena_rewind(arena, cast(u32) total_reserved_size - total_size);

	// TODO(rhett): length values don't exceed a u32.
	if (global_should_dump_core)
	{
		app_state->platform_api->folder_create(PACKET_FOLDER);
		char dump_path[96] = {0};
		stbsp_snprintf(dump_path,
					   SIZE_OF(dump_path),
					   PACKET_FOLDER "\\%llu_%llu_S_zone_%s.bin",
					   global_tick_count,
					   global_dump_count++,
					   zone_packet_names[packet_kind]);
		app_state->platform_api->buffer_write_to_file(dump_path,
													  zone_part_buffer,
													  zone_part_size);
	}
	protocol_gateway_tunnel_data_send((Buffer){.data = total_buffer, .size = cast(i64) total_size},
									  session_handle,
									  app_state);
}

void protocol_client_packet_raw_file_send(char *file_path,
										  u32 zone_part_reserved_size,
										  Arena *arena,
										  Session_Handle session_handle,
										  App_State *app_state)
{
	// IMPORTANT(rhett): reserve space for lower layer ids
	u32 total_reserved_size = ZONE_PACKET_RESERVED_SIZE + zone_part_reserved_size;
	u8 *total_buffer = arena_push_size(arena, total_reserved_size);

	u8 *zone_part_buffer = ZONE_PACKET_RESERVED_SIZE + total_buffer;
	u32 zone_part_size = app_state->platform_api->buffer_load_from_file(file_path, zone_part_buffer, zone_part_reserved_size - ZONE_PACKET_RESERVED_SIZE);

	u32 total_size = ZONE_PACKET_RESERVED_SIZE + zone_part_size;
	arena_rewind(arena, cast(u32) total_reserved_size - total_size);

	// TODO(rhett): length values don't exceed a u32.
	if (global_should_dump_core)
	{
		app_state->platform_api->folder_create(PACKET_FOLDER);
		char dump_path[96] = {0};
		stbsp_snprintf(dump_path,
					   SIZE_OF(dump_path),
					   PACKET_FOLDER "\\%llu_%llu_S_zone_file.bin",
					   global_tick_count,
					   global_dump_count++);
		app_state->platform_api->buffer_write_to_file(dump_path,
													  zone_part_buffer,
													  zone_part_size);
	}
	protocol_gateway_tunnel_data_send((Buffer){.data = total_buffer, .size = cast(i64) total_size},
									  session_handle,
									  app_state);
}

GATEWAY_LOGIN_CALLBACK(on_gateway_login)
{
	printf(MESSAGE_CONCAT_INFO("Gateway login %#x\n"), session_handle.id);

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

	Zone_Packet_SendSelfToClient send_self =
		{
			.payload_self =
				(struct payload_self_s[1]){
					[0] = {
						.guid = 0x133742069,
						.transient_id.value = 42069,
						.actor_model_id = 9474,
						.head_actor_length = 26,
						.head_actor = "SurvivorFemale_Head_02.adr",
						.hair_model_length = 32,
						.hair_model = "SurvivorFemale_Hair_ShortBun.adr",
						.is_respawning = FALSE,
						.character_name_length = 5,
						.character_name = "doggo",
						.gender1 = 1 || 2,
						.creation_date = 0x133333333,
						.last_login_date = 0x133333333,

						.loadout_id = 3,
						.loadout_slots_array_count = 1,
						.loadout_slots_array =
							(struct loadout_slots_array_s[1]){
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
							(struct equipment_slots_s[1]){
								[0] =
									{
										.unk_dword_7199 = 0,
										.unk_dword_890 = 0,
										.equipment_slot_id2 = 0,
										.equipment_slot_id3 = 0,
										.guid = 0x0,
										.decal_alias_length = 1,
										.decal_alias = "#"},
							},

						.character_resources_count = 1,
						.character_resources =
							(struct character_resources_s[1]){
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
							(struct containers_s[1]){
								[0] = {
									.loadout_slot_id = 0,
									.guid = 0x133742069,
									.def_id = 0,
									.associated_character_id = 0x133742069,
									.slots = 14,
									.items2_count = 1,
									.items2 =
										(struct items2_s[1]){
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

	Zone_Packet_InitializationParameters init_parms =
		{
			.environment_length = 9,
			.environment = "LIVE_KOTK",
		};

	Zone_Packet_ClientGameSettings settings =
		{
			.interact_glow_and_dist = 16,
			.unk_bool = TRUE,
			.timescale = 1.0,
			.enable_weapons = 1,
			.unk_u32_2 = 1,
			.unk_float2 = 15.,
			.damage_multiplier = 11.,
		};

	Zone_Packet_UpdateWeatherData update_weather_data =
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

	protocol_client_packet_send(&init_parms, Zone_Packet_Kind_InitializationParameters, 512, &app_state->arena_per_tick, session_handle, app_state);
	protocol_client_packet_send(&send_zone_details, Zone_Packet_Kind_SendZoneDetails, KB(10), &app_state->arena_per_tick, session_handle, app_state);
	protocol_client_packet_send(&settings, Zone_Packet_Kind_ClientGameSettings, KB(1), &app_state->arena_per_tick, session_handle, app_state);
	protocol_client_packet_send(&update_weather_data, Zone_Packet_Kind_ClientGameSettings, KB(1), &app_state->arena_per_tick, session_handle, app_state);
	protocol_client_packet_send(&send_self, Zone_Packet_Kind_SendSelfToClient, KB(500), &app_state->arena_per_tick, session_handle, app_state);

	app_state->pending_session = session_handle;
}

void protocol_client_packet_route(Buffer packet_buffer, Session_Handle session_handle, App_State *app_state)
{
	ASSERT(app_state);
	ASSERT(session_handle.id);
	ASSERT(packet_buffer.data);

	Stream packet_stream =
		{
			.size = packet_buffer.size,
			.data = packet_buffer.data,
		};
	// TODO(rhett):
	UNUSED(packet_stream);

	// TODO(rhett): rework this once schema tool is improved
	u32 packet_temp;
	u32 packet_iter;
	Zone_Packet_Kind packet_kind = Zone_Packet_Kind_Unhandled;
	if (packet_buffer.size > 0)
	{
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_buffer.data[0] == zone_registered_ids[packet_iter])
			{
				packet_kind = packet_iter;
			}
		}
	}

	if (packet_buffer.size > 1)
	{
		packet_temp = (((0ul | packet_buffer.data[0]) << 8) | packet_buffer.data[1]);
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_temp == zone_registered_ids[packet_iter])
			{
				packet_kind = packet_iter;
			}
		}
	}

	if (packet_buffer.size > 2)
	{
		packet_temp = ((0ul | packet_buffer.data[0]) << 16) | endian_read_u16_little(packet_buffer.data + 1);
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_temp == zone_registered_ids[packet_iter])
			{
				packet_kind = packet_iter;
			}
		}
	}

	if (global_should_dump_core)
	{
		app_state->platform_api->folder_create(PACKET_FOLDER);
		char dump_path[96] = {0};
		stbsp_snprintf(dump_path,
					   SIZE_OF(dump_path),
					   PACKET_FOLDER "\\%llu_%llu_C_zone_%s.bin",
					   global_tick_count,
					   global_dump_count++,
					   zone_packet_names[packet_kind]);
		app_state->platform_api->buffer_write_to_file(dump_path,
													  packet_buffer.data,
													  cast(u32) packet_buffer.size);
	}

	printf(MESSAGE_CONCAT_INFO("Routing %s...\n"), zone_packet_names[packet_kind]);
	Session_State *session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);
	switch (packet_kind)
	{
	case Zone_Packet_Kind_ClientIsReady:
	{
		if (app_state->pending_session.id)
		{
			Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preload_done =
				{
					.is_done = TRUE,
				};
			printf(MESSAGE_CONCAT_DEBUG("Sending to pending session\n"));
			protocol_client_packet_send(&preload_done, Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			// app_state->pending_session.id = 0;

			Zone_Packet_Character_CharacterStateDelta character_state_delta =
				{
					.guid_1 = 0x133742069,
					.guid_3 = 0x0000000040000000,
					.game_time = 11,
				};

			__time64_t timer;
			_time64(&timer);
			
			Zone_Packet_GameTimeSync sync =
				{
					.time = timer / 1000,
					.cycle_speed = 12.0f,
					.unk_bool = FALSE,
				};

			protocol_client_packet_send(&sync, Zone_Packet_Kind_GameTimeSync, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(0, Zone_Packet_Kind_ZoneDoneSendingInitialData, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(0, Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(&character_state_delta, Zone_Packet_Kind_Character_CharacterStateDelta, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			// Sleep(5000);
			app_state->pending_session.id = 0;
			ignore_packets = TRUE;
		}
	}
	break;

	case Zone_Packet_Kind_ClientFinishedLoading:
	{
		if (finished_loading == FALSE)
		{
			Zone_Packet_Character_WeaponStance weapon_stance =
				{
					.character_id = 0x133742069,
					.stance = 1,
				};

			Zone_Packet_Equipment_SetCharacterEquipment set_character_equipment =
				{
					.length_1_length = 1,
					.length_1 =
						(struct length_1_s[1]){
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
					.equipment_slot_array = (struct equipment_slot_array_s[1]){
						[0] = {
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
						[0] = {
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

			Zone_Packet_Loadout_SetLoadoutSlots ldt_setldtslots = {
				.character_id = 0x133742069,
				.loadout_id = 0,
				.loadout_slot_data_count = 1,
				.loadout_slot_data =
					(struct loadout_slot_data_s[1]){
						[0] = {
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

			Zone_Packet_Command_AddWorldCommand command_help =
				{
					.command_length = 5,
					.command = "/help",
				};

			Zone_Packet_Character_StartMultiStateDeath multi_state_dth = {
				.character_id = 0x0000000000000000,
				.unk_byte_1 = 0,
				.unk_byte_2 = 1,
				.unk_byte_3 = 0,
			};

			protocol_client_packet_send(&weapon_stance, Zone_Packet_Kind_Character_WeaponStance, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(&set_character_equipment, Zone_Packet_Kind_Equipment_SetCharacterEquipment, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(&ldt_setldtslots, Zone_Packet_Kind_Loadout_SetLoadoutSlots, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(&command_help, Zone_Packet_Kind_Command_AddWorldCommand, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
			protocol_client_packet_send(&multi_state_dth, Zone_Packet_Kind_Character_StartMultiStateDeath, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);

			finished_loading = TRUE;
			first_login = FALSE;
			is_ready = TRUE;
		}
	}
	break;

	case Zone_Packet_Kind_GetContinentBattleInfo:
	{
		Zone_Packet_ContinentBattleInfo battle_info = {
			.zones_count = 1,
			.zones =
			(struct zones_s[1]) {
				[0] = {
					.continent_id = 1,
					.info_name_id = 1,
					.zone_description_id = 1,

					.zone_name_length = 9,
					.zone_name = "LoginZone",
					.hex_size = 100,
					.is_production_zone = 1,
				},
			},
		};

		protocol_client_packet_send(&battle_info, Zone_Packet_Kind_ContinentBattleInfo, 512, &app_state->arena_per_tick, app_state->pending_session, app_state);
	} break;

	case Zone_Packet_Kind_GameTimeSync:
	{
		__time64_t timer;
		_time64(&timer);
		Zone_Packet_GameTimeSync sync =
			{
				.time = timer / 1000,
				.cycle_speed = 12.0f,
				.unk_bool = FALSE,
			};

		protocol_client_packet_send(&sync, Zone_Packet_Kind_GameTimeSync,
									KB(1),
									&app_state->arena_per_tick,
									session_handle,
									app_state);
	}
	break;

	case Zone_Packet_Kind_ClientLog:
	{
		// session->protocol_options.use_encryption = FALSE;
	}
	break;
	}
}