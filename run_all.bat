@echo off

pushd build_login_server_win_x64
IF EXIST packets rmdir /S /Q packets
start login_server_win_x64.exe
popd

pushd build_game_server_win_x64
IF EXIST packets rmdir /S /Q packets
start game_server_win_x64.exe
popd
