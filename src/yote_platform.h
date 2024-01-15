//====================================================================================================
// Platform - Requires only core and platform-provided headers
//====================================================================================================

#if defined(YOTE_PLATFORM_USE_SOCKETS)
typedef struct PlatformSocket
{
	b32 is_valid;
	uptr socket;
} PlatformSocket;
#endif // YOTE_PLATFORM_USE_SOCKETS

#define PLATFORM_FOLDER_CREATE(name) b32 name(char *folder_path)
typedef PLATFORM_FOLDER_CREATE(platform_folder_create);

#define PLATFORM_BUFFER_WRITE_TO_FILE(name) u32 name(char *file_path, void *buffer, u32 size)
typedef PLATFORM_BUFFER_WRITE_TO_FILE(platform_buffer_write_to_file);

#define PLATFORM_BUFFER_LOAD_FROM_FILE(name) u32 name(char *file_path, void *buffer, u32 size)
typedef PLATFORM_BUFFER_LOAD_FROM_FILE(platform_buffer_load_from_file);

#define PLATFORM_WALL_CLOCK(name) u64 name(void)
typedef PLATFORM_WALL_CLOCK(platform_wall_clock);

#define PLATFORM_ELAPSED_SECONDS(name) f32 name(u64 begin, u64 end)
typedef PLATFORM_ELAPSED_SECONDS(platform_elapsed_seconds);

#if defined(YOTE_PLATFORM_USE_SOCKETS)
#define PLATFORM_SOCKET_UDP_CREATE_AND_BIND(name) PlatformSocket name(u16 port)
typedef PLATFORM_SOCKET_UDP_CREATE_AND_BIND(platform_socket_udp_create_and_bind);

#define PLATFORM_RECEIVE_FROM(name) i32 name(PlatformSocket sock, void *buffer, i32 size, u32 *from_ip, u16 *from_port)
typedef PLATFORM_RECEIVE_FROM(platform_receive_from);

#define PLATFORM_SEND_TO(name) i32 name(PlatformSocket sock, void *buffer, i32 size, u32 to_ip, u16 to_port)
typedef PLATFORM_SEND_TO(platform_send_to);
#endif // YOTE_PLATFORM_USE_SOCKETS

typedef struct PlatformApi
{
	platform_folder_create *folder_create;
	platform_buffer_write_to_file *buffer_write_to_file;
	platform_buffer_load_from_file *buffer_load_from_file;
	platform_wall_clock *wall_clock;
	platform_elapsed_seconds *elapsed_seconds;

#if defined(YOTE_PLATFORM_USE_SOCKETS)
	platform_socket_udp_create_and_bind *socket_udp_create_and_bind;
	platform_receive_from *receive_from;
	platform_send_to *send_to;
#endif // YOTE_PLATFORM_USE_SOCKETS
} PlatformApi;

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <timeapi.h>
#include <limits.h>

#if defined(YOTE_PLATFORM_USE_SOCKETS)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#endif // YOTE_PLATFORM_USE_SOCKETS

u64 globalFrequency;

PLATFORM_FOLDER_CREATE(platform_win_folder_create)
{
	if (!CreateDirectory(folder_path, NULL))
	{
		DWORD last_error = GetLastError();
		if (last_error != ERROR_ALREADY_EXISTS)
		{
			printf("[!] CreateDirectory error on \"%s\" - Error: %lu\n",
				   folder_path,
				   last_error);
			return false;
		}
	}

	return true;
}

PLATFORM_BUFFER_WRITE_TO_FILE(platform_win_buffer_write_to_file)
{
	HANDLE file_handle = CreateFileA(file_path,
									 FILE_APPEND_DATA,
									 0,
									 NULL,
									 OPEN_ALWAYS,
									 FILE_ATTRIBUTE_NORMAL,
									 NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		printf("[!] Unable to open file to write \"%s\" - Error: %lu\n",
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
				   size,
				   &bytes_written,
				   0))
	{
		printf("[!] Unable to write to file \"%s\" - Error: %lu\n",
			   file_path,
			   GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	CloseHandle(file_handle);
	return bytes_written;
}

PLATFORM_BUFFER_LOAD_FROM_FILE(platform_win_buffer_load_from_file)
{
	HANDLE file_handle = CreateFileA(file_path,
									 GENERIC_READ,
									 0,
									 0,
									 OPEN_EXISTING,
									 FILE_ATTRIBUTE_NORMAL,
									 NULL);

	if (file_handle == INVALID_HANDLE_VALUE)
	{
		printf("[!] Unable to open file to read \"%s\" - Error: %lu\n",
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

	LARGE_INTEGER file_size;
	if (!GetFileSizeEx(file_handle, &file_size))
	{
		printf("[!] Unable to get size of \"%s\" - Error: %lu\n",
			   file_path,
			   GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	if (file_size.QuadPart > UINT_MAX)
	{
		printf("[!] File \"%s\" is too large to load\n",
			   file_path);
		CloseHandle(file_handle);
		return 0;
	}

	if (file_size.LowPart > size)
	{
		printf("[!] Buffer is too small to load from file \"%s\"\n", file_path);
		CloseHandle(file_handle);
		return 0;
	}

	DWORD bytes_read;
	if (!ReadFile(file_handle,
				  buffer,
				  file_size.LowPart,
				  &bytes_read,
				  NULL))
	{
		printf("[!] Unable to load from file \"%s\" - Error: %lu\n",
			   file_path,
			   GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	CloseHandle(file_handle);
	return bytes_read;
}

PLATFORM_WALL_CLOCK(platform_win_wall_clock)
{
	LARGE_INTEGER result;
	QueryPerformanceCounter(&result);
	return result.QuadPart;
}

PLATFORM_ELAPSED_SECONDS(platform_win_elapsed_seconds)
{
	f32 result = (f32)(end - begin) / (f32)globalFrequency;
	return result;
}

#if defined(YOTE_PLATFORM_USE_SOCKETS)
b32 platform_win_wsa_initialize()
{
	WSADATA wsa_data;
	int error = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (error)
	{
		printf("[!] WSAStartup failed - Error: %d\n", error);
		return false;
	}

	return true;
}

PLATFORM_SOCKET_UDP_CREATE_AND_BIND(platform_win_socket_udp_create_and_bind)
{
	b32 is_wsa_initialized;
	if (!is_wsa_initialized)
	{
		is_wsa_initialized = platform_win_wsa_initialize();
		ASSERT(is_wsa_initialized);
	}

	PlatformSocket result = {0};
	result.socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (result.socket == INVALID_SOCKET)
	{
		printf("[!] socket() failed: %d\n", WSAGetLastError());
		return result;
	}

	u_long cmd_arg = true;
	if (ioctlsocket(result.socket, FIONBIO, &cmd_arg) == SOCKET_ERROR)
	{
		printf("[!] ioctlsocket() failed: %d\n", WSAGetLastError());
		goto socket_close;
	}

	SOCKADDR_IN addr = {
		.sin_family = AF_INET,
		.sin_port = htons(port),
		.sin_addr.s_addr = inet_addr("127.0.0.1"),
	};

	int bind_result = bind(result.socket, (SOCKADDR *)&addr, sizeof(addr));
	if (bind_result == SOCKET_ERROR)
	{
		printf("[!] bind() failed: %d\n", WSAGetLastError());
		goto socket_close;
	}

	result.is_valid = true;
	return result;

socket_close:
	if (closesocket(result.socket) == SOCKET_ERROR)
	{
		printf("[!] closesocket() failed: %d\n", WSAGetLastError());
	}
	return result;
}

PLATFORM_RECEIVE_FROM(platform_win_receive_from)
{
	SOCKADDR_IN from_address = {0};
	int from_address_size = sizeof(from_address);

	int result = recvfrom(sock.socket,
						  buffer,
						  size,
						  0,
						  (struct sockaddr *)&from_address,
						  &from_address_size);

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

PLATFORM_SEND_TO(platform_win_send_to)
{
	SOCKADDR_IN to_address = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = htonl(to_ip),
		.sin_port = htons(to_port),
	};

	i32 result = sendto(sock.socket,
						buffer,
						size,
						0,
						(SOCKADDR *)&to_address,
						sizeof(to_address));

	if (result == SOCKET_ERROR)
	{
		printf("[!] sendto() failed: %d\n", WSAGetLastError());
		return 0;
	}

	return result;
}

#endif // YOTE_PLATFORM_USE_SOCKETS
