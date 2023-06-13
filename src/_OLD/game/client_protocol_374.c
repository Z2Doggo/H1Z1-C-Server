internal void zone_packet_send(App_State* server_state,
	                						 Session_State* session_state,
	                						 Arena* arena,
	                						 u32 max_length,
	              						   Zone_Packet_Kind packet_kind,
	              						   void* packet_ptr)
{
	u8* base_buffer = memory_arena_allocate(arena, max_length);
	u8* packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
	u32 packed_length = zone_packet_pack(packet_kind,
	                                     packet_ptr,
	                                     packed_buffer);
	u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;
	memory_arena_rewind_and_zero(arena, max_length - total_length);

	// TODO(rhett): packet dump counter will be out of order
	// NOTE(rhett): dumping before sending to aid with debugging
	if (session_state->connection_args.should_dump_zone)
	{
		wchar_t dump_path[256] = { 0 };
		_snwprintf_s(dump_path, 256, 256, L"packets\\%llu_%llu_S_zone_%ws.bin", global_tick_count, global_packet_dump_count++, zone_packet_names[packet_kind]);
		server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
	}

	// TODO(rhett): still only one client for now
	gateway_tunnel_data_send(server_state, session_state, base_buffer, total_length);
}

internal void zone_packet_raw_file_send(App_State* server_state,
	                          						Session_State* session_state,
	                          						Arena* arena,
	                          						u32 max_length,
	                          						wchar_t* path)
{
	u8* base_buffer = memory_arena_allocate(arena, max_length);
	u8* packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
	u32 packed_length = server_state->platform_api->buffer_load_from_file(path,
	                                                                      base_buffer,
	                                                                      max_length);
	u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;
	memory_arena_rewind_and_zero(arena, max_length - total_length);

	if (session_state->connection_args.should_dump_zone)
	{
		wchar_t dump_path[256] = { 0 };
		_snwprintf_s(dump_path, 256, 256, L"packets\\%llu_%llu_S_zone_RAW.bin", global_tick_count, global_packet_dump_count++);
		server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
	}

	// TODO(rhett): still only one client for now
	gateway_tunnel_data_send(server_state, session_state, base_buffer, total_length);
}

internal void zone_packet_handle(App_State* server_state,
                                 Session_State* session_state,
                                 u8* data,
                                 u32 data_length)
{
	Zone_Packet_Kind packet_kind;

	printf("\n");

	if (data_length == 0)
	{
		printf("\n\n[!] Empty zone packet????\n\n");
		return;
	}

	// TODO(rhett): once we start receiving packets, we'll need to handle subcodes
	// TODO(rhett): OPTIMIZE THIS !!!!!!!!
	// TODO(rhett): also this is SLOPPY
	u32 packet_temp;
	u32 packet_id;
	u32 packet_iter;
	if (data_length > 0)
	{
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (data[0] == zone_registered_ids[packet_iter])
			{
				packet_id = *data;
				goto packet_id_switch;
			}
		}
	}

	if (data_length > 1)
	{
		packet_temp = (((0ul | data[0]) << 8) | data[1]);
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_temp == zone_registered_ids[packet_iter])
			{
				packet_id = packet_temp;
				goto packet_id_switch;
			}
		}
	}

	if (data_length > 2)
	{
		packet_temp = ((0ul | data[0]) << 16) | endian_read_u16_little(data + 1);
		for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
		{
			if (packet_temp == zone_registered_ids[packet_iter])
			{
				packet_id = packet_temp;
				goto packet_id_switch;
			}
		}
	}

	packet_id = *data;
	goto packet_id_fail;

	packet_id_switch:
	switch (packet_id)
	{
		case ZONE_GAMETIMESYNC_ID:
		{
			packet_kind = Zone_Packet_Kind_GameTimeSync;
			printf("[*] Handling %ws...\n", zone_packet_names[packet_kind]);

			Zone_Packet_GameTimeSync result = { 0 };
			zone_packet_unpack(data,
			                   data_length,
			                   Zone_Packet_Kind_GameTimeSync,
			                   &result,
			                   &server_state->arena_per_frame);

			__time64_t timer;
			_time64(&timer);
			Zone_Packet_GameTimeSync packet =
			{
				.time = timer,
				.unk_f32 = 12.0f,
				.unk_bool = FALSE,
			};
			//zone_packet_pack(data, data_length, Zone_Packet_Kind_GameTimeSync, &packet, &global_test_arena);

			zone_packet_send(server_state,
			                 session_state,
			                 &server_state->arena_per_frame,
			                 32,
			                 Zone_Packet_Kind_GameTimeSync,
			                 &packet);

		} break;

		case ZONE_PACKETSETLOCALE_ID:
		{
			packet_kind = Zone_Packet_Kind_PacketSetLocale;
			printf("[*] Handling %ws...\n", zone_packet_names[packet_kind]);
		} break;

		case ZONE_PACKETSETCLIENTAREA_ID:
		{
			packet_kind = Zone_Packet_Kind_PacketSetClientArea;
			printf("[*] Handling %ws...\n", zone_packet_names[packet_kind]);
		} break;

		case ZONE_PLAYERUPDATEPACKETITEMDEFINITIONREQUEST_ID:
		{
			packet_kind = Zone_Packet_Kind_PlayerUpdatePacketItemDefinitionRequest;
			printf("[*] Handling %ws...\n", zone_packet_names[packet_kind]);
		} break;

		default:
		{
			packet_id_fail:
			packet_kind = Zone_Packet_Kind_Unhandled;
			printf("[!] Unhandled zone packet 0x%02x\n", packet_id);
		}
	}

	if (session_state->connection_args.should_dump_zone)
	{
		wchar_t dump_path[256] = { 0 };
		_snwprintf_s(dump_path, 256, 256, L"packets\\%llu_%llu_C_zone_%ws.bin", global_tick_count, global_packet_dump_count++, zone_packet_names[packet_kind]);
		server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
	}
}