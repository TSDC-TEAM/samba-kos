#!/bin/bash

BUILD=$PWD/build-qemu
mkdir -p $BUILD && cd $BUILD

export LANG=C
export TARGET="aarch64-kos"
export PKG_CONFIG=""
export SDK_PREFIX="/opt/KasperskyOS-Buddies-Edition-1.1.0.33"
export INSTALL_PREFIX=$BUILD/../install
BUILD_SIM_TARGET="y"
export PATH="$SDK_PREFIX/toolchain/bin:$PATH"

cmake -G "Unix Makefiles" \
      -D CMAKE_BUILD_TYPE:STRING=Debug \
      -D CMAKE_INSTALL_PREFIX:STRING=$BUILD/../install \
      -D CMAKE_TOOLCHAIN_FILE=$SDK_PREFIX/toolchain/share/toolchain-${TARGET}.cmake \
      ../ && make -j$(nproc) sim
