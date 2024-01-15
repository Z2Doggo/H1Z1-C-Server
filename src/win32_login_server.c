#include <stdio.h>
#include <stdbool.h>

#define YOTE_PLATFORM_USE_SOCKETS
#define YOTE_PLATFORM_WINDOWS

#include "yote.h"
#include "yote_platform.h"
#include "game_server.h"

#define ModuleFile "loginModule.dll"
#define ModuleFIleTemp "loginModuleTemp.dll"

typedef struct AppCode
{
	HMODULE hModule;
	FILETIME lastWriteTime;
	appTickT *tickFunc;
	bool isValid;
} AppCode;

AppTick(appTickStub)
{
	UNUSED(appMemory);
}

FILETIME GetLastWriteTime(char *filename)
{
	FILETIME result = {0};
	WIN32_FILE_ATTRIBUTE_DATA file_data;

	if (GetFileAttributesExA(filename, GetFileExInfoStandard, &file_data))
	{
		result = file_data.ftLastWriteTime;
	}

	return result;
}

AppCode AppCodeLoad()
{
	AppCode result = {0};

	result.lastWriteTime = GetLastWriteTime(ModuleFile);
	CopyFileA(ModuleFile, ModuleFIleTemp, false);

	result.hModule = LoadLibraryA(ModuleFIleTemp);
	if (result.hModule)
	{
		result.tickFunc = (appTickT *)GetProcAddress(result.hModule, "serverTick");
		result.isValid = !!result.tickFunc;
	}

	if (!result.isValid)
	{
		result.tickFunc = appTickStub;
	}

	return result;
}

void AppCodeUnload(AppCode *AppCode)
{
	if (AppCode->hModule)
	{
		FreeLibrary(AppCode->hModule);
		AppCode->hModule = 0;
	}

	AppCode->isValid = false;
	AppCode->tickFunc = appTickStub;
}

int main(void)
{
	AppMemory appMemory = {
		.api = {
			.folder_create = platform_win_folder_create,
			.buffer_write_to_file = platform_win_buffer_write_to_file,
			.buffer_load_from_file = platform_win_buffer_load_from_file,
			.socket_udp_create_and_bind = platform_win_socket_udp_create_and_bind,
			.receive_from = platform_win_receive_from,
			.send_to = platform_win_send_to,
			.wall_clock = platform_win_wall_clock,
			.elapsed_seconds = platform_win_elapsed_seconds,
		},
		.backingMemory.size = MB(100),
		.backingMemory.data = VirtualAlloc(NULL, appMemory.backingMemory.size, MEM_COMMIT, PAGE_READWRITE),
	};

	LARGE_INTEGER performanceFrequency;
	QueryPerformanceFrequency(&performanceFrequency);

	bool isSleepGranualor = timeBeginPeriod(1) == TIMERR_NOERROR;
	f32 tickRate = 128.0f;

	f32 secondsPerTick = 1.0f / tickRate;
	AppCode appCode = AppCodeLoad();

	u64 previousCounter = platform_win_wall_clock();
	bool isRunning = true;

	while (isRunning)
	{
		appCode.tickFunc(&appMemory);
		u64 workCounter = platform_win_wall_clock();

		appMemory.workMs = 1000.0f * platform_win_elapsed_seconds(previousCounter, workCounter);
		f32 elapsedTickSeconds = platform_win_elapsed_seconds(previousCounter, platform_win_wall_clock());

		if (elapsedTickSeconds < secondsPerTick)
		{
			if (isSleepGranualor)
			{
				i32 sleep_ms = (i32)(secondsPerTick * 1000.0f) - (i32)(elapsedTickSeconds * 1000.0f) - 1;

				if (sleep_ms > 0)
				{
					Sleep(sleep_ms);
				}
			}

			while (elapsedTickSeconds < secondsPerTick)
			{
				elapsedTickSeconds = platform_win_elapsed_seconds(previousCounter, platform_win_wall_clock());
			}
		}

		u64 endCounter = platform_win_wall_clock();
		appMemory.tickMs = 1000.0f * platform_win_elapsed_seconds(previousCounter, endCounter);

		previousCounter = endCounter;
		appMemory.tickCount++;
	}

	return 0;
}