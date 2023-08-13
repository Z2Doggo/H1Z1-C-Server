#define printf(...)

internal u32 core_packet_pack(Core_Packet_Kind packet_kind, void* packet_ptr, u8* buffer, b32 is_sub_packet, Connection_Args* connection_args)
{
	u32 offset = 0;

	printf("\n");
	switch (packet_kind)
	{
		case Core_Packet_Kind_Session_Reply:
		{
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), core_packet_names[packet_kind]);
			Session_Reply* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_SESSION_REPLY_ID);
			offset += 2;
			endian_write_u32_big(buffer + offset, packet->session_id);
			offset += 4;
			endian_write_u32_big(buffer + offset, packet->crc_seed);
			offset += 4;
			*(u8*)((uptr)buffer + offset) = packet->crc_length;
			offset += 1;
			endian_write_u16_big(buffer + offset, packet->compression);
			offset += 2;
			endian_write_u32_big(buffer + offset, packet->udp_length);
			offset += 4;
			endian_write_u32_big(buffer + offset, packet->soe_protocol_version);
			offset += 4;

			printf("--- session_id: %d\n",   packet->session_id);
			printf("--- crc_seed: %d\n",     packet->crc_seed);
			printf("--- crc_length: %d\n",   packet->crc_length);
			printf("--- compression: %d\n",  packet->compression);
			printf("--- udp_length: %d\n",   packet->udp_length);
			printf("--- soe_protocol_version: %d\n",   packet->soe_protocol_version);

			break;
		}
		case Core_Packet_Kind_Data:
		{
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), core_packet_names[packet_kind]);
			Data* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_DATA_ID);
			offset += 2;
			if (connection_args->compression)
			{
				offset++;
			}
			endian_write_u16_big(buffer + offset, packet->sequence);
			offset += 2;
			base_memory_copy(buffer + offset, packet->data, packet->data_length);
			offset += packet->data_length;

			if (!is_sub_packet && connection_args->crc_length)
			{
				offset += connection_args->crc_length;
			}

			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), core_packet_names[packet_kind]);
			Data* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_DATA_FRAGMENT_ID);
			offset += 2;
			if (connection_args->compression)
			{
				offset++;
			}
			endian_write_u16_big(buffer + offset, packet->sequence);
			offset += 2;

			base_memory_copy(buffer + offset, packet->data, packet->data_length);
			offset += packet->data_length;

			if (!is_sub_packet && connection_args->crc_length)
			{
				offset += connection_args->crc_length;
			}

			break;
		}
		case Core_Packet_Kind_Ack:
		{
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), core_packet_names[packet_kind]);
			Ack* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_ACK_ID);
			offset += 2;
			endian_write_u16_big(buffer + offset, packet->sequence);
			offset += 2;

			printf("--- sequence: %d\n", packet->sequence);

			break;
		}
		default:
		{
			printf(MESSAGE_CONCAT_WARN("Packing %s not implemented\n"), core_packet_names[packet_kind]);
		}
	}

	return offset;
}

internal void core_packet_unpack(u8* data, i32 data_length, Core_Packet_Kind packet_kind, void* packet_ptr, b32 is_sub_packet, Connection_Args* connection_args)
{
	u32 offset = 2;

	printf("\n");
	switch (packet_kind)
	{
		case Core_Packet_Kind_Session_Request:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), core_packet_names[packet_kind]);
			Session_Request* packet = packet_ptr;

			packet->crc_length = endian_read_u32_big(data + offset);
			offset += 4;
			packet->session_id = endian_read_u32_big(data + offset);
			offset += 4;
			packet->udp_length = endian_read_u32_big(data + offset);
			offset += 4;

			// TODO(rhett): destroy the magic number. just max protocol name length
			for (i32 i = 0; i < 32; i++)
			{
				if (!*(u8*)(data + offset + i))
				{
					break;
				}

				packet->protocol_name[i] = *(u8*)(data + offset + i);
			}


			printf("%-16s %-20d\n", "crc_length", packet->crc_length);
			printf("%-16s %-20d\n", "session_id", packet->session_id);
			printf("%-16s %-20d\n", "udp_length", packet->udp_length);
			printf("%-16s %-20s\n", "protocol_name", packet->protocol_name);
			// TODO(rhett): Skipping protocol name for now

			break;
		}
		case Core_Packet_Kind_Session_Reply:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), core_packet_names[packet_kind]);
			Session_Reply* packet = packet_ptr;

			packet->session_id = endian_read_u32_big(data + offset);
			offset += 4;
			packet->crc_seed = endian_read_u32_big(data + offset);
			offset += 4;
			packet->crc_length = *(u8*)(data + offset);
			offset += 1;
			packet->compression = (u8)endian_read_u16_big(data + offset);
			offset += 2;
			packet->udp_length = endian_read_u32_big(data + offset);
			offset += 4;
			packet->soe_protocol_version = endian_read_u32_big(data + offset);
			offset += 4;

			printf("%-16s %-24d\n", "session_id",  packet->session_id);
			printf("%-16s %-24d\n", "crc_seed",    packet->crc_seed);
			printf("%-16s %-24d\n", "crc_length",  packet->crc_length);
			printf("%-16s %-24d\n", "compression", packet->compression);
			printf("%-16s %-24d\n", "udp_length",  packet->udp_length);
			printf("%-16s %-24d\n", "soe_protocol_version",  packet->soe_protocol_version);

			break;
		}
		case Core_Packet_Kind_Data:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), core_packet_names[packet_kind]);
			// TODO(rhett): using Data struct
			Data* packet = packet_ptr;

			if (connection_args->compression && !is_sub_packet)
			{
				// NOTE(rhett): Seems like we skip a byte
				offset++;
			}

			packet->sequence = endian_read_u16_big(data + offset);
			offset += 2;

			u32 data_end;
			if (is_sub_packet)
			{
				data_end = data_length;
			}
			else
			{
				data_end = data_length - connection_args->crc_length;
			}

			if (!is_sub_packet && connection_args->crc_length)
			{
				// TODO(rhett): Ignoring Crc right now
				// packet->crc = endian_read_u16_big(data + data_end);
			}

			packet->data = (u8*)((uptr)data + offset);
			packet->data_length = data_end - offset;

			printf("%-16s %-20d\n", "sequence",    packet->sequence);
			printf("%-16s %-20p\n", "data",        packet->data);
			printf("%-16s %-20d\n", "data_length", packet->data_length);
			printf("%-16s %-20x\n", "crc",         packet->crc);

			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), core_packet_names[packet_kind]);
			// TODO(rhett): using Data struct
			Data* packet = packet_ptr;

			if (connection_args->compression && !is_sub_packet)
			{
				// NOTE(rhett): Seems like we skip a byte
				offset++;
			}

			packet->sequence = endian_read_u16_big(data + offset);
			offset += 2;

			u32 fragment_end;
			if (is_sub_packet)
			{
				fragment_end = data_length;
			}
			else
			{
				fragment_end = data_length - connection_args->crc_length;
			}

			if (!is_sub_packet && connection_args->crc_length)
			{
				// TODO(rhett): Ignoring Crc for now
				// packet->crc = endian_read_u16_big(data + fragment_end);
			}

			packet->data = (u8*)((uptr)data + offset);
			packet->data_length = fragment_end - offset;

			printf("%-16s %-20d\n", "sequence",    packet->sequence);
			printf("%-16s %-20p\n", "data",        packet->data);
			printf("%-16s %-20d\n", "data_length", packet->data_length);
			printf("%-16s %-20x\n", "crc",         packet->crc);

			break;
		}
		case Core_Packet_Kind_Ack:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), core_packet_names[packet_kind]);
			Ack* packet = packet_ptr;

			if (connection_args->compression && !is_sub_packet)
			{
				offset++;
			}

			packet->sequence = endian_read_u16_big(data + offset);
			offset += 2;

			printf("--- sequence: %d\n", packet->sequence);

			break;
		}
		default:
		{
			printf(MESSAGE_CONCAT_WARN("Unpacking %s not implemented\n"), core_packet_names[packet_kind]);
		}
	}
}

#if !defined(FL_PROXY)
internal void core_packet_send(Platform_Socket socket, Platform_Api* platform, u32 ip, u16 port, Connection_Args* connection_args, Core_Packet_Kind packet_kind, void* packet_ptr)
{
	u8 buffer[MAX_PACKET_LENGTH] = { 0 };
	u32 packed_length;

	switch (packet_kind)
	{
		case Core_Packet_Kind_Session_Reply:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, false, connection_args);
			break;
		}
		case Core_Packet_Kind_Data:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, false, connection_args);
			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, false, connection_args);
			break;
		}
		case Core_Packet_Kind_Ack:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, false, connection_args);
			break;
		}
		default:
		{
			//printf("[X] Unable to send unhandled packet: %d\n", packet_kind);
			//abort();
			ABORT_MSG("Unable to send unhandled packet");
			return;
		}
	}

	if (connection_args->should_dump_core)
	{
		char dump_path[256] = { 0 };
		stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_S_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
		platform->buffer_write_to_file(dump_path, buffer, packed_length);
	}

	u32 sent_length = platform->send_to(socket, buffer, packed_length, ip, port);
	if (!sent_length)
	{
		printf(MESSAGE_CONCAT_WARN("Sent packet length is 0\n"));
		return;
	}
	printf("\n");
	printf(MESSAGE_CONCAT_INFO("Sent %d bytes to %u.%u.%u.%u:%u\n"),
	       sent_length,
	       (ip & 0xff000000) >> 24,
	       (ip & 0x00ff0000) >> 16,
	       (ip & 0x0000ff00) >> 8,
	       (ip & 0x000000ff),
	       port);

	
}

internal Core_Packet_Kind core_packet_get_kind(u8* data, u32 data_length)
{
	UNUSED(data_length);

	u16 packet_id = endian_read_u16_big(data);
	switch (packet_id)
	{
		case CORE_SESSION_REQUEST_ID:
		{
			return Core_Packet_Kind_Session_Request;
		}
	}
	return Core_Packet_Kind_Unhandled;
}

internal void core_packet_handle(App_State* app_state, Platform_Api* platform, Session_State* session, u8* data, u32 data_length, b32 is_sub_packet)
{
	Core_Packet_Kind packet_kind;
	u32 offset;

	printf("\n");
	if (is_sub_packet)
	{
		printf(MESSAGE_CONCAT_INFO("Is Subpacket:\n"));
	}
	u16 packet_id = endian_read_u16_big(data);
	switch (packet_id)
	{
		case CORE_SESSION_REQUEST_ID:
		{
			packet_kind = Core_Packet_Kind_Session_Request;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			Session_Request packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &app_state->connection_args);

			if (!packet.protocol_name[0])
			{
				// NOTE(rhett): Must be a ping responder, right?
				// TODO(rhett): also don't hardcode this here
				printf(MESSAGE_CONCAT_INFO("Switching to Ping Responder"));
				session->input_stream.data_callback_ptr = &app_state->stream_function_table->ping_input_data;
				session->kind = Session_Kind_Ping_Responder;
			}

			printf("\n");
			// TODO(rhett): vvv
			printf(MESSAGE_CONCAT_WARN("Ignoring connection args requested by client\n"));

			session->id = packet.session_id;
			Session_Reply session_reply =
			{
				.session_id = packet.session_id,
				.crc_seed = session->connection_args.crc_seed,
				.crc_length = session->connection_args.crc_length,
				.compression = session->connection_args.compression,
				.encryption = session->connection_args.encryption,
				.udp_length = session->connection_args.udp_length,
				.soe_protocol_version = 3,
			};

			if (strcmp(packet.protocol_name,"LoginUdp_11") == 0)
			{
				session->input_stream.use_encryption 	= true;
				session->output_stream.use_encryption 	= true;

				printf("[*] Enabling encryption for session\n");
			}

			core_packet_send(app_state->socket, platform, session->address.ip, session->address.port, &session->connection_args, Core_Packet_Kind_Session_Reply, &session_reply);

			break;
		}
		case CORE_DISCONNECT_ID:
		{
			packet_kind = Core_Packet_Kind_Disconnect;
			printf(MESSAGE_CONCAT_INFO("Received disconnect from client\n"));

			break;
		}
		case CORE_PING_ID:
		{
			packet_kind = Core_Packet_Kind_Ping;
			printf(MESSAGE_CONCAT_INFO("Received ping from client\n"));

			break;
		}
		case CORE_MULTI_PACKET_ID:
		{
			packet_kind = Core_Packet_Kind_Multi_Packet;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			offset = CORE_PACKET_ID_LENGTH;

			// TODO(rhett): Some parsing happens here, might not be worth making a case for it though
			if (session->connection_args.compression)
			{
				offset++;
			}

			while (offset < data_length - session->connection_args.crc_length)
			{
				u32 chunk_length;
				offset += input_stream_read_chunk_length((u8*)((uptr)data + offset), &chunk_length);

				core_packet_handle(app_state, platform, session, data + offset, chunk_length, true);
				offset += chunk_length;
			}

			break;
		}
		case CORE_DATA_ID:
		{
			packet_kind = Core_Packet_Kind_Data;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			Data packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			input_stream_write(&session->input_stream, packet.data, packet.data_length, packet.sequence, false, app_state, session);

			break;
		}
		case CORE_DATA_FRAGMENT_ID:
		{
			packet_kind = Core_Packet_Kind_Data_Fragment;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			// TODO(rhett): using a Data struct
			Data packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			input_stream_write(&session->input_stream, packet.data, packet.data_length, packet.sequence, true, app_state, session);

			break;
		}
		case CORE_ACK_ID:
		{
			packet_kind = Core_Packet_Kind_Ack;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			Ack packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			// TODO(rhett): evaluate the mixing of signed and unsigned with ints of differing widths
			output_stream_ack_update(&session->output_stream, (i32)packet.sequence);

			break;
		}
		default:
		{
			packet_kind = Core_Packet_Kind_Unhandled;
			printf(MESSAGE_CONCAT_WARN("Unhandled core packet 0x%02x\n"), packet_id);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}
		}
	}

	
}
#endif // FL_PROXY
#undef printf