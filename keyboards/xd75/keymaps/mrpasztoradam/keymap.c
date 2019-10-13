/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_hungarian.h"

// Layer shorthand
#define _QW 0
#define _FN 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ Hungarian TEST
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    |  ESC   | 0      | 1      | 2      | 3      | 4      | 5      |  6     |  7     |  8     |  9     |  Ö     |  Ü     |   Ó    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | MYCOMP |  TAB   | Q      | W      | E      | R      | T      | Z      |  U     |  I     |  O     |  P     |  Ő     |  Ú     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | APP    |  TAB   | A      | S      | D      | F      | G      | H      |  J     |  K     |  L     |  É     |  Á     |  Ű     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | RUN    |  LSFT  | Y      | X      | C      | V      | B      | N      |  M     |  ,?    |  .:    |  -_    |        |        | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | CALC   | LCTRL  | LALT   | LGUI   | FUN    | BACKSP | SPACE  | SPACE  |  DEL   |  FUN   |        |        | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QW] = LAYOUT_ortho_5x15( /* QWERTZ */
    KC_ESC,  KC_ESC,      HU_0,    HU_1,    HU_2,    HU_3,    HU_4,    HU_5,    HU_6,    HU_7,    HU_8,    HU_9,    HU_OE,    HU_UE,   HU_OO,
    KC_MYCM, KC_TAB,      HU_Q,    HU_W,    HU_E,    HU_R,    HU_T,    HU_Z,    HU_U,    HU_I,    HU_O,    HU_P,    HU_OEE,   HU_UU,   KC_ENT,
    KC_APP,  KC_TAB,      HU_A,    HU_S,    HU_D,    HU_F,    HU_G,    HU_H,    HU_J,    HU_K,    HU_L,    HU_EE,   HU_AA,    HU_UEE,  KC_ENT,
    KC_LSFT, SFT_T(HU_II),HU_Y,    HU_X,    HU_C,    HU_V,    HU_B,    HU_N,    HU_M,    HU_COMM, HU_DOT,  HU_MINS, _______,  _______, KC_RSFT,
    KC_CALC, KC_LCTL,     KC_LALT, KC_LGUI, MO(_FN), KC_BSPC, KC_SPC,  KC_SPC,  KC_DEL,  MO(_FN), _______, _______, KC_RALT,  KC_RGUI, KC_RCTL
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        | F1     | F2     | F3     |  F4    |  F5    | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | É      | RGB HD | RGB HI | P7     | P8     | P9     | -      | Ú,Ű    | Í      | Ó,Ő    | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | Á      | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MSEL, KC_CALC, KC_MYCM, HU_EE,   RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, TD(TD_UU_UEE),   HU_II,   TD(TD_OO_OEE),   KC_SLCK, KC_PAUS,
    KC_MPRV, HU_AA,   KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
  )
};

//Tap Dance Declarations
enum {
  TD_O_OE = 0,
  TD_U_UE,
  TD_OO_OEE,
  TD_UU_UEE
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for o, twice for ö
  [TD_O_OE]  = ACTION_TAP_DANCE_DOUBLE(HU_O, HU_OE)
  //Tap once for u, twice for ü
  [TD_U_UE]  = ACTION_TAP_DANCE_DOUBLE(HU_U, HU_UE)
  //Tap once for u, twice for ü
  [TD_OO_OEE]  = ACTION_TAP_DANCE_DOUBLE(HU_OO, HU_OEE)
  //Tap once for u, twice for ü
  [TD_UU_UEE]  = ACTION_TAP_DANCE_DOUBLE(HU_UU, HU_UEE)
// Other declarations would go here, separated by commas, if you have them
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
