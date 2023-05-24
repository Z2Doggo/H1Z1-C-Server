#if defined(YOTE_INTERNAL)
#include <stdio.h>
#else
#include <stdarg.h> // Added for va_list, va_start, va_end
static void platform_console_write(const char* format, ...);
#define printf(...) platform_console_write(__VA_ARGS__)
#endif // YOTE_INTERNAL

#include "yote.h"

// Add Linux-specific headers
#if defined(__linux__)
#include <dlfcn.h>
#include <sys/stat.h>
#endif

// Add Windows-specific headers
#if defined(_WIN32)
#include <windows.h>
#endif

// Define the function pointer type for the server tick function
typedef void(app_tick_t)(App_Memory* app_memory);

#define MODULE_FILE       "login_server_module.dll"
#define MODULE_FILE_TEMP  "login_server_module_temp.dll"
#define MODULE_LOCK_FILE  ".reload-lock"

typedef struct App_Code App_Code;
struct App_Code
{
    void* module; // Use void* for platform-specific module handle
    time_t module_last_write_time; // Use time_t for last write time
    app_tick_t* tick_func;
    b32 is_valid;
};

APP_TICK(app_tick_stub)
{
    UNUSED(app_memory);
    UNUSED(should_reload);
}

// Define platform-specific functions
#if defined(_WIN32)
static FILETIME win32_get_last_write_time(const char* filename)
{
    FILETIME result = { 0 };

    WIN32_FILE_ATTRIBUTE_DATA file_data;
    if (GetFileAttributesExA(filename, GetFileExInfoStandard, &file_data))
    {
        result = file_data.ftLastWriteTime;
    }

    return result;
}

static App_Code win32_app_code_load()
{
    App_Code result = { 0 };

    result.module_last_write_time = (time_t)win32_get_last_write_time(MODULE_FILE).dwLowDateTime;
    CopyFileA(MODULE_FILE, MODULE_FILE_TEMP, FALSE);

    result.module = LoadLibraryA(MODULE_FILE_TEMP);
    if (result.module)
    {
        result.tick_func = (app_tick_t*)GetProcAddress((HMODULE)result.module, "server_tick");
        result.is_valid = !!result.tick_func;
    }

    if (!result.is_valid)
    {
        result.tick_func = app_tick_stub;
    }

    return result;
}

static void win32_app_code_unload(App_Code* app_code)
{
    if (app_code->module)
    {
        FreeLibrary((HMODULE)app_code->module);
        app_code->module = NULL;
    }

    app_code->is_valid = FALSE;
    app_code->tick_func = app_tick_stub;
}

static void platform_console_write(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

#elif defined(__linux__)
static time_t linux_get_last_write_time(const char* filename)
{
    struct stat file_stat;
    if (stat(filename, &file_stat) == 0)
    {
        return file_stat.st_mtime;
    }

    return 0;
}

static App_Code linux_app_code_load()
{
    App_Code result = { 0 };

    result.module_last_write_time = linux_get_last_write_time(MODULE_FILE);
    result.module = dlopen(MODULE_FILE_TEMP, RTLD_NOW | RTLD_LOCAL);
    if (result.module)
    {
        result.tick_func = (app_tick_t*)dlsym(result.module, "server_tick");
        result.is_valid = !!result.tick_func;
    }

    if (!result.is_valid)
    {
        result.tick_func = app_tick_stub;
    }

    return result;
}

static void linux_app_code_unload(App_Code* app_code)
{
    if (app_code->module)
    {
        dlclose(app_code->module);
        app_code->module = NULL;
    }

    app_code->is_valid = FALSE;
    app_code->tick_func = app_tick_stub;
}

static void platform_console_write(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

#endif

int main(void)
{
    App_Memory app_memory = { 0 };

    // Define platform-specific functions and variables
    #if defined(_WIN32)
    app_memory.platform_api.folder_create = platform_win_folder_create;
    app_memory.platform_api.buffer_write_to_file = platform_win_buffer_write_to_file;
    app_memory.platform_api.buffer_load_from_file = platform_win_buffer_load_from_file;
    app_memory.platform_api.socket_udp_create_and_bind = platform_win_socket_udp_create_and_bind;
    app_memory.platform_api.receive_from = platform_win_receive_from;
    app_memory.platform_api.send_to = platform_win_send_to;
    app_memory.platform_api.wall_clock = platform_win_wall_clock;
    app_memory.platform_api.elapsed_seconds = platform_win_elapsed_seconds;
    #elif defined(__linux__)
    app_memory.platform_api.folder_create = platform_linux_folder_create;
    app_memory.platform_api.buffer_write_to_file = platform_linux_buffer_write_to_file;
    app_memory.platform_api.buffer_load_from_file = platform_linux_buffer_load_from_file;
    app_memory.platform_api.socket_udp_create_and_bind = platform_linux_socket_udp_create_and_bind;
    app_memory.platform_api.receive_from = platform_linux_receive_from;
    app_memory.platform_api.send_to = platform_linux_send_to;
    app_memory.platform_api.wall_clock = platform_linux_wall_clock;
    app_memory.platform_api.elapsed_seconds = platform_linux_elapsed_seconds;
    #endif

    // Set backing memory size and allocate memory
    app_memory.backing_memory.size = MB(100);
    app_memory.backing_memory.data = VirtualAlloc(NULL, app_memory.backing_memory.size, MEM_COMMIT, PAGE_READWRITE);

    // Set tick rate and target seconds per tick
    f32 tick_rate = 60.0f;
    f32 target_seconds_per_tick = 1.0f / tick_rate;

    // Load app code based on platform
    #if defined(_WIN32)
    App_Code app_code = win32_app_code_load();
    #elif defined(__linux__)
    App_Code app_code = linux_app_code_load();
    #endif

    u64 previous_counter = platform_win_wall_clock();
    b32 is_running = TRUE;
    while (is_running)
    {
        // Reload app code if necessary
        #if defined(YOTE_INTERNAL)
        b32 should_reload = FALSE;
        // Add platform-specific code to check for code reload
        #if defined(_WIN32)
        FILETIME new_module_write_time = win32_get_last_write_time(MODULE_FILE);
        should_reload = CompareFileTime(&new_module_write_time, (FILETIME*)&app_code.module_last_write_time);
        #elif defined(__linux__)
        time_t new_module_write_time = linux_get_last_write_time(MODULE_FILE);
        should_reload = new_module_write_time != app_code.module_last_write_time;
        #endif

        if (should_reload)
        {
            printf("\n=======================================================================\n");
            printf("  Reloading...\n");
            printf("=======================================================================\n");
            // Unload and load app code based on platform
            #if defined(_WIN32)
            app_code.module_last_write_time = (time_t)win32_get_last_write_time(MODULE_FILE).dwLowDateTime;
            win32_app_code_unload(&app_code);
            app_code = win32_app_code_load();
            #elif defined(__linux__)
            app_code.module_last_write_time = linux_get_last_write_time(MODULE_FILE);
            linux_app_code_unload(&app_code);
            app_code = linux_app_code_load();
            #endif
        }
        #endif

        // Call tick function
        app_code.tick_func(&app_memory
        #if defined(YOTE_INTERNAL)
        , should_reload
        #endif
        );

        // Add platform-specific code to update the screen or perform other UI operations
        #if defined(TERMINAL_UI)
        // Add platform-specific code to update the console screen buffer
        #endif

        // Calculate elapsed tick time and sleep if necessary
        u64 end_counter = platform_win_wall_clock();
        f32 elapsed_tick_seconds = platform_win_elapsed_seconds(previous_counter, end_counter);
        if (elapsed_tick_seconds < target_seconds_per_tick)
        {
            if (is_sleep_granular)
            {
                i32 sleep_ms = (i32)(target_seconds_per_tick * 1000.0f) - (i32)(elapsed_tick_seconds * 1000.0f) - 1;

                if (sleep_ms > 0)
                {
                    Sleep(sleep_ms);
                }
            }

            while (elapsed_tick_seconds < target_seconds_per_tick)
            {
                elapsed_tick_seconds = platform_win_elapsed_seconds(previous_counter, platform_win_wall_clock());
            }
        }

        previous_counter = end_counter;

        app_memory.tick_count++;
    }

    return 0;
}
