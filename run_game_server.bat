IF EXIST GAME_PACKETS rmdir /S /Q GAME_PACKETS
pushd build_game_server
start game_server.exe
popd
