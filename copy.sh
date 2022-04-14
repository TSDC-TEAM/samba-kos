#!/bin/bash

set -x
set -v
set -e

sudo mount /dev/mmcblk0p1 ~/mnt/fat32/
sudo cp build-arm/kos/einit/kos-image ~/mnt/fat32/kos-image
sudo sync
sudo umount ~/mnt/fat32
