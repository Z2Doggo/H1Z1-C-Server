internal u32 core_packet_pack(Core_Packet_Kind packet_kind, void* packet_ptr, u8* buffer, b32 is_sub_packet, Connection_Args* connection_args)
{
	u32 offset = 0;

	switch (packet_kind)
	{
		case Core_Packet_Kind_Session_Reply:
		{
			Session_Reply* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_SESSION_REPLY_ID);
			offset += 2;
			endian_write_u32_big(buffer + offset, packet->session_id);
			offset += 4;
			endian_write_u32_big(buffer + offset, packet->crc_seed);
			offset += 4;
			*(u8*)((uptr)buffer + offset) = packet->crc_length;
			offset += 1;
			*(u8*)((uptr)buffer + offset) = packet->compression;
			offset += 1;
			*(u8*)((uptr)buffer + offset) = packet->encryption;
			offset += 1;
			endian_write_u32_big(buffer + offset, packet->udp_length);
			offset += 4;
			endian_write_u32_big(buffer + offset, packet->soe_protocol_version);
			offset += 4;

			break;
		}
		case Core_Packet_Kind_Data:
		{
			Data* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_DATA_ID);
			offset += 2;
			if (connection_args->compression)
			{
				offset++;
			}
			endian_write_u16_big(buffer + offset, packet->sequence);
			offset += 2;
			memcpy(buffer + offset, packet->data, packet->data_length);
			offset += packet->data_length;

			if (!is_sub_packet && connection_args->crc_length)
			{
				offset += connection_args->crc_length;
			}

			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
			Data* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_DATA_FRAGMENT_ID);
			offset += 2;
			if (connection_args->compression)
			{
				offset++;
			}
			endian_write_u16_big(buffer + offset, packet->sequence);
			offset += 2;

			util_memory_copy(buffer + offset, packet->data, packet->data_length);
			offset += packet->data_length;

			if (!is_sub_packet && connection_args->crc_length)
			{
				offset += connection_args->crc_length;
			}

			break;
		}
		case Core_Packet_Kind_Ack:
		{
			Ack* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_ACK_ID);
			offset += 2;
			endian_write_u16_big(buffer + offset, packet->sequence);
			offset += 2;

			break;
		}
		default:
		{
			printf("[!] Packing %s not implemented\n", core_packet_names[packet_kind]);
		}
	}

	return offset;
}

internal void core_packet_unpack(u8* data, i32 data_length, Core_Packet_Kind packet_kind, void* packet_ptr, b32 is_sub_packet, Connection_Args* connection_args)
{
	u32 offset = 2;

	switch (packet_kind)
	{
		case Core_Packet_Kind_Session_Request:
		{
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
			// todo(chris): verify protocol

			break;
		}
		case Core_Packet_Kind_Session_Reply:
		{
			Session_Reply* packet = packet_ptr;

			packet->session_id = endian_read_u32_big(data + offset);
			offset += 4;
			packet->crc_seed = endian_read_u32_big(data + offset);
			offset += 4;
			packet->crc_length = *(u8*)(data + offset);
			offset += 1;
			packet->compression = *(u8*)(data + offset);
			offset += 1;
			packet->encryption = *(u8*)(data + offset);
			offset += 1;
			packet->udp_length = endian_read_u32_big(data + offset);
			offset += 4;
			packet->soe_protocol_version = endian_read_u32_big(data + offset);
			offset += 4;

			break;
		}
		case Core_Packet_Kind_Data:
		{
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

			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
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

			break;
		}
		case Core_Packet_Kind_Ack:
		{
			Ack* packet = packet_ptr;

			if (connection_args->compression && !is_sub_packet)
			{
				offset++;
			}

			packet->sequence = endian_read_u16_big(data + offset);
			offset += 2;

			break;
		}
		default:
		{
			printf("[!] Unpacking %s not implemented\n", core_packet_names[packet_kind]);
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
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, FALSE, connection_args);
			break;
		}
		case Core_Packet_Kind_Data:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, FALSE, connection_args);
			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, FALSE, connection_args);
			break;
		}
		case Core_Packet_Kind_Ack:
		{
			packed_length = core_packet_pack(packet_kind, packet_ptr, buffer, FALSE, connection_args);
			break;
		}
		default:
		{
			printf("[X] Unable to send unhandled packet: %d\n", packet_kind);
			abort();
			return;
		}
	}

	u32 sent_length = platform->send_to(socket, buffer, packed_length, ip, port);
	if (!sent_length)
	{
		printf("[!] Sent packet length is 0\n");
		return;
	}
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

internal void core_packet_handle(Server_State* server, Platform_Api* platform, Session_State* session, u8* data, u32 data_length, b32 is_sub_packet)
{
	Core_Packet_Kind packet_kind;
	u32 offset;

	u16 packet_id = endian_read_u16_big(data);
	switch (packet_id)
	{
		case CORE_SESSION_REQUEST_ID:
		{
			packet_kind = Core_Packet_Kind_Session_Request;

			Session_Request packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &server->connection_args);

			if (!packet.protocol_name[0])
			{
				// NOTE(rhett): Must be a ping responder, right?
				// TODO(rhett): also don't hardcode this here
				session->input_stream.data_callback = on_ping_input_stream_data;
				session->kind = Session_Kind_Ping_Responder;
			}

			session->id = packet.session_id;
			Session_Reply session_reply =
			{
				.session_id 	= packet.session_id,
				.crc_seed 		= session->connection_args.crc_seed,
				.crc_length 	= session->connection_args.crc_length,
				.compression 	= session->connection_args.compression,
				.encryption 	= server->connection_args.encryption,
				.udp_length 	= session->connection_args.udp_length,
				.soe_protocol_version = 3,
			};

			// todo: fix the encryption set
			if (strcmp(packet.protocol_name,"LoginUdp_11") == 0)
			{
				session->input_stream.use_encryption 	= TRUE;
				session->output_stream.use_encryption 	= TRUE;

				printf("[*] Enabling encryption for session\n");
			}

			core_packet_send(server->socket, platform, session->address.ip, session->address.port, &session->connection_args, Core_Packet_Kind_Session_Reply, &session_reply);

			break;
		}
		case CORE_DISCONNECT_ID:
		{
			packet_kind = Core_Packet_Kind_Disconnect;

			break;
		}
		case CORE_PING_ID:
		{
			packet_kind = Core_Packet_Kind_Ping;

			break;
		}
		case CORE_MULTI_PACKET_ID:
		{
			packet_kind = Core_Packet_Kind_Multi_Packet;

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

				core_packet_handle(server, platform, session, data + offset, chunk_length, TRUE);
				offset += chunk_length;
			}

			break;
		}
		case CORE_DATA_ID:
		{
			packet_kind = Core_Packet_Kind_Data;

			Data packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			input_stream_write(&session->input_stream, packet.data, packet.data_length, packet.sequence, FALSE, server, session);

			break;
		}
		case CORE_DATA_FRAGMENT_ID:
		{
			packet_kind = Core_Packet_Kind_Data_Fragment;

			// TODO(rhett): using a Data struct
			Data packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			input_stream_write(&session->input_stream, packet.data, packet.data_length, packet.sequence, TRUE, server, session);

			break;
		}
		case CORE_ACK_ID:
		{
			packet_kind = Core_Packet_Kind_Ack;

			Ack packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			// TODO(rhett): evaluate the mixing of signed and unsigned with ints of differing widths
			output_stream_ack_update(&session->output_stream, (i32)packet.sequence);

			break;
		}
		default:
		{
			packet_kind = Core_Packet_Kind_Unhandled;
			printf("[!] Unhandled core packet 0x%02x\n", packet_id);
		}
	}

	
}
#endif // FL_PROXY
