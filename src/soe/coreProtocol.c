u32 CorePacketPack(CoreKindEnum kind, void *packetPtr, u8 *buffer, bool isSubPacket, ConnectionArgs *args)
{
    u32 offset = 0;
    printf("\n");

    switch (kind)
    {
    case CoreKindSessionReply:
    {
        printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), coreKindNames[kind]);
        SessionReply *packet = packetPtr;

        endian_write_u16_big(buffer + offset, CoreSessionReplyId);
        offset += 2;
        endian_write_u32_big(buffer + offset, packet->sessionId);
        offset += 4;
        endian_write_u32_big(buffer + offset, packet->crcSeed);
        offset += 4;
        *(u8 *)((uptr)buffer + offset) = packet->crcLen;
        offset += 1;
        endian_write_u16_big(buffer + offset, packet->compression);
        offset += 2;
        endian_write_u32_big(buffer + offset, packet->udpLen);
        offset += 4;
        endian_write_u32_big(buffer + offset, packet->soeProtocolVersion);
        offset += 4;

        printf("--- sessionId: %d\n", packet->sessionId);
        printf("--- crcSeed: %d\n", packet->crcSeed);
        printf("--- crcLen: %d\n", packet->crcLen);
        printf("--- compression: %d\n", packet->compression);
        printf("--- udpLen: %d\n", packet->udpLen);
        printf("--- soeProtocolVersion: %d\n", packet->soeProtocolVersion);
    }
    break;
    case CoreKindData:
    {
        printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), coreKindNames[kind]);
        Data *packet = packetPtr;

        endian_write_u16_big(buffer + offset, CoreDataId);
        offset += 2;

        if (args->compression)
        {
            offset++;
        }

        endian_write_u16_big(buffer + offset, packet->sequence);
        offset += 2;

        memcpy(buffer + offset, packet->data, packet->dataLen);
        offset += packet->dataLen;

        if (!isSubPacket && args->crcLen)
        {
            offset += args->crcLen;
        }
    }
    break;
    case CoreKindDataFragment:
    {
        printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), coreKindNames[kind]);
        Data *packet = packetPtr;

        endian_write_u16_big(buffer + offset, CoreDataFragmentId);
        offset += 2;

        if (args->compression)
        {
            offset++;
        }

        endian_write_u16_big(buffer + offset, packet->sequence);
        offset += 2;

        memcpy(buffer + offset, packet->data, packet->dataLen);
        offset += packet->dataLen;

        if (!isSubPacket && args->crcLen)
        {
            offset += args->crcLen;
        }
    }
    break;
    case CoreKindAck:
    {
        printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), coreKindNames[kind]);
        Ack *packet = packetPtr;

        endian_write_u16_big(buffer + offset, CoreAckId);
        offset += 2;
        endian_write_u16_big(buffer + offset, packet->sequence);
        offset += 2;

        printf("--- sequence: %d\n", packet->sequence);
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("Packing %s not implemented\n"), coreKindNames[kind]);
    }
    }

    return offset;
}

void CorePacketUnpack(u8 *data, i32 dataLen, CoreKindEnum kind, void *packetPtr, bool isSubPacket, ConnectionArgs *args)
{
    u32 offset = 2;
    printf("\n");

    switch (kind)
    {
    case CoreKindSessionRequest:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), coreKindNames[kind]);
        SessionRequest *packet = packetPtr;

        packet->crcLen = endian_read_u32_big(data + offset);
        offset += 4;
        packet->sessionId = endian_read_u32_big(data + offset);
        offset += 4;
        packet->udpLen = endian_read_u32_big(data + offset);
        offset += 4;

        for (i32 i = 0; i < 32; i++)
        {
            if (!*(u8 *)(data + offset + i))
            {
                break;
            }

            packet->protocolName[i] = *(u8 *)(data + offset + i);
        }

        printf("%-16s %-20d\n", "crcLen", packet->crcLen);
        printf("%-16s %-20d\n", "sessionId", packet->sessionId);
        printf("%-16s %-20d\n", "udpLength", packet->udpLen);
        printf("%-16s %-20s\n", "protocolName", packet->protocolName);
    }
    break;
    case CoreKindSessionReply:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), coreKindNames[kind]);
        SessionReply *packet = packetPtr;

        packet->sessionId = endian_read_u32_big(data + offset);
        offset += 4;
        packet->crcSeed = endian_read_u32_big(data + offset);
        offset += 4;
        packet->crcLen = *(u8 *)(data + offset);
        offset += 1;
        packet->compression = (u8)endian_read_u16_big(data + offset);
        offset += 2;
        packet->udpLen = endian_read_u32_big(data + offset);
        offset += 4;
        packet->soeProtocolVersion = endian_read_u32_big(data + offset);
        offset += 4;

        printf("%-16s %-24d\n", "sessionId", packet->sessionId);
        printf("%-16s %-24d\n", "crcSeed", packet->crcSeed);
        printf("%-16s %-24d\n", "crcLen", packet->crcLen);
        printf("%-16s %-24d\n", "compression", packet->compression);
        printf("%-16s %-24d\n", "udpLen", packet->udpLen);
        printf("%-16s %-24d\n", "soeProtocolVersion", packet->soeProtocolVersion);
    }
    break;
    case CoreKindData:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), coreKindNames[kind]);
        Data *packet = packetPtr;

        if (args->compression && !isSubPacket)
        {
            offset++;
        }

        packet->sequence = endian_read_u16_big(data + offset);
        offset += 2;

        u32 dataEnd;

        if (isSubPacket)
        {
            dataEnd = dataLen;
        }
        else
        {
            dataEnd = dataLen - args->crcLen;
        }

        packet->data = (u8 *)((uptr)data + offset);
        packet->dataLen = dataEnd - offset;

        printf("%-16s %-20d\n", "sequence", packet->sequence);
        printf("%-16s %-20p\n", "data", packet->data);
        printf("%-16s %-20d\n", "dataLen", packet->dataLen);
        printf("%-16s %-20x\n", "crc", packet->crc);
    }
    break;
    case CoreKindDataFragment:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), coreKindNames[kind]);
        Data *packet = packetPtr;

        if (args->compression && !isSubPacket)
        {
            offset++;
        }

        packet->sequence = endian_read_u16_big(data + offset);
        offset += 2;

        u32 fragmentEnd;
        if (isSubPacket)
        {
            fragmentEnd = dataLen;
        }
        else
        {
            fragmentEnd = dataLen - args->crcLen;
        }

        packet->data = (u8 *)((uptr)data + offset);
        packet->dataLen = fragmentEnd - offset;

        printf("%-16s %-20d\n", "sequence", packet->sequence);
        printf("%-16s %-20p\n", "data", packet->data);
        printf("%-16s %-20d\n", "dataLen", packet->dataLen);
        printf("%-16s %-20x\n", "crc", packet->crc);
    }
    break;
    case CoreKindAck:
    {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), coreKindNames[kind]);
        Ack *packet = packetPtr;

        if (args->compression && !isSubPacket)
        {
            offset++;
        }

        packet->sequence = endian_read_u16_big(data + offset);
        offset += 2;

        printf("--- sequence: %d\n", packet->sequence);
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("Unpacking %s not implemented\n"), coreKindNames[kind]);
    }
    }
}

void CorePacketSend(PlatformSocket socket, PlatformApi *api, u32 ip, u16 port, ConnectionArgs *args, CoreKindEnum kind, void *packetPtr)
{
    u8 buffer[MAX_PACKET_LENGTH] = {0};
    u32 packedLen;

    switch (kind)
    {
    case CoreKindSessionReply:
    {
        packedLen = CorePacketPack(kind, packetPtr, buffer, false, args);
    }
    break;
    case CoreKindData:
    {
        packedLen = CorePacketPack(kind, packetPtr, buffer, false, args);
    }
    break;
    case CoreKindDataFragment:
    {
        packedLen = CorePacketPack(kind, packetPtr, buffer, false, args);
    }
    break;
    case CoreKindAck:
    {
        packedLen = CorePacketPack(kind, packetPtr, buffer, false, args);
    }
    break;
    default:
    {
        ABORT_MSG("Unable to send unhandled packet!\n");
        return;
    }
    }

    u32 sentLen = api->send_to(socket, buffer, packedLen, ip, port);

    if (!sentLen)
    {
        printf(MESSAGE_CONCAT_WARN("Sent packet length is 0\n"));
        return;
    }

    printf("\n");
    printf(MESSAGE_CONCAT_INFO("Sent %d bytes to %u.%u.%u.%u:%u\n"), sentLen, (ip & 0xff000000) >> 24, (ip & 0x00ff0000) >> 16, (ip & 0x0000ff00) >> 8, (ip & 0x000000ff), port);
}

CoreKindEnum CorePacketGetKind(u8 *data, u32 dataLen)
{
    UNUSED(dataLen);
    u16 packetId = endian_read_u16_big(data);

    switch (packetId)
    {
    case CoreSessionRequestId:
    {
        return CoreKindSessionRequest;
    }
    }

    return CoreKindUnhandled;
}

void CorePacketHandle(AppState *app, SessionState *session, PlatformApi *api, u8 *data, u32 dataLen, bool isSubPacket)
{
    CoreKindEnum kind;
    u32 offset;

    printf("\n");
    u16 packetId = endian_read_u16_big(data);

    if (isSubPacket)
    {
        printf(MESSAGE_CONCAT_INFO("isSubPacket:\n"));
    }

    switch (packetId)
    {
    case CoreSessionRequestId:
    {
        kind = CoreKindSessionRequest;
        printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), coreKindNames[kind]);

        SessionRequest packet = {0};
        CorePacketUnpack(data, dataLen, kind, &packet, isSubPacket, &app->args);

        if (!packet.protocolName[0])
        {
            printf(MESSAGE_CONCAT_INFO("Switching to Ping Responder"));
            session->inputStream.dataCallbackPtr = &app->streamFunctionTable->pingInputData;
            session->kind = SessionKindPingResponder;
        }

        printf("\n");
        printf(MESSAGE_CONCAT_WARN("Ignoring connection args requested by client\n"));

        session->id = packet.sessionId;
        SessionReply sessionReply =
            {
                .sessionId = packet.sessionId,
                .crcSeed = session->args.crcSeed,
                .crcLen = session->args.crcLen,
                .compression = session->args.compression,
                .encryption = session->args.encryption,
                .udpLen = session->args.udpLen,
                .soeProtocolVersion = 3,
            };

        if (strcmp(packet.protocolName, "LoginUdp_11") == 0)
        {
            printf("[*] Enabling encryption for session\n");

            session->inputStream.useEncryption = true;
            session->outputStream.useEncryption = true;
        }

        CorePacketSend(app->socket, api, session->address.ip, session->address.port, &session->args, CoreKindSessionReply, &sessionReply);
    }
    break;
    case CoreDisconnectId:
    {
        kind = CoreKindDisconnect;
        printf(MESSAGE_CONCAT_INFO("Received disconnect from client\n"));
    }
    break;
    case CorePingId:
    {
        kind = CoreKindPing;
        printf(MESSAGE_CONCAT_INFO("Received ping from client\n"));
    }
    break;
    case CoreMultiPacketId:
    {
        kind = CoreKindMultiPacket;
        printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), coreKindNames[kind]);

        offset = CorePacketIdLen;

        if (session->args.compression)
        {
            offset++;
        }

        while (offset < dataLen - session->args.crcLen)
        {
            u32 chunkLen;
            offset += InputStreamReadLen((u8 *)((uptr)data + offset), &chunkLen);

            CorePacketHandle(app, session, api, data + offset, chunkLen, true);
            offset += chunkLen;
        }
    }
    break;
    case CoreDataId:
    {
        kind = CoreKindData;
        printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), coreKindNames[kind]);

        Data packet = {0};
        CorePacketUnpack(data, dataLen, kind, &packet, isSubPacket, &session->args);

        InputStreamWrite(app, session, &session->inputStream, packet.data, packet.dataLen, packet.sequence, false);
    }
    break;
    case CoreDataFragmentId:
    {
        kind = CoreKindDataFragment;
        printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), coreKindNames[kind]);

        Data packet = {0};
        CorePacketUnpack(data, dataLen, kind, &packet, isSubPacket, &session->args);

        InputStreamWrite(app, session, &session->inputStream, packet.data, packet.dataLen, packet.sequence, true);
    }
    break;
    case CoreAckId:
    {
        kind = CoreKindAck;
        printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), coreKindNames[kind]);

        Ack packet = {0};
        CorePacketUnpack(data, dataLen, kind, &packet, isSubPacket, &session->args);

        OutputStreamUpdateAck(&session->outputStream, (i32)packet.sequence);
    }
    break;
    default:
    {
        kind = CoreKindUnhandled;
        printf(MESSAGE_CONCAT_WARN("Unhandled core packet 0x%02x\n"), packetId);
    }
    }
}