internal void login_packet_send(App_State* server_state,
                                Session_State* session_state,
                                Arena* arena,
                                u32 max_length,
                                b32 should_override_encryption,
                                Login_Packet_Kind packet_kind,
                                void* packet_ptr)
{
	u8* appdata_buffer = memory_arena_push_length(arena, max_length);
	u32 appdata_length = login_packet_pack(packet_kind, packet_ptr, appdata_buffer);

	if (session_state->connection_args.should_dump_login)
	{
		char dump_path[256] = { 0 };
		stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_S_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
		server_state->platform_api->buffer_write_to_file(dump_path, appdata_buffer, appdata_length);
	}

	output_stream_write(&session_state->output_stream,
	                    appdata_buffer,
	                    appdata_length,
	                    should_override_encryption,
	                    server_state,
	                    session_state);
}

internal void login_packet_handle(App_State* server, Session_State* session, u8* data, u32 data_length)
{
	Login_Packet_Kind packet_kind;

	printf("\n");
	u8 packet_id = *data;
	i32 offset = sizeof(u8);

	switch (packet_id)
	{
		case LOGIN_LOGINREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_LoginRequest;
			printf("[*] Handling %s...\n", login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			// TODO(rhett): I don't care about the contents of the request packet right now
			Login_Packet_LoginRequest packet = { 0 };
			login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);

			// NOTE(rhett): Load raw business envs
			u8* business_envs_buffer = memory_arena_push_length(&server->arena_per_tick,
			                                                 KB(10));
			u32 business_envs_length = server->platform_api->buffer_load_from_file("..\\resources\\businessenvironments.dat",
			                                            													 business_envs_buffer,
			                                            													 KB(10));
			memory_arena_rewind(&server->arena_per_tick, KB(10) - business_envs_length);

			Login_Packet_LoginReply login_reply =
			{
				.is_logged_in = TRUE,
				.status = 1,
				.is_member = FALSE,
				.is_internal = FALSE,
				.namespace_length = 0,
				.payload_length = business_envs_length,
				.payload = business_envs_buffer,
			};

			login_packet_send(server, session, &server->arena_per_tick, KB(10), FALSE, Login_Packet_Kind_LoginReply, &login_reply);
			
			break;
		}
		case LOGIN_CHARACTERSELECTINFOREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_CharacterSelectInfoRequest;
			printf("[*] Recieved %s\n", login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			Login_Packet_CharacterSelectInfoReply character_info_reply =
			{
				.status = 1,
				.can_bypass_lock = 0,

				.characters_count = 1,
				.characters =
					(struct characters_s[1]){
					[0] =
					{
						.character_id = 0x44495F4152414843,
						.server_id = 101,
						.unk_u64_2 = 0,
						.status = 1,
						//.server_id = 101,
						//.status = 1,

						.payload =
							(struct payload_s[1]){
							[0] =
							{
								.name_length = 4,
								.name = "Yote",
								.empire_id = 1,
								.battle_rank = 100,
								.next_battle_rank_percent = 0,
								.head_id = 5,
								.model_id = 174,
								.gender = 2,
								.profile_id = 22,
								.unk_u32 = 1,

								.loadout_id = 20,
								.unk_u32_2 = 22,
								.unk_u8 = 1,

								.unk_u32_3 = 0,
								.unk_u32_4 = 0,
								.loadout_name_length = 0,
								.loadout_name = "",

								.tint_item_id = 0,
								.unk_u32_5 = 0,
								.decal_item_id = 0,

								.loadout_slots_count = 0,
								.loadout_slots =
									(struct loadout_slots_s[1]) {
									[0] =
									{
										.slot_id = 1,
										.index = 1,
										.item_line_id = 80,
										.flags = 0,
										
										.attachments_count = 0,
										.attachments =
											(struct attachments_s[4]) {
												[0] =
											{
												.id = 2400,
											},
												[1] =
											{
												.id = 45081,
											},
												[2] =
											{
												.id = 46156,
											},
												[3] =
											{
												.id = 46348,
											},
										},

										.attachment_classes_count = 0,
										.attachment_classes =
											(struct attachment_classes_s[4]) {
											[0] =
											{
												.class_id = 1,
												.attachment_id = 2400,
											},
												[1] =
											{
												.class_id = 5,
												.attachment_id = 45081,
											},
												[2] =
											{
												.class_id = 3,
												.attachment_id = 46156,
											},
												[3] =
											{
												.class_id = 2,
												.attachment_id = 46348,
											},
										},

										.tint_item_id = 0,
										.item_slot = 7,
									},
								},

								.item_definitions_count = 1,
								.item_definitions =
									(struct item_definitions_s[1]) {
									[0] =
									{
										.item_id = 80,
										.item_id_2 = 80,
										.flags = 0x0,
										.flags_2 = 0x0,
										.flags_3 = 0x0,
										.name_id = 1297664,
										.description_id = 1298432,
										.unk_u32 = 256,
										.icon_id = 722944,
										.unk_u32_2 = 0,
										.hud_image_set_id = 0,
										.unk_u32_3 = 0,
										.unk_u32_4 = 0,
										.cost = 0,
										.item_class = 20480,
										.unk_u32_5 = 0,
										.item_slot = 1792,
										.slot_override_key = 0,
										.model_name_length = 20,
										.model_name = "Weapon_VS_LMG001.adr",
										.unk_string_length = 0,
										.unk_u8 = 0,
										.item_type = 20,
										.category_id = 6,
										.unk_u32_6 = 0,
										.unk_u32_7 = 0,
										.unk_u32_8 = 0,
										.unk_u32_9 = 1,
										.unk_u32_10 = 0,
										.activatable_ability_id = 0,
										.passive_ability_id = 0,
										.unk_u32_11 = 0,
										.max_stack_size = 1,
										.tint_name_length = 0,
										.unk_u32_12 = 0,
										.unk_u32_13 = 0,
										.unk_u32_14 = 0,
										.unk_u32_15 = 0,
										.ui_model_camera = 19,
										.equip_count_max = 0,
										.currency_type = 0,
										.unk_u32_16 = 9,
										.client_item_type = 26,
										.skill_set_id = 111,
										.overlay_texture_length = 0,
										.decal_slot_length = 0,
										.unk_u32_17 = 0,
										.trial_duration_sec = 1800,
										.trial_exclusion_sec = 2592000,
										.client_use_requirement_id = 118,
										.override_appearance_length = 0,
										.unk_u32_18 = 0,
									},
								},

								.attachment_definitions_count = 0,

								.last_use_date = 0x0000000053da0a5b,
							},
						},
					},
				},
			};

			login_packet_send(server,
			                  session,
			                  &server->arena_per_tick,
			                  KB(500),
			                  FALSE,
			                  Login_Packet_Kind_CharacterSelectInfoReply,
			                  &character_info_reply);
		} break;

		case LOGIN_SERVERLISTREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_ServerListRequest;
			printf("[*] Recieved %s\n", login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			Login_Packet_ServerListReply server_info_reply =
			{
				.servers_count = 1,
				(struct servers_s[1])
				{
					[0] =
					{
						.server_id = 101,
						.state = 0,
						.is_locked = FALSE,
						.name_length = 5,
						.name = "Local",
						.name_id = 7699,
						.description_length = 12,
						.description = "Local Server",
						.description_id = 7699,
						.req_feature_id = 0,
						.server_info_length = 103,
						.server_info = "<ServerInfo Region=\"CharacterCreate.RegionUs\" Subregion=\"UI.SubregionUSEast\" IsRecommended=\"1\" />",
						.population_level = 1,
						.population_data_length = 417,
						.population_data = "<Population ServerCapacity=\"0\" PingAddress=\"127.0.0.1:60000\"><factionlist IsList=\"1\"><faction Id=\"1\" Percent=\"0\" TargetPopPct=\"0\" RewardBuff=\"52\" XPBuff=\"52\" PercentAvg=\"0\"/><faction Id=\"2\" Percent=\"0\" TargetPopPct=\"1\" RewardBuff=\"0\" XPBuff=\"0\" PercentAvg=\"0\"/><faction Id=\"3\" Percent=\"0\" TargetPopPct=\"1\" RewardBuff=\"0\" XPBuff=\"0\" PercentAvg=\"1\"/></factionlist></Population>",
						.is_access_allowed = TRUE,
					},
				},
			};

			login_packet_send(server,
			                  session,
			                  &server->arena_per_tick,
			                  KB(10),
			                  FALSE,
			                  Login_Packet_Kind_ServerListReply,
			                  &server_info_reply);

		} break;

		case LOGIN_CHARACTERLOGINREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_CharacterLoginRequest;
			printf("[*] Recieved %s\n", login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			Login_Packet_CharacterLoginRequest character_login_request = { 0 };
			login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_login_request, &server->arena_per_tick);

			Login_Packet_CharacterLoginReply character_login_reply =
			{
				.character_id = character_login_request.character_id,
				.server_id = character_login_request.server_id,
				.status = 1,
				.login_payload =
					(struct login_payload_s[1]) {
					[0] =
					{
						.server_address_length = 15,
						.server_address = "127.0.0.1:60000",
						.server_ticket_length = 15,
						.server_ticket = "7y3Bh44sKWZCYZH",
						.encryption_key_length = 16,
						.encryption_key = "\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f",
						.character_id = character_login_request.character_id,
						.station_name_length = 10,
						// TODO(rhett): not sure if the 0 is important?
						.station_name = "yote0rhett",
						.character_name_length = 4,
						.character_name = "Yote",
					},
				},
			};

			login_packet_send(server,
			                  session,
			                  &server->arena_per_tick,
			                  KB(1),
			                  FALSE,
			                  Login_Packet_Kind_CharacterLoginReply,
			                  &character_login_reply);

		} break;

		default:
		{
			packet_kind = Login_Packet_Kind_Unhandled;
			printf("[!] Unhandled login packet 0x%02x\n", packet_id);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}
		}
	}


}
