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
    login_packet_unpack(data + offset, dataLen - offset, kind, &packet, &app->arenaPerTick);

    u32 validationStatus = 1;

    session->selected_server_id = packet.server_id;
    session->characterName.nameLen = packet.data_client->character_name_length;
    session->characterName.name = packet.data_client->character_name;

    if (session->characterName.nameLen < 3 || session->characterName.nameLen > 20)
    {
        validationStatus = 3;
    }
    else if (!isalpha((uchar)session->characterName.name[0]))
    {
        validationStatus = 3;
    }
    else
    {
        for (u32 i = 1; i < session->characterName.nameLen; i++)
        {
            if (!isalpha((uchar)session->characterName.name[i]))
            {
                validationStatus = 3;
                break;
            }
        }
    }

    Login_Packet_TunnelAppPacketServerToClient packetReply = {0};

    packetReply.server_id = session->selected_server_id;
    packetReply.data_server_length = 14 + session->characterName.nameLen;

    packetReply.data_server = (struct data_server_s[1]){
        [0] = {
            .tunnel_op_code = 0xa7,
            .sub_op_code = 0x02,
            .character_name = session->characterName.name,
            .character_name_length = session->characterName.nameLen,
            .status = validationStatus,
        },
    };

    LoginPacketSend(app, session, &app->arenaPerTick, KB(10), Login_Packet_Kind_TunnelAppPacketServerToClient, &packetReply);
}

void GetHeadTypeId(SessionState *session, void *packetPtr)
{
    Login_Packet_CharacterCreateRequest *characterCreateReq = packetPtr;
    u32 headId = characterCreateReq->char_payload->head_type;

    memcpy(&session->pGetPlayerActor.headType, &headId, sizeof(headId));

    switch (headId)
    {
    case 1:
    {
        session->pGetPlayerActor.headType = 1;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = STRLEN(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_01.adr";
        session->pGetPlayerActor.headActorLen = STRLEN(session->pGetPlayerActor.headActor);
    }
    break;
    case 2:
    {
        session->pGetPlayerActor.headType = 2;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = STRLEN(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_02.adr";
        session->pGetPlayerActor.headActorLen = STRLEN(session->pGetPlayerActor.headActor);
    }
    break;
    case 5:
    {
        session->pGetPlayerActor.headType = 5;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = STRLEN(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_03.adr";
        session->pGetPlayerActor.headActorLen = STRLEN(session->pGetPlayerActor.headActor);
    }
    break;
    case 6:
    {
        session->pGetPlayerActor.headType = 6;
        session->pGetPlayerActor.gender = 1;
        session->pGetPlayerActor.actorModelId = 9240;
        session->pGetPlayerActor.hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        session->pGetPlayerActor.hairModelLen = STRLEN(session->pGetPlayerActor.hairModel);
        session->pGetPlayerActor.headActor = "SurvivorMale_Head_04.adr";
        session->pGetPlayerActor.headActorLen = STRLEN(session->pGetPlayerActor.headActor);
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
            .name = session->characterName.name,
            .name_length = session->characterName.nameLen,
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
