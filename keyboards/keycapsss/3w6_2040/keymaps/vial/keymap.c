// Copyright 2021 weteor | 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// enum layers {
//     _ALPHA_QWERTY = 0,
//     _ALPHA_COLEMAK,
//     _SYM,
//     _NAV,
//     _NUM,
//     _CFG,
// };

// The layers were originally generated from a QMK Configurator export;
// this file is now the sole source of truth and is edited by hand.

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    // KVM hotkey macros: double Scroll Lock + a key, or double Right Alt.
    KVM_1,     // SCRL SCRL 1
    KVM_2,     // SCRL SCRL 2
    KVM_UP,    // SCRL SCRL Up
    KVM_DOWN,  // SCRL SCRL Down
    KVM_LEFT,  // SCRL SCRL Left
    KVM_RIGHT, // SCRL SCRL Right
    RALT_2X,   // RAlt RAlt
};

// KVMs watch for the hotkey prefix as ordinary typing; taps sent
// back-to-back at USB speed can be missed, hence the pauses.
#define KVM_TAP_DELAY_MS 50

static void kvm_send(uint16_t keycode) {
    tap_code(KC_SCRL);
    wait_ms(KVM_TAP_DELAY_MS);
    tap_code(KC_SCRL);
    wait_ms(KVM_TAP_DELAY_MS);
    tap_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case KVM_1:     kvm_send(KC_1);    return false;
        case KVM_2:     kvm_send(KC_2);    return false;
        case KVM_UP:    kvm_send(KC_UP);   return false;
        case KVM_DOWN:  kvm_send(KC_DOWN); return false;
        case KVM_LEFT:  kvm_send(KC_LEFT); return false;
        case KVM_RIGHT: kvm_send(KC_RGHT); return false;
        case RALT_2X:
            tap_code(KC_RALT);
            wait_ms(KVM_TAP_DELAY_MS);
            tap_code(KC_RALT);
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
 [_LAYER0] = LAYOUT_split_3x5_3(
 // |               |               |               |               |               |------|               |               |               |               |
    KC_Q,           KC_W,           KC_E,           LCA_T(KC_R),    ALL_T(KC_T),            RALT_T(KC_Y),   LCA_T(KC_U),    KC_I,           KC_O,           KC_P,
    KC_A,           LGUI_T(KC_S),   LALT_T(KC_D),   LCTL_T(KC_F),   LCAG_T(KC_G),           RCAG_T(KC_H),   RCTL_T(KC_J),   RALT_T(KC_K),   RGUI_T(KC_L),   KC_SCLN,
    KC_Z,           SGUI_T(KC_X),   KC_C,           C_S_T(KC_V),    MEH_T(KC_B),            MEH_T(KC_N),    C_S_T(KC_M),    KC_COMM,        SGUI_T(KC_DOT), KC_SLSH,
                                    KC_NO,          LT(3,KC_TAB),   KC_LSFT,                LT(2,KC_ENT),   LT(4,KC_SPC),   KC_NO),

[_LAYER1] = LAYOUT_split_3x5_3(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,                   KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOT,
    KC_A,           KC_R,           KC_S,           KC_T,           KC_D,                   KC_H,           KC_N,           KC_E,           KC_I,           KC_O,
    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                   KC_K,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                    KC_TRNS,        KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,        KC_TRNS),

[_LAYER2] = LAYOUT_split_3x5_3(
    KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_TILD,        KC_PIPE,
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
    KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_EQL,         KC_MINS,                KC_UNDS,        KC_PLUS,        KC_RPRN,        KC_RBRC,        KC_RCBR,
                                    KC_NO,          KC_NO,          KC_TRNS,                KC_NO,          KC_NO,          KC_NO),

[_LAYER3] = LAYOUT_split_3x5_3(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,
    KC_ESC,         KC_MPLY,        KC_VOLD,        KC_VOLU,        KC_MUTE,                KC_PSCR,        KC_SCRL,        KC_PAUS,        KC_INS,         KC_F11,
    KC_MSTP,        KC_MRWD,        KC_MPRV,        KC_MNXT,        KC_MFFD,                KC_APP,         KVM_LEFT,       KVM_RIGHT,      RALT_2X,        KC_F12,
                                    KC_NO,          KC_NO,          KC_TRNS,                KC_NO,          KC_NO,          KC_NO),

[_LAYER4] = LAYOUT_split_3x5_3(
    DF(0),          DF(1),          KVM_UP,         NK_ON,          NK_OFF,                 KC_BTN1,        KC_BTN2,        KC_BSPC,        KC_DEL,         KC_BTN3,
    KVM_DOWN,       OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  KVM_1,                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_WH_U,
    KC_BSLS,        KC_GRV,         KC_QUOT,        KC_DQUO,        KVM_2,                  KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         KC_WH_D,
                                    KC_NO,          KC_NO,          KC_TRNS,                KC_NO,          KC_NO,          KC_NO)

    // clang-format on
};
