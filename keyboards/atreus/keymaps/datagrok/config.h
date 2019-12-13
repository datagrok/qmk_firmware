#pragma once

#define IGNORE_MOD_TAP_INTERRUPT

// I want to place an underscore as tap behavior on the right shift key. But
// RSFT_T(KC_UNDS) doesn't work; mod-tap doesn't work with pre-shifted keys. So
// instead I take advantage of Space Cadet Shift that does something similar
// and just tweak it to use the -/_ key instead of 0/). See
// https://github.com/qmk/qmk_firmware/pull/2055
#define RSPC_KEY KC_MINS
