IF EXIST GAME_PACKETS rmdir /S /Q GAME_PACKETS
pushd build_kotk_zone_server
start zoneServer.exe
popd
