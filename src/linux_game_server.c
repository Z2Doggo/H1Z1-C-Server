// TODO(rhett): hot reloading crashes the server. do a pass on which state is preserved

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "yote.h"
#include "yote_platform.h"
#include "game_server.h"

#define MODULE_FILE       "game_server_module.so"
#define MODULE_FILE_TEMP  "game_server_module_temp.so"
#define MODULE_LOCK_FILE  ".reload-lock"

typedef struct App_Code App_Code;
struct App_Code
{
	void* module;
	time_t module_last_write_time;
	app_tick_t* tick_func;
	int is_valid;
};

APP_TICK(app_tick_stub)
{
	UNUSED(app_memory);
	UNUSED(should_reload);
}

internal time_t get_last_write_time(const char* filename)
{
	struct stat file_stat;
	if (stat(filename, &file_stat) == 0)
	{
		return file_stat.st_mtime;
	}
	return 0;
}

internal App_Code linux_app_code_load()
{
	App_Code result = { 0 };

	result.module_last_write_time = get_last_write_time(MODULE_FILE);
	copy_file(MODULE_FILE, MODULE_FILE_TEMP);

	result.module = dlopen(MODULE_FILE_TEMP, RTLD_LAZY);
	if (result.module)
	{
		result.tick_func = (app_tick_t*)dlsym(result.module, "server_tick");
		result.is_valid = result.tick_func != NULL;
	}

	if (!result.is_valid)
	{
		result.tick_func = app_tick_stub;
	}

	return result;
}

internal void linux_app_code_unload(App_Code* app_code)
{
	if (app_code->module)
	{
		dlclose(app_code->module);
		app_code->module = NULL;
	}

	app_code->is_valid = 0;
	app_code->tick_func = app_tick_stub;
}

int main(void)
{
	App_Memory app_memory = {
		.platform_api = {
			.folder_create = platform_linux_folder_create,
			.buffer_write_to_file = platform_linux_buffer_write_to_file,
			.buffer_load_from_file = platform_linux_buffer_load_from_file,
			.socket_udp_create_and_bind = platform_linux_socket_udp_create_and_bind,
			.receive_from = platform_linux_receive_from,
			.send_to = platform_linux_send_to,
			.wall_clock = platform_linux_wall_clock,
			.elapsed_seconds = platform_linux_elapsed_seconds,
		},
		.backing_memory.size = MB(100),
		.backing_memory.data = malloc(app_memory.backing_memory.size),
	};

	//#if defined(YOTE_INTERNAL)
	//base_memory_fill(app_memory.backing_memory.data, 0xcc, app_memory.backing_memory.size);
	//#endif // YOTE_INTERNAL

	struct timespec local_performance_frequency;
	clock_getres(CLOCK_MONOTONIC, &local_performance_frequency);
	global_performance_frequency = (u64)local_performance_frequency.tv_sec * NANOSECONDS_PER_SECOND + local_performance_frequency.tv_nsec;
	b32 is_sleep_granular = TRUE; // Time granularity is fine in Linux
	f32 tick_rate = 30.0f;
	f32 target_seconds_per_tick = 1.0f / tick_rate;

#if defined(TERMINAL_UI)
	FILE* console_handle = stdout;
#endif // TERMINAL_UI

	App_Code app_code = linux_app_code_load();
	u64 previous_counter = platform_linux_wall_clock();
	b32 is_running = TRUE;
	while (is_running)
	{
#if defined(YOTE_INTERNAL)
		struct stat unused;
		b32 is_code_locked = stat(MODULE_LOCK_FILE, &unused) == 0;
		time_t new_module_write_time = get_last_write_time(MODULE_FILE);
		b32 should_reload = !is_code_locked && new_module_write_time != app_code.module_last_write_time;
		if (should_reload)
		{
			printf("\n=======================================================================\n");
			printf("  Reloading...\n");
			printf("=======================================================================\n");
			app_code.module_last_write_time = new_module_write_time;
			linux_app_code_unload(&app_code);
			app_code = linux_app_code_load();
		}
#endif

		app_code.tick_func(&app_memory
		                   #if defined(YOTE_INTERNAL)
		                   , should_reload
		                   #endif
		                   );

#if defined(TERMINAL_UI)
		fwrite(app_memory.screen.data, sizeof(char), app_memory.screen.size, console_handle);
		fflush(console_handle);
#endif // TERMINAL_UI

		u64 work_counter = platform_linux_wall_clock();
		app_memory.work_ms = 1000.0f * platform_linux_elapsed_seconds(previous_counter, work_counter);

		f32 elapsed_tick_seconds = platform_linux_elapsed_seconds(previous_counter, platform_linux_wall_clock());
		if (elapsed_tick_seconds < target_seconds_per_tick)
		{
			if (is_sleep_granular)
			{
				i32 sleep_ms = (i32)((target_seconds_per_tick - elapsed_tick_seconds) * 1000.0f) - 1;

				if (sleep_ms > 0)
				{
					usleep(sleep_ms * 1000);
				}
			}

			while (elapsed_tick_seconds < target_seconds_per_tick)
			{
				elapsed_tick_seconds = platform_linux_elapsed_seconds(previous_counter, platform_linux_wall_clock());
			}
		}

		u64 end_counter = platform_linux_wall_clock();
		app_memory.tick_ms = 1000.0f * platform_linux_elapsed_seconds(previous_counter, end_counter);
		previous_counter = end_counter;

		app_memory.tick_count++;
	}

	free(app_memory.backing_memory.data);

	return 0;
}
