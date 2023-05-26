#!/bin/bash

OUTPUT_NAME="login_server_linux_x64"
SOURCES="../src/win32_login_server.c"

DEFINES_SHARED=""
DEFINES="$DEFINES_SHARED"
DEFINES_D="$DEFINES_SHARED -DYOTE_INTERNAL"

LIBS_SHARED="-luser32 -lkernel32 -lws2_32 -lwinmm"
LIBS="$LIBS_SHARED -lvcruntime"
LIBS_D="$LIBS_SHARED"

FLAGS_COMPILE_SHARED="-Wall"
FLAGS_COMPILE="$FLAGS_COMPILE_SHARED -O2"
FLAGS_COMPILE_D="$FLAGS_COMPILE_SHARED -O0 -g -fsanitize=address"

FLAGS_LINK_SHARED=""
FLAGS_LINK="$FLAGS_LINK_SHARED -s"
# FLAGS_LINK_D="$FLAGS_LINK_SHARED -L/path/to/PerformanceAPI_MTd.lib"

COMPILE_ARGS="-o $OUTPUT_NAME $DEFINES $FLAGS_COMPILE $SOURCES $FLAGS_LINK $LIBS"
COMPILE_ARGS_D="-o $OUTPUT_NAME $DEFINES_D $FLAGS_COMPILE_D $SOURCES $FLAGS_LINK_D $LIBS_D"

if [ ! -d "build_login_server_linux_x64" ]; then
  mkdir build_login_server_linux_x64
fi
pushd build_login_server_linux_x64

gcc $FLAGS_COMPILE_D -o schema_tool ../src/schema_tool.c -lz
./schema_tool ../schema/login_udp_11.schm ../schema/output/login_udp_11.c

echo "LOCKED" > .reload-lock
gcc $FLAGS_COMPILE_D -o login_server_module.so ../src/h1z1_login_server.c $DEFINES_D -shared $FLAGS_LINK_D $LIBS_D
rm .reload-lock

gcc $FLAGS_COMPILE_D -o login_server ../src/win32_login_server.c $DEFINES_D $FLAGS_LINK_D $LIBS_D

# If "packets" directory exists, remove it
# if [ -d "packets" ]; then
#   rm -r packets
# fi

popd
