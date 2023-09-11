@echo off

set OUTPUT_NAME=game_server_win_x64.exe
set SOURCES=..\src\win32_game_server.c

set DEFINES_SHARED=
set DEFINES=%DEFINES_SHARED%
set DEFINES_D=%DEFINES_SHARED% -DYOTE_INTERNAL

set LIBS_SHARED=-luser32 -lkernel32 -lws2_32 -lwinmm
set LIBS=%LIBS_SHARED% -lmsvcrt
set LIBS_D=%LIBS_SHARED% -lmsvcrt

set FLAGS_COMPILE_SHARED=-Wall
set FLAGS_COMPILE=%FLAGS_COMPILE_SHARED% -O1
set FLAGS_COMPILE_D=%FLAGS_COMPILE_SHARED% -O1 -g

set FLAGS_LINK_SHARED=
set FLAGS_LINK=%FLAGS_LINK_SHARED%
set FLAGS_LINK_D=%FLAGS_LINK_SHARED%

set COMPILE_ARGS=-o %OUTPUT_NAME% %DEFINES% %FLAGS_COMPILE% %SOURCES% %FLAGS_LINK% %LIBS%
set COMPILE_ARGS_D=-o %OUTPUT_NAME% %DEFINES_D% %FLAGS_COMPILE_D% %SOURCES% %FLAGS_LINK_D% %LIBS_D%

IF NOT EXIST build_game_server_win_x64 mkdir build_game_server_win_x64
pushd build_game_server_win_x64

gcc -o schema_tool.exe %FLAGS_COMPILE_D% -g -c "..\src\schema_tool.c"
.\schema_tool.exe ..\schema\client_protocol_1087.schm ..\schema\output\client_protocol_1087.c
gcc -o game_server_module.dll -O1 -g "..\src\h1z1_game_server.c" %FLAGS_COMPILE_D% %DEFINES_D% -shared %FLAGS_LINK_D% %LIBS_D%

echo LOCKED > .reload-lock
del .reload-lock

gcc -o game_server.exe -O1 -g "..\src\win32_game_server.c" %FLAGS_COMPILE_D% %DEFINES_D% %FLAGS_LINK_D% %LIBS_D%
popd
