// NOTE(rhett): ID is always u16 as far as I know
// TODO(rhett): maybe I'll try moving code that ever needs to change to
//								outside of the core protocol stuff. this shouldn't change between any
//								different forgelight games
#define MAX_PACKET_SIZE          512
#define CORE_PACKET_ID_SIZE      2
#define CORE_DATA_SEQUENCE_SIZE  2
// TODO(rhett): name????
#define CORE_DATA_FRAGMENT_EXTRA_SIZE  4
#define MAX_CORE_DATA_FRAGMENT_SIZE       (MAX_PACKET_SIZE - CORE_PACKET_ID_SIZE - CORE_DATA_SEQUENCE_SIZE)

#define CORE_PACKET_KINDS \
	CORE_PACKET_KIND(Core_Packet_Kind_Invalid,           0xffff,  "INVALID"), \
	CORE_PACKET_KIND(Core_Packet_Kind_SessionRequest,    0x0001,  "SessionRequest"), \
	CORE_PACKET_KIND(Core_Packet_Kind_SessionReply,      0x0002,  "SessionReply"), \
	CORE_PACKET_KIND(Core_Packet_Kind_MultiPacket,       0x0003,  "MultiPacket"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Disconnect,        0x0005,  "Disconnect"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Ping,              0x0006,  "Ping"), \
	CORE_PACKET_KIND(Core_Packet_Kind_NetStatusRequest,  0x0007,  "NetStatusRequest"), \
	CORE_PACKET_KIND(Core_Packet_Kind_NetStatusReply,    0x0008,  "NetStatusReply"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Data,              0x0009,  "Data"), \
	CORE_PACKET_KIND(Core_Packet_Kind_DataFragment,      0x000d,  "DataFragment"), \
	CORE_PACKET_KIND(Core_Packet_Kind_OutOfOrder,        0x0011,  "OutOfOrder"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Ack,               0x0015,  "Ack"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Unknown_1c,        0x001c,  "UNKNOWN_1C"), \
	CORE_PACKET_KIND(Core_Packet_Kind_FatalError,        0x001d,  "FatalError"), \
	CORE_PACKET_KIND(Core_Packet_Kind_FatalErrorReply,   0x001e,  "FatalErrorReply"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Unknown_1f,        0x001f,  "UNKNOWN_1F"), \
	CORE_PACKET_KIND(Core_Packet_Kind__End,              0xffff,  "")

		typedef enum Core_Packet_Kind
	{
#define CORE_PACKET_KIND(kind, id, str) kind
		CORE_PACKET_KINDS
#undef CORE_PACKET_KIND
	} Core_Packet_Kind;

	// NOTE(rhett): Invalid must be falsey
	STATIC_ASSERT(!Core_Packet_Kind_Invalid);

	// NOTE(rhett): for remedybg stuff
	global Core_Packet_Kind global_core_packet_kinds[Core_Packet_Kind__End + 1] =
	{
#define CORE_PACKET_KIND(kind, id, str) [kind] = kind
		CORE_PACKET_KINDS
#undef CORE_PACKET_KIND
	};

	// TODO(rhett): + 1 for here and not when used in iter? to skip __End?
	global u16 global_core_packet_ids[Core_Packet_Kind__End + 1] =
	{
#define CORE_PACKET_KIND(kind, id, str) [kind] = id
		CORE_PACKET_KINDS
#undef CORE_PACKET_KIND
	};

	global char* global_core_packet_names[Core_Packet_Kind__End + 1] =
	{
#define CORE_PACKET_KIND(kind, id, str) [kind] = str
		CORE_PACKET_KINDS
#undef CORE_PACKET_KIND
	};

	// TODO(rhett): Do I like this?
	global i32 global_core_packet_begin = Core_Packet_Kind_Invalid + 1;
	global i32 global_core_packet_count = Core_Packet_Kind__End;


	typedef struct Core_Packet_SessionRequest Core_Packet_SessionRequest;
	struct Core_Packet_SessionRequest
	{
		u32  crc_length;
		u32  session_id;
		u32  udp_length;
		char protocol_name[32]; // TODO(rhett): take another look at this later
	};

	typedef struct Core_Packet_SessionReply Core_Packet_SessionReply;
	struct Core_Packet_SessionReply
	{
		u32  session_id;
		u32  crc_seed;
		u8   crc_size;
		u16  compression;
		u32  udp_size;
	};

	// NOTE(rhett): Using Data struct for Data and Data Fragments
	typedef struct Core_Packet_Data Core_Packet_Data;
	struct Core_Packet_Data
	{
		u16 sequence;
		u8* data;
		u32 data_size;
		// TODO(rhett): Assuming short crc
		u16 crc;
	};

	typedef struct Core_Packet_Ack Core_Packet_Ack;
	struct Core_Packet_Ack
	{
		u16 sequence;
	};


// TODO(rhett): IMPLEMENT THIS
//global b32 global_is_sub_packet;

#define CORE_DATA_INPUT_CALLBACK(name)  void name(Buffer data_buffer, Session_Handle session_handle, App_State* app_state)
CORE_DATA_INPUT_CALLBACK(on_core_data_input);

// TODO(rhett): is this a common structure?
typedef struct Chunk_Size_Result Chunk_Size_Result;
struct Chunk_Size_Result
{
	Stream stream;
	u32 chunk_length;
};
Chunk_Size_Result protocol_core_chunk_size_read(Stream data_stream)
{
	u32 chunk_length = stream_read_u8_big(data_stream);
	if (chunk_length == 0xff)
	{
		if (stream_peek_u8_big(data_stream, 0) == 0xff && stream_peek_u8_big(data_stream, 1))
		{
			data_stream.cursor += 2;
			chunk_length = stream_read_u32_big(data_stream);
		}
		else if (stream_peek_u8_big(data_stream, 0) > 0)
		{
			data_stream.cursor++;
			chunk_length = stream_read_u16_big(data_stream);
		}
	}

	return (Chunk_Size_Result) { .stream = data_stream, .chunk_length = chunk_length };
}

void protocol_core_input_data_process_chunks(Buffer data_buffer,
                                             Protocol_Options protocol_options,
                                             Session_Handle session_handle,
                                             App_State* app_state)
{
	Stream data_stream =
	{
		.size = data_buffer.size,
		.data = data_buffer.data,
	};

	Session_State* session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);

	if (stream_peek_u8_big(data_stream, 0) == 0x0 && stream_peek_u8_big(data_stream, 1) == 0x19)
	{
		data_stream.cursor += 2;

		while (data_stream.cursor < data_stream.size)
		{
			Chunk_Size_Result chunk_length_result = protocol_core_chunk_size_read(data_stream);
			data_stream = chunk_length_result.stream;
	
			Buffer chunk_buffer =
			{
				.size = chunk_length_result.chunk_length,
				.data = (u8*)data_stream.data + data_stream.cursor,
			};

			if (protocol_options.use_encryption)
			{
				crypt_rc4_transform(&session->rc4_state_in, chunk_buffer.data, cast(u32)chunk_buffer.size);
				if (global_should_dump_core)
				{
					app_state->platform_api->folder_create(PACKET_FOLDER);
					char dump_path[64] = { 0 };
					stbsp_snprintf(dump_path,
					               SIZE_OF(dump_path),
					               PACKET_FOLDER "\\%llu_%llu_C_core_DataChunk_DECRYPT.bin",
					               global_tick_count,
					               global_dump_count++);
					app_state->platform_api->buffer_write_to_file(dump_path,
					                                              chunk_buffer.data,
					                                              cast(u32)chunk_buffer.size);
				}
			}
			on_core_data_input(chunk_buffer, session_handle, app_state);
			data_stream.cursor += chunk_length_result.chunk_length;
		}
	}
	else
	{
		if (protocol_options.use_encryption)
		{
			crypt_rc4_transform(&session->rc4_state_in, data_buffer.data, cast(u32)data_buffer.size);
			if (global_should_dump_core)
			{
				app_state->platform_api->folder_create(PACKET_FOLDER);
				char dump_path[64] = { 0 };
				stbsp_snprintf(dump_path,
				               SIZE_OF(dump_path),
				               PACKET_FOLDER "\\%llu_%llu_C_core_Data_DECRYPT.bin",
				               global_tick_count,
				               global_dump_count++);
				app_state->platform_api->buffer_write_to_file(dump_path,
				                                              data_buffer.data,
				                                              cast(u32)data_buffer.size);
			}
		}

		on_core_data_input(data_buffer, session_handle, app_state);
	}
}

// TODO(rhett): let's use a flat buffer for just now
Buffer protocol_core_input_data_accumulate(Core_Packet_Data data_packet, Session_Handle session_handle, App_State* app_state)
{
	// TEMPORARY(rhett):
	Buffer result = { 0 };

	Stream data_packet_stream =
	{
		.size = data_packet.data_size,
		.data = data_packet.data,
	};

	local_persist u32 target_size;
	local_persist b32 is_occupied;
	if (!is_occupied)
	{
		// TODO(rhett): if we clear the buffer we'll do it here
		is_occupied = TRUE;
		target_size = stream_read_u32_big(data_packet_stream);
	}
	base_memory_copy(STREAM_REMAINING_DATA(app_state->fragment_accumulator), STREAM_REMAINING_DATA(data_packet_stream), STREAM_REMAINING_SIZE(data_packet_stream));
	app_state->fragment_accumulator.cursor += STREAM_REMAINING_SIZE(data_packet_stream);

	if (app_state->fragment_accumulator.cursor == target_size)
	{
		result.data = app_state->fragment_accumulator.data;
		result.size = app_state->fragment_accumulator.cursor;
		app_state->fragment_accumulator.cursor = 0;
		is_occupied = FALSE;
		target_size = 0;
	}

	return result;
}

//Buffer protocol_core_input_data_assemble()
//{
	//NOT_IMPLEMENTED_MSG("we aren't receiving fragments yet to test");
//}

void protocol_core_input_data_intake(Core_Packet_Data data_packet,
                           				   b32 is_fragment,
                                     Session_Handle session_handle,
                                     App_State* app_state)
{
	Session_State* session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);
	if (data_packet.sequence != session->sequence_in + 1)
	{
		printf(MESSAGE_CONCAT_WARN("Sequence out of order. expected %d, got %u\n"),
		       session->sequence_in + 1,
		       data_packet.sequence);
		return;
	}
	// TODO(rhett): how will the game handle wrapping the ack counter?
	session->sequence_in++;

	if (is_fragment)
	{
		Buffer completed_data_buffer = protocol_core_input_data_accumulate(data_packet, session_handle, app_state);
		if (completed_data_buffer.size)
		{
			protocol_core_input_data_process_chunks(completed_data_buffer, session->protocol_options, session_handle, app_state);
		}
	}
	else
	{
		Buffer data_buffer =
		{
			.data = data_packet.data,
			.size = data_packet.data_size,
		};
		protocol_core_input_data_process_chunks(data_buffer, session->protocol_options, session_handle, app_state);
	}
}

Stream protocol_core_packet_unpack(Stream packet_stream, void* result_ptr, Core_Packet_Kind packet_kind, b32 is_sub_packet, Protocol_Options protocol_options)
{
	ASSERT(packet_stream.data);
	ASSERT(packet_stream.size);
	ASSERT(packet_stream.cursor == CORE_PACKET_ID_SIZE);
	ASSERT(result_ptr);
	// NOTE(rhett): valid oughta be truthy
	ASSERT(packet_kind);

	switch (packet_kind)
	{
		case Core_Packet_Kind_SessionRequest:
		{
			Core_Packet_SessionRequest* session_request = result_ptr;
			session_request->crc_length = stream_read_u32_big(packet_stream);
			session_request->session_id = stream_read_u32_big(packet_stream);
			session_request->udp_length = stream_read_u32_big(packet_stream);

			// TODO(rhett): destroy the magic number. just max protocol name length
			for (i64 i = 0; i < 32; packet_stream.cursor++, i++)
			{
				if (!*((u8*)packet_stream.data + packet_stream.cursor))
				{
					// NOTE(rhett): consume zero terminator
					packet_stream.cursor++;
					break;
				}

				session_request->protocol_name[i] = *((u8*)packet_stream.data + packet_stream.cursor);
			}
		} break;

		case Core_Packet_Kind_Ack:
		{
			Core_Packet_Ack* ack_packet = result_ptr;
			ack_packet->sequence = stream_read_u16_big(packet_stream);

		} break;

		// TODO(rhett): should be the same, right?
		case Core_Packet_Kind_Data: fallthrough;
		case Core_Packet_Kind_DataFragment:
		{
			Core_Packet_Data* data_packet = result_ptr;
			if (protocol_options.compression && !is_sub_packet)
			{
				packet_stream.cursor++;
			}

			data_packet->sequence = stream_read_u16_big(packet_stream);

			i64 data_end;
			if (is_sub_packet)
			{
				data_end = packet_stream.size;
			}
			else
			{
				data_end = packet_stream.size - protocol_options.crc_size;
			}

			if (!is_sub_packet && protocol_options.crc_size)
			{
				NOT_IMPLEMENTED_MSG("ignoring crc for now");
			}

			data_packet->data = (u8*)packet_stream.data + packet_stream.cursor;
			// TODO(rhett): assert there is enough room for the u32
			data_packet->data_size = cast(u32)(data_end - packet_stream.cursor);
			packet_stream.cursor += data_packet->data_size;
		} break;

		default:
		{
			NOT_IMPLEMENTED_MSG("unpacking not handled");
		}
	}

	return packet_stream;
}

// TODO(rhett): merge pack and send? do we ever pack without sending?
void protocol_core_packet_send(void* packet_ptr, Core_Packet_Kind packet_kind, Session_Handle session_handle, App_State* app_state)
{
	u8 buffer[MAX_PACKET_SIZE] = { 0 };
	Stream output_stream =
	{
		.size = SIZE_OF(buffer),
		.data = buffer,
	};

	// NOTE(rhett): packing
	Session_State* session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);
	switch (packet_kind)
	{
		case Core_Packet_Kind_SessionReply:
		{
			Core_Packet_SessionReply* session_reply = packet_ptr;

			stream_write_u16_big(output_stream, global_core_packet_ids[packet_kind]);
			stream_write_u32_big(output_stream, session_reply->session_id);
			stream_write_u32_big(output_stream, session_reply->crc_seed);
			stream_write_u8_big(output_stream, session_reply->crc_size);
			stream_write_u16_big(output_stream, session_reply->compression);
			stream_write_u32_big(output_stream, session_reply->udp_size);
		} break;

		case Core_Packet_Kind_Data: fallthrough;
		case Core_Packet_Kind_DataFragment:
		{
			Core_Packet_Data* data_packet = packet_ptr;

			stream_write_u16_big(output_stream, global_core_packet_ids[packet_kind]);
			if (session->protocol_options.compression)
			{
				output_stream.cursor++;
			}
			stream_write_u16_big(output_stream, data_packet->sequence);
			ASSERT(output_stream.size - output_stream.cursor >= data_packet->data_size);
			base_memory_copy((u8*)output_stream.data + output_stream.cursor, data_packet->data, data_packet->data_size);
			output_stream.cursor += data_packet->data_size;

			//if (!global_is_sub_packet && session->protocol_options.crc_size)
			if (session->protocol_options.crc_size)
			{
				NOT_IMPLEMENTED;
			}
		} break;

		case Core_Packet_Kind_Ack:
		{
			Core_Packet_Ack* ack_packet = packet_ptr;

			stream_write_u16_big(output_stream, global_core_packet_ids[packet_kind]);
			stream_write_u16_big(output_stream, ack_packet->sequence);

#if 0
			printf(MESSAGE_CONCAT_INFO("Sending ack %d\n"), ack_packet->sequence);
#endif
		} break;

		default:
		{
			NOT_IMPLEMENTED_MSG("sending not handled");
		}
	}

#if 1
	printf(MESSAGE_CONCAT_INFO("Sending %s...\n"), global_core_packet_names[packet_kind]);
	if (global_should_dump_core)
	{
		app_state->platform_api->folder_create(PACKET_FOLDER);
		char dump_path[64] = { 0 };
		stbsp_snprintf(dump_path,
		               SIZE_OF(dump_path),
		               PACKET_FOLDER "\\%llu_%llu_S_core_%s.bin",
		               global_tick_count,
		               global_dump_count++,
		               global_core_packet_names[packet_kind]);
		app_state->platform_api->buffer_write_to_file(dump_path,
		                                              output_stream.data,
		                                              cast(u32)output_stream.cursor);
	}

	i64 sent_size = app_state->platform_api->send_to(app_state->socket,
	                                                   output_stream.data,
	                                                   cast(u32)output_stream.cursor,
	                                                   session->address.ip,
	                                                   session->address.port);
	ASSERT(sent_size > 0);
	printf(MESSAGE_CONCAT_INFO("Sent %zd bytes to %#x@%u.%u.%u.%u:%u\n"),
	       sent_size,
	       session_handle.id,
	       (session->address.ip & 0xff000000) >> 24,
	       (session->address.ip & 0x00ff0000) >> 16,
	       (session->address.ip & 0x0000ff00) >> 8,
	       (session->address.ip & 0x000000ff),
	       session->address.port);
#endif
}

void protocol_core_data_send(Buffer data_buffer, b32 ignore_encryption, Session_Handle session_handle, App_State* app_state)
{
	Session_State* session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);


	Stream output_stream =
	{
		.size = data_buffer.size - CORE_DATA_FRAGMENT_EXTRA_SIZE,
		.data = data_buffer.data + CORE_DATA_FRAGMENT_EXTRA_SIZE,
	};

	if (!ignore_encryption && session->protocol_options.use_encryption)
	{
		crypt_rc4_transform(&session->rc4_state_out, output_stream.data, cast(u32)output_stream.size);
	}

	Core_Packet_Kind packet_kind = Core_Packet_Kind_Invalid;
	u32 packets_required = 0;
	if (output_stream.size <= MAX_CORE_DATA_FRAGMENT_SIZE)
	{
		packets_required = 1;
		packet_kind = Core_Packet_Kind_Data;
	}
	else
	{
		//------------------------------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------
		//// NOTE(rhett): REMOVE THIS CAST MADNESS
		//------------------------------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------
		// NOTE(rhett): fragmenting, so use extra space to prepend length
		output_stream.size += CORE_DATA_FRAGMENT_EXTRA_SIZE;
		output_stream.data = cast(void*)(cast(u64)output_stream.data - CORE_DATA_FRAGMENT_EXTRA_SIZE);

		endian_write_u32_big((u8*)output_stream.data, cast(u32)output_stream.size - CORE_DATA_FRAGMENT_EXTRA_SIZE);

		packets_required = (cast(u32)output_stream.size + MAX_CORE_DATA_FRAGMENT_SIZE - 1) / MAX_CORE_DATA_FRAGMENT_SIZE;
		packet_kind = Core_Packet_Kind_DataFragment;
	}
	ASSERT(packet_kind);

	for (i64 packet_iter = 0; packet_iter < packets_required; packet_iter++)
	{
		u32 size_to_write = MIN(MAX_CORE_DATA_FRAGMENT_SIZE, cast(u32)output_stream.size - cast(u32)output_stream.cursor);

		// NOTE(rhett): We start at sequence -1
		session->sequence_out++;
		Core_Packet_Data packet =
		{
			.sequence = cast(u16)session->sequence_out,
			.data = cast(u8*)output_stream.data + output_stream.cursor,
			.data_size = size_to_write,
		};
		protocol_core_packet_send(&packet, packet_kind, session_handle, app_state);
		output_stream.cursor += size_to_write;
	}
}

#define SESSION_ESTABLISHED_CALLBACK(name)  void name(Session_Handle session_handle, App_State* app_state)
SESSION_ESTABLISHED_CALLBACK(on_session_established);

void protocol_core_packet_route(Buffer packet_buffer, b32 is_sub_packet, Session_Handle session_handle, App_State* app_state)
{
	ASSERT(app_state);
	ASSERT(session_handle.id);
	ASSERT(packet_buffer.size >= CORE_PACKET_ID_SIZE);
	ASSERT(packet_buffer.data);

	Stream packet_stream =
	{
		.size = packet_buffer.size,
		.data = packet_buffer.data,
	};

	u16 packet_id = stream_read_u16_big(packet_stream);

	Core_Packet_Kind packet_kind = Core_Packet_Kind_Invalid;
	// TODO(rhett): Skip Invalid and __End?
	for (i32 kind_iter = global_core_packet_begin; kind_iter < global_core_packet_count; kind_iter++)
	{
		if (packet_id == global_core_packet_ids[kind_iter])
		{
			packet_kind = kind_iter;
			break;
		}
	}
	// NOTE(rhett): invalid should be falsey
	if (!packet_kind)
	{
		NOT_IMPLEMENTED_MSG("Invalid core packet");
	}

	if (global_should_dump_core)
	{
		app_state->platform_api->folder_create(PACKET_FOLDER);
		char dump_path[64] = { 0 };
		stbsp_snprintf(dump_path,
		               SIZE_OF(dump_path),
		               PACKET_FOLDER "\\%llu_%llu_C_core_%s.bin",
		               global_tick_count,
		               global_dump_count++,
		               global_core_packet_names[packet_kind]);
		app_state->platform_api->buffer_write_to_file(dump_path,
		                                              packet_buffer.data,
		                                              cast(u32)packet_buffer.size);
	}

	printf(MESSAGE_CONCAT_INFO("Routing %s...\n"), global_core_packet_names[packet_kind]);
	Session_State* session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);
	switch (packet_kind)
	{
		case Core_Packet_Kind_SessionRequest:
		{
			Core_Packet_SessionRequest packet = { 0 };
			packet_stream = protocol_core_packet_unpack(packet_stream, &packet, packet_kind, is_sub_packet, session->protocol_options);

			session->id = packet.session_id;

			// TEMP(rhett):
			if (!packet.protocol_name[0])
			{
				session->kind = Session_Kind_Ping_Responder;
			}

			Core_Packet_SessionReply reply =
			{
				.session_id = session->id,
				.crc_seed = session->protocol_options.crc_seed,
				.crc_size = session->protocol_options.crc_size,
				.compression = session->protocol_options.compression,
				.udp_size = session->protocol_options.udp_size,
			};
			protocol_core_packet_send(&reply, Core_Packet_Kind_SessionReply, session_handle, app_state);

			on_session_established(session_handle, app_state);
		} break;

#if 0
		case Core_Packet_Kind_Ack:
		{
			Core_Packet_Ack ack_packet = { 0 };
			packet_stream = protocol_core_packet_unpack(packet_stream, &ack_packet, packet_kind, global_is_sub_packet, session->protocol_options);

			printf(MESSAGE_CONCAT_INFO("Received ack %d\n"), ack_packet.sequence);

		} break;
#endif

		case Core_Packet_Kind_Data: fallthrough;
		case Core_Packet_Kind_DataFragment:
		{
			Core_Packet_Data packet = { 0 };
			packet_stream = protocol_core_packet_unpack(packet_stream, &packet, packet_kind, is_sub_packet, session->protocol_options);

			b32 is_fragment = packet_kind == Core_Packet_Kind_DataFragment;
			protocol_core_input_data_intake(packet, is_fragment, session_handle, app_state);
		} break;

		case Core_Packet_Kind_MultiPacket:
		{
			if (session->protocol_options.compression)
			{
				packet_stream.cursor++;
			}

			while (packet_stream.cursor < packet_stream.size - session->protocol_options.crc_size)
			{
				Chunk_Size_Result chunk_size_result = protocol_core_chunk_size_read(packet_stream);
				packet_stream = chunk_size_result.stream;

				Buffer chunk_buffer =
				{
					.size = chunk_size_result.chunk_length,
					.data = STREAM_REMAINING_DATA(packet_stream),
				};

				protocol_core_packet_route(chunk_buffer, TRUE, session_handle, app_state);
				packet_stream.cursor += chunk_size_result.chunk_length;
			}
		} break;

		default:
		{
			//NOT_IMPLEMENTED_MSG("routing not handled");
			return;
		}
	}

	ASSERT_MSG(packet_stream.cursor == packet_stream.size, "There is more data left?");
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
#if 0

internal u32 core_packet_pack(Core_Packet_Kind packet_kind, void* packet_ptr, u8* buffer, b32 is_sub_packet, Connection_Args* connection_args)
{
	u32 offset = 0;

	printf("\n");
	switch (packet_kind)
	{
		case Core_Packet_Kind_Session_Reply:
		{
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), global_core_packet_names[packet_kind]);
			Core_Packet_SessionReply* packet = packet_ptr;

			endian_write_u16_big(buffer + offset, CORE_SESSION_REPLY_ID);
			offset += 2;
			endian_write_u32_big(buffer + offset, packet->session_id);
			offset += 4;
			endian_write_u32_big(buffer + offset, packet->crc_seed);
			offset += 4;
			*(u8*)((u64)buffer + offset) = packet->crc_length;
			offset += 1;
			endian_write_u16_big(buffer + offset, packet->compression);
			offset += 2;
			endian_write_u32_big(buffer + offset, packet->udp_length);
			offset += 4;

			printf("--- session_id: %d\n",   packet->session_id);
			printf("--- crc_seed: %d\n",     packet->crc_seed);
			printf("--- crc_length: %d\n",   packet->crc_length);
			printf("--- compression: %d\n",  packet->compression);
			printf("--- udp_length: %d\n",   packet->udp_length);

			break;
		}
		case Core_Packet_Kind_Data:
		{
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), global_core_packet_names[packet_kind]);
			Core_Packet_Data* packet = packet_ptr;

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
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), global_core_packet_names[packet_kind]);
			Core_Packet_Data* packet = packet_ptr;

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
			printf(MESSAGE_CONCAT_INFO("Packing %s...\n"), global_core_packet_names[packet_kind]);
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
			printf(MESSAGE_CONCAT_WARN("Packing %s not implemented\n"), global_core_packet_names[packet_kind]);
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
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), global_core_packet_names[packet_kind]);
			Core_Packet_SessionRequest* packet = packet_ptr;

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
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), global_core_packet_names[packet_kind]);
			Core_Packet_SessionReply* packet = packet_ptr;

			packet->session_id = endian_read_u32_big(data + offset);
			offset += 4;
			packet->crc_seed = endian_read_u32_big(data + offset);
			offset += 4;
			packet->crc_length = *(u8*)(data + offset);
			offset += 1;
			packet->compression = endian_read_u16_big(data + offset);
			offset += 2;
			packet->udp_length = endian_read_u32_big(data + offset);
			offset += 4;

			printf("%-16s %-24d\n", "session_id",  packet->session_id);
			printf("%-16s %-24d\n", "crc_seed",    packet->crc_seed);
			printf("%-16s %-24d\n", "crc_length",  packet->crc_length);
			printf("%-16s %-24d\n", "compression", packet->compression);
			printf("%-16s %-24d\n", "udp_length",  packet->udp_length);

			break;
		}
		case Core_Packet_Kind_Data:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), global_core_packet_names[packet_kind]);
			// TODO(rhett): using Data struct
			Core_Packet_Data* packet = packet_ptr;

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

			packet->data = (u8*)((u64)data + offset);
			packet->data_length = data_end - offset;

			printf("%-16s %-20d\n", "sequence",    packet->sequence);
			printf("%-16s %-20p\n", "data",        packet->data);
			printf("%-16s %-20d\n", "data_length", packet->data_length);
			printf("%-16s %-20x\n", "crc",         packet->crc);

			break;
		}
		case Core_Packet_Kind_Data_Fragment:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), global_core_packet_names[packet_kind]);
			// TODO(rhett): using Data struct
			Core_Packet_Data* packet = packet_ptr;

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

			packet->data = (u8*)((u64)data + offset);
			packet->data_length = fragment_end - offset;

			printf("%-16s %-20d\n", "sequence",    packet->sequence);
			printf("%-16s %-20p\n", "data",        packet->data);
			printf("%-16s %-20d\n", "data_length", packet->data_length);
			printf("%-16s %-20x\n", "crc",         packet->crc);

			break;
		}
		case Core_Packet_Kind_Ack:
		{
			printf(MESSAGE_CONCAT_INFO("Unpacking %s...\n"), global_core_packet_names[packet_kind]);
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
			printf(MESSAGE_CONCAT_WARN("Unpacking %s not implemented\n"), global_core_packet_names[packet_kind]);
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
			//printf("[X] Unable to send unhandled packet: %d\n", packet_kind);
			//abort();
			ABORT_MSG("Unable to send unhandled packet");
			return;
		}
	}

	if (connection_args->should_dump_core)
	{
		char dump_path[256] = { 0 };
		stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_S_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
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
	return Core_Packet_Kind_Invalid;
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
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), global_core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			Core_Packet_SessionRequest packet = { 0 };
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
			Core_Packet_SessionReply session_reply =
			{
				.session_id = packet.session_id,
				.crc_seed = session->connection_args.crc_seed,
				.crc_length = session->connection_args.crc_length,
				.compression = session->connection_args.compression,
				.udp_length = session->connection_args.udp_length
			};

			//session->input_stream.use_encryption = TRUE;
			//session->output_stream.use_encryption = TRUE;
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
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), global_core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
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
				offset += input_stream_read_chunk_length((u8*)((u64)data + offset), &chunk_length);

				core_packet_handle(app_state, platform, session, data + offset, chunk_length, TRUE);
				offset += chunk_length;
			}

			break;
		}
		case CORE_DATA_ID:
		{
			packet_kind = Core_Packet_Kind_Data;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), global_core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			Core_Packet_Data packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			input_stream_write(&session->input_stream, packet.data, packet.data_length, packet.sequence, FALSE, app_state, session);

			break;
		}
		case CORE_DATA_FRAGMENT_ID:
		{
			packet_kind = Core_Packet_Kind_Data_Fragment;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), global_core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}

			// TODO(rhett): using a Data struct
			Core_Packet_Data packet = { 0 };
			core_packet_unpack(data, data_length, packet_kind, &packet, is_sub_packet, &session->connection_args);

			input_stream_write(&session->input_stream, packet.data, packet.data_length, packet.sequence, TRUE, app_state, session);

			break;
		}
		case CORE_ACK_ID:
		{
			packet_kind = Core_Packet_Kind_Ack;
			printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), global_core_packet_names[packet_kind]);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
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
			packet_kind = Core_Packet_Kind_Invalid;
			printf(MESSAGE_CONCAT_WARN("Unhandled core packet 0x%02x\n"), packet_id);

			if (session->connection_args.should_dump_core)
			{
				char dump_path[256] = { 0 };
				stbsp_snprintf(dump_path, sizeof(dump_path), "packets\\%llu_%llu_C_core_%s.bin", global_tick_count, global_packet_dump_count++, global_core_packet_names[packet_kind]);
				platform->buffer_write_to_file(dump_path, data, data_length);
			}
		}
	}

	
}
#endif // FL_PROXY

#endif