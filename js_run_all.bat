@echo off

<<<<<<<< HEAD:kotk_run_all.bat
pushd build_kotk_login_server
========
pushd build_js_login_server
>>>>>>>> 215f4353346507dd61aeefb9a988d9fe5b650f5f:js_run_all.bat
IF EXIST packets rmdir /S /Q packets
start login_server.exe
popd

<<<<<<<< HEAD:kotk_run_all.bat
pushd build_kotk_zone_server
========
pushd build_js_zone_server
>>>>>>>> 215f4353346507dd61aeefb9a988d9fe5b650f5f:js_run_all.bat
IF EXIST packets rmdir /S /Q packets
start zone_server.exe
popd
