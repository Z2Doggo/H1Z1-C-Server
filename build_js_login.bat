@echo off


call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

setlocal EnableDelayedExpansion
setlocal EnableExtensions


set OUTPUT_NAME=login_server_win_x64.exe
set SOURCES="..\src\win32_login_server.c"

set DEFINES_SHARED=
set DEFINES=  !DEFINES_SHARED!
set DEFINES_D=!DEFINES_SHARED! /DYOTE_INTERNAL

set LIBS_SHARED=user32.lib kernel32.lib ws2_32.lib winmm.lib
set LIBS=  !LIBS_SHARED! libvcruntime.lib
rem set LIBS=  !LIBS_SHARED!
rem set LIBS_D=!LIBS_SHARED! libucrtd.lib libvcruntimed.lib
set LIBS_D=!LIBS_SHARED!

set FLAGS_COMPILE_SHARED=/FC /nologo /W4
set FLAGS_COMPILE=  !FLAGS_COMPILE_SHARED! /O2 /GS-
set FLAGS_COMPILE_D=!FLAGS_COMPILE_SHARED! /Od /Zi /RTC1
rem set FLAGS_COMPILE_D=!FLAGS_COMPILE_SHARED! /Od /Zi /RTC1 /fsanitize=address

set FLAGS_LINK_SHARED=/incremental:no
set FLAGS_LINK=  !FLAGS_LINK_SHARED! /fixed /opt:icf /opt:ref
rem set FLAGS_LINK_D=!FLAGS_LINK_SHARED! "D:\WindowsPrograms\Superluminal\Performance\API\lib\x64\PerformanceAPI_MTd.lib"

set COMPILE_ARGS=  /Fe:!OUTPUT_NAME! !DEFINES!   !FLAGS_COMPILE!   !SOURCES! !FLAGS_LINK!   !LIBS!
set COMPILE_ARGS_D=/Fe:!OUTPUT_NAME! !DEFINES_D! !FLAGS_COMPILE_D! !SOURCES! !FLAGS_LINK_D! !LIBS_D!


IF NOT EXIST build_js_login_server mkdir build_js_login_server
pushd build_js_login_server


cl /nologo /Fe:schema_tool.exe /Od /Zi /FC "..\src\schema_tool.c" /link /debug:full
schema_tool.exe ..\schema\js_login_udp_11.schm ..\schema\output\js_login_udp_11.c

echo LOCKED > .reload-lock
cl /Fe:login_server_module.dll "..\src\js_login_server.c"   !FLAGS_COMPILE_D! !DEFINES_D! /LD  /link !FLAGS_LINK_D!                    !LIBS_D!
del .reload-lock

cl /Fe:login_server.exe        "..\src\win32_login_server.c" !FLAGS_COMPILE_D! !DEFINES_D! /MTd /link !FLAGS_LINK_D! /subsystem:console !LIBS_D!


rem IF EXIST packets rmdir /S /Q packets
popd
