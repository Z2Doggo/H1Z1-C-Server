#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <timeapi.h>
#include <winsock2.h>
#include <synchapi.h>

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <assert.h>


static void platform_win_console_write(char* format, ...);
#define printf(s, ...) platform_win_console_write(s, __VA_ARGS__)

#define DEBUG_BREAK __debugbreak()

//#define NDEBUG
//#define abort() ExitProcess(1)


#define STB_SPRINTF_IMPLEMENTATION
#include "thirdparty/stb_sprintf.h"

#include "shared/base.h"
#include "utility/util.c"
#include "utility/memory_arena.c"
#include "utility/endian.c"
#include "utility/crypt_rc4.c"
#include "shared/platform/platform.h"
#include "shared/platform/platform_win.c"


global u64 global_tick_count;

typedef struct Program_State Program_State;
typedef struct Server_State Server_State;

struct Program_State
{
	Platform_State* platform_state;
	Platform_Api*   platform_api;
	Memory_Arena    arena_persist;
	Server_State*   server_state;
};


#include "h1z1_game_server.c"


internal void platform_win_console_write(char* format, ...)
{
	va_list args;
	va_start(args, format);

	local_persist HANDLE standard_handle;
	if (!standard_handle)
	{
		standard_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	char buffer[1024] = { 0 };
	int to_write = stbsp_vsnprintf(buffer, sizeof(buffer), format, args);

	DWORD written;
	WriteConsole(standard_handle, buffer, to_write, &written, NULL);
	//OutputDebugString(buffer);

	va_end(args);
}


int mainCRTStartup(void)
{
	Platform_State platform_state = { 0 };
	QueryPerformanceFrequency(&platform_state.frequency);

	Program_State server_memory = { 0 };
	Platform_Api platform_api =
	{
		.folder_create = platform_win_folder_create,
		.buffer_write_to_file = platform_win_buffer_write_to_file,
		.buffer_load_from_file = platform_win_buffer_load_from_file,
		.socket_udp_create_and_bind = platform_win_socket_udp_create_and_bind,
		.receive_from = platform_win_receive_from,
		.send_to = platform_win_send_to,
		.wall_clock = platform_win_wall_clock,
		.elapsed_seconds = platform_win_elapsed_seconds,
	};
	server_memory.platform_state = &platform_state;
	server_memory.platform_api = &platform_api;
	usize backing_memory_length = MB(100);
	void* backing_memory = VirtualAlloc(NULL, backing_memory_length, MEM_COMMIT, PAGE_READWRITE);
	server_memory.arena_persist = memory_arena_init(
		backing_memory,
	    backing_memory_length,
	    "Persist"
	);

	b32 is_sleep_granular = timeBeginPeriod(1) == TIMERR_NOERROR;
	f32 target_seconds_per_tick = 1.0f / 60.0f;
	b32 is_running = TRUE;
	u64 tick_count = 0;

	u64 previous_counter = platform_api.wall_clock();
	while (is_running)
	{
		char time_info[128] = { 0 };
		stbsp_snprintf(time_info, sizeof(time_info), "[*] --- TICK: %llu\n", tick_count);
		OutputDebugString(time_info);


		// NOTE(rhett): WORK
		game_tick_run(&server_memory);


		local_persist i32 arena_debug_cooldown_ticks;
		if (GetKeyState('M') & 0x8000)
		{
			if (!arena_debug_cooldown_ticks)
			{
				arena_debug_cooldown_ticks = 30;

				printf("\nArena Debug\n[*] %s:\t\tPEAK: %u KiB\tTAIL: %u KiB\tPADDING: %u B\tCOUNT: %d\n",
				    server_memory.arena_persist.name,
				    server_memory.arena_persist.peak_used >> 10,
				    server_memory.arena_persist.tail_offset >> 10,
				    server_memory.arena_persist.padding >> 10,
				    server_memory.arena_persist.active_count
				);

				printf("[*] %s:\t\tPEAK: %u KiB\tTAIL: %u KiB\tPADDING: %u B\tCOUNT: %d\n",
					server_memory.server_state->arena_per_tick.name,
				    server_memory.server_state->arena_per_tick.peak_used >> 10,
				    server_memory.server_state->arena_per_tick.tail_offset >> 10,
				    server_memory.server_state->arena_per_tick.padding >> 10,
				    server_memory.server_state->arena_per_tick.active_count
				);
			}
		}
		if (arena_debug_cooldown_ticks)
		{
			arena_debug_cooldown_ticks -= 1;
		}

		u64 work_counter = platform_api.wall_clock();
		f32 elapsed_work_seconds = platform_api.elapsed_seconds(&platform_state, previous_counter, work_counter);

		f32 ms_per_work = 1000.0f * elapsed_work_seconds;
		stbsp_snprintf(time_info, sizeof(time_info), "[*] WORK: %fms/f\n\n\0", ms_per_work);
		OutputDebugString(time_info);


		f32 elapsed_tick_seconds = platform_api.elapsed_seconds(&platform_state, previous_counter, platform_api.wall_clock());
		if (elapsed_tick_seconds < target_seconds_per_tick)
		{
			if (is_sleep_granular)
			{
				i32 sleep_ms = (i32)(target_seconds_per_tick * 1000.0f) - (i32)(elapsed_tick_seconds * 1000.0f) - 1;
				char sleep_info[128] = { 0 };
				stbsp_snprintf(sleep_info, sizeof(sleep_info), "[*] Sleeping %dms\n", sleep_ms);
				OutputDebugString(sleep_info);

				if (sleep_ms > 0)
				{
					Sleep(sleep_ms);
				}
			}

			while (elapsed_tick_seconds < target_seconds_per_tick)
			{
				//Sleep(0);
				elapsed_tick_seconds = platform_api.elapsed_seconds(&platform_state, previous_counter, platform_api.wall_clock());
			}
		}

		u64 end_counter = platform_api.wall_clock();
		f32 ms_per_tick = 1000.0f * platform_api.elapsed_seconds(&platform_state, previous_counter, end_counter);
		previous_counter = end_counter;

		// TODO(rhett): Can't use a width specifier here?
		stbsp_snprintf(time_info, sizeof(time_info), "[*] TOTAL: %fms/f\n\n\0", ms_per_tick);
		OutputDebugString(time_info);

		global_tick_count++;
	}
	
	return 0;
}