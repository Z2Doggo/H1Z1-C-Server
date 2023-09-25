@echo off

pushd build_js_login_server
IF EXIST packets rmdir /S /Q packets
start login_server.exe
popd

pushd build_js_zone_server
IF EXIST packets rmdir /S /Q packets
start zone_server.exe
popd
