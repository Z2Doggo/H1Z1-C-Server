internal void login_packet_send(App_State* server_state,
                                Session_State* session_state,
                                Arena* arena,
                                u32 max_length,
                                b32 should_override_encryption,
                                Login_Packet_Kind packet_kind,
                                void* packet_ptr)
{
	u8* appdata_buffer = arena_push_size(arena, max_length);
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

	generate_guid(session->character_id);

	printf("\n");
	u8 packet_id = *data;
	i32 offset = sizeof(u8);

	switch (packet_id)
	{
		case LOGIN_LOGINREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_LoginRequest;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			// TODO(rhett): I don't care about the contents of the request packet right now
			Login_Packet_LoginRequest packet = { 0 };
			login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);	
			
			Login_Packet_LoginReply login_reply =
			{

				.is_logged_in 			= 1,
				.status 				= 1,
				.result_code 			= 1,
				.is_member 				= 1,
				.is_internal 			= 1,
				.namespace_name_length 	= 3,
				.namespace_name 		= "soe",
				.account_features_count	= 1,
				.account_features =
					(struct account_features_s[1])
				{
					[0] =
					{
						.key 				= 2,
						.id 				= 2,
						.active 			= 1,
						.remaining_count 	= 2,
						.raw_data_length 	= 4,
						.raw_data 			= "test",
					},
				},
				.application_payload_length = 2,
				.application_payload 		= "EU",
				.error_details_count 		= 1,
				.error_details =
					(struct error_details_s[1])
				{
					[0] =
					{
						.unknown_dword1 = 0,
						.name_length 	= 4,
						.name 			= "None",
						.value_length 	= 4,
						.value 			= "None",
					},
				},
				.ip_country_code_length = 2,
				.ip_country_code 		= "EU",
			};

			login_packet_send(server, session, &server->arena_per_tick, KB(10), FALSE, Login_Packet_Kind_LoginReply, &login_reply);
			
			break;
		}
		case LOGIN_LOGOUT_ID:
		{
			packet_kind = Login_Packet_Kind_Logout;
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

			break;
		}
		case LOGIN_FORCEDISCONNECT_ID:
		{
			packet_kind = Login_Packet_Kind_ForceDisconnect;
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

			break;
		}
		case LOGIN_CHARACTERCREATEREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_CharacterCreateRequest;
			printf(MESSAGE_CONCAT_INFO("Received %s\n"), login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			Login_Packet_CharacterCreateRequest character_create_request = { 0 };
			login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_create_request, &server->arena_per_tick);

			Login_Packet_CharacterCreateReply character_create_reply =
			{
				.status = 1,
				.character_id = session->character_id,
			};

			login_packet_send(server, session, &server->arena_per_tick, KB(1), FALSE, Login_Packet_Kind_CharacterCreateReply, &character_create_reply);

			break;
		}
		case LOGIN_CHARACTERSELECTINFOREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_CharacterSelectInfoRequest;
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			Login_Packet_CharacterSelectInfoReply character_info_reply =		
			{
				.character_status = 1,
				.can_bypass_server_lock = 1,
			};

			login_packet_send(server,
			                  session,
			                  &server->arena_per_tick,
			                  KB(500),
			                  FALSE,
			                  Login_Packet_Kind_CharacterSelectInfoReply,
			                  &character_info_reply);
		};

		case LOGIN_SERVERLISTREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_ServerListRequest;
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

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
						.id 						= 1,
						.state 						= 2,
						.is_locked 					= FALSE,
						.name_length 				= 5,
						.name 						= "SoloServer",
						.name_id 					= 195,
						.description_length 		= 10,
						.description 				= "yeah",
						.description_id 			= 1362,
						.server_info_length 		= 165,
						.server_info 				= "<ServerInfo Region=\"CharacterCreate.RegionEu\" Subregion=\"UI.SubregionEu\" IsRecommended=\"1\" IsRecommendedVS=\"0\" IsRecommendedNC=\"0\" IsRecommendedTR=\"0\" />",
						.population_level			= 0,
						.population_data_length 	= 436,
						.population_data 			= "<Population ServerCapacity=\"0\" PingAdr=\"127.0.0.1:1117\" Rulesets=\"Permadeath\"><factionlist IsList=\"1\"><faction Id=\"1\" Percent=\"0\" TargetPopPct=\"0\" RewardBuff=\"52\" XPBuff=\"52\" PercentAvg=\"0\"/><faction Id=\"2\" Percent=\"0\" TargetPopPct=\"1\" RewardBuff=\"0\" XPBuff=\"0\" PercentAvg=\"0\"/><faction Id=\"3\" Percent=\"0\" TargetPopPct=\"1\" RewardBuff=\"0\" XPBuff=\"0\" PercentAvg=\"1\"/></factionlist></Population>",
						.is_access_allowed 			= TRUE,
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
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

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
				.character_id = session->character_id,
				.server_id = session->selected_server_id,
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
						.encryption_key = (u8*)"\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f",
						.soe_protocol_version	= 3,
						.character_id = session->character_id,
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

		case LOGIN_CHARACTERDELETEREQUEST_ID:
		{
			packet_kind = Login_Packet_Kind_CharacterDeleteRequest;
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);
			
			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}

			Login_Packet_CharacterDeleteRequest character_delete_request = { 0 };
			login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_delete_request, &server->arena_per_tick);

			Login_Packet_CharacterDeleteReply character_delete_reply =
			{
				.character_id = session->character_id,
				.status = 1,
			};

			login_packet_send(server, session, &server->arena_per_tick, KB(10), FALSE, Login_Packet_Kind_CharacterDeleteReply, &character_delete_reply);

			break;
		}
		case LOGIN_TUNNELAPPPACKETCLIENTTOSERVER_ID:
		{
			packet_kind = Login_Packet_Kind_TunnelAppPacketClientToServer;
			printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

			Login_Packet_TunnelAppPacketClientToServer packet = { 0 };
			login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);
			
			u32 packet_status = 1; // default status is 1

			// check if character name has less than 4 or more than 20 letters
			if (packet.data_client->character_name_length < 4 ||
				packet.data_client->character_name_length > 20) {
				packet_status = 3; // invalid length
			} else {
				// check if character name contains only alphabets
				if (!isalpha(packet.data_client->character_name[0])) {
					packet_status = 3; // first character is not alphabetic
				} else {
					for (int i = 1; i < packet.data_client->character_name_length; i++) {
						if (!isalpha(packet.data_client->character_name[i])) {
							packet_status = 3; // contains non-alphabetic character
							break;
						}
					}
				}
			}

			printf("char name: %d", packet.data_client->character_name_length);
			
			Login_Packet_TunnelAppPacketServerToClient tunnel_app_packet_server_to_client =
			{
				.server_id			= session->selected_server_id,
				.data_server		=
					(struct data_server_s[1]){
					[0] =
					{
						.tunnel_op_code			= 0xa7,
						.sub_op_code			= 0x02,
						.character_name_length	= packet.data_client->character_name_length,
						.character_name			= packet.data_client->character_name,
						.status					= packet_status,
					},
				},
				.data_server_length	= 14 + packet.data_client->character_name_length,
			};

			login_packet_send(server, session, &server->arena_per_tick, KB(100), FALSE, Login_Packet_Kind_TunnelAppPacketServerToClient, &tunnel_app_packet_server_to_client);

			break;
		}
		default:
		{
			packet_kind = Login_Packet_Kind_Unhandled;
			printf(MESSAGE_CONCAT_WARN("Unhandled login packet 0x%02x\n"), packet_id);

			if (session->connection_args.should_dump_login)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
				server->platform_api->buffer_write_to_file(dump_path, data, data_length);
			}
		}
	}


}
