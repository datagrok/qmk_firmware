#define KF_LAYO SAFE_RANGE
#include "feature_cdeq.h"
#include "feature_default_layers_selector.h"

// I don't use Japanese myself, but I've placed henkan 変換 and muhenkan 無変換
// in my layout to act as left and right HYPER

// The weird /*,*/ comments are a hack to get slightly better automatic
// tabulation in my editor.

enum layers { qwerty, colemak, dvorak, workman, red, blue, purple };
const uint8_t highest_base_layer = workman;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        LALT_T(KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,        /*,      ,        */KC_Y,      KC_U,    KC_I,    KC_O,    RALT_T(KC_P),
        LCTL_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,        /*,      ,        */KC_H,      KC_J,    KC_K,    KC_L,    RCTL_T(KC_SCLN),
        LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,        /*,      ,        */KC_N,      KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_QUOT),
        MO(blue),       KC_HENK, _______, KC_LGUI, MO(red),    KC_TAB,  KC_SPC,  MO(red),    KC_RGUI, KC_BSPC, KC_MHEN, MO(blue)),
    LAYOUT(
        LALT_T(KC_Q),    KC_W,    KC_F,    KC_P,    KC_G,        /*,      ,        */KC_J,      KC_L,    KC_U,    KC_Y,    RALT_T(KC_SCLN),
        LCTL_T(KC_A),    KC_R,    KC_S,    KC_T,    KC_D,        /*,      ,        */KC_H,      KC_N,    KC_E,    KC_I,    RCTL_T(KC_O),
        LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,        /*,      ,        */KC_K,      KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_QUOT),
        _______,         _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______),
    LAYOUT(
        LALT_T(KC_QUOT), KC_COMM, KC_DOT,  KC_P,    KC_Y,        /*,      ,        */KC_F,      KC_G,    KC_C,    KC_R,    RALT_T(KC_L),
        LCTL_T(KC_A),    KC_O,    KC_E,    KC_U,    KC_I,        /*,      ,        */KC_D,      KC_H,    KC_T,    KC_N,    RCTL_T(KC_S),
        LSFT_T(KC_SCLN), KC_Q,    KC_J,    KC_K,    KC_X,        /*,      ,        */KC_B,      KC_M,    KC_W,    KC_V,    RSFT_T(KC_Z),
        _______,         _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______),
    LAYOUT(
        LALT_T(KC_Q),    KC_D,    KC_R,    KC_W,    KC_B,        /*,      ,        */KC_J,      KC_F,    KC_U,    KC_P,    RALT_T(KC_SCLN),
        LCTL_T(KC_A),    KC_S,    KC_H,    KC_T,    KC_G,        /*,      ,        */KC_Y,      KC_N,    KC_E,    KC_O,    RCTL_T(KC_I),
        LSFT_T(KC_Z),    KC_X,    KC_M,    KC_C,    KC_V,        /*,      ,        */KC_K,      KC_L,    KC_COMM, KC_DOT,  RSFT_T(KC_QUOT),
        _______,         _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______),
    LAYOUT(
        KC_ESC,          KC_GRV , KC_UP,   KC_EQL , KC_TILD,     /*,      ,        */KC_PLUS,   KC_CIRC, KC_AMPR, KC_PERC, KC_MINS,
        _______,         KC_LEFT, KC_DOWN, KC_RGHT, _______,     /*,      ,        */KC_PIPE,   KC_AT,   KC_DLR,  KC_HASH, KC_ENT,
        KC_BSLS,         KC_LABK, KC_LCBR, KC_LPRN, KC_LBRC,     /*,      ,        */KC_RBRC,   KC_RPRN, KC_RCBR, KC_RABK, KC_SLSH,
        TT(purple),     _______, _______, _______, _______,     _______, _______, _______,     _______, KC_DEL,  _______, TT(purple)),
    LAYOUT(
        KC_PSCR,         KC_F7,   KC_F8,   KC_F9,   KC_F10,      /*,      ,        */KC_PLUS,   KC_7,    KC_8,    KC_9,    KC_MINS,
        KC_SLCK,         KC_F4,   KC_F5,   KC_F6,   KC_F11,      /*,      ,        */KC_NLCK,   KC_4,    KC_5,    KC_6,    KC_ENT,
        KC_PAUS,         KC_F1,   KC_F2,   KC_F3,   KC_F12,      /*,      ,        */KC_ASTR,   KC_1,    KC_2,    KC_3,    KC_SLSH,
        _______,         _______, _______, _______, TT(purple), _______, _______, TT(purple), KC_0,    KC_DOT,  _______, _______),
    LAYOUT(
        RESET,           KC_INS,  KC_PGUP, DEBUG,   KC_VOLU,     /*,      ,        */KC_PPLS,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        _______,         KC_HOME, KC_PGDN, KC_END,  KC_VOLD,     /*,      ,        */KC_NLCK,   KC_P4,   KC_P5,   KC_P6,   KC_PENT,
        KF_LAYO,         KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,     /*,      ,        */KC_PAST,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
        _______,         _______, _______, _______, _______,     _______, _______, _______,     _______, KC_P0,   KC_PDOT, _______),
    };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return \
      process_record_cdeq(keycode, record) && \
      process_record_save_default_layer(keycode, record) && \
      process_record_select_default_layer(keycode, record);
}
