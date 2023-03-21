internal void ping_packet_handle(Server_State* server_state,
                                 Session_State* session_state,
                                 u8* data,
                                 u32 data_length)
{
	u8 packet_id = *data;

	switch (packet_id)
	{
		case 1:
		{
			printf("[*] Responding to ping\n");

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

			u32 sent_length = server_state->platform_api->send_to(server_state->socket, data, data_length, session_state->address.ip, session_state->address.port);
			if (!sent_length)
			{
				printf("[!] Sent packet length is 0\n");
				return;
			}
		} break;

		case 2:
		{
			// TODO(rhett): THIS IS NOT WHATS HAPPENING
			printf("[*] Transitioning core protocol to ping only\n");

			session_state->kind = Session_Kind_Ping_Responder;

			//if (session_state->connection_args.should_dump_gateway)
			//{
				//wchar_t dump_path[256] = { 0 };
				//_snwprintf_s(dump_path, 256, 256, L"packets\\%llu_%llu_C_ping_Transition.bin", global_tick_count, global_packet_dump_count++);
				//server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
			//}
		} break;

		default:
		{
			printf("[!] Unhandled ping packet 0x%02x\n", packet_id);

			//if (session_state->connection_args.should_dump_gateway)
			//{
				//char dump_path[256] = { 0 };
				//stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_ping_UNHANDLED.bin", global_tick_count, global_packet_dump_count++);
				//server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
			//}
		}
	}
}