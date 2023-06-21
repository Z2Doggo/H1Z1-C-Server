IF EXIST LOGIN_PACKETS rmdir /S /Q LOGIN_PACKETS
pushd build_login_server_win_x64
start login_server.exe
popd
