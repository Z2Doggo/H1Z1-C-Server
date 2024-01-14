@echo off
pushd build_kotk_login_server
IF EXIST packets rmdir /S /Q packets
start loginServer.exe
popd

pushd build_kotk_zone_server
IF EXIST packets rmdir /S /Q packets
start zoneServer.exe
popd
