# Disabling VIA/VIAL makes the keyboard work with the KVM switch.
# However, it's obviously a bit pointless to have this in the VIAL
# repository, just to disable it. The 3w6 keyboard with RP2040
# isn't in the qmk repository, so making the change here was easier.
VIA_ENABLE  = no
VIAL_ENABLE = no
