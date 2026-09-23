# Nix shell with everything needed to build the keycapsss/3w6_2040 firmware.
#
# Used by ./build_3w6.sh, or directly:
#   nix-shell --run 'make keycapsss/3w6_2040:vial'
#   nix-shell            # interactive shell with qmk + toolchain on PATH
{ pkgs ? import (fetchTarball {
    # nixpkgs pinned (nixos-unstable snapshot, 2026-09-01) so this still
    # builds identically years from now. Bump url + sha256 together to update.
    url = "https://github.com/NixOS/nixpkgs/archive/a311611.tar.gz";
    sha256 = "0qbzjra0z5v7fwzji7j2h7g632a5zg2934v3j4555n6xnwsx9sv7";
  }) { }
}:

pkgs.mkShell {
  packages = with pkgs; [
    qmk              # QMK CLI + its python environment
    gcc-arm-embedded # arm-none-eabi toolchain for the RP2040
    gnumake
    git
  ];
}
