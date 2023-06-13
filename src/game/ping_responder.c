void protocol_ping_packet_route(Buffer packet_buffer,
                                Session_Handle session_handle,
                                App_State* app_state)

{
	ASSERT(app_state);
	ASSERT(session_handle.id);
	ASSERT(packet_buffer.data);

	u8 packet_id = *packet_buffer.data;
	Session_State* session = session_get_pointer_from_handle(&app_state->session_pool, session_handle);

	switch (packet_id)
	{
		case 1:
		{
			printf(MESSAGE_CONCAT_INFO("Responding to ping\n"));

			//if (session_state->connection_args.should_dump_gateway)
			//{
				//wchar_t dump_path[256] = { 0 };
				//_snwprintf_s(dump_path, 256, 256, L"packets\\%llu_%llu_C_ping_Ping.bin", global_tick_count, global_packet_dump_count++);
				//server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
			//}

			// TODO(rhett): is this enough?
			//output_stream_write(&session_state->output_stream,
			                    //data,
			                    //data_length,
			                    //FALSE,
			                    //server_state,
			                    //session_state);

			u32 sent_size = app_state->platform_api->send_to(app_state->socket,
			                                                   packet_buffer.data,
			                                                   cast(u32)packet_buffer.size,
			                                                   session->address.ip,
			                                                   session->address.port);
			if (!sent_size)
			{
				printf(MESSAGE_CONCAT_WARN("Sent packet size is 0\n"));
				return;
			}
		} break;

		//case 2:
		//{
			//// TODO(rhett): THIS IS NOT WHATS HAPPENING
			//printf("[*] Transitioning core protocol to ping only\n");
//
			////session_state->kind = Session_Kind_Ping_Responder;
//
			////if (session_state->connection_args.should_dump_gateway)
			////{
				////wchar_t dump_path[256] = { 0 };
				////_snwprintf_s(dump_path, 256, 256, L"packets\\%llu_%llu_C_ping_Transition.bin", global_tick_count, global_packet_dump_count++);
				////server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
			////}
		//} break;

		default:
		{
			printf(MESSAGE_CONCAT_WARN("Unhandled ping packet 0x%02x\n"), packet_id);

			//if (session_state->connection_args.should_dump_gateway)
			//{
				//char dump_path[256] = { 0 };
				//stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_ping_UNHANDLED.bin", global_tick_count, global_packet_dump_count++);
				//server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
			//}
		}
	}
}