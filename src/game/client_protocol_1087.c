internal void zone_packet_send(u8 data,
							   App_State* server_state,
                               Session_State* session_state,
                               Arena* arena,
                               u32 max_length,
                               Zone_Packet_Kind packet_kind,
                               void* packet_ptr)
{
	u8* base_buffer = arena_push_size(arena, max_length);
	u8* packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
	u32 packed_length = zone_packet_pack(packet_kind,
	                                     packet_ptr,
	                                     packed_buffer);
	u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;
	arena_rewind(arena, max_length - total_length);

	if (session_state->connection_args.should_dump_zone)
	{
		char dump_path[256] = { 0 };
		stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_S_zone_%s.bin", global_tick_count, global_packet_dump_count++, zone_packet_names[packet_kind]);
		server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
	}

	// TODO(rhett): still only one client for now
	gateway_tunnel_data_send(server_state, session_state, data, base_buffer, total_length);
}

internal void zone_packet_raw_file_send(u8 data,
										App_State* server_state,
                                        Session_State* session_state,
                                        Arena* arena,
                                        u32 max_length,
                                        char* path)
{
	u8* base_buffer = arena_push_size(arena, max_length);
	u8* packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
	u32 packed_length = server_state->platform_api->buffer_load_from_file(path,
	                                                                      base_buffer + TUNNEL_DATA_HEADER_LENGTH,
	                                                                      max_length);
	u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;
	arena_rewind(arena, max_length - total_length);

	if (session_state->connection_args.should_dump_zone)
	{
		char dump_path[256] = { 0 };
		stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_S_zone_RAW.bin", global_tick_count, global_packet_dump_count++);
		server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
	}

	// TODO(rhett): still only one client for now
	gateway_tunnel_data_send(server_state, session_state, data, base_buffer, total_length);
}

internal void zone_packet_handle(App_State* server_state,
                                 Session_State* session_state,
                                 u8* data,
                                 u32 data_length)
{
	Zone_Packet_Kind packet_kind;

	printf("\n");

	if (data_length == 0)
	{
		printf(MESSAGE_CONCAT_WARN("Empty zone packet????\n\n"));
		return;
	}

	// TODO(rhett): once we start receiving packets, we'll need to handle subcodes
	// TODO(rhett): OPTIMIZE THIS !!!!!!!!
	// TODO(rhett): also this is SLOPPY
	u32 packet_temp;
	u32 packet_id;
	u32 packet_iter;
	if (data_length > 0)
	{
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (data[0] == zone_registered_ids[packet_iter])
			{
				packet_id = *data;
				goto packet_id_switch;
			}
		}
	}

	if (data_length > 1)
	{
		packet_temp = (((0ul | data[0]) << 8) | data[1]);
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_temp == zone_registered_ids[packet_iter])
			{
				packet_id = packet_temp;
				goto packet_id_switch;
			}
		}
	}

	if (data_length > 2)
	{
		packet_temp = ((0ul | data[0]) << 16) | endian_read_u16_little(data + 1);
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_temp == zone_registered_ids[packet_iter])
			{
				packet_id = packet_temp;
				goto packet_id_switch;
			}
		}
	}

	__time64_t timer64;
	_time64(&timer64);

	__time32_t timer32;
	_time32(&timer32);

	packet_id = *data;
	goto packet_id_fail;


	packet_id_switch:
		switch (packet_id)
	{
		case ZONE_CLIENTISREADY_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientIsReady;
					printf("[Zone] Handling ZONE_CLIENTISREADY_ID\n");

					Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preload_done =
					{
						.is_done = TRUE,
					};					
					
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(30), Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, &preload_done);
					zone_packet_send(0, server_state,session_state,&server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ZoneDoneSendingInitialData, 0);
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, 	0);			
				
					break;
				}
				// (doggo) need to figure out a way to confirm the ClientFinishedLoading packet, because, right now this packet is not working and is being spammed and called an unhandled packet, baffles me
				case ZONE_CLIENTFINISHEDLOADING_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientFinishedLoading;
					if(session_state->finished_loading == FALSE) 
					{
						printf("[Zone] Handling ZONE_CLIENTFINISHEDLOADING_ID\n");

						Zone_Packet_Character_UpdateCharacterState updt_char_state = 
						{
							.character_id = get_guid(session_state->character_id),
							.state1 = 0,
							.state2 = 0,
							.state3 = 0,
							.state4 = 0,
							.state5 = 0,
							.state6 = 0,
							.state7 = 0,
						};

						zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_UpdateCharacterState, &updt_char_state);

						Zone_Packet_Character_WeaponStance weapon_stance =
						{
							.character_id = get_guid(session_state->character_id),
							.stance = 1,
						};

						zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_WeaponStance, &weapon_stance);

						Zone_Packet_Equipment_SetCharacterEquipment set_character_equipment =
						{	
							.length_1_length = 1,
							.length_1 =
								(struct length_1_s[1]) {
								[0] = {
									.profile_id = 5,
									.character_id = get_guid(session_state->character_id),
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
									.length_2 =
										(struct length_2_s[1]) {
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
							.attachments_data_1 =
								(struct attachments_data_1_s[1]) {
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

						zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Equipment_SetCharacterEquipment, &set_character_equipment);

						Zone_Packet_Command_AddWorldCommand command_help =
						{
							.command_length = 5,
							.command 		= "/help",
						};

						zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Command_AddWorldCommand, &command_help);
					
						Zone_Packet_Command_RunSpeed run_speed =
						{
							.run_speed = 10.0f,
						};
						
						zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Command_RunSpeed, &run_speed);
					}
					
					break;
				}
				case ZONE_LOBBYGAMEDEFINITION_DEFINITIONSREQUEST_ID:
				{
					packet_kind = Zone_Packet_Kind_LobbyGameDefinition_DefinitionsRequest;
					printf("[Zone] Handling LobbyGameDefinition.DefinitionsRequest\n");

					Zone_Packet_LobbyGameDefinition_DefinitionsResponse lobby_def_reply = 
					{
						.definitions_data = 
						(struct definitions_data_s[1]) {
							[0] = 
							{
								.data_length = 0,
								.data = "",
							},
						},
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_LobbyGameDefinition_DefinitionsResponse, &lobby_def_reply);

					break;
				}
				case ZONE_CHARACTER_RESPAWN_ID:
				{
					packet_kind = Zone_Packet_Kind_Character_Respawn;
					printf("[Zone] Handling Character.Respawn\n");

					Zone_Packet_Character_Respawn result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

					session_state->is_loading = TRUE;
					session_state->character_released = FALSE;
					// (doggo)input last login date here
					session_state->is_alive = TRUE;
					session_state->is_running = FALSE;
					session_state->is_respawning = FALSE;
					session_state->is_in_air = FALSE;

					resource_ids resource_id = {
						.HEALTH_ID = 10000,
						.HUNGER_ID = 10000,
						.HYDRATION_ID = 10000,
						.STAMINA_ID = 600,
						.VIRUS_ID = 0,
						.BLEEDING_ID = -40,
					};

					Zone_Packet_Character_RespawnReply respawn_reply = 
					{
						.character_id_1_1 = get_guid(session_state->character_id),
						.status = TRUE,
					};
					
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_RespawnReply, &respawn_reply);
					
					break;
				}
				case ZONE_CLIENTLOGOUT_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientLogout;
					printf("[Zone] Handling ClientLogout\n");
					
					/*
					char local_message[36] = { 0 };
					
					(doggo) not sure how to include the character's name, for this, will comment out for now
					stbsp_snprintf(local_message, sizeof(local_message), "%s left the server", character_name);
					
					Zone_Packet_ClientUpdate_TextAlert text_alert =
					{
						.message_length = util_string_length(local_message),
						.message 		= local_message,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_TextAlert, &text_alert);
					*/
				
					break;
				}
				case ZONE_INGAMEPURCHASEBASE_ID:
				{
					packet_kind = Zone_Packet_Kind_InGamePurchaseBase;
					printf("[Zone] Handling InGamePurchaseBase\n");
					break;
				}
				case ZONE_CLIENTLOG_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientLog;
					printf("[Zone] Handling ClientLog\n");
					break;
				}
				case ZONE_CHAT_CHAT_ID:
				{
					packet_kind = Zone_Packet_Kind_Chat_Chat;

					//Zone_Packet_Chat_Chat result = { 0 };
					//zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

					// Zone_Packet_Chat_ChatText packet =
					// {
					// 	.message_length = result.message_length,
					// 	.message = result.message,
					// };

					// zone_packet_send(server_state,session_state, &server_state->arena_per_tick, KB(30), Zone_Packet_Kind_Chat_ChatText, &packet);

					break;
				}
				case ZONE_GAMETIMESYNC_ID:
				{
					packet_kind = Zone_Packet_Kind_GameTimeSync;
					printf("[Zone] Handling GameTimeSync\n");

					//Zone_Packet_GameTimeSync result = { 0 };
					//zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

					/*
					Zone_Packet_GameTimeSync time_sync =
					{
						.time = timer64,
						.cycle_speed = 12.0f,
						.unk_bool = FALSE,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_GameTimeSync, &time_sync);
					*/
					/*
					char local_message[36] = { 0 };					
					
					(doggo) not sure how to include the character's name, for this, will comment out for now
					//stbsp_snprintf(local_message, sizeof(local_message), "%s joined the server", character_name);
					
					if (!session_state->first_login)
					{
						session_state->first_login = TRUE;
				
						Zone_Packet_ClientUpdate_TextAlert text_alert =
						{
							.message_length = util_string_length(local_message),
							.message = local_message,
						};
				
						zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_TextAlert, &text_alert);
					}
					*/

					break;
				}
				case ZONE_GETRESPAWNLOCATIONS_ID:
				{
					packet_kind = Zone_Packet_Kind_GetRespawnLocations;
					printf("[Zone] Handling GetRespawnLocations\n");

					Zone_Packet_ClientUpdate_RespawnLocations respawn_locations =
					{
						.locations1_count = 1,
						.locations1 =
							(struct locations1_s[1]) {
							[0] =
							{
								.guid = get_guid(session_state->character_id),
								.respawn_type = 4,
								.position = 602.91, 71.62, -1301.5, 1,
								.unk_dword_1 = 1,
								.unk_dword_2 = 1,
								.icon_id_1 = 1,
								.icon_id_2 = 1,
								.respawn_total_time = 10,
								.respawn_time_ms = 10000,
								.name_id = 1,
								.distance = 1000,
								.unk_byte_1 = 1,
								.unk_byte_2 = 1,

								.unk_byte_3 = 1,
								.unk_byte_4 = 1,
								.unk_byte_5 = 1,
								.unk_byte_6 = 1,
								.unk_byte_7 = 1,

								.unk_dword_3 = 1,
								.unk_byte_8 = 1,
								.unk_byte_9 = 1,
							},
						},

						.locations2_count = 1,
						.locations2 =
							(struct locations2_s[1]) {
							[0] =
							{
								.guid = get_guid(session_state->character_id),
								.respawn_type = 4,
								.position = 602.91, 71.62, -1301.5, 1,
								.unk_dword_1 = 1,
								.unk_dword_2 = 1,
								.icon_id_1 = 1,
								.icon_id_2 = 1,
								.respawn_total_time = 10,
								.respawn_time_ms = 10000,
								.name_id = 1,
								.distance = 1000,
								.unk_byte_1 = 1,
								.unk_byte_2 = 1,

								.unk_byte_3 = 1,
								.unk_byte_4 = 1,
								.unk_byte_5 = 1,
								.unk_byte_6 = 1,
								.unk_byte_7 = 1,

								.unk_dword_3 = 1,
								.unk_byte_8 = 1,
								.unk_byte_9 = 1,
							},
						},
					};

					Zone_Packet_Character_Respawn result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

					Zone_Packet_Character_RespawnReply respawn_reply = 
					{
						.character_id_1_1 = get_guid(session_state->character_id),
						.status = TRUE,
					};
					
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_RespawnReply, &respawn_reply);
					
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_RespawnLocations, &respawn_locations);

					break;
				}
				case ZONE_CLIENTUPDATE_RESPAWNLOCATIONS_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientUpdate_RespawnLocations;
					printf("[Zone] Handling ClientUpdate.RespawnLocations\n");

					Zone_Packet_ClientUpdate_RespawnLocations respawn_locations =
					{
						.locations1_count = 1,
						.locations1 =
							(struct locations1_s[1]) {
							[0] =
							{
								.guid = get_guid(session_state->character_id),
								.respawn_type = 4,
								.position = 602.91, 71.62, -1301.5, 1,
								.unk_dword_1 = 1,
								.unk_dword_2 = 1,
								.icon_id_1 = 1,
								.icon_id_2 = 1,
								.respawn_total_time = 10,
								.respawn_time_ms = 10000,
								.name_id = 1,
								.distance = 1000,
								.unk_byte_1 = 1,
								.unk_byte_2 = 1,

								.unk_byte_3 = 1,
								.unk_byte_4 = 1,
								.unk_byte_5 = 1,
								.unk_byte_6 = 1,
								.unk_byte_7 = 1,

								.unk_dword_3 = 1,
								.unk_byte_8 = 1,
								.unk_byte_9 = 1,
							},
						},

						.locations2_count = 1,
						.locations2 =
							(struct locations2_s[1]) {
							[0] =
							{
								.guid = get_guid(session_state->character_id),
								.respawn_type = 4,
								.position = 602.91, 71.62, -1301.5, 1,
								.unk_dword_1 = 1,
								.unk_dword_2 = 1,
								.icon_id_1 = 1,
								.icon_id_2 = 1,
								.respawn_total_time = 10,
								.respawn_time_ms = 10000,
								.name_id = 1,
								.distance = 1000,
								.unk_byte_1 = 1,
								.unk_byte_2 = 1,

								.unk_byte_3 = 1,
								.unk_byte_4 = 1,
								.unk_byte_5 = 1,
								.unk_byte_6 = 1,
								.unk_byte_7 = 1,

								.unk_dword_3 = 1,
								.unk_byte_8 = 1,
								.unk_byte_9 = 1,
							},
						},
					};					

					Zone_Packet_Character_Respawn result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

					Zone_Packet_Character_RespawnReply respawn_reply = 
					{
						.character_id_1_1 = get_guid(session_state->character_id),
						.status = TRUE,
					};
					
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_RespawnReply, &respawn_reply);
					
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_RespawnLocations, &respawn_locations);

					break;
				}
				case ZONE_SETLOCALE_ID:
				{
					packet_kind = Zone_Packet_Kind_SetLocale;
					printf("[Zone] Handling SetLocale\n");

					break;
				}
				case ZONE_CLIENTINITIALIZATIONDETAILS_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientInitializationDetails;
					printf("[Zone] Handling ClientInitializationDetails\n");

					break;
				}

				case ZONE_WALLOFDATA_UIEVENT_ID:
				{
					packet_kind = Zone_Packet_Kind_WallOfData_UIEvent;
					printf("[Zone] Handling WallOfData.UIEvent\n");

					Zone_Packet_WallOfData_UIEvent result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);
			
					break;
				}

				case ZONE_WALLOFDATA_CLIENTSYSTEMINFO_ID:
				{
					packet_kind = Zone_Packet_Kind_WallOfData_ClientSystemInfo;
					printf("[Zone] Handling WallOfData.ClientSystemInfo\n");

					Zone_Packet_WallOfData_ClientSystemInfo result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);
			
					break;
				}
				case ZONE_WALLOFDATA_CLIENTTRANSITION_ID:
				{
					packet_kind = Zone_Packet_Kind_WallOfData_ClientTransition;
					printf("[Zone] Handling WallOfData.ClientTransition\n");

					Zone_Packet_WallOfData_ClientTransition result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);
			
					break;
				}
				case ZONE_CLIENTUPDATE_MONITORTIMEDRIFT_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift;
					printf("[Zone] Handling ClientUpdate.MonitorTimeDrift\n");

					Zone_Packet_ClientUpdate_MonitorTimeDrift time_drift =
					{
						.time_drift = timer32,
					};
			
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(time_drift), Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift, &time_drift);

					break;
				}
				case ZONE_GETCONTINENTBATTLEINFO_ID:
				{
					packet_kind = Zone_Packet_Kind_GetContinentBattleInfo;
					printf("[Zone] Handling GetContinentBattleInfo\n");

					Zone_Packet_ContinentBattleInfo battle_info =
					{
						.zones_count = 1,
						.zones =
							(struct zones_s[1]) {
							[0] =
							{
								.continent_id = 1,
								.info_name_id = 1,
								.zone_description_id = 1,

								.zone_name_length = 2,
								.zone_name = "Z2",
								.hex_size = 100,
								.is_production_zone = 1,
							}
						}
					};
			
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(battle_info), Zone_Packet_Kind_ContinentBattleInfo, &battle_info);

					break;
				}
				case ZONE_RESOURCEEVENTBASE_ID:
				{
					packet_kind = Zone_Packet_Kind_ResourceEventBase;
					printf("[Zone] Handling ResourceEventBase\n");

					/*
					Zone_Packet_ResourceEventBase rsrc_event_base =
					{
						.gametime = timer32,
						.variabletype8 =
						(struct set_character_resources_1_s[1]) {
							[0] = 
							{
								.character_id_1 = get_guid(session_state->character_id),

								.character_resources_1_count = 1,
								.character_resources_1 = 
									(struct character_resources_1_s[1]) {
									[0] = 
									{
										.resource_type_1 = 3,

										.resource_id_1 = session_state->resource_id,
										.resource_type_2 = session_state->resource_type ? session_state->resource_type : session_state->resource_id,
										.value = 1000,
									},
								},
							},
						},
						(struct set_character_resources_2_s[1]) {
							[0] = 
							{
								.character_id_2 = get_guid(session_state->character_id),

								.character_resources_2_count = 1,
								.character_resources_2 = 
									(struct character_resources_2_s[1]) {
									[0] = 
									{
										.resource_type_1 = 3,

										.resource_id = session_state->resource_id,
										.resource_type_2 = session_state->resource_type ? session_state->resource_type : session_state->resource_id,
										.value = 1000,
									},
								},
							},
						},
						(struct updt_character_resources_s[1]) {
							[0] = 
							{
								.character_id_3 = get_guid(session_state->character_id),
								.resource_id_2 = session_state->resource_id,
								.resource_type_3 = session_state->resource_type ? session_state->resource_type : session_state->resource_id,
								.initial_value = 1000 >= 0 ? 1000 : 0,
							},
						},
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(rsrc_event_base), Zone_Packet_Kind_ResourceEventBase, &rsrc_event_base);
					*/

					break;
				}
				case ZONE_CLIENTUPDATE_UPDATEBATTLEYEREGISTRATION_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration;
					printf("[Zone] Handling ClientUpdate.UpdateBattlEyeRegistration\n");

					// (doggo)keep empty, don't need this

					break;
				}
				case ZONE_KEEPALIVE_ID:
				{
					packet_kind = Zone_Packet_Kind_KeepAlive;
					printf("[Zone] Handling KeepAlive\n");

				/*
					Zone_Packet_KeepAlive keep_alive =
					{
						.game_time = timer32,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_KeepAlive, &keep_alive);
				*/
					break;
				}
		default:
		{
			packet_id_fail:
				packet_kind = Zone_Packet_Kind_Unhandled;
			printf(MESSAGE_CONCAT_WARN("Unhandled zone packet 0x%02x\n"), packet_id);

			if (session_state->connection_args.should_dump_zone)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_zone_%s.bin", global_tick_count, global_packet_dump_count++, zone_packet_names[packet_kind]);
				server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}
		}
	}
}