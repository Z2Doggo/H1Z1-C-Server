@echo off

IF EXIST LOGIN_PACKETS rmdir /S /Q LOGIN_PACKETS
pushd build_login_server
start login_server.exe
popd

IF EXIST GAME_PACKETS rmdir /S /Q GAME_PACKETS
pushd build_game_server
start game_server.exe
popd
