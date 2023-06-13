// TODO(rhett): Support utf-8 at some point


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <timeapi.h>
#include <winsock2.h>
#include <synchapi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <assert.h>


static void platform_win_console_write(char* format, ...);
#define printf(s, ...) platform_win_console_write(s, __VA_ARGS__)

#define DEBUG_BREAK __debugbreak()


#include "shared/base.h"
#include "utility/util.c"
#include "utility/memory_arena.c"
#include "utility/endian.c"
#include "utility/crypt_rc4.c"
#include "shared/platform/platform.h"
#include "shared/platform/platform_win.c"

#include "proxy.c"


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
	int to_write = vsnprintf(buffer, sizeof(buffer), format, args);

	DWORD written;
	WriteConsole(standard_handle, buffer, to_write, &written, NULL);
	//OutputDebugString(buffer);

	va_end(args);
}


int mainCRTStartup(void)
{
	Platform_State platform_state = { 0 };
	QueryPerformanceFrequency(&platform_state.frequency);

	Proxy_Memory proxy_memory = { 0 };
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
	proxy_memory.platform_state = &platform_state;
	proxy_memory.platform_api = &platform_api;
	void* backing_buffer = VirtualAlloc(NULL, MB(100), MEM_COMMIT, PAGE_READWRITE);
	usize backing_buffer_length = MB(100);
	proxy_memory.arena_persist = memory_arena_init(backing_buffer,
	                                               backing_buffer_length,
	                                               "Persist");

	b32 is_sleep_granular = timeBeginPeriod(1) == TIMERR_NOERROR;
	f32 target_seconds_per_frame = 1.0f / 60.0f;
	b32 is_running = TRUE;
	u64 tick_count = 0;

	u64 previous_counter = platform_api.wall_clock();
	while (is_running)
	{
		char time_info[128] = { 0 };
		snprintf(time_info, 128, "[*] --- TICK: %llu\n", tick_count);
		OutputDebugString(time_info);


		// NOTE(rhett): Work
		proxy_tick_run(&proxy_memory);

		local_persist i32 arena_debug_cooldown_ticks;
		if (GetKeyState('M') & 0x8000)
		{
			if (!arena_debug_cooldown_ticks)
			{
				arena_debug_cooldown_ticks = 30;

				printf("\nArena Debug\n[*] %s:\t\tPEAK: %u KiB\tTAIL: %u KiB\tPADDING: %u B\tCOUNT: %d\n",
				       proxy_memory.arena_persist.name,
				       proxy_memory.arena_persist.peak_used >> 10,
				       proxy_memory.arena_persist.tail_offset >> 10,
				       proxy_memory.arena_persist.padding >> 10,
				       proxy_memory.arena_persist.active_count);
				printf("[*] %s:\t\tPEAK: %u KiB\tTAIL: %u KiB\tPADDING: %u B\tCOUNT: %d\n",
				       proxy_memory.proxy_state->arena_per_frame.name,
				       proxy_memory.proxy_state->arena_per_frame.peak_used >> 10,
				       proxy_memory.proxy_state->arena_per_frame.tail_offset >> 10,
				       proxy_memory.proxy_state->arena_per_frame.padding >> 10,
				       proxy_memory.proxy_state->arena_per_frame.active_count);
			}
		}
		if (arena_debug_cooldown_ticks)
		{
			arena_debug_cooldown_ticks -= 1;
		}


		u64 work_counter = platform_api.wall_clock();

		f32 elapsed_frame_seconds = platform_api.elapsed_seconds(&platform_state, previous_counter, work_counter);
		if (elapsed_frame_seconds < target_seconds_per_frame)
		{
			if (is_sleep_granular)
			{
				i32 sleep_ms = (i32)(target_seconds_per_frame * 1000.0f) - (i32)(elapsed_frame_seconds * 1000.0f) - 1;
				char sleep_info[128] = { 0 };
				snprintf(sleep_info, sizeof(sleep_info), "[*] Sleeping %d ms\n", sleep_ms);
				OutputDebugString(sleep_info);

				if (sleep_ms > 0)
				{
					Sleep(sleep_ms);
				}
			}

			while (elapsed_frame_seconds < target_seconds_per_frame)
			{
				elapsed_frame_seconds = platform_api.elapsed_seconds(&platform_state,
				                                                     previous_counter,
				                                                     platform_api.wall_clock());
			}
		}

		u64 end_counter = platform_api.wall_clock();
		f32 ms_per_frame = 1000.0f * platform_api.elapsed_seconds(&platform_state ,previous_counter, end_counter);
		previous_counter = end_counter;
		// TODO(rhett): Can't use a width specifier here?
		snprintf(time_info, 128, "[*] TOTAL: %fms/f\n\n\0", ms_per_frame);
		OutputDebugString(time_info);

		tick_count++;
	}
	//DEBUG_BREAK;

	return 0;
};