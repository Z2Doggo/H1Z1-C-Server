u32 GatewayPacketPack(GatewayKindEnum kind, void *packetPtr, u8 *buffer)
{
    u32 offset = 0;
    printf("\n");

    switch (kind)
    {
    case GatewayKindLoginRequest:
    {
        printf(MESSAGE_CONCAT_INFO("Packing LoginRequest...\n"));
        GatewayLoginRequest *packet = packetPtr;

        endian_write_u8_little(buffer + offset, GatewayLoginRequestId);
        offset++;

        endian_write_u64_little(buffer + offset, packet->characterId);
        offset += sizeof(u64);
        printf("-- characterId            \t%lld\t%llxh\t%f\n", (i64)packet->characterId, (u64)packet->characterId, (f64)packet->characterId);

        endian_write_u32_little(buffer + offset, packet->serverTicketLen);
        offset += sizeof(u32);
        printf("-- serverTicketLen           \t%lld\t%llxh\t%f\n", (i64)packet->serverTicketLen, (u64)packet->serverTicketLen, (f64)packet->serverTicketLen);

        for (u32 serverTickeIter = 0; serverTickeIter < packet->serverTicketLen; serverTickeIter++)
        {
            endian_write_i8_little(buffer + offset, packet->serverTicket[serverTickeIter]);
            offset++;
        }

        endian_write_u32_little(buffer + offset, packet->clientProtocolLen);
        offset += sizeof(u32);
        printf("-- clientProtocolLen           \t%lld\t%llxh\t%f\n", (i64)packet->clientProtocolLen, (u64)packet->clientProtocolLen, (f64)packet->clientProtocolLen);

        for (u32 clientProtocolIter = 0; clientProtocolIter < packet->clientProtocolLen; clientProtocolIter++)
        {
            endian_write_i8_little(buffer + offset, packet->clientProtocol[clientProtocolIter]);
            offset++;
        }

        endian_write_u32_little(buffer + offset, packet->clientBuildLen);
        offset += sizeof(u32);
        printf("-- clientBuildLen           \t%lld\t%llxh\t%f\n", (i64)packet->clientBuildLen, (u64)packet->clientBuildLen, (f64)packet->clientBuildLen);

        for (u32 clientBuildIter = 0; clientBuildIter < packet->clientBuildLen; clientBuildIter++)
        {
            endian_write_i8_little(buffer + offset, packet->clientBuild[clientBuildIter]);
            offset++;
        }
    }
    break;
    case GatewayKindLoginReply:
    {
        printf(MESSAGE_CONCAT_INFO("Packing LoginReply...\n"));
        GatewayLoginReply *packet = packetPtr;

        endian_write_u8_little(buffer + offset, GatewayLoginReplyId);
        offset++;

        endian_write_b8_little(buffer + offset, packet->isLoggedIn);
        offset += sizeof(b8);

        printf("-- isLoggedIn            \t%lld\t%llxh\t%f\n", (i64)packet->isLoggedIn, (u64)packet->isLoggedIn, (f64)packet->isLoggedIn);
    }
    break;
    case GatewayKindTunnelPacketToExternalConnection:
    case GatewayKindTunnelPacketFromExternalConnection:
    {
        printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), gatewayKindNames[kind]);
        GatewayTunnelPacket *packet = packetPtr;

        u8 opcode;

        if (kind == GatewayKindTunnelPacketToExternalConnection)
        {
            opcode = GatewayTunnelToExternalConnectionId;
        }
        else if (kind == GatewayKindTunnelPacketFromExternalConnection)
        {
            opcode = GatewayTunnelFromExternalConnectionId;
        }
        else
        {
            opcode = 0;
            ABORT_MSG("Packing unknown TunnelPacket");
        }

        endian_write_u8_little(buffer + offset, opcode | (packet->channel << 5));
        offset++;

        printf("-- channel                 \t%lld\t%llxh\t%f\n", (i64)packet->channel, (u64)packet->channel, (f64)packet->channel);
        offset += packet->dataLen;
    }
    break;
    case GatewayKindChannelIsRoutable:
    {
        printf(MESSAGE_CONCAT_INFO("Packing ChannelIsRoutable...\n"));
        GatewayChannelIsRoutable *packet = packetPtr;

        endian_write_u8_little(buffer + offset, GatewayChannelIsRoutableId | (packet->channel << 5));
        offset++;

        printf("-- channel                 \t%lld\t%llxh\t%f\n", (i64)packet->channel, (u64)packet->channel, (f64)packet->channel);

        endian_write_b8_little(buffer + offset, packet->isRoutable);
        offset += sizeof(b8);

        printf("-- isRoutable             \t%lld\t%llxh\t%f\n", (i64)packet->isRoutable, (u64)packet->isRoutable, (f64)packet->isRoutable);

        endian_write_b8_little(buffer + offset, packet->unkBool);
        offset += sizeof(b8);

        printf("-- unkBool                \t%lld\t%llxh\t%f\n", (i64)packet->unkBool, (u64)packet->unkBool, (f64)packet->unkBool);
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("Packing %s not implemented\n"), gatewayKindNames[kind]);
    }
    }

    return offset;
}

void GatewayPacketUnpack(u8 *data, u32 dataLen, GatewayKindEnum kind, void *packetPtr, Arena *arena)
{
    u32 offset = 1;
    printf("\n");

    switch (kind)
    {
    case GatewayKindLoginRequest:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking LoginRequest...\n"));
        GatewayLoginRequest *packet = packetPtr;

        packet->characterId = endian_read_u64_little(data + offset);
        offset += sizeof(u64);

        printf("-- characterId            \t%lld\t%llxh\t%f\n", (i64)packet->characterId, (u64)packet->characterId, (f64)packet->characterId);

        packet->serverTicketLen = endian_read_u32_little(data + offset);
        offset += sizeof(u32);

        packet->serverTicket = arena_push_size(arena, packet->serverTicketLen);
        printf("-- serverTicketLen           \t%d\n", packet->serverTicketLen);

        for (u32 serverTicketIter = 0; serverTicketIter < packet->serverTicketLen; serverTicketIter++)
        {
            packet->serverTicket[serverTicketIter] = *(i8 *)((uptr)data + offset);
            offset++;
        }

        packet->clientProtocolLen = endian_read_u32_little(data + offset);
        offset += sizeof(u32);

        packet->clientProtocol = arena_push_size(arena, packet->clientProtocolLen);
        printf("-- clientProtocolLen           \t%d\n", packet->clientProtocolLen);

        for (u32 clientProtocolIter = 0; clientProtocolIter < packet->clientProtocolLen; clientProtocolIter++)
        {
            packet->clientProtocol[clientProtocolIter] = *(i8 *)((uptr)data + offset);
            offset++;
        }

        packet->clientBuildLen = endian_read_u32_little(data + offset);
        offset += sizeof(u32);

        packet->clientBuild = arena_push_size(arena, packet->clientBuildLen);
        printf("-- clientBuildLen           \t%d\n", packet->clientBuildLen);

        for (u32 clientBuildIter = 0; clientBuildIter < packet->clientBuildLen; clientBuildIter++)
        {
            packet->clientBuild[clientBuildIter] = *(i8 *)((uptr)data + offset);
            offset++;
        }
    }
    break;
    case GatewayKindLoginReply:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking LoginReply...\n"));
        GatewayLoginReply *packet = packetPtr;

        packet->isLoggedIn = endian_read_b8_little(data + offset);
        offset += sizeof(b8);

        printf("-- isLoggedIn            \t%lld\t%llxh\t%f\n", (i64)packet->isLoggedIn, (u64)packet->isLoggedIn, (f64)packet->isLoggedIn);
    }
    break;
    case GatewayKindTunnelPacketFromExternalConnection:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), gatewayKindNames[kind]);
        GatewayTunnelPacket *packet = packetPtr;

        packet->channel = (*data) >> 5;
        packet->data = data + offset;
        packet->dataLen = dataLen - 1;
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("Unpacking %s not implemented\n"), gatewayKindNames[kind]);
    }
    }
}

void GatewayTunnelDataSend(AppState *app, SessionState *session, u8 *baseBuffer, u32 totalLen)
{
    GatewayTunnelPacket tunnelPacket = {
        .channel = 0,
        .data = baseBuffer + TunnelDataHeaderLen,
        .dataLen = totalLen - TunnelDataHeaderLen,
    };

    u32 packedLen = GatewayPacketPack(GatewayKindTunnelPacketToExternalConnection, &tunnelPacket, baseBuffer);
    OutputStreamWrite(app, session, &session->outputStream, baseBuffer, packedLen, false);
}

void GatewayPacketSend(AppState *app, SessionState *session, Arena *arena, u32 maxLen, GatewayKindEnum kind, void *packetPtr)
{
    u8 *packedBuffer = arena_push_size(arena, maxLen);
    u32 packedLen = GatewayPacketPack(kind, packetPtr, packedBuffer);

    OutputStreamWrite(app, session, &session->outputStream, packedBuffer, packedLen, false);
}

void GatewayPacketHandle(AppState *app, SessionState *session, u8 *data, u32 dataLen)
{
    GatewayKindEnum kind;
    printf("\n");

    u8 channel = *data >> 5;
    u8 packetId = *data & 0b00011111;

    switch (packetId)
    {
    case GatewayLoginRequestId:
    {
        kind = GatewayKindLoginRequest;
        printf(MESSAGE_CONCAT_INFO("(%u) Handling %s...\n"), channel, gatewayKindNames[kind]);

        GatewayLoginRequest loginRequest = {0};
        GatewayPacketUnpack(data, dataLen, kind, &loginRequest, &app->arenaPerTick);

        printf("[*] Enabling encryption for session\n");

        session->inputStream.useEncryption = true;
        session->outputStream.useEncryption = true;

        GatewayLoginReply loginReply = {
            .isLoggedIn = true,
        };

        GatewayPacketSend(app, session, &app->arenaPerTick, 32, GatewayKindLoginReply, &loginReply);

        GatewayChannelIsRoutable channelZeroIsRoutable = {
            .channel = 0,
            .isRoutable = true,
        };

        GatewayPacketSend(app, session, &app->arenaPerTick, 32, GatewayKindChannelIsRoutable, &channelZeroIsRoutable);

        GatewayChannelIsRoutable channelOneIsRoutable = {
            .channel = 1,
            .isRoutable = true,
        };

        GatewayPacketSend(app, session, &app->arenaPerTick, 32, GatewayKindChannelIsRoutable, &channelOneIsRoutable);

        GatewayOnLogin(app, session, loginRequest.characterId);
    }
    break;
    case GatewayTunnelFromExternalConnectionId:
    {
        kind = GatewayKindTunnelPacketFromExternalConnection;
        printf(MESSAGE_CONCAT_INFO("(%u) Handling %s...\n"), channel, gatewayKindNames[kind]);

        GatewayTunnelPacket tunnelPacket = {0};
        GatewayPacketUnpack(data, dataLen, GatewayKindTunnelPacketFromExternalConnection, &tunnelPacket, &app->arenaPerTick);

        GatewayOnTunnelDataFromClient(app, session, tunnelPacket.data, tunnelPacket.dataLen);
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("(%u) Unhandled gateway packet 0x%02x\n"), channel, packetId);
    }
    }
}