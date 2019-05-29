# Arduino - Netcat - Backdoor for Windows
> Name suggestions welcome.

	Proof Of Concept. Not intended for real life use.
	I can't take responsibillity for stuff other People do with this
Attacks a Windows machine running Windows 7 or later, creating a persistent Backdoor.

## Funtionallity
The Arduino-script saves a batch script from a server into the Windows startup-folder. This script checks, wether a netcat executable exists in a certain location and saves it from the server if necessary and then starts it, linking to the command prompt. Anyone can therefor enter the machines command-prompt.

The Script then sends a request to the server that includes the machines IP-address.

## Environment Requirements

### Arduino script
The Arduino script can run on any arduino that supports the [Arduino Keyboard Library](https://github.com/arduino-libraries/Keyboard), specifically those that are based on the ATmega32U4 boards.

These include:
- Pro Micro
- Leonardo
- Yun
- Due
- Zero
- and more

You can find further information [here](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/).

### Batch Script
Batch is the Windows-native scripting language. The batch-script included in this project is written for Windows 10 but will be compatible with the most, recent Windows versions.

### Node server
The Node server has been written and tested on version 10.15.1.0. To successfully receive and process information the script may need permissions from the administrator and if information is transmitted across networks you may have to unlock the port 25565 on your router.

## Integration into your own attack

### Setting up the file host
First you will need to upload batch file and the [netcat](https://github.com/diegocr/netcat) to a file hosting service. It is important, that you can get a direct download-link. Viable services are, for example:
- [bplaced](https://bplaced.net)
- [1fitcher](https://1fichier.com/)

### Installing the node server
To get the node server running, you first need a version of node on your system. I advise node 10.15.1.0 or newer. The server requires the node-module "net" which is placed in the repository or it can be installed via

	npm install net
when all files are placed in one directory you can start the server by running

	node Server.js
I also advice to use a server with a static IP for longer missions.

### IPs

Make sure, to adjust both the URL of the batch file in the Arduino script and the URL of the node-server in the batch file.
