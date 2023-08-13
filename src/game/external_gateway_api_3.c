#define TUNNEL_DATA_HEADER_LENGTH 1

#define GATEWAY_LOGINREQUEST_ID 0x1
#define GATEWAY_LOGINREPLY_ID 0x2
#define GATEWAY_TUNNELPACKETTOEXTERNALCONNECTION_ID 0x5
#define GATEWAY_TUNNELPACKETFROMEXTERNALCONNECTION_ID 0x6
#define GATEWAY_CHANNELISROUTABLE_ID 0x7

#define GATEWAY_PACKET_KINDS                                                                                               \
    GATEWAY_PACKET_KIND(Gateway_Packet_Kind_Unhandled, "Unhandled"),                                                       \
        GATEWAY_PACKET_KIND(Gateway_Packet_Kind_LoginRequest, "LoginRequest"),                                             \
        GATEWAY_PACKET_KIND(Gateway_Packet_Kind_LoginReply, "LoginReply"),                                                 \
        GATEWAY_PACKET_KIND(Gateway_Packet_Kind_TunnelPacketToExternalConnection, "TunnelPacketToExternalConnection"),     \
        GATEWAY_PACKET_KIND(Gateway_Packet_Kind_TunnelPacketFromExternalConnection, "TunnelPacketFromExternalConnection"), \
        GATEWAY_PACKET_KIND(Gateway_Packet_Kind_ChannelIsRoutable, "ChannelIsRoutable"),                                   \
        GATEWAY_PACKET_KIND(Gateway_Packet_Kind__End, "")

typedef enum Gateway_Packet_Kind {
#define GATEWAY_PACKET_KIND(e, s) e
    GATEWAY_PACKET_KINDS
#undef GATEWAY_PACKET_KIND
} Gateway_Packet_Kind;

char* gateway_packet_names[Gateway_Packet_Kind__End + 1] = {
#define GATEWAY_PACKET_KIND(e, s) s
    GATEWAY_PACKET_KINDS
#undef GATEWAY_PACKET_KIND
};

typedef struct Gateway_Packet_LoginRequest Gateway_Packet_LoginRequest;
struct Gateway_Packet_LoginRequest {
    u64 character_id;
    u32 server_ticket_length;
    char* server_ticket;
    u32 client_protocol_length;
    char* client_protocol;
    u32 client_build_length;
    char* client_build;
};

typedef struct Gateway_Packet_LoginReply Gateway_Packet_LoginReply;
struct Gateway_Packet_LoginReply {
    b8 is_logged_in;
};

typedef struct Gateway_Packet_TunnelPacket Gateway_Packet_TunnelPacket;
struct Gateway_Packet_TunnelPacket {
    u8 channel;

    u32 data_length;
    u8* data;
};

typedef struct Gateway_Packet_ChannelIsRoutable Gateway_Packet_ChannelIsRoutable;
struct Gateway_Packet_ChannelIsRoutable {
    u8 channel;

    b8 is_routable;
    b8 unk_bool;
};

internal u32 gateway_packet_pack(Gateway_Packet_Kind packet_kind,
    void* packet_ptr,
    u8* buffer)
{
    u32 offset = 0;

    printf("\n");
    switch (packet_kind) {
    case Gateway_Packet_Kind_LoginRequest: {
        printf(MESSAGE_CONCAT_INFO("Packing LoginRequest...\n"));
        Gateway_Packet_LoginRequest* packet = packet_ptr;

        endian_write_u8_little(buffer + offset, GATEWAY_LOGINREQUEST_ID);
        offset++;

        // u64 character_id
        endian_write_u64_little(buffer + offset, packet->character_id);
        offset += sizeof(u64);
        printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

        // string server_ticket
        endian_write_u32_little(buffer + offset, packet->server_ticket_length);
        offset += sizeof(u32);
        printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->server_ticket_length, (u64)packet->server_ticket_length, (f64)packet->server_ticket_length);
        for (u32 server_ticket_iter = 0; server_ticket_iter < packet->server_ticket_length; server_ticket_iter++) {
            endian_write_i8_little(buffer + offset, packet->server_ticket[server_ticket_iter]);
            offset++;
        }

        // string client_protocol
        endian_write_u32_little(buffer + offset, packet->client_protocol_length);
        offset += sizeof(u32);
        printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->client_protocol_length, (u64)packet->client_protocol_length, (f64)packet->client_protocol_length);
        for (u32 client_protocol_iter = 0; client_protocol_iter < packet->client_protocol_length; client_protocol_iter++) {
            endian_write_i8_little(buffer + offset, packet->client_protocol[client_protocol_iter]);
            offset++;
        }

        // string client_build
        endian_write_u32_little(buffer + offset, packet->client_build_length);
        offset += sizeof(u32);
        printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->client_build_length, (u64)packet->client_build_length, (f64)packet->client_build_length);
        for (u32 client_build_iter = 0; client_build_iter < packet->client_build_length; client_build_iter++) {
            endian_write_i8_little(buffer + offset, packet->client_build[client_build_iter]);
            offset++;
        }

    } break;

    case Gateway_Packet_Kind_LoginReply: {
        printf(MESSAGE_CONCAT_INFO("Packing LoginReply...\n"));
        Gateway_Packet_LoginReply* packet = packet_ptr;

        endian_write_u8_little(buffer + offset, GATEWAY_LOGINREPLY_ID);
        offset++;

        // b8 is_logged_in
        endian_write_b8_little(buffer + offset, packet->is_logged_in);
        offset += sizeof(b8);
        printf("-- is_logged_in            \t%lld\t%llxh\t%f\n", (i64)packet->is_logged_in, (u64)packet->is_logged_in, (f64)packet->is_logged_in);

    } break;

    case Gateway_Packet_Kind_TunnelPacketToExternalConnection:
    case Gateway_Packet_Kind_TunnelPacketFromExternalConnection: {
        // NOTE(rhett): To avoid allocating a buffer for a full packet twice,
        //              assume the passed buffer already includes the tunnel data
        printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), gateway_packet_names[packet_kind]);
        Gateway_Packet_TunnelPacket* packet = packet_ptr;

        u8 opcode;
        if (packet_kind == Gateway_Packet_Kind_TunnelPacketToExternalConnection) {
            opcode = GATEWAY_TUNNELPACKETTOEXTERNALCONNECTION_ID;
        } else if (packet_kind == Gateway_Packet_Kind_TunnelPacketFromExternalConnection) {
            opcode = GATEWAY_TUNNELPACKETFROMEXTERNALCONNECTION_ID;
        } else {
            opcode = 0;
            ABORT_MSG("Packing unknown TunnelPacket");
            // printf("[X] Packing unknown TunnelPacket\n");
            // abort();
        }

        endian_write_u8_little(buffer + offset, opcode | (packet->channel << 5));
        offset++;
        printf("-- channel                 \t%lld\t%llxh\t%f\n", (i64)packet->channel, (u64)packet->channel, (f64)packet->channel);

        // util_memory_copy(buffer + offset, packet->data, packet->data_length);
        offset += packet->data_length;

    } break;

    case Gateway_Packet_Kind_ChannelIsRoutable: {
        printf(MESSAGE_CONCAT_INFO("Packing ChannelIsRoutable...\n"));
        Gateway_Packet_ChannelIsRoutable* packet = packet_ptr;

        endian_write_u8_little(buffer + offset, GATEWAY_CHANNELISROUTABLE_ID | (packet->channel << 5));
        offset++;
        printf("-- channel                 \t%lld\t%llxh\t%f\n", (i64)packet->channel, (u64)packet->channel, (f64)packet->channel);

        // b8 is_logged_in
        endian_write_b8_little(buffer + offset, packet->is_routable);
        offset += sizeof(b8);
        printf("-- is_routable             \t%lld\t%llxh\t%f\n", (i64)packet->is_routable, (u64)packet->is_routable, (f64)packet->is_routable);

        // b8 unk_bool
        endian_write_b8_little(buffer + offset, packet->unk_bool);
        offset += sizeof(b8);
        printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

    } break;

    default: {
        printf(MESSAGE_CONCAT_WARN("Packing %s not implemented\n"), gateway_packet_names[packet_kind]);
    }
    }
    return offset;
}

internal void gateway_packet_unpack(u8* data,
    u32 data_length,
    Gateway_Packet_Kind packet_kind,
    void* packet_ptr,
    Arena* arena)
{
    u32 offset = 1;

    printf("\n");
    switch (packet_kind) {
    case Gateway_Packet_Kind_LoginRequest: {
        printf(MESSAGE_CONCAT_INFO("Unpacking LoginRequest...\n"));
        Gateway_Packet_LoginRequest* packet = packet_ptr;

        // u64 character_id
        packet->character_id = endian_read_u64_little(data + offset);
        offset += sizeof(u64);
        printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

        // string server_ticket
        packet->server_ticket_length = endian_read_u32_little(data + offset);
        offset += sizeof(u32);
        packet->server_ticket = arena_push_size(arena, packet->server_ticket_length);
        printf("-- STRING_LENGTH           \t%d\n", packet->server_ticket_length);
        for (u32 server_ticket_iter = 0; server_ticket_iter < packet->server_ticket_length; server_ticket_iter++) {
            packet->server_ticket[server_ticket_iter] = *(i8*)((uptr)data + offset);
            offset++;
        }

        // string client_protocol
        packet->client_protocol_length = endian_read_u32_little(data + offset);
        offset += sizeof(u32);
        packet->client_protocol = arena_push_size(arena, packet->client_protocol_length);
        printf("-- STRING_LENGTH           \t%d\n", packet->client_protocol_length);
        for (u32 client_protocol_iter = 0; client_protocol_iter < packet->client_protocol_length; client_protocol_iter++) {
            packet->client_protocol[client_protocol_iter] = *(i8*)((uptr)data + offset);
            offset++;
        }

        // string client_build
        packet->client_build_length = endian_read_u32_little(data + offset);
        offset += sizeof(u32);
        packet->client_build = arena_push_size(arena, packet->client_build_length);
        printf("-- STRING_LENGTH           \t%d\n", packet->client_build_length);
        for (u32 client_build_iter = 0; client_build_iter < packet->client_build_length; client_build_iter++) {
            packet->client_build[client_build_iter] = *(i8*)((uptr)data + offset);
            offset++;
        }

    } break;

    case Gateway_Packet_Kind_LoginReply: {
        printf(MESSAGE_CONCAT_INFO("Unpacking LoginReply...\n"));
        Gateway_Packet_LoginReply* packet = packet_ptr;

        // b8 is_logged_in
        packet->is_logged_in = endian_read_b8_little(data + offset);
        offset += sizeof(b8);
        printf("-- is_logged_in            \t%lld\t%llxh\t%f\n", (i64)packet->is_logged_in, (u64)packet->is_logged_in, (f64)packet->is_logged_in);

    } break;

    case Gateway_Packet_Kind_TunnelPacketFromExternalConnection: {
        printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), gateway_packet_names[packet_kind]);
        Gateway_Packet_TunnelPacket* packet = packet_ptr;

        packet->channel = (*data) >> 5;
        packet->data = data + offset;
        packet->data_length = data_length - 1;

    } break;

    default: {
        printf(MESSAGE_CONCAT_WARN("Unpacking %s not implemented\n"), gateway_packet_names[packet_kind]);
    }
    }
}

internal void gateway_tunnel_data_send(App_State* server_state,
    Session_State* session_state,
    u8* base_buffer,
    u32 total_length)
{
    // NOTE(rhett): Assumes the passed buffer is prefixed with
    //              enough space for the tunnel data header
    Gateway_Packet_TunnelPacket tunnel_packet = {
        .channel = 0,
        .data = base_buffer + TUNNEL_DATA_HEADER_LENGTH,
        .data_length = total_length - TUNNEL_DATA_HEADER_LENGTH,
    };

    // u8* packed_buffer = arena_allocate(arena, max_length);
    u32 packed_length = gateway_packet_pack(Gateway_Packet_Kind_TunnelPacketToExternalConnection,
        &tunnel_packet,
        base_buffer);

    // NOTE(rhett): leave room for an extra zero at the beginning
    // TODO(rhett): or not?
    // packed_buffer++;

    if (session_state->connection_args.should_dump_tunnel) {
        char dump_path[256] = { 0 };
        stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_S_tunneldata_%u.bin", global_tick_count, global_packet_dump_count++, tunnel_packet.channel);
        server_state->platform_api->buffer_write_to_file(dump_path, base_buffer, packed_length);
    }

    output_stream_write(&session_state->output_stream,
        base_buffer,
        packed_length,
        false,
        server_state,
        session_state);
}

internal void gateway_packet_send(App_State* server_state,
    Session_State* session_state,
    Arena* arena,
    u32 max_length,
    Gateway_Packet_Kind packet_kind,
    void* packet_ptr)
{
    u8* packed_buffer = arena_push_size(arena, max_length);
    u32 packed_length = gateway_packet_pack(packet_kind,
        packet_ptr,
        packed_buffer);

    // NOTE(rhett): Leave room for an extra zero at the beginning
    // packed_buffer++;

    if (session_state->connection_args.should_dump_gateway) {
        char dump_path[256] = { 0 };
        stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_S_gateway_%s.bin", global_tick_count, global_packet_dump_count++, gateway_packet_names[packet_kind]);
        server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
    }

    output_stream_write(&session_state->output_stream,
        packed_buffer,
        packed_length,
        false,
        server_state,
        session_state);
}

internal void gateway_packet_handle(App_State* server_state,
    Session_State* session_state,
    u8* data,
    u32 data_length)
{
    Gateway_Packet_Kind packet_kind;

    printf("\n");
    // TODO(rhett): opcode may have variable length
    u8 channel = *data >> 5;
    u8 packet_id = *data & 0b00011111;
    switch (packet_id) {
    case GATEWAY_LOGINREQUEST_ID: {
        packet_kind = Gateway_Packet_Kind_LoginRequest;
        printf(MESSAGE_CONCAT_INFO("(%u) Handling %s...\n"), channel, gateway_packet_names[packet_kind]);

        if (session_state->connection_args.should_dump_gateway) {
            char dump_path[256] = { 0 };
            stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_gateway_%u_%s.bin", global_tick_count, global_packet_dump_count++, channel, gateway_packet_names[packet_kind]);
            server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
        }

        Gateway_Packet_LoginRequest packet = { 0 };
        gateway_packet_unpack(data, data_length, packet_kind, &packet, &server_state->arena_per_tick);

        printf("[*] Enabling encryption for session\n");
        session_state->input_stream.use_encryption = true;
        session_state->output_stream.use_encryption = true;

        Gateway_Packet_LoginReply login_reply = {
            .is_logged_in = true,
        };
        gateway_packet_send(server_state, session_state, &server_state->arena_per_tick, 32, Gateway_Packet_Kind_LoginReply, &login_reply);

        Gateway_Packet_ChannelIsRoutable channel_is_routable_0 = {
            .channel = 0,
            .is_routable = true,
        };
        gateway_packet_send(server_state, session_state, &server_state->arena_per_tick, 32, Gateway_Packet_Kind_ChannelIsRoutable, &channel_is_routable_0);

        Gateway_Packet_ChannelIsRoutable channel_is_routable_1 = {
            .channel = 1,
            .is_routable = true,
        };
        gateway_packet_send(server_state, session_state, &server_state->arena_per_tick, 32, Gateway_Packet_Kind_ChannelIsRoutable, &channel_is_routable_1);

        gateway_on_login(server_state, session_state);
    } break;

    case GATEWAY_TUNNELPACKETFROMEXTERNALCONNECTION_ID: {
        packet_kind = Gateway_Packet_Kind_TunnelPacketFromExternalConnection;
        printf(MESSAGE_CONCAT_INFO("(%u) Handling %s...\n"), channel, gateway_packet_names[packet_kind]);

        if (session_state->connection_args.should_dump_gateway) {
            char dump_path[256] = { 0 };
            stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_gateway_%u_%s.bin", global_tick_count, global_packet_dump_count++, channel, gateway_packet_names[packet_kind]);
            server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
        }

        Gateway_Packet_TunnelPacket tunnel_data = { 0 };
        gateway_packet_unpack(data, data_length, Gateway_Packet_Kind_TunnelPacketFromExternalConnection, &tunnel_data, &server_state->arena_per_tick);

        if (session_state->connection_args.should_dump_tunnel) {
            char dump_path[256] = { 0 };
            stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_tunneldata_%u.bin", global_tick_count, global_packet_dump_count++, tunnel_data.channel);
            server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
        }

        gateway_on_tunnel_data_from_client(server_state, session_state, tunnel_data.data, tunnel_data.data_length);
    } break;

    default: {
        packet_kind = Gateway_Packet_Kind_Unhandled;
        printf(MESSAGE_CONCAT_WARN("(%u) Unhandled gateway packet 0x%02x\n"), channel, packet_id);

        if (session_state->connection_args.should_dump_gateway) {
            char dump_path[256] = { 0 };
            stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_gateway_%u_%s.bin", global_tick_count, global_packet_dump_count++, channel, gateway_packet_names[packet_kind]);
            server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
        }
    }
    }
}