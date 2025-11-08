# Samba server's tests

In this project, a dedicated test version of a Samba server is built to execute the tests.
The tests are carried out by running the `run-tests.py` script, which systematically executes the [smbtorture utility](https://linux.die.net/man/1/smbtorture). This utility, included in the `samba-testsuite` package, offers a comprehensive suite of tests that are specifically designed to evaluate Samba server implementations.
The `tests.py` script is used for parsing test results.

## Table of contents
- [Samba server's tests](#samba-servers-tests)
  - [Table of contents](#table-of-contents)
  - [Solution overview](#solution-overview)
    - [List of programs](#list-of-programs)
    - [Initialization description](#initialization-description)
    - [Security policy description](#security-policy-description)
  - [Getting started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building and running a test version of the Samba server](#building-and-running-a-test-version-of-the-samba-server)
      - [CMake input files](#cmake-input-files)
  - [Usage](#usage)

## Solution overview

### List of programs

* `NetInit`—Program that initializes the network interface `en0`
* `Smbd`—Samba server adapted for KasperskyOS
* `VfsSdCardFs`—Program that supports SDCardFS file system
* `VfsNet`—Program that is used for working with the network
* `Dhcpcd`—DHCP client implementation program that gets network interface parameters from an external DHCP server in the background and passes them to the virtual file system
* `DCM`—KasperskyOS Native Dynamic Connection Manager
* `SDCard`—Block device driver of the SDCard
* `EntropyEntity`—Random number generator
* `DNetSrv`—Driver for working with network cards
* `GPIO`—GPIO driver (only for Radxa ROCK 3A)
* `BSP`—Board support package driver
* `PinCtrl`—PinCtrl driver (only for Radxa ROCK 3A)
* `Bcm2711MboxArmToVc`—Mailbox driver (only for Raspberry Pi 4 B)

[⬆ Back to Top](#Table-of-contents)

### Initialization description

<details><summary>Statically created IPC channels</summary>

* `netinit.NetInit` → `kl.VfsNet`
* `netinit.NetInit` → `kl.VfsSdCardFs`
* `samba.Smbd` → `kl.VfsNet`
* `samba.Smbd` → `kl.VfsSdCardFs`
* `kl.rump.Dhcpcd` → `kl.VfsNet`
* `kl.rump.Dhcpcd` → `kl.VfsSdCardFs`
* `kl.VfsNet` → `kl.EntropyEntity`
* `kl.VfsNet` → `kl.drivers.DNetSrv`
* `kl.VfsSdCardFs` → `kl.drivers.SDCard`
* `kl.VfsSdCardFs` → `kl.EntropyEntity`
* `kl.drivers.SDCard` → `kl.drivers.BSP`
* `kl.drivers.SDCard` → `kl.drivers.GPIO` (only for Radxa ROCK 3A)
* `kl.drivers.DNetSrv` → `kl.drivers.Bcm2711MboxArmToVc` (only for Raspberry Pi 4 B)
* `kl.drivers.BSP` → `kl.drivers.Bcm2711MboxArmToVc` (only for Raspberry Pi 4 B)
* `kl.drivers.GPIO` → `kl.drivers.PinCtrl` (only for Radxa ROCK 3A)

</details>

The [`./einit/src/init.yaml.in`](einit/src/init.yaml.in) template is used to automatically generate a part of the solution initialization description file `init.yaml`. For more information about the `init.yaml.in` template file, see the [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=cmake_yaml_templates).

[⬆ Back to Top](#Table-of-contents)

### Security policy description

The [`./einit/src/security.psl`](einit/src/security.psl) file contains a solution security policy description. For more information about the `security.psl` file, see [KasperskyOS Community Edition Online Help](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=ssp_descr).

[⬆ Back to Top](#Table-of-contents)

## Getting started

### Prerequisites

1. Confirm that your host system meets all the
[System requirements](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=system_requirements)
listed in the KasperskyOS Community Edition Developer's Guide.
1. [Install](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=sdk_install_and_remove)
the KasperskyOS Community Edition SDK version 1.4. You can download it for free from
[os.kaspersky.com](https://os.kaspersky.com/development/).
1. Copy the source files of this example to your local project directory.
1. Source the SDK setup script to configure the build environment. This exports the `KOSCEDIR`
  environment variable, which points to the SDK installation directory:
   ```sh
   source /opt/KasperskyOS-Community-Edition-<platform>-<version>/common/set_env.sh
   ```
1. [Build the necessary drivers](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=building_radxa_drivers)
from source only if you intend to run this example on Radxa ROCK 3A hardware. This step is not
required for QEMU or Raspberry Pi 4 B.
1. Make sure you have at least Python 3 version 3.10.0 installed. To install the latest version of
   Python 3, run the following command:
    ```sh
    $ sudo apt-get install python3
    ```
1. Install all dependencies from the [./st/requirements.txt](st/requirements.txt) file.
    ```
    pip3 install -r ./st/requirements.txt
    ```
1. To install the `smbtorture` utility, run the following command:
    ```sh
    $ sudo apt-get install samba-testsuite
    ```

### Building and running a test version of the Samba server

The Samba server in KasperskyOS is built using the CMake build system, which is provided in the KasperskyOS Community Edition SDK.

To build and run the Samba server on QEMU, run the following commands in this directory:
```
$ cmake -B build -D CMAKE_TOOLCHAIN_FILE="$KOSCEDIR/toolchain/share/toolchain-aarch64-kos.cmake"
$ cmake --build build --target {kos-qemu-image|sim}
```
where:
* `kos-qemu-image` creates a KasperskyOS-based solution image for QEMU that includes the example;
* `sim` creates a KasperskyOS-based solution image for QEMU that includes the example and runs it.

To build and run the Samba server on a hardware, run the following commands in this directory:
```
$ cmake -B build -D CMAKE_TOOLCHAIN_FILE="$KOSCEDIR/toolchain/share/toolchain-aarch64-kos.cmake"
$ cmake --build build --target {kos-image|sd-image}
```
where:
* `kos-image` creates a KasperskyOS-based solution image that includes the example;
* `sd-image` creates a file system image for a bootable SD card.

For more information about running tests on a hardware see the following [link](https://click.kaspersky.com/?hl=en-us&link=online_help&pid=kos&version=1.4&customization=KCE&helpid=running_sample_programs_rpi).

[⬆ Back to Top](#Table-of-contents)

#### CMake input files

[./netinit/CMakeLists.txt](netinit/CMakeLists.txt)—CMake commands for building the `NetInit` program.

[./einit/CMakeLists.txt](einit/CMakeLists.txt)—CMake commands for building the `Einit` program and the solution image.

[./CMakeLists.txt](CMakeLists.txt)—CMake commands for building the solution.

[⬆ Back to Top](#Table-of-contents)

## Usage

1. [Build and run](#build-and-run-a-test-version-of-the-samba-server) the test version of the Samba server in KasperskyOS.
1. Wait until the following message appears in the standard output:
    ```
    KOS: skipping start_epmd
    KOS: skipping start_lsasd
    KOS: skipping start_fssd
    ```
1. Go to the [`./st`](st) directory.
    In this directory is located the script `run-tests.py`, developed for easy testing of KasperskyOS-implementation of the Samba server and output of results tests. Syntax for using the `run-tests.py` script:
    ```sh
    python3 ./run-tests.py [-n SERVER_NAME] [-f FILE]
    ```
    where:

    * `-n SERVER_NAME`

    Host name where the Samba server is running. If not specified, the default address `//127.0.0.1` will be used.
    * `-f FILE`

    Full path to the file containing the list of tests implemented in the `smbtorture` utility. If not specified, the default value `tests.txt` will be used. You can modify the list of tests in the file `tests.txt`

    Once the script is run, a sequential test run will begin. Test results and general statistics will be displayed in the standard output. You can redirect the output of the results to a file.
1. Run the `run-tests.py` script from a separate terminal window:
    ```sh
    python3 ./run-tests.py -n //127.0.0.1 -f tests.txt > tests_results.txt
    ```
    This command will run the tests listed in the `tests.txt` file. The results of the tests will be written to the `tests_results.txt` file.
1. If the provided statistics are insufficient, you have the option to utilize the script named `tests.py` for parsing test results. This script provides more detailed information about the tests and allows for the comparison of test results across various versions of the KasperskyOS Community Edition SDK. To work, the `tests.py` script needs the `tests_results.txt` file with the test run results generated at the previous step. Stay in the [`./st`](st) directory and perform the actions you require:

    * To get detailed statistics about the tests, run the following command:
      ```sh
      python3 ./tests.py stat tests_results.txt
      ```
      The statistics should be displayed in the standard output with division into test groups. The following characteristics are displayed for each group:
      * total number of tests (TOTAL)
      * number of successful tests (PASS)
      * number of skipped tests (SKIP)
      * number of failed tests (FAIL)
      * percentage of successful tests = PASS / (TOTAL - SKIP) * 100 (%)
    * To get a list of tests that completed with the specified result, run the following command:
      ```sh
      python3 ./tests.py filter <PASS|SKIP|FAIL> tests_results.txt
      ```
      The list of tests whose execution result is equal to the value passed in the script parameter (`PASS`, `SKIP` or `FAIL`) should be displayed in the standard output.
    * To compare the test results in two files, run the following command:
      ```sh
      python3 ./tests.py diff <file1> <file2>
      ```
      In this command, `file1` and `file2` are the names of files containing the test execution results generated on different runs. The list of tests whose results in `file2` are different from the results in `file1` should be displayed in the standard output.

[⬆ Back to Top](#Table-of-contents)
