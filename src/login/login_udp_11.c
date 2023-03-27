internal void login_packet_send(
	Server_State* server_state,
    Session_State* session_state,
    Memory_Arena* arena,
    u32 max_length,
    b32 should_override_encryption,
    Login_Packet_Kind packet_kind,
    void* packet_ptr
)
{
	u8* appdata_buffer = memory_arena_push_length(arena, max_length);
	u32 appdata_length = login_packet_pack(packet_kind, packet_ptr, appdata_buffer);

	output_stream_write(
		&session_state->output_stream,
		appdata_buffer,
		appdata_length,
		should_override_encryption,
		server_state,
		session_state
	);
}

internal void login_packet_handle(Server_State* server, Session_State* session, u8* data, u32 data_length)
{
	Login_Packet_Kind packet_kind;

	u8 packet_id = *data;
	i32 offset = sizeof(u8);

	switch (packet_id)
	{
	case LOGIN_LOGINREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_LoginRequest;
		printf("[LoginServer] Handling LoginRequest\n");

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
		printf("[LoginServer] Handling Logout\n");

		break;
	}
	case LOGIN_FORCEDISCONNECT_ID:
	{
		packet_kind = Login_Packet_Kind_ForceDisconnect;
		printf("[LoginServer] Handling ForceDisconnect\n");

		break;
	}
	case LOGIN_CHARACTERCREATEREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterCreateRequest;
		printf("[LoginServer] Handling CharacterCreateRequest\n");

		Login_Packet_CharacterCreateRequest packet = { 0 };
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);
		
		printf("[LoginServer] 1\n");

		//! todo: add generate id (need fix!)
		session->character_id = 0x1337;

		printf("[LoginServer] generated id: 0x%x\n", session->character_id);

		Login_Packet_CharacterCreateReply character_create_reply =
		{
			//todo(chris): reverse status according to character creation
			.status			= 1,
			.character_id	= session->character_id,
		};

		login_packet_send(server, session, &server->arena_per_tick, KB(1), FALSE, Login_Packet_Kind_CharacterCreateReply, &character_create_reply);

		break;
	}
	case LOGIN_CHARACTERLOGINREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterLoginRequest;
		printf("[LoginServer] CharacterLoginRequest\n");

		Login_Packet_CharacterLoginRequest character_login_request = { 0 };
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &character_login_request, &server->arena_per_tick);

		Login_Packet_CharacterLoginReply character_login_reply =
		{
			.character_id		= character_login_request.character_id,
			.server_id			= character_login_request.server_id,
			.status				= 1,
			.login_payload =
				(struct login_payload_s[1]) {
				[0] =
				{
					.server_address_length	= 14,
					.server_address			= "127.0.0.1:1117",
					.server_ticket_length	= 1,
					.server_ticket			= "0",
					.encryption_key_length	= 16,
					.encryption_key			= "\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f",
					.soe_protocol_version	= 3,
					.character_id			= character_login_request.character_id,
				},
			},
		};
		
		login_packet_send(server, session, &server->arena_per_tick, KB(1), FALSE, Login_Packet_Kind_CharacterLoginReply, &character_login_reply);

		break;
	}
	case LOGIN_CHARACTERDELETEREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterDeleteRequest;
		printf("[LoginServer] CharacterDeleteRequest\n");

		Login_Packet_CharacterDeleteRequest packet = { 0 };
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);

		if (strcmp(session->character_id, packet.character_id) != 0)
		{
			// ! report malicious request 
			printf("	[!] character_id != session, user reported\n");

			break;
		}

		Login_Packet_CharacterDeleteReply character_delete_reply =
		{
			.character_id 	= session->character_id,
			.status 		= 1, // todo: reverse the status enum (0 = error, 1 = success)
		};
		
		login_packet_send(server, session, &server->arena_per_tick, KB(10), FALSE, Login_Packet_Kind_CharacterDeleteReply, &character_delete_reply);

		break;
	}
	case LOGIN_TUNNELAPPPACKETCLIENTTOSERVER_ID:
	{
		packet_kind = Login_Packet_Kind_TunnelAppPacketClientToServer;
		printf("[LoginServer] Handling TunnelAppPacketClientToServer\n");

		Login_Packet_TunnelAppPacketClientToServer packet = { 0 };
		login_packet_unpack(data + offset, data_length - offset, packet_kind, &packet, &server->arena_per_tick);

		u32 packet_status = 1;
		
		printf("char name: %d", packet.data_client->character_name_length);

		// session->character_name = strings_cstring_to_string(packet.data_client->character_name);

		// // * check name length (3min/20max)
		// if (session->character_name.length > 20 || session->character_name.length < 3)
		// 	packet_status = 3 ; // todo: use enum (invalid)

		// // * check if the name contains only letters
		// if (!contains_only_letters(session->character_name.content))
		// 	packet_status = 3 ; // todo: use enum (invalid)

		session->selected_server_id = packet.server_id;
		Login_Packet_TunnelAppPacketServerToClient tunnel_app_packet_server_to_client =
		{
			.server_id			= session->selected_server_id,
			.data_server		=
			(struct data_server_s[1]){
				[0] =
				{
					.tunnel_op_code			= 0xa7,
					.sub_op_code			= 0x02,
					.character_name_length	= 5,
					.character_name			= "Chris",
					.status					= packet_status,
				},
			},
			.data_server_length	= 14 + 5,
		};
		
		login_packet_send(server, session, &server->arena_per_tick, KB(100), FALSE, Login_Packet_Kind_TunnelAppPacketServerToClient, &tunnel_app_packet_server_to_client);

		break;
	}
	case LOGIN_CHARACTERSELECTINFOREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_CharacterSelectInfoRequest;
		printf("[LoginServer] Received CharacterSelectInfoRequest\n");

		Login_Packet_CharacterSelectInfoReply character_info_reply =
		{
			.character_status = 1,
			.can_bypass_server_lock = 1,
		};

		login_packet_send(server, session, &server->arena_per_tick, KB(500), FALSE, Login_Packet_Kind_CharacterSelectInfoReply, &character_info_reply);

		break;
	}
	case LOGIN_SERVERLISTREQUEST_ID:
	{
		packet_kind = Login_Packet_Kind_ServerListRequest;
		printf("[LoginServer] Received ServerListRequest\n");
		Login_Packet_ServerListReply server_info_reply =
		// todo: make an enum for population level (0 low, 1 medium, 2 high, 3 full)
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
					.server_info 				= "<ServerInfo Region=\"CharacterCreate.RegionEu\" Subregion=\"UI.SubregionEU\" IsRecommended=\"1\" IsRecommendedVS=\"0\" IsRecommendedNC=\"0\" IsRecommendedTR=\"0\" />",
					.population_level			= 0,
					.population_data_length 	= 436,
					.population_data 			= "<Population ServerCapacity=\"0\" PingAdr=\"127.0.0.1:1117\" Rulesets=\"Permadeath\"><factionlist IsList=\"1\"><faction Id=\"1\" Percent=\"0\" TargetPopPct=\"0\" RewardBuff=\"52\" XPBuff=\"52\" PercentAvg=\"0\"/><faction Id=\"2\" Percent=\"0\" TargetPopPct=\"1\" RewardBuff=\"0\" XPBuff=\"0\" PercentAvg=\"0\"/><faction Id=\"3\" Percent=\"0\" TargetPopPct=\"1\" RewardBuff=\"0\" XPBuff=\"0\" PercentAvg=\"1\"/></factionlist></Population>",
					.is_access_allowed 			= TRUE,
				},
			},
		};
		
		login_packet_send(server, session, &server->arena_per_tick, KB(500), FALSE, Login_Packet_Kind_ServerListReply, &server_info_reply);

		break;
	}

		default:
		{
			packet_kind = Login_Packet_Kind_Unhandled;
			printf("[!] Unhandled login packet 0x%02x\n", packet_id);
		}
	}
}