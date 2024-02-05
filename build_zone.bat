@echo off

IF NOT EXIST H1Z1-ZoneServer mkdir H1Z1-ZoneServer
pushd H1Z1-ZoneServer

gcc -o schema_tool.exe -g -O2 ../src/schema_tool.c -lm
schema_tool.exe ../schema/client_protocol_1087.schm ../schema/output/client_protocol_1087.c

gcc -shared -o zoneModule.dll -g -O0 ../src/kotk_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

gcc -o zoneServer.exe -g -O2 ../src/win32_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

popd
