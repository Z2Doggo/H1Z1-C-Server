void login_packet_send(App_State *server_state,
					   Session_State *session_state,
					   Arena *arena,
					   u32 max_length,
					   b32 should_override_encryption,
					   Login_Packet_Kind packet_kind,
					   void *packet_ptr)
{
	u8 *appdata_buffer = arena_push_size(arena, max_length);
	u32 appdata_length = login_packet_pack(packet_kind, packet_ptr, appdata_buffer);

	output_stream_write(&session_state->output_stream,
						appdata_buffer,
						appdata_length,
						should_override_encryption,
						server_state,
						session_state);
}

void addDummyDataToCharacters(struct characters_s *character)
{
	character->payload->loadoutSlots_count = 1;
	character->payload->loadoutSlots = calloc(character->payload->loadoutSlots_count, sizeof(struct loadoutSlots_s));
	character->payload->loadoutSlots->unkByte1 = 1;
	character->payload->loadoutSlots->loadoutId = 3;
	character->payload->loadoutSlots->unkDword1 = 22;
}

void tunnelAppPacket(App_State *server, Session_State *session, u8 *data, u32 data_length)
{
	Login_Packet_Kind packet_kind = Login_Packet_Kind_TunnelAppPacketClientToServer;
	i32 offset = sizeof(u8);

	Login_Packet_TunnelAppPacketClientToServer packet = {0};
	login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);

	u32 name_status = 1; // default value is 1
	u32 char_name_length = packet.data_client->character_name_length;
	char *char_name_content = packet.data_client->character_name;

	if (char_name_length < 3 || char_name_length > 20)
	{
		name_status = 3; // invalid length
	}
	else
	{
		// check if character name contains only alphabets
		if (!isalpha((uchar)char_name_content[0]))
		{
			name_status = 3; // first character is not alphabetic
		}
		else
		{
			for (u32 i = 1; i < char_name_length; i++)
			{
				if (!isalpha((uchar)char_name_content[i]))
				{
					name_status = 3; // contains non-alphabetic character
					break;
				}
			}
		}
	}

	Login_Packet_TunnelAppPacketServerToClient *tunnelReply = calloc(1, sizeof(Login_Packet_TunnelAppPacketServerToClient));
	tunnelReply->server_id = 1;
	tunnelReply->data_server_length = 14;

	tunnelReply->data_server = calloc(1, sizeof(struct data_server_s) * tunnelReply->data_server_length);
	tunnelReply->data_server->tunnel_op_code = 0xa7;
	tunnelReply->data_server->sub_op_code = 0x02;
	tunnelReply->data_server->character_name = char_name_content;
	tunnelReply->data_server->character_name_length = char_name_length;
	tunnelReply->data_server->status = name_status;

	session->name.nameContent = char_name_content;
	session->name.nameLength = char_name_length;
	printf("Character name: %s, validation status: %u", session->name.nameContent, name_status);

	login_packet_send(server,
					  session,
					  &server->arena_per_tick,
					  KB(100),
					  false,
					  Login_Packet_Kind_TunnelAppPacketServerToClient,
					  tunnelReply);

	free(tunnelReply->data_server);
	free(tunnelReply);
}

void pGetHeadTypeData(Session_State *session, u32 head_type)
{
	switch (head_type)
	{
	// white male
	case 1:
		session->pGetPlayerActor.headType = 1;
		session->pGetPlayerActor.gender = 1;
		session->pGetPlayerActor.actorModelId = 9240;
		session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
		session->pGetPlayerActor.hairModelLength = (u32)strlen(session->pGetPlayerActor.hairModel);
		session->pGetPlayerActor.headActor = "SurvivorMale_Head_01.adr";
		session->pGetPlayerActor.headActorLength = (u32)strlen(session->pGetPlayerActor.headActor);
	// hispanic male
	case 2:
		session->pGetPlayerActor.headType = 2;
		session->pGetPlayerActor.gender = 1;
		session->pGetPlayerActor.actorModelId = 9240;
		session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
		session->pGetPlayerActor.hairModelLength = (u32)strlen(session->pGetPlayerActor.hairModel);
		session->pGetPlayerActor.headActor = "SurvivorMale_Head_02.adr";
		session->pGetPlayerActor.headActorLength = (u32)strlen(session->pGetPlayerActor.headActor);
	// black male
	case 5:
		session->pGetPlayerActor.headType = 5;
		session->pGetPlayerActor.gender = 1;
		session->pGetPlayerActor.actorModelId = 9240;
		session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
		session->pGetPlayerActor.hairModelLength = (u32)strlen(session->pGetPlayerActor.hairModel);
		session->pGetPlayerActor.headActor = "SurvivorMale_Head_03.adr";
		session->pGetPlayerActor.headActorLength = (u32)strlen(session->pGetPlayerActor.headActor);
	// asian male
	case 7:
		session->pGetPlayerActor.headType = 7;
		session->pGetPlayerActor.gender = 1;
		session->pGetPlayerActor.actorModelId = 9240;
		session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
		session->pGetPlayerActor.hairModelLength = (u32)strlen(session->pGetPlayerActor.hairModel);
		session->pGetPlayerActor.headActor = "SurvivorMale_Head_04.adr";
		session->pGetPlayerActor.headActorLength = (u32)strlen(session->pGetPlayerActor.headActor);
	default:
		NULL;
	}
}

Login_Packet_CharacterCreateReply
CharacterCreateRequest(App_State *app, Session_State *session)
{
	session->character_id = generateRandomGuid();
	Login_Packet_CharacterCreateReply *createReply = calloc(1, sizeof(Login_Packet_CharacterCreateReply));

	createReply->character_id = session->character_id;
	createReply->status = 1;

	session->createReply.status = createReply->status;

	login_packet_send(app, session, &app->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterCreateReply, createReply);
	return *createReply;
}

void CharacterSelectInfo(App_State *app, Session_State *session)
{
	Login_Packet_CharacterSelectInfoReply *reply = calloc(1, sizeof(Login_Packet_CharacterSelectInfoReply));

	reply->character_status = 1;
	reply->can_bypass_server_lock = true;
	reply->characters_count = 1;

	reply->characters = calloc(reply->characters_count, reply->characters_count * sizeof(struct characters_s));
	reply->characters->charId = session->character_id;
	reply->characters->serverId = session->selected_server_id;
	reply->characters->lastLoginDate = 0x0ull;
	if (session->createReply.status == 1)
	{
		reply->characters->status = 1;
	}

	reply->characters->payload = calloc(1, sizeof(struct payload_s));
	reply->characters->payload->name = session->name.nameContent;
	reply->characters->payload->name_length = session->name.nameLength;
	reply->characters->payload->actorModelId = session->pGetPlayerActor.actorModelId;
	reply->characters->payload->gender = session->pGetPlayerActor.gender;
	reply->characters->payload->headId = session->pGetPlayerActor.headType;
	addDummyDataToCharacters(reply->characters);

	login_packet_send(app, session, &app->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterSelectInfoReply, reply);

	free(reply->characters->payload->loadoutSlots);
	free(reply->characters->payload);
	free(reply->characters);
	free(reply);
}

void login_packet_handle(App_State *server, Session_State *session, u8 *data, u32 data_length)
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

		Login_Packet_LoginReply login_reply =
			{

				.is_logged_in = 1,
				.status = 1,
				.result_code = 1,
				.is_member = 1,
				.is_logged_in = 1,
				.namespace_name_length = 3,
				.namespace_name = "soe",
				.account_features_count = 1,
				.account_features =
					(struct account_features_s[1]){
						[0] =
							{
								.key = 2,
								.id = 2,
								.active = 1,
								.remaining_count = 2,
								.raw_data_length = 4,
								.raw_data = "test",
							},
					},
				.application_payload_length = 2,
				.application_payload = "US",
				.error_details_count = 1,
				.error_details =
					(struct error_details_s[1]){
						[0] =
							{
								.unknown_dword1 = 0,
								.name_length = 4,
								.name = "None",
								.value_length = 4,
								.value = "None",
							},
					},
				.ip_country_code_length = 2,
				.ip_country_code = "US",
			};

		login_packet_send(server, session, &server->arena_per_tick, KB(10), false, Login_Packet_Kind_LoginReply, &login_reply);

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

		Login_Packet_ServerListReply server_info_reply =
			{
				.servers_count = 1,
				(struct servers_s[1]){
					[0] =
						{
							.id = 1,
							.state = 2,
							.is_locked = false,
							.name_length = 4,
							.name = "KotK",
							.name_id = 193,
							.description_length = 4,
							.description = "test",
							.description_id = 1362,
							.req_feature_id = 0,
							.server_info_length = 153,
							.server_info = "<ServerInfo Region=\"CharacterCreate.RegionUs\" Subregion=\"UI.SubregionUS\" IsRecommended=\"1\" IsRecommendedVS=\"0\" IsRecommendedNC=\"0\" IsRecommendedTR=\"0\" />",
							.population_level = 0,
							.population_data_length = 207,
							.population_data = "<Population PctCap=\"0\" PingAdr=\"127.0.0.1:20043\" Rulesets=\"\" Mode=\"13\" IsLogin=\"1\" IsWL=\"0\" IsEvt=\"0\" PL=\"0\" DC=\"LVS\" PopLock=\"0\" GP=\"100\" BP=\"175\" MaxPop=\"4000\" Subregion=\"US\"><Fac IsList=\"1\"/></Population>",
							.is_access_allowed = true,
						},
				},
			};

		login_packet_send(server,
						  session,
						  &server->arena_per_tick,
						  KB(10),
						  false,
						  Login_Packet_Kind_ServerListReply,
						  &server_info_reply);
	}
	break;
	case LOGIN_CHARACTERDELETEREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterDeleteRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

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
		printf("Received %s\n", login_packet_names[packet_kind]);
		tunnelAppPacket(server, session, data, data_length);

		break;
	}
	case LOGIN_CHARACTERCREATEREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterCreateRequest;
		printf(MESSAGE_CONCAT_INFO("Received %s\n"), login_packet_names[packet_kind]);

		Login_Packet_CharacterCreateRequest character_create_request = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_create_request, &server->arena_per_tick);

		pGetHeadTypeData(session, character_create_request.char_payload->head_type);
		CharacterCreateRequest(server, session);

		break;
	}
	case LOGIN_CHARACTERSELECTINFOREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterSelectInfoRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

		CharacterSelectInfo(server, session);
		break;
	}
	break;
	case LOGIN_CHARACTERLOGINREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterLoginRequest;
		printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[packet_kind]);

		Login_Packet_CharacterLoginRequest character_login_request = {0};
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_login_request, &server->arena_per_tick);

		Login_Packet_CharacterLoginReply character_login_reply =
			{
				.character_id = session->character_id,
				.server_id = 1,
				.last_login = 0,
				.status = 1,
				.login_payload =
					(struct login_payload_s[1]){
						[0] =
							{
								.unk_byte_1 = 0,
								.unk_byte_2 = 0,
								.server_address_length = 15,
								.server_address = "127.0.0.1:20043",
								.server_ticket_length = 15,
								.server_ticket = "7y3Bh44sKWZCYZH",
								.encryption_key_length = 16,
								.encryption_key = (u8 *)"\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f",
								.soe_protocol_version = 3,
								.character_id = session->character_id,
								.unk_u64 = 0x0ull,
								.character_name_length = session->name.nameLength,
								.character_name = session->name.nameContent,
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
	}
	}
}