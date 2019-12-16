#include "feature_cdeq.h"
#include "feature_default_layers_selector.h"

#ifdef AUDIO_ENABLE
#include "audio.h"
#ifdef DEFAULT_LAYER_SONGS
extern float default_layer_songs[][16][2];
#endif
#endif

/*
  Setting MITOSIS_DATAGROK_BOTTOMSPACE in rules.mk will swap the upper and
  lower center four thumb-keys. See keymaps/datagrok/rules.mk.
*/
#ifdef MITOSIS_DATAGROK_BOTTOMSPACE
#undef LAYOUT
#define LAYOUT LAYOUT_bottomspace
#endif

/*
  I don't use Japanese myself, but I've placed henkan 変換 and muhenkan 無変換in
  my layout to act as left and right HYPER

  Momentary tri-state layers. Mitosis default keymap does this too but employs
  new keymappings and a bunch of conditional code. This simpler keymap
  accomplishes it but with a small quirk: triggering both layers then releasing
  one out-of-order will leave the tri-state triggered until the other is
  released. Which doesn't bother me.

  The weird interior comments are a hack to get slightly better automatic
  tabulation in my editor.

  I use Space Cadet KC_RSPC to get _ on right shift. See config.h for details.
*/

enum mitosis_layers {qwerty, colemak, dvorak, workman, _red, _blu, _pur};
const uint8_t highest_base_layer = workman;
#define K_LS_TAB LSFT_T(KC_TAB)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(
         LALT_T(KC_Q),    KC_W,       KC_E,    KC_R,     KC_T,     /*.....*/KC_Y,    KC_U,     KC_I,    KC_O,     RALT_T(KC_P),
         LCTL_T(KC_A),    KC_S,       KC_D,    KC_F,     KC_G,     /*.....*/KC_H,    KC_J,     KC_K,    KC_L,     RCTL_T(KC_SCLN),
         LSFT_T(KC_Z),    KC_X,       KC_C,    KC_V,     KC_B,     /*.....*/KC_N,    KC_M,     KC_COMM, KC_DOT,   RSFT_T(KC_QUOT),
         /*,              */ KC_LGUI, _______, MO(_red), KC_BSPC,  /*.....*/KC_SPC,  MO(_red), _______, KC_RGUI,
         /*,              */ KC_HENK, _______, MO(_blu), K_LS_TAB, /*.....*/KC_RSPC, MO(_blu), _______, KC_MHEN),
  LAYOUT(
         LALT_T(KC_Q),    KC_W,       KC_F,    KC_P,     KC_G,     /*.....*/KC_J,    KC_L,     KC_U,    KC_Y,     RALT_T(KC_SCLN),
         LCTL_T(KC_A),    KC_R,       KC_S,    KC_T,     KC_D,     /*.....*/KC_H,    KC_N,     KC_E,    KC_I,     RCTL_T(KC_O),
         LSFT_T(KC_Z),    KC_X,       KC_C,    KC_V,     KC_B,     /*.....*/KC_K,    KC_M,     KC_COMM, KC_DOT,   RSFT_T(KC_QUOT),
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______,
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______),
  LAYOUT(
         LALT_T(KC_QUOT), KC_COMM,    KC_DOT,  KC_P,     KC_Y,     /*.....*/KC_F,    KC_G,     KC_C,    KC_R,     RALT_T(KC_L),
         LCTL_T(KC_A),    KC_O,       KC_E,    KC_U,     KC_I,     /*.....*/KC_D,    KC_H,     KC_T,    KC_N,     RCTL_T(KC_S),
         LSFT_T(KC_SCLN), KC_Q,       KC_J,    KC_K,     KC_X,     /*.....*/KC_B,    KC_M,     KC_W,    KC_V,     RSFT_T(KC_Z),
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______,
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______),
  LAYOUT(
         LALT_T(KC_Q),    KC_D,       KC_R,    KC_W,     KC_B,     /*.....*/KC_J,    KC_F,     KC_U,    KC_P,     RALT_T(KC_SCLN),
         LCTL_T(KC_A),    KC_S,       KC_H,    KC_T,     KC_G,     /*.....*/KC_Y,    KC_N,     KC_E,    KC_O,     RCTL_T(KC_I),
         LSFT_T(KC_Z),    KC_X,       KC_M,    KC_C,     KC_V,     /*.....*/KC_K,    KC_L,     KC_COMM, KC_DOT,   RSFT_T(KC_QUOT),
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______,
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______),
  LAYOUT(
         KC_ESC,          KC_GRV ,    KC_UP,   KC_EQL ,  KC_TILD,  /*.....*/KC_PLUS, KC_CIRC,  KC_AMPR, KC_PERC,  KC_MINS,
         _______,         KC_LEFT,    KC_DOWN, KC_RGHT,  _______,  /*.....*/KC_PIPE, KC_AT,    KC_DLR,  KC_HASH,  KC_ENT,
         KC_BSLS,         KC_LABK,    KC_LCBR, KC_LPRN,  KC_LBRC,  /*.....*/KC_RBRC, KC_RPRN,  KC_RCBR, KC_RABK,  KC_SLSH,
         /*,              */ _______, _______, _______,  KC_DEL,   /*.....*/_______, _______,  _______, _______,
         /*,              */ _______, _______, TT(_pur), _______,  /*.....*/_______, TT(_pur), _______, _______),
  LAYOUT(
         KC_PSCR,         KC_F7,      KC_F8,   KC_F9,    KC_F10,   /*.....*/KC_PLUS, KC_7,     KC_8,    KC_9,     KC_MINS,
         KC_SLCK,         KC_F4,      KC_F5,   KC_F6,    KC_F11,   /*.....*/KC_NLCK, KC_4,     KC_5,    KC_6,     KC_ENT,
         KC_PAUS,         KC_F1,      KC_F2,   KC_F3,    KC_F12,   /*.....*/KC_ASTR, KC_1,     KC_2,    KC_3,     KC_SLSH,
         /*,              */ _______, _______, TT(_pur), _______,  /*.....*/_______, TT(_pur), KC_0,    KC_DOT,
         /*,              */ _______, _______, _______,  _______,  /*.....*/_______, _______,  _______, _______),
  LAYOUT(
         RESET,           KC_INS,     KC_PGUP, DEBUG,    KC_VOLU,  /*.....*/KC_PPLS, KC_P7,    KC_P8,   KC_P9,    KC_PMNS,
         CK_TOGG,         KC_HOME,    KC_PGDN, KC_END,   KC_VOLD,  /*.....*/KC_NLCK, KC_P4,    KC_P5,   KC_P6,    KC_PENT,
         KF_LAYO,         KC_MPRV,    KC_MPLY, KC_MNXT,  KC_MUTE,  /*.....*/KC_PAST, KC_P1,    KC_P2,   KC_P3,    KC_PSLS,
         /*,              */ CK_UP,   MU_TOG,  _______,  _______,  /*.....*/_______, _______,  KC_P0,   KC_PDOT,
         /*,              */ CK_DOWN, MU_MOD,  _______,  _______,  /*.....*/_______, _______,  _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return \
        process_record_cdeq(keycode, record) && \
        process_record_save_default_layer(keycode, record) && \
        process_record_select_default_layer(keycode, record);
}

/*
                         |    pro micro pin, or connection
  bit  layer    usb_led  |  PORTB  PORTC  PORTD  PORTE  PORTF
  0    _qwe     num      |  rxled  ___    scl^5  ___    NC!
  1    _col     caps     |  15     ___    grn^2  ___    NC!
  2    _dvo     scrl     |  16     ___    rx^1   gnd^4  ___
  3    workman  cmps     |  14     ___    tx^1   ___    ___
  4    red      kana     |  8      ___    4^2    ___    blu
  5    blue     -        |  9      ___    txled  ___    red
  6    purple   -        |  10     5^3    NC!    7      a1
  7    -        -        |  NC!    NC!    6      ___    a0

  legend:
  16  = the pro micro pin labeled "16," etc. (available for use.)
  a1  = the pro micro pin labeled "a1," etc. (available for use.)
  ___ = not a pin on atmega32u4
  NC! = it's a pin on atmega32u4 but the pro micro doesn't break it out! 😡
  red = connected to the red component of the RGB LED
  grn = connected to the green component of the RGB LED
  blu = connected to the blue component of the RGB LED
  tx  = USART1 transmit pin
  rx  = USART1 receive pin
  txled = connected to the tx LED on the pro micro
  rxled = connected to the rx LED on the pro micro

  notes:
  ^1: PD3 and PD2 are transmit and receive for USART1 which is how the pro micro
      communicates with the wireless module.
  ^2: I moved the green LED from PD1 to PD4; see rules.mk.
  ^3: I have a speaker connected to PC6. (#define C6_AUDIO in config.h)
  ^4: PE2 is tied to ground on the Pro Micro, I assume for use with the hardware
      boot enable feature, even though that feature is disabled by the default
      fuse settings.
  ^5: PD0(scl) is connected to the pairing button and p29 on the wireless
      module. If you use this for TWI/I2C, don't push the button.
  PB1-6,PD4,PD7,PF6-7 are not connected to the Mitosis receiver board.

  i use the table above as reference when tinkering with the bit shifting logic
  below. the idea was: since keyboard state is represented by bits in bitfields,
  and LEDs are controlled by bits in bitfields (ports), instead of a bunch of
  if/thens and setting of individual LED pins there should be some minimal
  bit-manipulation equation i can use to set whole ports at once and thus
  transform keyboard state to LED indication in a minimal number of
  instructions/cpu cycles.

  but in my (limited) testing i found the compiler was at least as good at
  optimizing easy-to-read code as it was this bit-shifting mess. oh well 🤷
*/

void led_set_user(uint8_t usb_leds) {
    uint8_t ls = layer_state | default_layer_state;
    /*
      red layer active -> indicator = red
      blue layer active -> indicator = blue
      purple layer active -> indicator = purple
      the Pro Micro tx LED displays Num Lock status.
      the Pro Micro rx LED displays Caps Lock status.
    */
    if (usb_leds&(1<<0)) led(tx, on); else led(tx, off);
    if (usb_leds&(1<<1)) led(rx, on); else led(rx, off);
    if (ls&(1<<workman)) led(green, on); else led(green, off);
    if (ls&(1<<_pur) || ls&(1<<_red)) led(red, on); else led(red, off);
    if (ls&(1<<_pur) || ls&(1<<_blu)) led(blue, on); else led(blue, off);
}

#ifdef OLED_DRIVER_ENABLE

static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

void oled_task_user(void) {
    /* still very much a work in progress, obvs. */
    oled_write_P(qmk_logo, false);
    switch (biton32(layer_state | default_layer_state)) {
    case workman:
        oled_write_ln_P(PSTR("Alt QDRWB JFUP: Alt"), false);
        oled_write_ln_P(PSTR("Ctl ASHTG YNEOI Ctl"), false);
        oled_write_ln_P(PSTR("Sft ZXMCV KL?!\" Sft"), false);
        break;
    case _red:
        oled_write_P(PSTR(" e`^=~   +^&%-\n  <v>    |@$#Ent\n \\<{([   ])}/\n"), false);
        break;
    case _blu:
        oled_write_P(PSTR("Ps       +789-\nSl        456 \nPs       *123/\n"), false);
        break;
    case _pur:
        oled_write_P(PSTR("Rs       +789-\nCk        456 \nLt       *123/\n"), false);
        break;
    default:
        oled_write_P(PSTR("Undefined\n"), false);
    }

    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCR ") : PSTR("    "), false);
}

#endif
