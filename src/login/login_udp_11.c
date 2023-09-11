internal void login_packet_send(App_State *server_state,
								Session_State *session_state,
								Arena *arena,
								u32 max_length,
								b32 should_override_encryption,
								Login_Packet_Kind packet_kind,
								void *packet_ptr)
{
	u8 *appdata_buffer = arena_push_size(arena, max_length);
	u32 appdata_length = login_packet_pack(packet_kind, packet_ptr, appdata_buffer);

	if (session_state->connection_args.should_dump_login)
	{
		char dump_path[256] = {0};
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

internal void login_packet_handle(App_State *server, Session_State *session, u8 *data, u32 data_length)
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
		printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), login_packet_names[packet_kind]);

		// TODO(rhett): I don't care about the contents of the request packet right now
		Login_Packet_LoginRequest packet = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);

		LoginReply(server, session);
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
	case LOGIN_SERVERLISTREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_ServerListRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

		if (session->connection_args.should_dump_login)
		{
			char dump_path[256] = {0};
			stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
			server->platform_api->buffer_write_to_file(dump_path, data, data_length);
		}

		ServerListReply(server, session);
	}
	break;
	case LOGIN_CHARACTERDELETEREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterDeleteRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

		if (session->connection_args.should_dump_login)
		{
			char dump_path[256] = {0};
			stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
			server->platform_api->buffer_write_to_file(dump_path, data, data_length);
		}

		Login_Packet_CharacterDeleteRequest character_delete_request = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_delete_request, &server->arena_per_tick);

		Login_Packet_CharacterDeleteReply character_delete_reply =
			{
				.character_id = session->character_id,
				.status = 1,
			};

		login_packet_send(server, session, &server->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterDeleteReply, &character_delete_reply);

		break;
	}
	case LOGIN_TUNNELAPPPACKETCLIENTTOSERVER_ID:
	{
		packet_kind = Login_Packet_Kind_TunnelAppPacketClientToServer;
		printf(MESSAGE_CONCAT_INFO("Received %s\n"), login_packet_names[packet_kind]);

		Login_Packet_TunnelAppPacketClientToServer packet = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);

		u32 packet_status = 1; // default status is 1

		u32 char_name_length = packet.data_client->character_name_length;
		char *char_name_content = packet.data_client->character_name;

		characterName name;
		name.nameLength = char_name_length;
		name.nameContent = char_name_content;

		if (name.nameLength < 3 || name.nameLength > 20)
		{
			packet_status = 3; // invalid length
		}
		else
		{
			// check if character name contains only alphabets
			if (!isalpha(name.nameContent[0]))
			{
				packet_status = 3; // first character is not alphabetic
			}
			else
			{
				for (u32 i = 1; i < name.nameLength; i++)
				{
					if (!isalpha(name.nameContent[i]))
					{
						packet_status = 3; // contains non-alphabetic character
						break;
					}
				}
			}
		}

		Login_Packet_TunnelAppPacketServerToClient tunnel_app_packet_server_to_client =
			{
				.server_id = session->selected_server_id,
				.data_server =
					(struct data_server_s[1]){
						[0] =
							{
								.tunnel_op_code = 0xa7,
								.sub_op_code = 0x02,
								.character_name_length = name.nameLength,
								.character_name = name.nameContent,
								.status = packet_status,
							},
					},
				.data_server_length = 14,
			};

		login_packet_send(server, session, &server->arena_per_tick, KB(100), false, Login_Packet_Kind_TunnelAppPacketServerToClient, &tunnel_app_packet_server_to_client);
		break;
	}
	case LOGIN_CHARACTERCREATEREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterCreateRequest;
		printf(MESSAGE_CONCAT_INFO("Received %s\n"), login_packet_names[packet_kind]);

		if (session->connection_args.should_dump_login)
		{
			char dump_path[256] = {0};
			stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
			server->platform_api->buffer_write_to_file(dump_path, data, data_length);
		}

		Login_Packet_CharacterCreateRequest character_create_request = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_create_request, &server->arena_per_tick);

		Login_Packet_CharacterCreateReply character_create_reply =
			{
				.status = 1,
				.character_id = session->character_id,
			};

		login_packet_send(server, session, &server->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterCreateReply, &character_create_reply);
		printf("fuck this packet!\n");
		break;
	}
	case LOGIN_CHARACTERSELECTINFOREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterSelectInfoRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

		if (session->connection_args.should_dump_login)
		{
			char dump_path[256] = {0};
			stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
			server->platform_api->buffer_write_to_file(dump_path, data, data_length);
		}

		CharacterSelectInfoReply(server, session);
		break;
	}
	break;
	case LOGIN_CHARACTERLOGINREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterLoginRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

		if (session->connection_args.should_dump_login)
		{
			char dump_path[256] = {0};
			stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
			server->platform_api->buffer_write_to_file(dump_path, data, data_length);
		}

		Login_Packet_CharacterLoginRequest character_login_request = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_login_request, &server->arena_per_tick);

		Login_Packet_CharacterLoginReply character_login_reply =
			{
				.character_id = 0x0ull,
				.server_id = 0,
				.last_login = 0,
				.status = 1,
				.login_payload =
					(struct login_payload_s[1]){
						[0] =
							{
								.unk_byte_1 = 0,
								.unk_byte_2 = 0,
								.server_address_length = 15,
								.server_address = "127.0.0.1:60000",
								.server_ticket_length = 15,
								.server_ticket = "7y3Bh44sKWZCYZH",
								.encryption_key_length = 16,
								.encryption_key = (u8 *)"\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f",
								.soe_protocol_version = 3,
								.character_id = session->character_id,
								.unk_u64 = 0x0ull,
								.character_name_length = 4,
								.character_name = "test",
							},
					},
			};

		login_packet_send(server,
						  session,
						  &server->arena_per_tick,
						  KB(10),
						  false,
						  Login_Packet_Kind_CharacterLoginReply,
						  &character_login_reply);
	}
	break;
	default:
	{
		packet_kind = Login_Packet_Kind_Unhandled;
		printf(MESSAGE_CONCAT_WARN("Unhandled login packet 0x%02x\n"), packet_id);

		if (session->connection_args.should_dump_login)
		{
			char dump_path[256] = {0};
			stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_login_%s.bin", global_tick_count, global_packet_dump_count++, login_packet_names[packet_kind]);
			server->platform_api->buffer_write_to_file(dump_path, data, data_length);
		}
	}
	}
}
