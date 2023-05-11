![alt text](https://cutewallpaper.org/21/h1z1-king-of-the-kill-twitter/H1z1-King-Of-The-Kill-Wallpaper-Z1-Battle-Royale-Hd-.jpg)

# An 'H1Z1: King of the Kill' server made in the C programming language (PRIVATE)

## Current Status

- [x] Compile for use, send and receive packets
- [x] Handle Client connection request (you'll still be on the loading screen but the `BaseApi` is setup & connected)
- [x] Send Session, Fingerprint and Encryption
- [x] Make sure the client gets the right data to get to the server list screen
- [x] Zone in-to the game with a character
- [ ] Reverse all vital packets in-order to function as it was then in 2016

## Permission to use
Rhett (Made the server to begin with)
Doggo (Me)
GhostsKappa (H1Emu)
LegendsNeveerrDie (H1Emu)
Chriis (H1Emu)


## Contributions

- Thank you to Jacob Seidelin and QuentinGruber without whom none of this would have been possible.
- Also Thank you to EVERYONE over at [H1Emu Project](https://github.com/QuentinGruber/h1z1-server) for helping us learn many great things.


## Dependencies
The game requirements are the following DirectX and Visual C++ libraries to be installed to work.

VC 2015 Redist [Download from Microsoft](https://www.microsoft.com/en-gb/download/details.aspx?id=48145)

DirectX June 2010 Redist [Download from Guru3D](https://www.guru3d.com/files-get/directx-end-user-runtimes-(june-2010),8.html)


## How to Download
WARNING: This will only work if you have 'Z1: Battle Royale' formerly known as 'H1Z1: King of the Kill' from steam!

Use [DepotDownloader](https://github.com/SteamRE/DepotDownloader)

Example (Downloading H1Z1: King of the Kill)
AppID : 433850  DepotID : 433851   ManifestID : 6098349229565958949

cmd : `dotnet .\DepotDownloader.dll -app 433850 -depot 433851 -manifest 6098349229565958949 -username YOURUSERNAME -password YOURPASSWORD`

## Setup ClientConfig.ini
In the H1Z1 Folder you will have a file called "ClientConfig.ini".

Remove the line ~~Server=Lvshaa-liv-l02.h1z1.net:20042;Lvshaa-liv-l02.h1z1.net:20043;Lvshaa-liv-l02.h1z1.net:20044;Lvshaa-liv-l02.h1z1.net:20045~~ 

Add the following:

- World=None
- Server=127.0.0.1:20042
- usenewui=1
- SessionId=0

At the beginning of this file.

## Launching the Game
Click the `run_all.bat` file in the 'H1Z1-C-Server' folder to run the login-server and zone-server.

## Legal Notes

This project is for Educational Purposes. We are NOT Responsible for your actions using it.
