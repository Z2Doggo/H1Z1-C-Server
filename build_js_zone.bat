@echo off

IF NOT EXIST build_js_zone_server mkdir build_js_zone_server
pushd build_js_zone_server

gcc -o schema_tool.exe -g -O2 ../src/schema_tool.c -lm
schema_tool.exe ../schema/client_protocol_1080.schm ../schema/output/client_protocol_1080.c

gcc -shared -o zone_server_module.dll -g -O2 ../src/js_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

gcc -o zone_server.exe -g -O2 ../src/win32_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

popd
