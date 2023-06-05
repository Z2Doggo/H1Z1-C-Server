#include <stdio.h>
#include <dlfcn.h>
#include <time.h>
#include "yote.h"
#define YOTE_PLATFORM_USE_SOCKETS  1
#define YOTE_PLATFORM_LINUX        1
#include "yote_platform.h"
#include "game_server.h"

#define MODULE_FILE       "login_server_module.so"
#define MODULE_FILE_TEMP  "login_server_module_temp.so"
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

internal time_t linux_get_last_write_time(const char* filename)
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

	result.module_last_write_time = linux_get_last_write_time(MODULE_FILE);
	link(MODULE_FILE, MODULE_FILE_TEMP);

	result.module = dlopen(MODULE_FILE_TEMP, RTLD_LAZY);
	if (result.module)
	{
		result.tick_func = (app_tick_t*)dlsym(result.module, "server_tick");
		result.is_valid = (result.tick_func != NULL);
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
	App_Memory app_memory =
	{
		.platform_api =
		{
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
		.backing_memory.data = mmap(NULL, app_memory.backing_memory.size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0),
	};

	LARGE_INTEGER local_performance_frequency;
	global_performance_frequency = sysconf(_SC_CLK_TCK);
	b32 is_sleep_granular = (nanosleep((struct timespec[]){{0, 0}}, NULL) == 0);
	f32 tick_rate = 60.0f;
	f32 target_seconds_per_tick = 1.0f / tick_rate;

	App_Code app_code = linux_app_code_load();
	u64 previous_counter = platform_linux_wall_clock();
	b32 is_running = 1;
	while (is_running)
	{
		#if defined(YOTE_INTERNAL)
		struct stat unused;
		b32 is_code_locked = (stat(MODULE_LOCK_FILE, &unused) == 0);
		time_t new_module_write_time = linux_get_last_write_time(MODULE_FILE);
		b32 should_reload = (!is_code_locked && (new_module_write_time != app_code.module_last_write_time));
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
		printf("\033[H\033[J"); // Clear the terminal screen
		printf("%s", app_memory.screen.data);
		#endif

		u64 work_counter = platform_linux_wall_clock();
		app_memory.work_ms = 1000.0f * platform_linux_elapsed_seconds(previous_counter, work_counter);

		f32 elapsed_tick_seconds = platform_linux_elapsed_seconds(previous_counter, platform_linux_wall_clock());
		if (elapsed_tick_seconds < target_seconds_per_tick)
		{
			if (is_sleep_granular)
			{
				i32 sleep_ns = (i32)((target_seconds_per_tick - elapsed_tick_seconds) * 1e9) - 1;
				struct timespec sleep_time = {0, sleep_ns};
				nanosleep(&sleep_time, NULL);
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

	return 0;
}
