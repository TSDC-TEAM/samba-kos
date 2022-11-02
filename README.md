# Samba Server for Kaspersky OS

Version of the Samba Server adapted for use on Kaspersky OS.

For a default build and use, you need to install the Kaspersky OS SDK on your system.
The latest version of the SDK can be downloaded from this [link](https://os.kaspersky.com/development/).

All files required to build an server with Kaspersky OS and an examples of connecting him to your solution are located in the folder:

    ./kos

## Building

For build you need to run the script:

    ./kos/samba/cross-build.sh

## Installation

For easy using the Samba Server in your own solutions on Kaspersky OS, it is recommended to incorporate it in the SDK.
To do this, after the build you will need to run the script with root permissions:

    ./kos/samba/install.sh

## Deinstallation

To remove all files related to Samba from Kaspersky OS SDK, just run the script with root permissions:

    ./kos/samba/uinstall.sh

## Using in your own solutions on Kaspersky OS

To connect Samba to your solution, you need to add the smbd package connection in the cmake build script:

    find_package (smbd REQUIRED)

Next, you need to add the Fpm entity to the list of project entities and give it the required permissions to work with disk, network, etc.

After that, in the folder from which the image of the connected disk will be built, you need to add the Samba configuration files.

For further information on how to add Samba to your solution, see the examples in the folder:

    ./kos/exmaples
