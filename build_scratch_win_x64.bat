@echo off


call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

setlocal EnableDelayedExpansion
setlocal EnableExtensions


set OUTPUT_NAME=scratch_win_x64.exe
set SOURCES="..\src\scratch.c"
set DEFINES=/D_CRT_SECURE_NO_WARNINGS /D_WINSOCK_DEPRECATED_NO_WARNINGS /DFL_DEBUG
set COMPILATION_FLAGS=/Od /Zi /FC /W4 /wd4057
set LINK_FLAGS=/link /DEBUG:FULL user32.lib kernel32.lib ws2_32.lib


IF NOT EXIST build_scratch_win_x64 mkdir build_scratch_win_x64
pushd build_scratch_win_x64
cl /nologo /Fe:schema_tool.exe !DEFINES! !COMPILATION_FLAGS! "..\src\schema_tool.c" /link /DEBUG:FULL
schema_tool.exe ..\schema\test.schm ..\schema\output\test.c
cl /nologo /Fe:!OUTPUT_NAME! !DEFINES! !COMPILATION_FLAGS! !SOURCES! !LINK_FLAGS!
popd
