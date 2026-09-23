#!/bin/sh
# Build the keycapsss/3w6_2040 firmware in a nix shell (see shell.nix),
# so no toolchain needs to be installed on the host.
#
# Usage:
#   ./build_3w6.sh              # build the vial keymap
#   KM=default ./build_3w6.sh   # build another keymap
#   ./build_3w6.sh clean        # extra args are passed to make
#
# Output: keycapsss_3w6_2040_<keymap>.uf2 at the repo root. Flash it by
# holding BOOTSEL while plugging in, then copying the .uf2 to the mounted
# RPI-RP2 drive.
set -eu
cd "$(dirname "$0")"

KB=keycapsss/3w6_2040
KM=${KM:-vial}

# The RP2040/ChibiOS build needs these submodules checked out.
if [ ! -e lib/pico-sdk/CMakeLists.txt ] || [ ! -e lib/chibios/os ]; then
    echo "Initializing git submodules (first run only)..."
    git submodule update --init --recursive \
        lib/chibios lib/chibios-contrib lib/pico-sdk lib/printf
fi

exec nix-shell shell.nix --run "make $KB:$KM $*"
