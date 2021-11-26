#!/bin/bash

export LANG=C
export TARGET="x86_64-pc-kos"
export SDK_PREFIX="/opt/KOS-CE-SDK-RPI4-x86-64-QEMU-0.0.0.40"
BUILD_SIM_TARGET="y"
export PATH="$SDK_PREFIX/toolchain/bin:$PATH"

export CROSS_PATH=${SDK_PREFIX}/toolchain/bin/${TARGET}

export CPP=${CROSS_PATH}-cpp
export AR=${CROSS_PATH}-ar
export AS=${CROSS_PATH}-as
export NM=${CROSS_PATH}-nm
export CC=${CROSS_PATH}-gcc
export CXX=${CROSS_PATH}-g++
export LD=${CROSS_PATH}-ld
export RANLIB=${CROSS_PATH}-ranlib

export LDFLAGS="-L${SDK_PREFIX}/sysroot-x86_64-pc-kos/lib/"

./configure --without-ad-dc --without-ldap --disable-python --with-static-modules='!vfs_snapper,ALL' --without-systemd --without-json --without-libarchive --without-acl-support --without-ads --without-pam --enable-debug
