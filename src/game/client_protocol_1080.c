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
		printf(MESSAGE_CONCAT_WARN("Empty zone packet?\n\n"));
		return;
	}

	typedef enum packet_channel 
	{
		packet_channel_0 = 0,
		packet_channel_1 = 1,
		packet_channel_2 = 2,
		packet_channel_3 = 3,
		packet_channel_4 = 4,
		packet_channel_5 = 5,
		packet_channel_6 = 6,
		packet_channel_7 = 7,
	} packet_channel;

	__time64_t timer;
	_time64(&timer);

	// TODO(rhett): once we start receiving packets, we'll need to handle subcodes
	// (doggo) ^ done!
	// TODO(rhett): OPTIMIZE THIS !!!!!!!!
	// TODO(rhett): also this is SLOPPY
	u32 packet_temp;
	u32 packet_id = *data;
	u32 sub_packet_id = data[1];
	u32 packet_iter;
	u8 channel = *data >> 5;

	if (data_length > 0)
	{
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (data[0] == zone_registered_ids[packet_iter])
			{
				packet_id = *data;
				goto switch_gateway_channel;
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
				goto switch_gateway_channel;
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
				goto switch_gateway_channel;
			}
		}
	}

	packet_id = *data;
	goto packet_id_fail;
	
	local_persist u8 test = FALSE;
	
	// (doggo)makes it easier to send packets that need to be sent on the proper gateway channel, 
	switch_gateway_channel:
	switch (channel)
	{
		case packet_channel_0:
		{ 
			switch (packet_id)
			{
				case ZONE_CLIENTISREADY_ID:
				{
					printf("[Zone] Handling ZONE_CLIENTISREADY_ID\n");

					Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preload_done =
					{
						.is_done = TRUE,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(30), Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, &preload_done);
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, 	0);
					// todo: send DtoObjectInitialData for trees
					zone_packet_send(0, server_state,session_state,&server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ZoneDoneSendingInitialData, 0);

					Zone_Packet_Character_CharacterStateDelta character_state_delta =
					{
						.guid_1 	= session_state->character_id,
						.guid_3 	= 0x0000000040000000,
						.game_time 	= (u32)timer,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(character_state_delta), Zone_Packet_Kind_Character_CharacterStateDelta, &character_state_delta);

					break;
				}
				// (doggo) need to figure out a way to confirm the ClientFinishedLoading packet, because, right now this packet is not working and is being spammed and called an unhandled packet, baffles me
				case ZONE_CLIENTFINISHEDLOADING_ID:
				{
					//packet_kind = Zone_Packet_Kind_ClientFinishedLoading;
					//printf("[Zone] Handling ZONE_CLIENTFINISHEDLOADING_ID\n");

					if (session_state->finished_loading == FALSE)
					{
						packet_kind = Zone_Packet_Kind_ClientFinishedLoading;
						printf("[Zone] Handling ZONE_CLIENTFINISHEDLOADING_ID\n");

						session_state->finished_loading = TRUE;

						Zone_Packet_Character_WeaponStance weapon_stance =
						{
							.character_id = session_state->character_id,
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
									.character_id = session_state->character_id,
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
											.guid = 0,
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
					}

					return;
				}
				case ZONE_CLIENTLOGOUT_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientLogout;
					printf("[Zone] Handling ClientLogout\n");

					char local_message[36] = { 0 };

					/*
					(doggo) not sure how to include the character's name, for this, will comment out for now
					stbsp_snprintf(local_message, sizeof(local_message), "%s left the server", character_name);
					*/

					Zone_Packet_ClientUpdate_TextAlert text_alert =
					{
						.message_length = util_string_length(local_message),
						.message 		= local_message,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_TextAlert, &text_alert);
			
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

					Zone_Packet_Chat_Chat result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

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

					Zone_Packet_GameTimeSync result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

					Zone_Packet_GameTimeSync time_sync =
					{
						.time = timer,
						.cycle_speed = 12.0f,
						.unk_bool = FALSE,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(time_sync), Zone_Packet_Kind_GameTimeSync, &time_sync);

					char local_message[36] = { 0 };					
					
					/*
					(doggo) not sure how to include the character's name, for this, will comment out for now
					//stbsp_snprintf(local_message, sizeof(local_message), "%s joined the server", character_name);
					*/

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

					break;
				}
				case ZONE_KEEPALIVE_ID:
				{
					packet_kind = Zone_Packet_Kind_KeepAlive;
					printf("[Zone] Handling KeepAlive\n");

					Zone_Packet_KeepAlive keep_alive =
					{
						.game_time = (u32)timer,
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_KeepAlive, &keep_alive);
					
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
								.guid = generate_guid(),
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
								.guid = generate_guid(),
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

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(respawn_locations), Zone_Packet_Kind_ClientUpdate_RespawnLocations, &respawn_locations);

					break;
				}
				case ZONE_SETLOCALE_ID:
				{
					packet_kind = Zone_Packet_Kind_SetLocale;
					printf("[Zone] Handling SetLocale\n");

					break;
				}
				case ZONE_SYNCHRONIZATION_ID:
				{
					packet_kind = Zone_Packet_Kind_Synchronization;
					printf("[Zone] Handling Synchronization\n");

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

					Zone_Packet_ClientUpdate_MonitorTimeDrift result = { 0 };
					zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);
			

					Zone_Packet_ClientUpdate_MonitorTimeDrift time_drift =
					{
						.time_drift = (u32)timer,
					};
			
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift, &time_drift);

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
								.zone_name = "Z1",
								.hex_size = 100,
								.is_production_zone = 1,
							}
						}
					};
			
					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ContinentBattleInfo, &battle_info);

					break;
				}
				case ZONE_RESOURCEEVENTBASE_ID:
				{
					packet_kind = Zone_Packet_Kind_ResourceEventBase;
					printf("[Zone] Handling ResourceEventBase\n");

					Zone_Packet_ResourceEventBase rsrc_event_base =
					{
						.gametime = (u32)timer,
						.variabletype8_case =
							(struct set_character_resources_1_s[1]) {
							[0] =
							{
								.character_id_1 = session_state->character_id,
								.character_resources_1_count = 1,
								.character_resources_1 =
									(struct character_resources_1_s[1]) {
									[0] =
									{
										.resource_type_1 = 3,
									},
								},
							},
						},
					};

					zone_packet_send(0, server_state, session_state, &server_state->arena_per_tick, sizeof(rsrc_event_base), Zone_Packet_Kind_ResourceEventBase, &rsrc_event_base);

					break;
				}
				case ZONE_CLIENTUPDATE_UPDATEBATTLEYEREGISTRATION_ID:
				{
					packet_kind = Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration;
					printf("[Zone] Handling ClientUpdate.UpdateBattlEyeRegistration\n");

					// (doggo)keep empty, don't need this

					break;
				}

				break;
			}
		}
		case packet_channel_1:
		{	
			switch (packet_id)
			{
				break;
			}
		}
		case packet_channel_2:
		{
					u32 offset = 0;

					u16 flags = endian_read_u16_little(data + offset);
					offset += sizeof(u16);

					u32 sequence = endian_read_u32_little(data + offset);
					offset += sizeof(u32);

					/*
					(doggo) not sure if used but commented it out for now...

					u8 unk_u8		= endian_read_u8_little(data + offset);
					offset += sizeof(u8);
					*/

					Zone_Packet_PlayerUpdatePosition updt_pos =
					{
						.transient_id.value = 0x1337,
						.flag = flags,
						.sequence = sequence
					};

					if (flags & 1)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->stance = v.value;
					}

					if (flags & 2)
					{
						i32 position[3];
						int2b v;

						v = endian_read_int2b_little(data, offset);
						offset += v.length;

						position[0] = v.value / 100;

						v = endian_read_int2b_little(data, offset);
						offset += v.length;

						position[1] = v.value / 100;

						v = endian_read_int2b_little(data, offset);
						offset += v.length;

						position[2] = v.value / 100;

						session_state->position[0] = position[0];
						session_state->position[1] = position[1];
						session_state->position[2] = position[2];

					}

					if (flags & 0x20)
					{
						f32 v = endian_read_f32_little(data + offset);
						offset += sizeof(f32);

						session_state->orientation = v;
					}

					if (flags & 0x40)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->front_tilt = v.value;
					}

					if (flags & 0x80)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->side_tilt = v.value;
					}

					if (flags & 4)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->angle_change = v.value;
					}

					if (flags & 0x8)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->vertical_speed = v.value;
					}

					if (flags & 0x10)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->horizontal_speed = v.value;
					}

					if (flags & 0x100)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						v = endian_read_int2b_little(data, offset);
						offset += v.length;

						v = endian_read_int2b_little(data, offset);
						offset += v.length;
					}

					if (flags & 0x200) {
						euler_angle rotation_euler;

						int2b v = endian_read_int2b_little(data, offset);
						rotation_euler.pitch = v.value / 100;
						offset += v.length;

						v = endian_read_int2b_little(data, offset);
						rotation_euler.yaw = v.value / 100;
						offset += v.length;

						v = endian_read_int2b_little(data, offset);
						rotation_euler.roll = v.value / 100;
						offset += v.length;

						v = endian_read_int2b_little(data, offset);
						// rotation_euler.w = v.value / 100;
						offset += v.length;

						//vec4_i32 rotation = euler_to_quaternion(rotation_euler);
					}

					if (flags & 0x400)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;
				
						session_state->direction = v.value / 10;
					}

					if (flags & 0x800)
					{
						int2b v = endian_read_int2b_little(data, offset);
						offset += v.length;

						session_state->engine_rpm = v.value / 10;
					}

					if (test == FALSE)
						return;

					updt_pos.test = malloc(data_length);
					memcpy(updt_pos.test, data + 7, data_length - 7);
					updt_pos.test_length = 0;

					zone_packet_send(2, server_state, session_state, &server_state->arena_per_tick, KB(50), Zone_Packet_Kind_PlayerUpdatePosition, &updt_pos);

					return;
		}	
		case packet_channel_3:
		{
			switch (packet_id)
			{
				break;
			}
		}
		case packet_channel_4:
		{
			if (session_state->is_synced == FALSE)
			{
				session_state->is_synced = TRUE;

				packet_kind = Zone_Packet_Kind_Synchronization;
				printf("[Zone] Handling Synchronization\n");

				Zone_Packet_Synchronization sync_packet =
				{
					.server_time = timer,
					.server_time_2 = timer,
					.unk_time = timer + 2,
				};
			
			zone_packet_send(4, server_state, session_state, &server_state->arena_per_tick, sizeof(sync_packet), Zone_Packet_Kind_Synchronization, &sync_packet);
			}

			return;
		}
		case packet_channel_5:
		{
			switch (packet_id)
			{
				case ZONE_GETREWARDBUFFINFO_ID:
				{
					Zone_Packet_RewardBuffInfo buff_info =
					{
						.unk_float_1 = 1,
						.unk_float_2 = 2,
						.unk_float_3 = 3,
						.unk_float_4 = 4,
						.unk_float_5 = 5,
						.unk_float_6 = 6,
						.unk_float_7 = 7,
						.unk_float_8 = 8,
						.unk_float_9 = 9,
						.unk_float_10 = 10,
						.unk_float_11 = 11,
						.unk_float_12 = 12,
					};

					zone_packet_send(5, server_state, session_state, &server_state->arena_per_tick, sizeof(buff_info), Zone_Packet_Kind_RewardBuffInfo, &buff_info);
				}

				return;
			}
		}	
		case packet_channel_6:
		{
			switch (packet_id)
			{
				break;
			}
		}
		// (doggo) haven't seen packets on anything above gateway_channel_7, keep like this for now		
		case packet_channel_7:
		{
			switch (packet_id)
			{
				break;
			}
		}
		default:
		{
			packet_id_fail:
				packet_kind = Zone_Packet_Kind_Unhandled;
				
			printf("[!] Unhandled zone packet from:\n gateway channel: [%x],\n packet opcode: [0x%x],\n sub packet opcode: [0x%x],\n\n", channel, packet_id, sub_packet_id);
		}
	}
}