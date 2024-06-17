# KasperskyOS Samba client example

> An example of a KasperskyOS-based solution using a Samba client.

## Table of contents
- [KasperskyOS Samba client example](#kasperskyos-samba-client-example)
  - [Table of contents](#table-of-contents)
  - [Solution overview](#solution-overview)
    - [List of programs](#list-of-programs)
    - [Solution scheme](#solution-scheme)
    - [Initialization description](#initialization-description)
    - [Security policy description](#security-policy-description)
  - [Getting started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building the example](#building-the-example)
  - [Usage](#usage)

## Solution overview

### List of programs

* `TestClient`—Program that initializes the network interface `en0` and interacts with the Samba server by calling API methods
* `VfsNet`—Networking program
* `Dhcpcd`—DHCP client
* `VfsRamFs`—File system program
* `BSP`—Driver for configuring pin multiplexing parameters (pinmux)
* `GPIO`—GPIO support driver
* `RAMDisk`—Block device driver of a virtual drive in RAM

[⬆ Back to Top](#Table-of-contents)

### Solution scheme

```mermaid
graph LR
  classDef Ksp fill:#006d5d, stroke:#006d5d, color:white;
  classDef SubKOS fill:#e8e8e8, stroke:#e8e8e8;
  classDef Hdd fill:#bfe9e3, stroke:#006d5d;
  node1(Samba server)<--->|"SMB"|node2("Samba client for KasperskyOS")
    subgraph KOS ["KasperskyOS"]
    node2
  end
  class node2 Ksp
  class KOS SubKOS
```

[⬆ Back to Top](#Table-of-contents)

### Initialization description

Statically created IPC channels:

* `testclient.TestClient` → `kl.VfsRamFs`
* `testclient.TestClient` → `kl.VfsNet`
* `kl.VfsNet` → `kl.drivers.BSP`
* `kl.VfsNet` → `kl.drivers.GPIO`
* `kl.rump.Dhcpcd` → `kl.VfsRamFs`
* `kl.rump.Dhcpcd` → `kl.VfsNet`
* `kl.VfsRamFs` → `kl.drivers.RAMDisk`

The [`./einit/src/init.yaml.in`](einit/src/init.yaml.in) template is used to automatically generate a part of the solution initialization description file `init.yaml`. For more information about the `init.yaml.in` template file, see the [KasperskyOS Community Edition Online Help](https://support.kaspersky.com/help/KCE/1.1/en-US/cmake_yaml_templates.htm).

[⬆ Back to Top](#Table-of-contents)

### Security policy description

The [`./einit/src/security.psl`](einit/src/security.psl) file contains a solution security policy description. For more information about the `security.psl` file, see [Describing a security policy for a KasperskyOS-based solution](https://support.kaspersky.com/help/KCE/1.1/en-US/ssp_descr.htm).

[⬆ Back to Top](#Table-of-contents)

## Getting started

### Prerequisites

1. Make sure that you have installed the latest version of the [KasperskyOS Community Edition SDK](https://os.kaspersky.com/development/).
1. Set the environment variable `SDK_PREFIX` to `/opt/KasperskyOS-Community-Edition-<version>`, where `version` is the version of the KasperskyOS Community Edition SDK that you installed. To do this, run the following command:
   ```
   $ export SDK_PREFIX=/opt/KasperskyOS-Community-Edition-<version>
   ```

[⬆ Back to Top](#Table-of-contents)

### Building the example

The Samba client for KasperskyOS is built using the CMake build system, which is provided in the KasperskyOS Community Edition SDK.

To build the example to run on QEMU, go to the directory with the example and run the following command:
```
$ ./cross-build.sh
```
Running `cross-build.sh` creates a KasperskyOS-based solution image that includes the example. The `kos-qemu-image` solution image is located in the `./build/einit` directory.

[./testclient/CMakeLists.txt](testclient/netinit/CMakeLists.txt)—CMake commands for building the `TestClient` program.

[./einit/CMakeLists.txt](einit/CMakeLists.txt)—CMake commands for building the `Einit` program and the solution image.

[./CMakeLists.txt](CMakeLists.txt)—CMake commands for building the solution.

[⬆ Back to Top](#Table-of-contents)

## Usage

1. Configure any Samba server available to you:
    * [Create an account](https://www.cyberciti.biz/faq/adding-a-user-to-a-samba-smb-share/) with the username `test` and password `12345678`.
    * Add the following parameters to the `/etc/samba/smb.conf` file:
      ```
      [public]
      path = /home/test
      valid users = test
      writeable = yes
      ```
   If you already have a Samba server configured, you can replace the parameters in the example code [./testclient/main.c](testclient/main.c) with the required parameters.
1. Run the Samba server.
1. To run the example on QEMU, go to the directory with the Samba client example and run the following command:
   ```
   $ ./cross-build.sh
   ```
   For more information about running the example on Raspberry Pi 4 B, see the [KasperskyOS Community Edition Online Help](https://support.kaspersky.com/help/KCE/1.1/en-US/running_sample_programs_rpi.htm).
1. Wait until the program activity report is fully generated in the standard output. The report ends with information about the API methods called by the Samba client and results of executing these methods.

[⬆ Back to Top](#Table-of-contents)
