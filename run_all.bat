@echo off
pushd H1Z1-LoginServer
IF EXIST packets rmdir /S /Q packets
start loginServer.exe
popd

pushd H1Z1-ZoneServer
IF EXIST packets rmdir /S /Q packets
start zoneServer.exe
popd
