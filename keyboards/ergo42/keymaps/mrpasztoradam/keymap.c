#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Z   |   U  |   I  |   O  |   P  |   Ö  |   Ü  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  | RCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   É  |   Á  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB | LSft |   Y  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   -  |  UP  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | META | Space| BKSP |   |  Del | Space|   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_ESC,   KC_TAB,  HU_Q,   HU_W,    HU_E,    HU_R,   HU_T,        HU_Z,    TD(TD_U_UU),    TD(TD_I_II),    TD(TD_O_OO),   HU_P,    TD(TD_OE_OEE),   TD(TD_UE_UEE), \
    KC_DELT,  KC_RCTL, HU_A,   HU_S,    HU_D,    HU_F,   HU_G,        HU_H,    HU_J,    HU_K,    HU_L,   HU_EE,   HU_AA,   KC_ENT, \
    MO(SYMB), KC_LSFT, HU_Y,   HU_X,    HU_C,    HU_V,   HU_B,        HU_N,    HU_M,    HU_COMM, HU_DOT, HU_MINS, KC_UP,   KC_RSFT, \
    KC_LGUI,  KC_LCTL, KC_GRV, KC_BSLS, MO(META),KC_SPC, KC_BSPC,     KC_DELT, KC_SPC, KC_MINS, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  0§  |   1' |   2" |   3+ |  4!  |  5%  |  [   |   |  ]   |  7   |  8   |  9   |  /   |   0  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  |  F1  |      |Muhen | Henk |      |  (   |   |  )   |  4   |  5   |  6   |  *   |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  1   |  2   |  3   |  +   |  UP  | F12  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |  0   |   .  |  -   |  LFT |  DN  |  RGT |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    HU_0,    HU_1,    HU_2,    HU_3,    HU_4,    HU_5,    KC_LBRC,        KC_RBRC,    HU_7,    HU_8,    HU_9,    KC_PSLS,  KC_0,    _______, \
    _______, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, KC_LPRN,        KC_RPRN,    HU_4,    HU_5,    HU_6,    KC_PAST,  XXXXXXX, _______, \
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   S(KC_LBRC),     S(KC_RBRC), HU_1,    HU_2,    HU_3,    KC_PPLS,  KC_TRNS,  KC_F12, \
    _______, _______, _______, _______, _______, _______, _______,        _______,    HU_0,    KC_PDOT, KC_PMNS, KC_TRNS,  KC_TRNS, KC_TRNS \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   !  |   @  |   #  |   $  |   %  |  [   |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB |      |      |      |      |      |  {   |   |  }   |      |      |      |      |  UP  | Sft  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LBRC,    KC_RBRC,    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9),    S(KC_0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______, _______ \
  )

//Tap Dance Declarations
enum {
  TD_O_OO = 0,
  TD_U_UU,
  TD_OE_OEE,
  TD_UE_UEE
  TD_I_II
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for o, twice for ó
  [TD_O_OO]  = ACTION_TAP_DANCE_DOUBLE(HU_O, HU_OO)
  //Tap once for u, twice for ú
  [TD_U_UU]  = ACTION_TAP_DANCE_DOUBLE(HU_U, HU_UU)
  //Tap once for ö, twice for ő
  [TD_OE_OEE]  = ACTION_TAP_DANCE_DOUBLE(HU_OE, HU_OEE)
  //Tap once for ü, twice for ű
  [TD_UE_UEE]  = ACTION_TAP_DANCE_DOUBLE(HU_UU, HU_UEE)
  //Tap once for i, twice for í
  [TD_I_II]  = ACTION_TAP_DANCE_DOUBLE(HU_I, HU_II)
// Other declarations would go here, separated by commas, if you have them
};

};

