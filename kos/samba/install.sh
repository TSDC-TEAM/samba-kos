#!/bin/bash

BUILD=$(pwd)/build
cd $BUILD

export SDK_PREFIX="/opt/KasperskyOS-Community-Edition-1.1.0.23"

$SDK_PREFIX/toolchain/bin/cmake --install .
