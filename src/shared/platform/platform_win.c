struct Platform_State
{
	LARGE_INTEGER frequency;
	b32 is_wsa_initialized;
};

struct Platform_Socket
{
	b32 is_valid;
	SOCKET socket;
};


internal b32 platform_win_wsa_startup(Platform_State* state)
{
	if (state->is_wsa_initialized)
	{
		printf("[!] WSA already initialized\n");
		return TRUE;
	}

	WSADATA wsa_data;
	int error = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (error)
	{
		printf("[!] WSAStartup failed - Error: %d\n", error);
		return FALSE;
	}

	return state->is_wsa_initialized = TRUE;
}

internal PLATFORM_FOLDER_CREATE(platform_win_folder_create)
{
	if (!CreateDirectory(folder_path, NULL))
	{
		DWORD last_error = GetLastError();
		if (last_error != ERROR_ALREADY_EXISTS)
		{
			printf("[!] CreateDirectory error on \"%s\" - Error: %u\n",
			        folder_path,
			        last_error);
			return FALSE;
		}
	}

	return TRUE;
}

internal PLATFORM_BUFFER_WRITE_TO_FILE(platform_win_buffer_write_to_file)
{
	HANDLE file_handle = CreateFile(file_path,
	                                GENERIC_WRITE,
	                                0,
	                                NULL,
	                                CREATE_ALWAYS,
	                                FILE_ATTRIBUTE_NORMAL,
	                                NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		printf("[!] Unable to open file to write \"%s\" - Error: %u\n",
		        file_path,
		        GetLastError());
		return 0;
	}

	if (!buffer)
	{
		printf("[!] Buffer to write from is null\n");
		CloseHandle(file_handle);
		return 0;
	}

	DWORD bytes_written;
	if (!WriteFile(file_handle,
	               buffer,
	               buffer_length,
	               &bytes_written,
	               NULL))
	{
		printf("[!] Unable to write to file \"%s\" - Error: %u\n",
		        file_path,
		        GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	CloseHandle(file_handle);
	return bytes_written;
}

internal PLATFORM_BUFFER_LOAD_FROM_FILE(platform_win_buffer_load_from_file)
{
	HANDLE file_handle = CreateFile(file_path,
	                                GENERIC_READ,
	                                0,
	                                0,
	                                OPEN_EXISTING,
	                                FILE_ATTRIBUTE_NORMAL,
	                                NULL);

	if (file_handle == INVALID_HANDLE_VALUE)
	{
		printf("[!] Unable to open file to read \"%s\" - Error: %u\n",
		        file_path,
		        GetLastError());
		return 0;
	}

	if (!buffer)
	{
		printf("[!] Buffer to load to is null\n");
		CloseHandle(file_handle);
		return 0;
	}

	LARGE_INTEGER file_length;
	if (!GetFileSizeEx(file_handle, &file_length))
	{
		printf("[!] Unable to get size of \"%s\" - Error: %u\n",
		        file_path,
		        GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	if (file_length.QuadPart > UINT_MAX)
	{
		printf("[!] File \"%s\" is too large to load\n",
		        file_path);
		CloseHandle(file_handle);
		return 0;
	}

	// TODO(rhett): make sure we want LowPart
	if (file_length.LowPart > buffer_length)
	{
		printf("[!] Buffer is too small to load from file \"%s\"\n", file_path);
		CloseHandle(file_handle);
		return 0;
	}

	DWORD bytes_read;
	if (!ReadFile(file_handle,
	              buffer,
	              file_length.LowPart,
	              &bytes_read,
	              NULL))
	{
		printf("[!] Unable to load from file \"%s\" - Error: %u\n",
		        file_path,
		        GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	CloseHandle(file_handle);
	return bytes_read;
}

internal PLATFORM_SOCKET_UDP_CREATE_AND_BIND(platform_win_socket_udp_create_and_bind)
{
	if (!state->is_wsa_initialized)
	{
		platform_win_wsa_startup(state);
	}

	Platform_Socket result = { 0 };
	result.socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (result.socket == INVALID_SOCKET)
	{
		printf("[!] socket() failed: %d\n", WSAGetLastError());
		return result;
	}

	// NOTE(rhett): Use non-blocking socket
	u_long cmd_arg = TRUE;
	if (ioctlsocket(result.socket, FIONBIO, &cmd_arg) == SOCKET_ERROR)
	{
		printf("[!] ioctlsocket() failed: %d\n", WSAGetLastError());
		goto socket_close;
	}

	// NOTE(rhett): Bind
	SOCKADDR_IN addr =
	{
	.sin_family = AF_INET,
	.sin_port = htons(port),
	.sin_addr.s_addr = inet_addr("127.0.0.1"),
	};

	int bind_result = bind(result.socket, (SOCKADDR*)&addr, sizeof(addr));
	if (bind_result == SOCKET_ERROR)
	{
		printf("[!] bind() failed: %d\n", WSAGetLastError());
		goto socket_close;
	}

	result.is_valid = TRUE;
	return result;

	socket_close:
		if (closesocket(result.socket) == SOCKET_ERROR)
		{
			// TODO(rhett): What do we even do at this point?
			printf("[!] closesocket() failed: %d\n", WSAGetLastError());
		}
		return result;
}

internal PLATFORM_RECEIVE_FROM(platform_win_receive_from)
{
	SOCKADDR_IN from_address = { 0 };
	int from_address_length = sizeof(from_address);

	int result = recvfrom(sock.socket,
	                      buffer,
	                      length,
	                      0,
	                      (struct sockaddr*)&from_address,
	                      &from_address_length);

	if (result == SOCKET_ERROR)
	{
		int last_error = WSAGetLastError();
		if (last_error != WSAEWOULDBLOCK)
		{
			printf("[!] recvfrom() failed: %d\n", last_error);
		}
		return 0;
	}
	else if (!result)
	{
		printf("[!] recvfrom() returned 0\n");
		return 0;
	}

	*from_ip = ntohl(from_address.sin_addr.s_addr);
	*from_port = ntohs(from_address.sin_port);
	return result;
}

internal PLATFORM_SEND_TO(platform_win_send_to)
{
	SOCKADDR_IN to_address =
	{
	.sin_family = AF_INET,
	.sin_addr.s_addr = htonl(to_ip),
	.sin_port = htons(to_port),
	};

	i32 result = sendto(sock.socket,
	                    buffer,
	                    length,
	                    0,
	                    (SOCKADDR*)&to_address,
	                    sizeof(to_address));

	if (result == SOCKET_ERROR)
	{
		printf("[!] sendto() failed: %d\n", WSAGetLastError());
		return 0;
	}

	return result;
}

internal PLATFORM_WALL_CLOCK(platform_win_wall_clock)
{
	LARGE_INTEGER result;
	QueryPerformanceCounter(&result);
	return result.QuadPart;
}

internal PLATFORM_ELAPSED_SECONDS(platform_win_elapsed_seconds)
{
	f32 result = (f32)(end - begin) / (f32)state->frequency.QuadPart;
	return result;
}