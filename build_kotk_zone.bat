@echo off

IF NOT EXIST build_kotk_zone_server mkdir build_kotk_zone_server
pushd build_kotk_zone_server

gcc -o schema_tool.exe -g -O2 ../src/schema_tool.c -lm
schema_tool.exe ../schema/client_protocol_1087.schm ../schema/output/client_protocol_1087.c

<<<<<<< HEAD
gcc -shared -o zone_server_module.dll -g -O0 ../src/kotk_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm
=======
gcc -shared -o zone_server_module.dll -g -O2 ../src/kotk_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm
>>>>>>> 215f4353346507dd61aeefb9a988d9fe5b650f5f

gcc -o zone_server.exe -g -O2 ../src/win32_zone_server.c -DYOTE_INTERNAL -luser32 -lkernel32 -lws2_32 -lwinmm

popd
