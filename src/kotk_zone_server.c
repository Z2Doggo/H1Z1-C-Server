// C headers
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define YOTE_USE_ARENA
#define YOTE_USE_STRING
#include "yote.h"
#define YOTE_PLATFORM_USE_SOCKETS
#include "yote_platform.h"
#include "game_server.h"

#define MAX_THREADS 4   // Change as is necessary
#define LOCAL_PORT 1117 // Zone server port
#define MAX_FRAGMENTS 0xffff
#define MAX_PACKET_LENGTH 512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 16 // Will increase as time goes on, but, good enough for testing right now

// Utilities
#include "utils/endian.c"
#include "utils/util.c"
#include "utils/crypt_rc4.c"

// SoE and SoE protocol related
#include "soe/stream.h"
#include "soe/fragment_pool.c"
#include "soe/input_stream.c"
#include "soe/output_stream.c"
#include "soe/core_protocol.h"
#include "soe/connection.h"
#include "soe/session.h"
#include "soe/packet_queue.h"
#include "soe/packet_queue.c"

// WiP SOE Related
#include "soe/newSOE/stream.h"
#include "soe/newSOE/stream.c"
#include "soe/newSOE/inputStream.c"

#define PACKET_FOLDER "..\\GAME_PACKETS"
u64 global_tick_count = 0;

typedef struct Stream_Function_Table
{
    input_stream_callback_ack *game_input_ack;
    input_stream_callback_data *game_input_data;
    output_stream_callback_data *game_output_data;
    input_stream_callback_data *ping_input_data;
} Stream_Function_Table;

struct App_State
{
    Stream_Function_Table *stream_function_table;
    f32 *tick_ms;
    f32 *work_ms;
    u64 *tick_count;
    Key_States *key_states;
    Arena arena_total;
    Platform_Api *platform_api;
    Arena arena_per_tick;
    Platform_Socket socket;
    u8 rc4_key_decoded[256];
    i32 rc4_key_decoded_length;
    Connection_Args connection_args;
    i32 sessions_capacity;
    Session_State sessions[MAX_SESSIONS_COUNT];
};

void readPositionUpdateData(App_State *app, Session_State *session, u8 *data, u32 offset);
void gateway_on_login(App_State *app_state, Session_State *session_state);
void gateway_on_tunnel_data_from_client(App_State *app_state, Session_State *session_state, u8 *data, u32 data_length);

INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data);

#undef MESSAGE_NAMESPACE
#define MESSAGE_NAMESPACE "Core"
#include "soe/core_protocol.c"
#include "core/core.c"
#include "core/classes/base.h"
#include "core/entities/core_base_full_character.h"
#include "core/entities/core_base_entity.h"
#include "core/classes/grid_cell.h"
#include "core/core_server.h"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE "Gateway"
#include "zone/external_gateway_api_3.c"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE "Zone"
#include "../schema/output/client_protocol_1087.c"
void staticViewReply(App_State *app, Session_State *session, Zone_Packet_StaticViewRequest *packetPtr);
#include "zone/client_protocol_1087.c"
#include "zone/data/loginZoneData.c"
#include "zone/data/send_self.c"
#include "zone/character/zone_character.c"
#include "zone/character/zone_login.c"
#include "zone/data/shared.c"
#undef MESSAGE_NAMESPACE

#define MESSAGE_NAMESPACE MESSAGE_NAMESPACE_DEFAULT

void gateway_on_login(App_State *app_state, Session_State *session_state)
{
    printf("[!] Character %llxh trying to login to zone server\n", session_state->character_id); // (doggo)temp characterId until I implement a decent enough solution!
    onZoneLogin(app_state, session_state);
}

void gateway_on_tunnel_data_from_client(App_State *app_state, Session_State *session_state, u8 *data, u32 data_length)
{
    zone_packet_handle(app_state, session_state, data, data_length);
}

INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data)
{
    UNUSED(server);
    UNUSED(session);
    UNUSED(data);
    UNUSED(data_length);
}

INPUT_STREAM_CALLBACK_ACK(on_input_stream_ack)
{
    Session_State *session_state = session;
    session_state->ack_next = ack;
}

INPUT_STREAM_CALLBACK_DATA(on_input_stream_data)
{
    gateway_packet_handle(server, session, data, data_length);
}

OUTPUT_STREAM_CALLBACK_DATA(on_output_stream_data)
{
    App_State *app_state = server;
    Session_State *session_state = session;

    Data packet =
        {
            .sequence = (u16)sequence,
            .data = data,
            .data_length = data_length,
        };

    if (!is_fragment)
    {
        core_packet_send(app_state->socket, app_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data, &packet);
    }
    else
    {
        core_packet_send(app_state->socket, app_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data_Fragment, &packet);
    }
}

// TODO(rhett): STBSP_SPRINTF breaks if this is less than 4 bytes each? or sanitizer issue
char toggle_state_text[2][4] =
    {
        [false] = "--",
        [true] = "ON",
};

__declspec(dllexport) APP_TICK(server_tick)
{
    App_State *app_state = app_memory->app_state;
    if (!app_state)
    {
        app_state = app_memory->app_state = arena_bootstrap_push_struct(app_memory->backing_memory.data,
                                                                        app_memory->backing_memory.size,
                                                                        "Total",
                                                                        App_State,
                                                                        arena_total);
        app_state->platform_api = &app_memory->platform_api;
        app_state->tick_ms = &app_memory->tick_ms;
        app_state->work_ms = &app_memory->work_ms;
        app_state->tick_count = &app_memory->tick_count;
        app_state->key_states = &app_memory->key_states;

#if defined(TERMINAL_UI)
        Buffer screen =
            {
                .size = sizeof(char) * SCREEN_RESOLUTION,
                .data = arena_push_size(&app_state->arena_total,
                                        screen.size),
            };
        app_state->screen = app_memory->screen = screen;
        // core_memory_fill(app_state->screen.data, ' ', app_state->screen.size);
#endif // TERMINAL_UI

        Buffer per_tick_backing_memory =
            {
                .size = MB(10),
                .data = arena_push_size(&app_state->arena_total,
                                        per_tick_backing_memory.size),
            };

        app_state->stream_function_table = arena_push_struct(&app_state->arena_total, Stream_Function_Table);
        app_state->stream_function_table->game_input_ack = on_input_stream_ack;
        app_state->stream_function_table->game_input_data = on_input_stream_data;
        app_state->stream_function_table->game_output_data = on_output_stream_data;
        app_state->stream_function_table->ping_input_data = on_ping_input_stream_data;

        app_state->arena_per_tick =
            (Arena){
                .buffer = per_tick_backing_memory.data,
                .capacity = per_tick_backing_memory.size,
                .name = "Tick",
            };

        u8 rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
        app_state->rc4_key_decoded_length = util_base64_decode((u8 *)rc4_key_encoded,
                                                               sizeof(rc4_key_encoded) - 1,
                                                               app_state->rc4_key_decoded);

        app_state->connection_args.udp_length = MAX_PACKET_LENGTH;
        // TODO(rhett): encryption should probably be kept disabled initially and toggled on in higher layers
        // app_state->connection_args.use_encryption = false;
        app_state->connection_args.should_dump_core = true;
        app_state->connection_args.should_dump_login = true;
        app_state->connection_args.should_dump_tunnel = true;
        app_state->connection_args.should_dump_gateway = true;
        app_state->connection_args.should_dump_zone = true;

        app_state->sessions_capacity = MAX_SESSIONS_COUNT;
        app_state->socket = app_state->platform_api->socket_udp_create_and_bind(LOCAL_PORT);
        printf(MESSAGE_CONCAT_INFO("Game server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n"));
        app_state->platform_api->folder_create("packets");
    }

    /*
    (doggo)not needed right now, since I don't compile when the server is up and the game is running /shrug!

    if (session_state->should_reload)
    {
        printf(MESSAGE_CONCAT_INFO("Reloading function table...\n"));
        app_state->stream_function_table->game_input_ack = on_input_stream_ack;
        app_state->stream_function_table->game_input_data = on_input_stream_data;
        app_state->stream_function_table->game_output_data = on_output_stream_data;
        app_state->stream_function_table->ping_input_data = on_ping_input_stream_data;
    }
    */

    // app_state->platform_api->buffer_write_to_file("STATE.dump",
    //(u8*)app_state,
    // sizeof(App_State));

    global_tick_count = *app_state->tick_count;

#if defined(TERMINAL_UI)
    core_memory_fill(app_state->screen.data, ' ', app_state->screen.size);
    stbsp_sprintf((char *)app_state->screen.data,
                  "Tick: %llu    %fms/w | %fms/f", *app_state->tick_count, *app_state->work_ms, *app_state->tick_ms);

    i32 pos = 0;
    for (i32 key = 0; key < 0xff; key++)
    {
        pos += stbsp_sprintf((char *)(app_state->screen.data + (SCREEN_WIDTH * 2) + pos),
                             "K%02x %s  ",
                             key,
                             toggle_state_text[(*app_state->key_states)[key]]);
    }

    // pos = SCREEN_WIDTH * 29;
    // pos += stbsp_sprintf((char*)(app_state->screen.data + pos),
    //"cool :)");
#endif // TERMINAL_UI

    u8 incoming_buffer[MAX_PACKET_LENGTH] = {0};
    u32 from_ip;
    u16 from_port;
    i32 receive_result = app_state->platform_api->receive_from(app_state->socket,
                                                               incoming_buffer,
                                                               MAX_PACKET_LENGTH,
                                                               &from_ip,
                                                               &from_port);

    if (receive_result)
    {
        printf("\n\nPacket Tick Begin ============================================================\\\\\n");

        Session_Address incoming_session_address =
            {
                .ip = from_ip,
                .port = from_port,
            };

        // TODO(rhett): Before we tackle the problem of multiple clients, let's reliably handle one first
        // TODO(rhett): will need cleaned up
        i32 first_free_session = -1;
        i32 known_session = -1;
        for (i32 i = 0; i < app_state->sessions_capacity; i++)
        {
            if (first_free_session == -1 && !app_state->sessions[i].address.full)
            {
                first_free_session = i;
            }

            if (known_session == -1 && incoming_session_address.full == app_state->sessions[i].address.full)
            {
                known_session = i;
            }

            if (first_free_session != -1 && known_session != -1)
            {
                break;
            }
        }

        if (core_packet_get_kind(incoming_buffer, receive_result) == Core_Packet_Kind_Session_Request)
        {
            if (known_session != -1)
            {
                printf(MESSAGE_CONCAT_INFO("Known client %u.%u.%u.%u:%u re-sent SessionRequest\n"),
                       (from_ip & 0xff000000) >> 24,
                       (from_ip & 0x00ff0000) >> 16,
                       (from_ip & 0x0000ff00) >> 8,
                       (from_ip & 0x000000ff),
                       from_port);
            }
            else
            {
                printf(MESSAGE_CONCAT_INFO("Unknown client %u.%u.%u.%u:%u sent SessionRequest. Beginning session\n"),
                       (from_ip & 0xff000000) >> 24,
                       (from_ip & 0x00ff0000) >> 16,
                       (from_ip & 0x0000ff00) >> 8,
                       (from_ip & 0x000000ff),
                       from_port);

                if (first_free_session == -1)
                {
                    printf(MESSAGE_CONCAT_WARN("No free sessions avaliable\n"));
                }
                else
                {
                    known_session = first_free_session;
                    app_state->sessions[first_free_session].address.full = incoming_session_address.full;
                    app_state->sessions[first_free_session].ack_next = -1;
                    app_state->sessions[first_free_session].ack_previous = -1;

                    base_memory_copy((void *)&app_state->sessions[first_free_session].connection_args,
                                     (void *)&app_state->connection_args,
                                     sizeof(app_state->connection_args));

                    // TODO(rhett): These fragment pools will leak memory. this whole system needs refactored
                    app_state->sessions[first_free_session].input_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
                                                                                                       MAX_PACKET_LENGTH,
                                                                                                       &app_state->arena_total);
                    app_state->sessions[first_free_session].output_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
                                                                                                        MAX_PACKET_LENGTH - DATA_HEADER_LENGTH,
                                                                                                        &app_state->arena_total);
                    app_state->sessions[first_free_session].input_stream = input_stream_init(&app_state->sessions[first_free_session].input_fragment_pool,
                                                                                             app_state->rc4_key_decoded,
                                                                                             app_state->rc4_key_decoded_length,
                                                                                             false);
                    app_state->sessions[first_free_session].output_stream = output_stream_init(&app_state->sessions[first_free_session].output_fragment_pool,
                                                                                               app_state->rc4_key_decoded,
                                                                                               app_state->rc4_key_decoded_length,
                                                                                               false);

                    app_state->sessions[first_free_session].input_stream.ack_callback_ptr = &app_state->stream_function_table->game_input_ack;
                    app_state->sessions[first_free_session].input_stream.data_callback_ptr = &app_state->stream_function_table->game_input_data;
                    app_state->sessions[first_free_session].output_stream.data_callback_ptr = &app_state->stream_function_table->game_output_data;
                }
            }
        }

        if (known_session != -1)
        {
            if (app_state->sessions[known_session].kind == Session_Kind_Ping_Responder)
            {
                // ping_packet_handle(app_state,
                //&app_state->sessions[known_session],
                // incoming_buffer,
                // receive_result);
            }
            else
            {
                core_packet_handle(app_state, app_state->platform_api, &app_state->sessions[known_session], incoming_buffer, receive_result, false);
            }

            if (app_state->sessions[known_session].ack_previous != app_state->sessions[known_session].ack_next)
            {
                printf(MESSAGE_CONCAT_INFO("Syncing ack...\n"));
                app_state->sessions[known_session].ack_previous = app_state->sessions[known_session].ack_next;

                Ack ack =
                    {
                        .sequence = (u16)app_state->sessions[known_session].ack_next};

                core_packet_send(app_state->socket,
                                 app_state->platform_api,
                                 app_state->sessions[known_session].address.ip,
                                 app_state->sessions[known_session].address.port,
                                 &app_state->sessions[known_session].connection_args,
                                 Core_Packet_Kind_Ack,
                                 &ack);
            }
        }

        ////// TODO(rhett): SHELVING THIS FOR NOW
        // TODO(rhett): think about when we should process our packet queue
        // TODO(rhett): we also should have a way to time this,
        //              probably through the platform api
        // TODO(rhett): processing one normal packet per tick for now
        // if (app_state->packet_queue.entries_tail > 0)
        //{
        // packet_queue_pop_and_send(&app_state->packet_queue,
        //                     app_state);
        //                     //&app_state->arena_per_frame,
        //                     //app_state->server_packet_send);
        //
        ////Packet_Queue_Entry normal_packet_entry = packet_queue_pop(&app_state->packet_queue);
        ////zone_packet_send(app_state,
        //			//normal_packet_entry.session_state,
        //			//&app_state->arena_per_frame,
        //			//normal_packet_entry.max_packed_length,
        //			//normal_packet_entry.packet_kind,
        //			//app_state->packet_queue.buffer + normal_packet_entry.buffer_offset);
        //}

        printf("Packet Tick End ==============================================================//\n");
    }

    arena_reset(&app_state->arena_per_tick);
}
