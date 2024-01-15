#include <Windows.h>

typedef struct AppState AppState;
typedef struct SessionState SessionState;

typedef b8 KeyStates[0xff];

typedef struct AppMemory
{
    PlatformApi api;
    Buffer backingMemory;
    AppState *app;
    f32 tickMs;
    f32 workMs;
    u64 tickCount;
    KeyStates keyStates;
} AppMemory;

#define AppTick(name) void name(AppMemory *appMemory)
typedef AppTick(appTickT);