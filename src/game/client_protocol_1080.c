internal void zone_packet_send(
	Server_State* server_state,
	Session_State* session_state,
	Memory_Arena* arena,
	u32 max_length,
	Zone_Packet_Kind packet_kind,
	void* packet_ptr
)
{
	u8* base_buffer = memory_arena_push_length(arena, max_length);
	u8* packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
	u32 packed_length = zone_packet_pack(packet_kind, packet_ptr, packed_buffer);
	u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;

	memory_arena_rewind(arena, max_length - total_length);

	// TODO(rhett): still only one client for now
	gateway_tunnel_data_send(server_state, session_state, base_buffer, total_length);
}

internal void zone_packet_raw_file_send(
	Server_State* server_state,
	Session_State* session_state,
	Memory_Arena* arena,
	u32 max_length,
	char* path
)
{
	u8* base_buffer = memory_arena_push_length(arena, max_length);
	u8* packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
	u32 packed_length = server_state->platform_api->buffer_load_from_file(path, base_buffer + TUNNEL_DATA_HEADER_LENGTH, max_length);
	u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;

	memory_arena_rewind(arena, max_length - total_length);

	// TODO(rhett): still only one client for now
	gateway_tunnel_data_send(server_state, session_state, base_buffer, total_length);
}

internal void zone_packet_handle(
	Server_State* server_state,
	Session_State* session_state,
	u8* data,
	u32 data_length
)
{
	Zone_Packet_Kind packet_kind;

	if (data_length == 0)
	{
		printf("[Zone] Empty zone packet\n");
		return;
	}

	//  todo: Cache the zone_registered_ids array: Instead of accessing zone_registered_ids
	// multiple times in each loop, you could cache a pointer to it outside the loops.
	// This would reduce the number of memory accesses and improve performance.

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

	packet_id = *data;
	goto packet_id_fail;

	packet_id_switch:
	switch (packet_id)
	{
		case ZONE_CLIENTISREADY_ID:
		{
			packet_kind = Zone_Packet_Kind_ClientIsReady;
			printf("[Zone] Handling ClientIsReady\n");

			Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preload_done =
			{
				.is_done = TRUE,
			};

			zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(30), Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, &preload_done);
			zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, 	0);
			// todo: send DtoObjectInitialData for trees
			zone_packet_send(server_state,session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ZoneDoneSendingInitialData, 						0);
			
			__time64_t timer;
			_time64(&timer);

			Zone_Packet_Character_CharacterStateDelta character_state_delta =
			{
				.guid_1 	= session_state->character_id,
				.game_time 	= timer,
			};

			zone_packet_send(server_state,session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_CharacterStateDelta, &character_state_delta);

			break;
		}
		case ZONE_CLIENTFINISHEDLOADING_ID:
		{
			packet_kind = Zone_Packet_Kind_ClientFinishedLoading;
			
			if (session_state->finished_loading == FALSE)
			{
				session_state->finished_loading = TRUE;

				Zone_Packet_ClientUpdate_TextAlert text_alert =
				{
					.message_length = 20,
					.message = "c server running boy",
				};

				zone_packet_send(
					server_state,
					session_state,
					&server_state->arena_per_tick,
					KB(10),
					Zone_Packet_Kind_ClientUpdate_TextAlert, &text_alert
				);

				Zone_Packet_Character_WeaponStance weapon_stance =
				{
					.character_id = session_state->character_id,
					.stance = 1,
				};

				zone_packet_send(
					server_state,
					session_state,
					&server_state->arena_per_tick,
					KB(10),
					Zone_Packet_Kind_Character_WeaponStance, &weapon_stance
				);

				Zone_Packet_EquipmentSetCharacterEquipment set_character_equipment =
				{
					.profile_id = 5,
					.character_id = session_state->character_id,
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
							.equipment_slot_id_2 = 0,
							.guid = 0,
							.tint_alias_length = 7,
							.tint_alias = "Default",
							.decal_alias_length = 1,
							.decal_alias = "#",
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
				
				zone_packet_send(
					server_state,
					session_state,
					&server_state->arena_per_tick,
					KB(10),
					Zone_Packet_Kind_EquipmentSetCharacterEquipment, &set_character_equipment
				);
			}

			break;
		}
		case ZONE_CLIENTLOGOUT_ID:
		{
			packet_kind = Zone_Packet_Kind_ClientLogout;
			printf("[Zone] Handling ClientLogout\n");
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

			__time64_t timer;
			_time64(&timer);
			Zone_Packet_GameTimeSync packet =
			{
				.time = timer,
				.cycle_speed = 12.0f,
				.unk_bool = FALSE,
			};

			zone_packet_send(server_state,session_state, &server_state->arena_per_tick, 10, Zone_Packet_Kind_GameTimeSync, &packet);

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
		case ZONE_KEEPALIVE_ID:
		{
			packet_kind = Zone_Packet_Kind_KeepAlive;
			printf("[Zone] Handling KeepAlive\n");

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

			// Zone_Packet_ClientUpdate_MonitorTimeDrift result = { 0 };
			// zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

			// printf("	-- %d\n", result.time_drift);
			
			break;
		}

		case ZONE_GETCONTINENTBATTLEINFO_ID:
		{
			packet_kind = Zone_Packet_Kind_GetContinentBattleInfo;
			printf("[Zone] Handling GetContinentBattleInfo\n");

			//Zone_Packet_GetContinentBattleInfo result = { 0 };
			//zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

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
			
			zone_packet_send(server_state, session_state, &server_state->arena_per_tick, 10, Zone_Packet_Kind_ContinentBattleInfo, &battle_info);

			break;
		}

		case ZONE_CLIENTUPDATE_UPDATEBATTLEYEREGISTRATION_ID:
		{
			packet_kind = Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration;
			printf("[Zone] Handling ClientUpdate.UpdateBattlEyeRegistration\n");
			
			break;
		}

		default:
		{
			packet_id_fail:
				packet_kind = Zone_Packet_Kind_Unhandled;
				
			printf("[!] Unhandled zone packet 0x%x\n", packet_id);

		}
	}
}