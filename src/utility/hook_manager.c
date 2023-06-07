#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define HOOK_COUNT 10
#define ASYNC_HOOK_COUNT 4

typedef struct FunctionHookType FunctionHookType;
struct FunctionHookType {
    bool boolean;
    void* voidptr;
};

typedef struct AsyncHookType AsyncHookType;
struct AsyncHookType {
    bool boolean;
    void* voidptr;
};

typedef struct Hooks Hooks;
struct Hooks {
    char* hookName;
    size_t HookLen;
    // Add more hook names as needed
};

typedef struct AsyncHooks AsyncHooks;
struct AsyncHooks {
    char* hookName;
    size_t HookLen;
    // Add more async hook names as needed
};

typedef struct HookManager HookManager;
struct HookManager {
    FunctionHookType (*hooks[HOOK_COUNT])(void* args);
    AsyncHookType (*asyncHooks[ASYNC_HOOK_COUNT])(void* args);
    bool enableHooks;
};

void hook(HookManager* hook, Hooks hookName, FunctionHookType (*func)(void* args)) {
    hook->hooks[hookName.HookLen] = func;  // Access the HookLen member
}

void hookAsync(HookManager* hook, AsyncHooks hookName, AsyncHookType (*func)(void* args)) {
    hook->asyncHooks[hookName.HookLen] = func;  // Access the HookLen member
}

bool checkHook(HookManager* hook, Hooks hookName, void* args) {
    if (hook->hooks[hookName.HookLen] != NULL) {  // Access the HookLen member
        FunctionHookType result = hook->hooks[hookName.HookLen](args);  // Access the HookLen member
        return result.boolean;
    }
    return true;
}

bool checkAsyncHook(HookManager* hook, AsyncHooks hookName, void* args) {
    if (hook->asyncHooks[hookName.HookLen] != NULL) {  // Access the HookLen member
        AsyncHookType result = hook->asyncHooks[hookName.HookLen](args);  // Access the HookLen member
        return result.boolean;
    }
    return true;
}
