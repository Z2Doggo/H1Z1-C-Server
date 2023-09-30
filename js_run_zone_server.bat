IF EXIST GAME_PACKETS rmdir /S /Q GAME_PACKETS
pushd build_js_zone_server
start zone_server.exe
popd
