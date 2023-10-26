@echo off
pushd build_kotk_login_server
IF EXIST packets rmdir /S /Q packets
start login_server.exe
popd

pushd build_kotk_zone_server
IF EXIST packets rmdir /S /Q packets
start zone_server.exe
popd
