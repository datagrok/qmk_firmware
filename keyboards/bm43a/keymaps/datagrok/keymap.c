#include QMK_KEYBOARD_H
#include "feature_cdeq.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,         KC_Q,    KC_W,      KC_E,    KC_R,      KC_T,    KC_Y,      KC_U,    KC_I,      KC_O,    KC_P,    KC_BSPC,
        LCTL_T(KC_TAB), KC_A,    KC_S,      KC_D,    KC_F,      KC_G,    KC_H,      KC_J,    KC_K,      KC_L,    /*,      */RCTL(KC_SCLN),
        KC_LSFT,        /*,      */KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,      KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_RSPC,
        MO(2),          KC_LGUI, KC_LALT,   /*,      */MO(1),   /*,      */KC_SPC,  /*,      */KC_RALT, KC_RGUI, KC_NO,   MO(2)
        ),
    [1] = LAYOUT(
        KC_TILD,        KC_GRV,  KC_NO,     KC_UP,   KC_NO,     KC_NO,   KC_EQL,    KC_CIRC, KC_AMPR,   KC_PERC, KC_PLUS, KC_ASTR,
        KC_TRNS,        KC_NO,   KC_LEFT,   KC_DOWN, KC_RGHT,   KC_NO,   KC_PIPE,   KC_AT,   KC_DLR,    KC_HASH, /*,      */KC_ENT,
        KC_BSLS,        /*,      */KC_LT,   KC_LBRC, KC_LPRN,   KC_LCBR, KC_RCBR,   KC_RPRN, KC_RBRC,   KC_GT,   KC_MINS, KC_SLSH,
        TT(3),          KC_TRNS, KC_TRNS,   /*,      */KC_TRNS, /*,      */KC_UNDS, /*,      */KC_TRNS, KC_TRNS, KC_TRNS, TT(3)
        ),
    [2] = LAYOUT(
        KC_NO,          KC_NO,   KC_F10,    KC_F7,   KC_F8,     KC_F9,   KC_EQL,    KC_7,    KC_8,      KC_9,    KC_PLUS, KC_ASTR,
        KC_NO,          KC_NO,   KC_F11,    KC_F4,   KC_F5,     KC_F6,   KC_NO,     KC_4,    KC_5,      KC_6,    /*,      */KC_ENT,
        KC_NO,          /*,      */KC_F12,  KC_F1,   KC_F2,     KC_F3,   KC_NO,     KC_1,    KC_2,      KC_3,    KC_MINS, KC_SLSH,
        KC_TRNS,        KC_TRNS, KC_TRNS,   /*,      */TT(3),   /*,      */KC_TRNS, /*,      */KC_0,    KC_DOT,  KC_NO,   KC_TRNS
        ),
    [3] = LAYOUT(
        MO(4),          KC_NO,   KC_NO,     KC_PGUP, KC_NO,     KC_VOLU, KC_PEQL,   KC_P7,   KC_P8,     KC_P9,   KC_PPLS, KC_PAST,
        KC_NO,          KC_NO,   KC_HOME,   KC_PGDN, KC_END,    KC_VOLD, KC_NLCK,   KC_P4,   KC_P5,     KC_P6,   /*,      */KC_PENT,
        KC_NO,          /*,      */KC_MPRV, KC_MPLY, KC_MNXT,   KC_MUTE, RESET,     KC_P1,   KC_P2,     KC_P3,   KC_PMNS, KC_PSLS,
        KC_TRNS,        KC_NO,   KC_NO,     /*,      */KC_TRNS, /*,      */KC_TRNS, /*,      */KC_P0,   KC_PDOT, KC_NO,   KC_TRNS
        ),
    [4] = LAYOUT(
        KC_TRNS, BL_TOGG, BL_DEC,  BL_INC,  BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return \
        process_record_cdeq(keycode, record);
}
