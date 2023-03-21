@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64

setlocal EnableDelayedExpansion
setlocal EnableExtensions


set OUTPUT_NAME=proxy_win_x64.exe
set SOURCES="..\src\win_proxy.c"

set DEFINES_SHARED=/DINTERNAL
set LIBS_SHARED=user32.lib kernel32.lib ws2_32.lib winmm.lib


set FLAGS_COMPILE_SHARED=/FC /nologo /W4 /utf-8 /validate-charset
set FLAGS_COMPILE=!FLAGS_COMPILE_SHARED! /MT /O2 /GS-
set FLAGS_COMPILE_D=!FLAGS_COMPILE_SHARED! /MTd /Od /Zi /RTC1 /fsanitize=address

set FLAGS_LINK_SHARED=/link /incremental:no /subsystem:console
set FLAGS_LINK=!FLAGS_LINK_SHARED! /fixed /opt:icf /opt:ref ucrt.lib libvcruntime.lib
set FLAGS_LINK_D=!FLAGS_LINK_SHARED! libucrtd.lib libvcruntimed.lib


IF NOT EXIST build_proxy_win_x64 mkdir build_proxy_win_x64
pushd build_proxy_win_x64


rem cl /nologo /Fe:schema_tool.exe /Od /Zi /FC "..\src\schema_tool.c" /link /debug:full
rem schema_tool.exe ..\schema\test.schm ..\schema\output\test.c

rem cl /Fe:!OUTPUT_NAME! !DEFINES_SHARED! !FLAGS_COMPILE! !SOURCES! !FLAGS_LINK! !LIBS_SHARED!
cl /Fe:!OUTPUT_NAME! !DEFINES_SHARED! !FLAGS_COMPILE_D! !SOURCES! !FLAGS_LINK_D! !LIBS_SHARED!


popd
