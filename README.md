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

## Examples

### smbd

The example demonstrates the creation of a Samba server based on Kaspersky OS, on which a test account is created for the test user (login/password: user/1234).
After building and running the example, you can connect to the server using any Samba client available to you.

    smbclient //localhost/tmp --user=user --port=1490

### smbclient

The example demonstrates the creation of a custom Samba client based on Kaspersky OS using the provided API.

To test the example, you must first configure the Samba server and create an account for a new user.

A guide to setting up a local Samba server is available at this [link](https://wiki.samba.org/index.php/Setting_up_Samba_as_a_Standalone_Server).

The following API functions are available to the client:

#### _kos_client_connect_

Establishing a connection to the Samba server.

##### Definition

`int kos_client_connect(const char *address, int port, const char *user, const char *password)`

##### Parameters

- **address** - IP-address of Samba server
- **port** - port of Samba server
- **user** - user login
- **password** - user password

##### Return value

- **0** - successful connection
- **other** - error code

#### _kos_client_disconnect_

Disconnect from the Samba server.

##### Definition

`void kos_client_disconnect()`

#### _kos_client_get_file_

Copying a file from a Samba server to a local machine.

##### Definition

`int kos_client_get_file(const char *remote_name, const char *local_name)`

##### Parameters

- **remote_name** - path to the file on Samba server
- **local_name** - path to the file on local machine

##### Return value

- **0** - success
- **other** - error code

#### _kos_client_put_file_

Copying a file from the local machine to the Samba server.

##### Definition

`int kos_client_put_file(const char *remote_name, const char *local_name)`

##### Parameters

- **remote_name** - path to the file on Samba server
- **local_name** - path to the file on local machine

##### Return value

- **0** - success
- **other** - error code

#### _kos_client_rm_

Deleting a file on the Samba server.

##### Definition

`int kos_client_rm(const char *mask)`

##### Parameters

- **mask** - mask used to delete files on Samba server

##### Return value

- **0** - success
- **other** - error code

#### _kos_client_mkdir_

Create a new folder on the Samba server.

##### Definition

`int kos_client_mkdir(const char *remote_name)`

##### Parameters

- **remote_name** - path to the folder on Samba server

##### Return value

- **0** - success
- **other** - error code

#### _kos_client_rmdir_

Deleting a folder on the Samba server.

##### Definition

`int kos_client_rmdir(const char *mask)`

##### Parameters

- **mask** - mask used to delete folders on Samba server

##### Return value

- **0** - success
- **other** - error code

#### _kos_client_ls_

Getting the contents of a folder on a Samba server.

##### Definition

`int kos_client_ls(const char *mask, kos_client_ls_stat_t **stat)`

##### Parameters

- **mask** - mask used to listing content of the folder on Samba server
- **stat** - pointer to a structure that will store information about the contents of the folder

##### Return value

- **0** - success
- **other** - error code
