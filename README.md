# Samba for KasperskyOS

>This version of the Samba is adapted for use on KasperskyOS.

## What is a Samba for KasperskyOS?

The Samba for KasperskyOS is based on the original version of Samba [4.15](https://github.com/samba-team/samba/tree/v4-15-stable).
Please refer to [README.md](https://github.com/samba-team/samba/blob/master/README.md) for more
information about the original Samba that is not related to this project.

Currently, subprocess creation isn't available in KasperskyOS Community Edition. Therefore, separate
threads are created to execute client requests. A thread executes a client request and then terminates.
Other limitations and known issues are described in the
[KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_limitations_and_known_problems).

## Table of contents

- [Samba for KasperskyOS](#samba-for-kasperskyos)
  - [What is a Samba for KasperskyOS?](#what-is-a-samba-for-kasperskyos)
  - [Table of contents](#table-of-contents)
  - [Getting started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building the Samba for KasperskyOS](#building-the-samba-for-kasperskyos)
    - [Installing and removing the Samba for KasperskyOS](#installing-and-removing-the-samba-for-kasperskyos)
  - [Usage](#usage)
    - [Examples](#examples)
    - [Tests](#tests)
  - [API](#api)
    - [_kos\_client\_connect_](#kos_client_connect)
      - [Definition](#definition)
      - [Parameters](#parameters)
      - [Return value](#return-value)
    - [_kos\_client\_disconnect_](#kos_client_disconnect)
      - [Definition](#definition-1)
    - [_kos\_client\_get\_file_](#kos_client_get_file)
      - [Definition](#definition-2)
      - [Parameters](#parameters-1)
      - [Return value](#return-value-1)
    - [_kos\_client\_put\_file_](#kos_client_put_file)
      - [Definition](#definition-3)
      - [Parameters](#parameters-2)
      - [Return value](#return-value-2)
    - [_kos\_client\_rm_](#kos_client_rm)
      - [Definition](#definition-4)
      - [Parameters](#parameters-3)
      - [Return value](#return-value-3)
    - [_kos\_client\_mkdir_](#kos_client_mkdir)
      - [Definition](#definition-5)
      - [Parameters](#parameters-4)
      - [Return value](#return-value-4)
    - [_kos\_client\_rmdir_](#kos_client_rmdir)
      - [Definition](#definition-6)
      - [Parameters](#parameters-5)
      - [Return value](#return-value-5)
    - [_kos\_client\_ls_](#kos_client_ls)
      - [Definition](#definition-7)
      - [Parameters](#parameters-6)
      - [Return value](#return-value-6)
  - [Trademarks](#trademarks)
  - [Contributing](#contributing)
  - [License](#license)

## Getting started

### Prerequisites

1. [Install](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_sdk_install_and_remove)
the KasperskyOS Community Edition SDK. You can download the latest version of KasperskyOS Community
Edition for free from [os.kaspersky.com](https://os.kaspersky.com/development/). Minimum required
version of the KasperskyOS Community Edition SDK is 1.2. For more information, see
[System requirements](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_system_requirements).
1. Copy source files to your project directory. All files that are required to build the Samba
for KasperskyOS and examples of KasperskyOS-based solutions are located in the [`./kos`](kos) directory.
1. Set the environment variable `SDK_PREFIX` to `/opt/KasperskyOS-Community-Edition-<version>`, where
`version` is the version of the KasperskyOS Community Edition SDK that you installed. To do this, run
the following command:
   ```
   $ export SDK_PREFIX=/opt/KasperskyOS-Community-Edition-<version>
   ```

### Building the Samba for KasperskyOS

Run the following script to build the Samba for KasperskyOS:
```
./kos/samba/cross-build.sh
```
The Samba for KasperskyOS is built using the CMake build system, which is provided in the KasperskyOS
Community Edition SDK.

### Installing and removing the Samba for KasperskyOS

To install the Samba for KasperskyOS to the KasperskyOS Community Edition SDK, run the following
script with root privileges:
```
./kos/samba/install.sh
```

To remove the Samba for KasperskyOS from the KasperskyOS Community Edition SDK, run the following
script with root privileges:
```
./kos/samba/uninstall.sh
```

[⬆ Back to Top](#Table-of-contents)

## Usage

When you develop a KasperskyOS-based solution, use the
[recommended structure of project directories](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_cmake_using_sdk_cmake)
to simplify usage of CMake scripts.

To include a Samba server in your KasperskyOS-based solution, follow these steps:

1. Add the `find_package()` command to the [`./kos/example/smbd/CMakeLists.txt`](kos/example/smbd/CMakeLists.txt)
root file to find and load the `smbd` package.
   ```
   find_package (smbd REQUIRED)
   ```
   For more information about the `./kos/example/smbd/CMakeLists.txt` root file, see the
[KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_cmake_lists_root).
1. Add the `Smbd` program to a list of program executable files defined in the
[`./kos/example/smbd/einit/CMakeLists.txt`](kos/example/smbd/einit/CMakeLists.txt) file as follows:
   ```
   set (ENTITIES
        Smbd
        ...)
   ```
   For more information about the `./kos/example/smbd/einit/CMakeLists.txt` file for building
the `Einit` initializing program, see the
[KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_cmake_lists_einit).
1. Specify a list of IPC channels that connect the  `Smbd` program to `VfsNet` and `VfsRamFs` programs
in the [`./kos/example/smbd/einit/src/init.yaml.in`](kos/example/smbd/einit/src/init.yaml.in)
template file. For more information about the `init.yaml.in` template file, see the
[KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_cmake_yaml_templates).
1. Create a solution security policy description in the [`./kos/example/smbd/einit/src/security.psl`](kos/example/smbd/einit/src/security.psl)
file. For more information about the `security.psl` file, see the
[KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.2&customization=KCE_cmake_psl_templates).
1. Add Samba configuration files to the directory [`./kos/example/smbd/resources`](kos/example/smbd/resources).

A Samba client can be included in your KasperskyOS-based solution in a similar way.

### Examples

* [`./kos/example/smbclient`](kos/example/smbclient)—Example of developing a solution using the Samba
client in KasperskyOS.
* [`./kos/example/smbd`](kos/example/smbd)—Example of developing a solution using the Samba server
in KasperskyOS.

### Tests

See the [`./kos/smbdtest/README.md`](kos/smbdtest/README.md) file for instructions on how to run tests
for the Samba server.

[⬆ Back to Top](#Table-of-contents)

## API

API is defined in the header file [`./source3/client/kos_client.h`](source3/client/kos_client.h).
API is designed for server-client interactions.

### _kos_client_connect_

Connect to the Samba server.

#### Definition

`int kos_client_connect(const char *address, int port, const char *user, const char *password)`

#### Parameters

- **address**—IP-address of the Samba server
- **port**—Port of the Samba server
- **user**—User name
- **password**—User password

#### Return value

0 if successful; an error code otherwise.

### _kos_client_disconnect_

Disconnect from the Samba server.

#### Definition

`void kos_client_disconnect()`

### _kos_client_get_file_

Copy a file from the Samba server to a local machine.

#### Definition

`int kos_client_get_file(const char *remote_name, const char *local_name)`

#### Parameters

- **remote_name**—Path to the file on the Samba server
- **local_name**—Path to the file on a local machine

#### Return value
0 if successful; an error code otherwise.

### _kos_client_put_file_

Copy a file from a local machine to the Samba server.

#### Definition

`int kos_client_put_file(const char *remote_name, const char *local_name)`

#### Parameters

- **remote_name**—Path to the file on the Samba server
- **local_name**—Path to the file on a local machine

#### Return value
0 if successful; an error code otherwise.

### _kos_client_rm_

Delete files on the Samba server.

#### Definition

`int kos_client_rm(const char *mask)`

#### Parameters

- **mask**—Mask used to delete files on the Samba server

#### Return value

0 if successful; an error code otherwise.

### _kos_client_mkdir_

Create a directory on the Samba server.

#### Definition

`int kos_client_mkdir(const char *remote_name)`

#### Parameters

- **remote_name**—Path to the directory on the Samba server

#### Return value

0 if successful; an error code otherwise.

### _kos_client_rmdir_

Delete directories on the Samba server.

#### Definition

`int kos_client_rmdir(const char *mask)`

#### Parameters

- **mask**—Mask used to delete directories on the Samba server

#### Return value

0 if successful; an error code otherwise.

### _kos_client_ls_

Get contents of a directory on the Samba server.

#### Definition

`int kos_client_ls(const char *mask, kos_client_ls_stat_t **stat)`

#### Parameters

- **mask**—Mask used to get the contents of the directory on the Samba server
- **stat**—Pointer to a structure that will store information about the contents of the directory

#### Return value

0 if successful; an error code otherwise.

## Trademarks

Registered trademarks and endpoint marks are the property of their respective owners.

Python is a trademark or registered trademark of the Python Software Foundation.

Raspberry Pi is a trademark of the Raspberry Pi Foundation.

## Contributing

Only KasperskyOS-specific changes can be approved. See [CONTRIBUTING.md](CONTRIBUTING.md) for
detailed instructions on code contribution.

## License

This project is distributable for free under the GNU public license. See [COPYING](COPYING) for
more information.

[⬆ Back to Top](#Table-of-contents)
