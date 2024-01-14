void LoginPacketSend(AppState *app, SessionState *session, Arena *arena, u32 maxLen, Login_Packet_Kind kind, void *packetPtr)
{
    u8 *dataBuffer = arena_push_size(arena, maxLen);
    u32 dataBufferLen = login_packet_pack(kind, packetPtr, dataBuffer);

    OutputStreamWrite(app, session, &session->outputStream, dataBuffer, dataBufferLen, false);
}

void NameValidation(AppState *app, SessionState *session, u8 *data, u32 dataLen)
{
    Login_Packet_Kind kind = Login_Packet_Kind_TunnelAppPacketClientToServer;
    printf("Received %s\n", login_packet_names[kind]);

    i32 offset = sizeof(u8);

    Login_Packet_TunnelAppPacketClientToServer packet = {0};
    login_packet_unpack(data + offset, dataLen - offset, Login_Packet_Kind_TunnelAppPacketClientToServer, &packet, &app->arenaPerTick);

    u32 validationStatus = 1;
    u32 nameLen = packet.data_client->character_name_length;

    char *name = packet.data_client->character_name;

    if (nameLen < 3 || nameLen > 20)
    {
        validationStatus = 3;
    }
    else if (!isalpha((uchar)name[0]))
    {
        validationStatus = 3;
    }
    else
    {
        for (u32 i = 1; i < nameLen; i++)
        {
            if (!isalpha((uchar)name[i]))
            {
                validationStatus = 3;
                break;
            }
        }
    }

    Login_Packet_TunnelAppPacketServerToClient packetReply = {0};

    packetReply.server_id = session->selected_server_id;
    packetReply.data_server_length = 14 + nameLen;

    packetReply.data_server = (struct data_server_s[1]){
        [0] = {
            .tunnel_op_code = 0xa7,
            .sub_op_code = 0x02,
            .character_name = name,
            .character_name_length = nameLen,
            .status = validationStatus,
        },
    };

    LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_TunnelAppPacketServerToClient, &packetReply);
}

void GetHeadTypeId(SessionState *session, void *packetPtr)
{
    Login_Packet_CharacterCreateRequest *characterCreateReq = packetPtr;
    u32 headId = characterCreateReq->char_payload->head_type;

    switch (headId)
    {
    case 1:
    {
        session->pGetPlayerActor.headType = 1;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = (u32)strlen(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_01.adr";
        session->pGetPlayerActor.headActorLen = (u32)strlen(session->pGetPlayerActor.headActor);
    }
    break;
    case 2:
    {
        session->pGetPlayerActor.headType = 2;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = (u32)strlen(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_02.adr";
        session->pGetPlayerActor.headActorLen = (u32)strlen(session->pGetPlayerActor.headActor);
    }
    break;
    case 5:
    {
        session->pGetPlayerActor.headType = 5;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = (u32)strlen(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_03.adr";
        session->pGetPlayerActor.headActorLen = (u32)strlen(session->pGetPlayerActor.headActor);
    }
    break;
    case 6:
    {
        session->pGetPlayerActor.headType = 6;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = (u32)strlen(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_04.adr";
        session->pGetPlayerActor.headActorLen = (u32)strlen(session->pGetPlayerActor.headActor);
    }
    break;
    default:
    {
        printf("Head type data is invalid!\n");
        return;
    }
    }
}

void CharacterCreate(AppState *app, SessionState *session)
{
    session->characterId = generateRandomGuid();

    Login_Packet_CharacterCreateReply packetReply = {0};
    packetReply.character_id = session->characterId;
    packetReply.status = 1;

    session->createReply.status = packetReply.status;

    LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_CharacterCreateReply, &packetReply);
}

void CharacterSelectInfo(AppState *app, SessionState *session)
{
    Login_Packet_CharacterSelectInfoReply packetReply = {0};

    packetReply.character_status = 1;
    packetReply.can_bypass_server_lock = true;
    packetReply.characters_count = 1;

    packetReply.characters = (struct characters_s[1]){
        [0] = {
            .charId = session->characterId,
            .lastLoginDate = 0x00ull,
            .serverId = session->selected_server_id,
        },
    };

    packetReply.characters->payload = (struct payload_s[1]){
        [0] = {
            .actorModelId = session->pGetPlayerActor.actorModelId,
            .gender = session->pGetPlayerActor.gender,
            .headId = session->pGetPlayerActor.headType,
            .name = "Doggo",
            .name_length = STRLEN("Doggo"),
        },
    };

    packetReply.characters->payload->loadoutSlots_count = 1;
    packetReply.characters->payload->loadoutSlots = (struct loadoutSlots_s[1]){
        [0] = {
            .unkByte1 = 1,
            .unkDword1 = 22,
            .loadoutId = 3,
        },
    };

    if (session->createReply.status == 1)
    {
        packetReply.characters->status = 1;
    }

    LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_CharacterSelectInfoReply, &packetReply);
}

void LoginPacketHandle(AppState *app, SessionState *session, u8 *data, u32 dataLen)
{
    Login_Packet_Kind kind;
    printf("\n");

    u8 packetId = *data;
    i32 offset = sizeof(u8);

    switch (packetId)
    {
    case LOGIN_LOGINREQUEST_ID:
    {
        kind = Login_Packet_Kind_LoginRequest;
        printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[kind]);

        Login_Packet_LoginRequest packet = {0};
        login_packet_unpack(data + offset, dataLen - offset, Login_Packet_Kind_LoginRequest, &packet, &app->arenaPerTick);

        Login_Packet_LoginReply packetReply = {0};

        packetReply.is_logged_in = 1;
        packetReply.status = 1;
        packetReply.result_code = 1;
        packetReply.is_member = 1;
        packetReply.is_internal = 1;
        packetReply.namespace_name = "SOE";
        packetReply.namespace_name_length = STRLEN("SOE");

        packetReply.account_features_count = 1;
        packetReply.account_features = (struct account_features_s[1]){
            [0] = {
                0,
            },
        };

        packetReply.error_details_count = 1;
        packetReply.error_details = (struct error_details_s[1]){
            [0] = {
                0,
            },
        };

        LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_LoginReply, &packetReply);
    }
    break;
    case LOGIN_LOGOUT_ID:
    {
        kind = Login_Packet_Kind_Logout;
        printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[kind]);
    }
    break;
    case LOGIN_FORCEDISCONNECT_ID:
    {
        kind = Login_Packet_Kind_ForceDisconnect;
        printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[kind]);
    }
    break;
    case LOGIN_SERVERLISTREQUEST_ID:
    {
        kind = Login_Packet_Kind_ServerListRequest;
        printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[kind]);

        Login_Packet_ServerListReply packetReply = {0};

        packetReply.servers_count = 1;

        packetReply.servers = (struct servers_s[1]){
            [0] = {
                .id = 1,
                .state = 2,
                .is_locked = false,
                .name = "H1Z1-C-Server",
                .name_length = STRLEN("H1Z1-C-Server"),
                .name_id = 193,
                .description = "A server-emulator for H1Z1: King of the Kill, Preseason 3; Built in C",
                .description_length = STRLEN("A server-emulator for H1Z1: King of the Kill, Preseason 3; Built in C"),
                .description_id = 1362,
                .server_info = "<ServerInfo Region=\"CharacterCreate.RegionUs\" Subregion=\"UI.SubregionUS\" IsRecommended=\"1\" IsRecommendedVS=\"0\" IsRecommendedNC=\"0\" IsRecommendedTR=\"0\" />",
                .server_info_length = STRLEN("<ServerInfo Region=\"CharacterCreate.RegionUs\" Subregion=\"UI.SubregionUS\" IsRecommended=\"1\" IsRecommendedVS=\"0\" IsRecommendedNC=\"0\" IsRecommendedTR=\"0\" />"),
                .population_data = "<Population PctCap=\"0\" PingAdr=\"127.0.0.1:1117\" Rulesets=\"\" Mode=\"13\" IsLogin=\"1\" IsWL=\"0\" IsEvt=\"0\" PL=\"0\" DC=\"LVS\" PopLock=\"0\" GP=\"100\" BP=\"175\" MaxPop=\"4000\" Subregion=\"US\"><Fac IsList=\"1\"/></Population>",
                .population_data_length = STRLEN("<Population PctCap=\"0\" PingAdr=\"127.0.0.1:1117\" Rulesets=\"\" Mode=\"13\" IsLogin=\"1\" IsWL=\"0\" IsEvt=\"0\" PL=\"0\" DC=\"LVS\" PopLock=\"0\" GP=\"100\" BP=\"175\" MaxPop=\"4000\" Subregion=\"US\"><Fac IsList=\"1\"/></Population>"),
                .is_access_allowed = true,
            },
        };

        LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_ServerListReply, &packetReply);
    }
    break;
    case LOGIN_CHARACTERDELETEREQUEST_ID:
    {
        kind = Login_Packet_Kind_CharacterDeleteRequest;
        printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[kind]);

        Login_Packet_CharacterDeleteRequest packet = {0};
        login_packet_unpack(data + offset, dataLen - offset, Login_Packet_Kind_CharacterDeleteRequest, &packet, &app->arenaPerTick);

        Login_Packet_CharacterDeleteReply packetReply = {0};

        packetReply.character_id = session->characterId;
        packetReply.status = 1;

        LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_CharacterDeleteReply, &packetReply);
    }
    break;
    case LOGIN_TUNNELAPPPACKETCLIENTTOSERVER_ID:
    {
        NameValidation(app, session, data, dataLen);
    }
    break;
    case LOGIN_CHARACTERCREATEREQUEST_ID:
    {
        kind = Login_Packet_Kind_CharacterCreateRequest;
        printf(MESSAGE_CONCAT_INFO("Received %s\n"), login_packet_names[kind]);

        Login_Packet_CharacterCreateRequest packet = {0};
        login_packet_unpack(data + offset, dataLen - offset, Login_Packet_Kind_CharacterCreateRequest, &packet, &app->arenaPerTick);

        GetHeadTypeId(session, &packet);
        CharacterCreate(app, session);
    }
    break;
    case LOGIN_CHARACTERSELECTINFOREQUEST_ID:
    {
        kind = Login_Packet_Kind_CharacterSelectInfoRequest;
        printf(MESSAGE_CONCAT_INFO("Received %s\n"), login_packet_names[kind]);

        CharacterSelectInfo(app, session);
    }
    break;
    case LOGIN_CHARACTERLOGINREQUEST_ID:
    {
        kind = Login_Packet_Kind_CharacterLoginRequest;
        printf(MESSAGE_CONCAT_INFO("Recieved %s\n"), login_packet_names[kind]);

        Login_Packet_CharacterLoginRequest packet = {0};
        login_packet_unpack(data + offset, dataLen - offset, Login_Packet_Kind_CharacterLoginRequest, &packet, &app->arenaPerTick);

        Login_Packet_CharacterLoginReply packetReply = {0};

        packetReply.character_id = session->characterId;
        packetReply.server_id = session->selected_server_id;
        packetReply.status = 1;

        packetReply.login_payload = (struct login_payload_s[1]){
            [0] = {
                .server_address = "127.0.0.1:1117",
                .server_address_length = STRLEN("127.0.0.1:1117"),
                .server_ticket = "7y3Bh44sKWZCYZH",
                .server_ticket_length = STRLEN("7y3Bh44sKWZCYZH"),
                .encryption_key = "\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f",
                .encryption_key_length = STRLEN("\x17\xbd\x08\x6b\x1b\x94\xf0\x2f\xf0\xec\x53\xd7\x63\x58\x9b\x5f"),
                .soe_protocol_version = 3,
                .character_id = session->characterId,
                .character_name = "Doggo",
                .character_name_length = STRLEN("Doggo"),
            },
        };

        LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_CharacterLoginReply, &packetReply);
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("Unhandled login packet 0x%02x\n"), packetId);
        return;
    }
    }
}