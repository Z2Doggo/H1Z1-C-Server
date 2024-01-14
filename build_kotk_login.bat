@echo off

IF NOT EXIST build_kotk_login_server mkdir build_kotk_login_server
pushd build_kotk_login_server

gcc -o schema_tool.exe -g -O2 ../src/schema_tool.c -lm
schema_tool.exe ../schema/kotk_login_udp_11.schm ../schema/output/kotk_login_udp_11.c

gcc -shared -o loginModule.dll -g -O2 ../src/kotk_login_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

gcc -o loginServer.exe -g -O2 ../src/win32_login_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

popd
