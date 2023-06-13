IF EXIST LOGIN_PACKETS rmdir /S /Q LOGIN_PACKETS
pushd build_login_server
start login_server.exe
popd
