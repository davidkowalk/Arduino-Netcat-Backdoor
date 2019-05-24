# Arduino Typer

	Proof Of Concept. Not intended for real life use.
	I can't take responsibillity for stuff other People do with this
Attacks a Windows machine running Windows 7 or later, creating a persistent Backdoor.

## Funtionallity
The Arduino-script saves a batch script from a server into the Windows startup-folder. This script checks, wether a netcat executable exists in a certain location and saves it from the server if necessary and then starts it, linking to the command prompt. Anyone can therefor enter the machines command-prompt.

The Script then sends a request to the server that includes the machines IP-address.

