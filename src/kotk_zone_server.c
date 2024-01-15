// C headers
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define YOTE_USE_ARENA
#define YOTE_USE_STRING
#define YOTE_PLATFORM_USE_SOCKETS

#include "yote.h"
#include "yote_platform.h"
#include "game_server.h"

#define MAX_THREADS 2 // Keep at 2 threads for testing, change to 4 threads when multiplayer works
#define LOCAL_PORT 1117
#define MAX_FRAGMENTS 12000
#define MAX_PACKET_LENGTH 512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 16 // Will increase as time goes on, but, good enough for testing right now

// Utilities
#include "utils/endian.c"
#include "utils/util.c"
#include "utils/rc4.c"

// SOE Related
#include "soe/stream.h"
#include "soe/fragments.c"
#include "soe/inputStream.c"
#include "soe/outputStream.c"
#include "soe/coreProtocol.h"
#include "soe/session.h"

typedef struct StreamFunctionTable
{
    inputStreamCallbackAck *gameInputAck;
    inputStreamCallbackData *gameInputData;
    outputStreamCallbackData *gameOutputData;
    inputStreamCallbackData *pingInputData;
} StreamFunctionTable;

struct AppState
{
    StreamFunctionTable *streamFunctionTable;
    f32 *tickMs;
    f32 *workMs;
    u64 *tickCount;
    KeyStates *keyStates;
    Arena arenaTotal;
    PlatformApi *api;
    Arena arenaPerTick;
    PlatformSocket socket;
    u8 rc4Decoded[256];
    u32 rc4DecodedLen;
    ConnectionArgs args;
    i32 sessionCapacity;
    SessionState sessions[MAX_SESSIONS_COUNT];
};

void GatewayOnLogin(AppState *app, SessionState *session, u64 characterId);
void GatewayOnTunnelDataFromClient(AppState *app, SessionState *session, u8 *data, u32 dataLen);

InputStreamCallbackData(pingInputStreamData);

#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE "Core"
#include "soe/coreProtocol.c"
#include "core/core.c"
#include "core/classes/base.h"
#include "core/entities/core_base_full_character.h"
#include "core/entities/core_base_entity.h"
#include "core/classes/grid_cell.h"
#include "core/core_server.h"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE "Gateway"
#include "zone/gatewayApi.h"
#include "zone/gatewayApi.c"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE "Zone"
#include "../schema/output/client_protocol_1087.c"
#include "zone/clientProtocol_1087.h"
#include "zone/clientProtocol_1087.c"
#include "zone/sendSelfToClient.c"
#include "zone/onLogin.c"
#include "zone/zonePacketHandler.c"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE MESSAGE_NAMESPACE_DEFAULT

void GatewayOnLogin(AppState *app, SessionState *session, u64 characterId)
{
    printf("[!] Character %llxh trying to login to zone server\n", characterId);
    session->characterId = characterId;

    OnLogin(app, session);
}

void GatewayOnTunnelDataFromClient(AppState *app, SessionState *session, u8 *data, u32 dataLen)
{
    ZonePacketHandler(app, session, data, dataLen);
}

InputStreamCallbackData(pingInputStreamData)
{
    UNUSED(app);
    UNUSED(session);
    UNUSED(data);
    UNUSED(dataLen);
}

InputStreamCallbackAck(inputCallbackAck)
{
    session->nextAck = ack;
}

InputStreamCallbackData(inputCallbackData)
{
    GatewayPacketHandle(app, session, data, dataLen);
}

OutputStreamCallbackData(outputCallBackData)
{
    Data packet = {
        .sequence = (u16)sequence,
        .data = data,
        .dataLen = dataLen,
    };

    if (!isFragment)
    {
        CorePacketSend(app->socket, app->api, session->address.ip, session->address.port, &session->args, CoreKindData, &packet);
    }
    else
    {
        CorePacketSend(app->socket, app->api, session->address.ip, session->address.port, &session->args, CoreKindDataFragment, &packet);
    }
}

__declspec(dllexport) AppTick(serverTick)
{
    AppState *app = appMemory->app;
    if (!app)
    {
        app = appMemory->app = arena_bootstrap_push_struct(appMemory->backingMemory.data,
                                                           appMemory->backingMemory.size,
                                                           "Total",
                                                           AppState,
                                                           arenaTotal);
        app->api = &appMemory->api;
        app->tickMs = &appMemory->tickMs;
        app->workMs = &appMemory->workMs;
        app->tickCount = &appMemory->tickCount;
        app->keyStates = &appMemory->keyStates;

        Buffer perTickBackingMemory = {
            .size = MB(10),
            .data = arena_push_size(&app->arenaTotal, perTickBackingMemory.size),
        };

        app->streamFunctionTable = arena_push_struct(&app->arenaTotal, StreamFunctionTable);
        app->streamFunctionTable->gameInputAck = inputCallbackAck;
        app->streamFunctionTable->gameInputData = inputCallbackData;
        app->streamFunctionTable->gameOutputData = outputCallBackData;
        app->streamFunctionTable->pingInputData = pingInputStreamData;

        app->arenaPerTick = (Arena){
            .buffer = perTickBackingMemory.data,
            .capacity = perTickBackingMemory.size,
            .name = "Tick",
        };

        u8 rc4KeyEncoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
        app->rc4DecodedLen = util_base64_decode(rc4KeyEncoded, sizeof(rc4KeyEncoded) - 1, app->rc4Decoded);

        app->args.udpLen = MAX_PACKET_LENGTH;
        app->args.dumpCore = true;
        app->args.dumpLogin = true;
        app->args.dumpTunnel = true;
        app->args.dumpGateway = true;
        app->args.dumpZone = true;

        app->sessionCapacity = MAX_SESSIONS_COUNT;
        app->socket = app->api->socket_udp_create_and_bind(LOCAL_PORT);

        printf(MESSAGE_CONCAT_INFO("Game server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n"));
    }

    u8 incomingBuffer[MAX_PACKET_LENGTH] = {0};

    u32 fromIp;
    u16 fromPort;

    i32 receiveResult = app->api->receive_from(app->socket, incomingBuffer, MAX_PACKET_LENGTH, &fromIp, &fromPort);

    if (receiveResult)
    {
        printf("\n\nPacket Tick Begin ============================================================\\\\\n");

        SessionAddress incomingAddress = {
            .ip = fromIp,
            .port = fromPort,
        };

        i32 firstFreeSession = -1;
        i32 knownSession = -1;

        for (i32 i = 0; i < app->sessionCapacity; i++)
        {
            if (firstFreeSession == -1 && !app->sessions[i].address.full)
            {
                firstFreeSession = i;
            }

            if (knownSession == -1 && incomingAddress.full == app->sessions[i].address.full)
            {
                knownSession = i;
            }

            if (firstFreeSession != -1 && knownSession != -1)
            {
                break;
            }
        }

        if (CorePacketGetKind(incomingBuffer, receiveResult) == CoreKindSessionRequest)
        {
            if (knownSession != -1)
            {
                printf(MESSAGE_CONCAT_INFO("Known client %u.%u.%u.%u:%u re-sent SessionRequest\n"),
                       (fromIp & 0xff000000) >> 24,
                       (fromIp & 0x00ff0000) >> 16,
                       (fromIp & 0x0000ff00) >> 8,
                       (fromIp & 0x000000ff),
                       fromPort);
            }
            else
            {
                printf(MESSAGE_CONCAT_INFO("Unknown client %u.%u.%u.%u:%u sent SessionRequest. Beginning session\n"),
                       (fromIp & 0xff000000) >> 24,
                       (fromIp & 0x00ff0000) >> 16,
                       (fromIp & 0x0000ff00) >> 8,
                       (fromIp & 0x000000ff),
                       fromPort);

                if (firstFreeSession == -1)
                {
                    printf(MESSAGE_CONCAT_WARN("No free sessions avaliable\n"));
                }
                else
                {
                    knownSession = firstFreeSession;

                    app->sessions[firstFreeSession].address.full = incomingAddress.full;
                    app->sessions[firstFreeSession].nextAck = -1;
                    app->sessions[firstFreeSession].previousAck = -1;

                    memcpy(&app->sessions[firstFreeSession].args, &app->args, sizeof(app->args));

                    app->sessions[firstFreeSession].inputPool = FragmentCreate(MAX_FRAGMENTS, MAX_PACKET_LENGTH, &app->arenaTotal);
                    app->sessions[firstFreeSession].outputPool = FragmentCreate(MAX_FRAGMENTS, MAX_PACKET_LENGTH, &app->arenaTotal);

                    app->sessions[firstFreeSession].inputStream = InputStreamInit(&app->sessions[firstFreeSession].inputPool, app->rc4Decoded, app->rc4DecodedLen, false);
                    app->sessions[firstFreeSession].outputStream = OutputStreamInit(&app->sessions[firstFreeSession].outputPool, app->rc4Decoded, app->rc4DecodedLen, false);

                    app->sessions[firstFreeSession].inputStream.ackCallbackPtr = &app->streamFunctionTable->gameInputAck;
                    app->sessions[firstFreeSession].inputStream.dataCallbackPtr = &app->streamFunctionTable->gameInputData;
                    app->sessions[firstFreeSession].outputStream.dataCallbackPtr = &app->streamFunctionTable->gameOutputData;
                }
            }
        }

        if (knownSession != -1)
        {
            CorePacketHandle(app, &app->sessions[knownSession], app->api, incomingBuffer, receiveResult, false);

            if (app->sessions[knownSession].previousAck != app->sessions[knownSession].nextAck)
            {
                printf(MESSAGE_CONCAT_INFO("Syncing ack...\n"));
                app->sessions[knownSession].previousAck = app->sessions[knownSession].nextAck;

                Ack ack = {
                    .sequence = (u16)app->sessions[knownSession].nextAck,
                };

                CorePacketSend(app->socket, app->api, app->sessions[knownSession].address.ip, app->sessions[knownSession].address.port, &app->sessions[knownSession].args, CoreKindAck, &ack);
            }
        }

        printf("Packet Tick End ==============================================================//\n");
    }

    arena_reset(&app->arenaPerTick);
}
