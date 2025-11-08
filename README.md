# Samba for KasperskyOS

> This version of Samba is adapted for use on KasperskyOS.

## What is a Samba for KasperskyOS?

The Samba for KasperskyOS is based on the original Samba version [4.15](https://github.com/samba-team/samba/tree/v4-15-stable). Please refer to [README.md](https://github.com/samba-team/samba/blob/master/README.md) for more information about the original Samba that is not related to this project.

Currently, subprocess creation isn't available in KasperskyOS Community Edition. Therefore, separate threads are created to execute client requests. A thread executes a client request and then terminates. Other limitations and known issues are described in the [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=limitations_and_known_problems).

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
    - [_kos\_client\_ls_](#kos_client_ls)
      - [Definition](#definition-4)
      - [Parameters](#parameters-3)
      - [Return value](#return-value-3)
    - [_kos\_client\_ls\_stat\_free_](#kos_client_ls_stat_free)
      - [Definition](#definition-5)
      - [Parameters](#parameters-4)
    - [_kos\_client\_rm_](#kos_client_rm)
      - [Definition](#definition-6)
      - [Parameters](#parameters-5)
      - [Return value](#return-value-4)
    - [_kos\_client\_mkdir_](#kos_client_mkdir)
      - [Definition](#definition-7)
      - [Parameters](#parameters-6)
      - [Return value](#return-value-5)
    - [_kos\_client\_rmdir_](#kos_client_rmdir)
      - [Definition](#definition-8)
      - [Parameters](#parameters-7)
      - [Return value](#return-value-6)
  - [Trademarks](#trademarks)
  - [Contributing](#contributing)
  - [License](#license)

## Getting started

### Prerequisites

1. [Install](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=sdk_install_and_remove) the KasperskyOS Community Edition SDK version 1.4. You can download it for free from
[os.kaspersky.com](https://os.kaspersky.com/development/). For more information, see [System requirements](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=system_requirements).
1. Copy source files to your project directory. All files that are required to build the Samba for KasperskyOS and examples of KasperskyOS-based solutions are located in the [`./kos`](kos) directory.
1. Run the `source /opt/KasperskyOS-Community-Edition-<version>/common/set_env.sh` to make all the required environment variables available in the current session.

[⬆ Back to Top](#Table-of-contents)

### Building the Samba for KasperskyOS

KasperskyOS Community Edition does not contain openssl headers, but this project depends on them. To obtain them, run the following commands:
```
$ git submodule update --init --depth=1 third_party/openssl
$ (cd third_party/openssl && ./config && make build_generated)
```
If you clone this repository with `--recurse-submodules` option, you will not need to run the `git submodule update --init` command.

Go to the [./kos/samba](./kos/samba/) directory and run the following commands to build the Samba for KasperskyOS:
```
$ cmake -B build -D CMAKE_TOOLCHAIN_FILE="$KOSCEDIR/toolchain/share/toolchain-aarch64-kos.cmake" -D CMAKE_INSTALL_PREFIX="$KOSCEDIR/sysroot-aarch64-kos"
$ cmake --build build
```
The Samba for KasperskyOS is built using the CMake build system, which is provided in the KasperskyOS Community Edition SDK.

[⬆ Back to Top](#Table-of-contents)

### Installing and removing the Samba for KasperskyOS

To install the Samba for KasperskyOS to the KasperskyOS Community Edition SDK, go to the [./kos/samba](./kos/samba/) and run the following command:
```
$ cmake --install build
```

To remove the Samba for KasperskyOS from the KasperskyOS Community Edition SDK, go to the [./kos/samba](./kos/samba/) and run the following command:
```
$ cmake --build build --target uninstall
```

[⬆ Back to Top](#Table-of-contents)

## Usage

When you develop a KasperskyOS-based solution, use the [recommended structure of project directories](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=cmake_using_sdk_cmake) to simplify usage of CMake scripts.

To include a Samba server in your KasperskyOS-based solution, follow these steps:

1. Add the `find_package()` command to the `./CMakeLists.txt` root file to find and load the `samba` package.
   ```
   find_package (samba REQUIRED)
   ```
   For more information about the `./CMakeLists.txt` root file, see the [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=cmake_lists_root).
1. Add the `Smbd` program to a list of program executable files defined in the `./einit/CMakeLists.txt` file as follow:
   ```
   set (ENTITIES
        samba::Smbd
        ...)
   ```
   For more information about the `./einit/CMakeLists.txt` file for building the `Einit` initializing program, see the [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=cmake_lists_einit).
1. Specify a list of IPC channels that connect the `Smbd` program to `VfsNet` and `VfsSdCardFs` programs in the `./einit/src/init.yaml.in` template file or using target properties. For more information about the `init.yaml.in` template file, see the [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=cmake_yaml_templates).
1. Create a solution security policy description in the `./einit/src/security.psl` file. For more information about the `security.psl` file, see [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=ssp_descr).
1. Add Samba configuration files to the directory [`./kos/example/smbd/resources`](kos/example/smbd/resources).

A Samba client can be included in your KasperskyOS-based solution in a similar way.

[⬆ Back to Top](#Table-of-contents)

### Examples

* [`./kos/example/smbclient`](./kos/example/smbclient)—Example of developing a solution using the Samba client in KasperskyOS.
* [`./kos/example/smbd`](./kos/example/smbd)—Example of developing a solution using the Samba server in KasperskyOS.

[⬆ Back to Top](#Table-of-contents)

### Tests

See the [`./kos/smbdtest/README.md`](./kos/smbdtest/README.md) file for instructions on how to run tests for the Samba server.

[⬆ Back to Top](#Table-of-contents)

## API

API is defined in the header file [`./source3/client/kos_client.h`](source3/client/kos_client.h). API is designed for server-client interactions.

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

### _kos_client_ls_

Get contents of a directory on the Samba server.

#### Definition

`int kos_client_ls(const char *mask, kos_client_ls_stat_t **stat)`

#### Parameters

- **mask**—Mask used to get the contents of the directory on the Samba server
- **stat**—Pointer to a structure that will store information about the contents of the directory

#### Return value

0 if successful; an error code otherwise.

### _kos_client_ls_stat_free_

Free memory previously allocated by `kos_client_ls` for `kos_client_ls_stat_t`.

#### Definition

`void kos_client_ls_stat_free(kos_client_ls_stat_t *stat);`

#### Parameters

- **stat**—Pointer to the structure returned by `kos_client_ls`

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

[⬆ Back to Top](#Table-of-contents)

## Trademarks

Registered trademarks and endpoint marks are the property of their respective owners.

Active Directory, ActiveX, Authenticode, Azure, BitLocker, Direct3D, DirectShow, DirectX, Excel,
IntelliMirror, Internet Explorer, Microsoft, MSDN, MS-DOS, OpenType, PowerShell, Visual C++, Visual
Studio, Win32, Windows, Windows Media, Windows Phone, Windows Server and Windows Vista are
trademarks of the Microsoft group of companies.

Adobe, PostScript are either registered trademarks or trademarks of Adobe in the United States
and/or other countries.

AFS, AI X, Approach, Blue Gene, DYNIX/ptx, GPFS, IBM, ibm.com, PowerPC, RDN, THINK, Tivoli and
TrueType are trademarks of International Business Machines Corporation, registered in many
jurisdictions worldwide.

AMD, AMD64 are trademarks or registered trademark of Advanced Micro Devices, Inc.

Android, Chrome, Chromium, Google, PROTOBUF and YouTube are trademarks of Google LLC.

Apache is either a registered trademark or a trademark of the Apache Software Foundation in the
United States and/or other countries.

Apple, AppleTalk, Carbon, Leopard, Mac, Macintosh, macOS, Mac OS, Objective-C, OS X, Safari,
Spotlight, Time Machine and Xcode are trademarks of Apple Inc.

Borland is a trademark or registered trademark of Borland Software Corporation.

Catalyst, Cisco, Cisco Systems, ClamAV and Jabber are registered trademarks or trademarks of Cisco
Systems, Inc. and/or its affiliates in the United States and certain other countries.

Dell Technologies, Dell, Celerra, EMC and other trademarks are trademarks of Dell Inc. or its
subsidiaries.

CentOS, CEPH, Fedora and Red Hat are trademarks or registered trademark of Red Hat, Inc. or its
subsidiaries in the United States and other countries.

Debian is a registered trademark of Software in the Public Interest, Inc.

Docker and the Docker logo are trademarks or registered trademarks of Docker, Inc. in the United
States and/or other countries. Docker, Inc. and other parties may also have trademark rights in
other terms used herein.

Dropbox is a trademark of Dropbox, Inc.

Elasticsearch is a trademark of Elasticsearch BV, registered in the U.S. and in other countries.

Firefox, Mozilla are trademarks of the Mozilla Foundation in the U.S. and other countries.

FreeBSD is a registered trademark of The FreeBSD Foundation.

GITLAB is a trademark of GitLab Inc. in the United States and other countries and regions.

Huawei is a trademark of Huawei Technologies Co., Ltd.

Intel, Itanium are trademarks of Intel Corporation or its subsidiaries.

Java, JavaScript, Oracle and Solaris are registered trademarks of Oracle and/or its affiliates.

Linux is the registered trademark of Linus Torvalds in the U.S. and other countries.

MINIO is a trademark of the MinIO Corporation.

MIPS is a trademark or registered trademark of MIPS Technologies, Inc. in the United States and
other countries.

MOTOROLA and the Stylized M Logo are trademarks or registered trademarks of Motorola Trademark
Holdings, LLC.

NetApp is the registered trademark of NetApp, Inc. in the United States and/or other countries.

NetWare, Novell are registered trademarks of Novell Enterprises Inc. in the United States and other
countries.

Nokia is the registered trademark of Nokia Corporation.

OpenSSL is a trademark owned by the OpenSSL Software Foundation.

PGP is a trademark or registered trademark of Symantec Corporation or its affiliates in the U.S. and
other countries.

Python is a trademark or registered trademark of the Python Software Foundation.

QT is a trademark or registered trademark of The Qt Company Ltd.

Raspberry Pi is a trademark of the Raspberry Pi Foundation.

Symantec is the registered trademark of Symantec Corporation or its affiliates in the U.S. and other
countries.

Texas Instruments is a trademark of Texas Instruments.

Ubuntu is a registered trademark of Canonical Ltd.

UNIX is a registered trademark in the United States and other countries, licensed exclusively
through X/Open Company Limited.

Veritas is a trademark or registered trademark of Symantec Corporation or its affiliates in the U.S.
and other countries.

## Contributing

Only KasperskyOS-specific changes can be approved. See [CONTRIBUTING.md](CONTRIBUTING.md) for
detailed instructions on code contribution.

## License

This project is distributable for free under the GNU public license. See [COPYING](COPYING) for more information.

[⬆ Back to Top](#Table-of-contents)
