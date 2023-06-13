// NOTE(rhett): Fix complaints by the VS address sanitizer 
#define STBSP__ASAN __declspec(no_sanitize_address)
#define STB_SPRINTF_IMPLEMENTATION
#include "thirdparty/stb_sprintf.h"

typedef struct App_State App_State;
typedef struct App_Memory App_Memory;
struct App_Memory
{
	Platform_Api platform_api;
	Buffer backing_memory;
	App_State* app_state;

	f32 tick_ms;
	f32 work_ms;
	u64 tick_count;
};

#if defined(YOTE_INTERNAL)
#define APP_TICK(name) void name(App_Memory* app_memory, f32 dt, b32 should_reload)
#else
#define APP_TICK(name) void name(App_Memory* app_memory, f32 dt)
#endif // YOTE_INTERNAL
typedef APP_TICK(app_tick_t);