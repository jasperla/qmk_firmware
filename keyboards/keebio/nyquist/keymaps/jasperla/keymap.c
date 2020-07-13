#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4

#define _POINTER 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

/* OS-defined shortcuts */
#define SPTLGHT   LGUI(KC_SPC)               /* Open Spotlight                            */
#define WTOPL     LCTL(LGUI(LSFT(KC_LEFT))) /* Spectacle: move window top left corner    */
#define WMIDL     LALT(LGUI(KC_LEFT))        /* Spectacle: move window left half          */
#define WLOWL     LCTL(LGUI(KC_LEFT))        /* Spectacle: move window lower left corner  */
#define WTOPR     LCTL(LGUI(LSFT(KC_RIGHT))) /* Spectacle: move window top right corner   */
#define WMIDR     LALT(LGUI(KC_RIGHT))       /* Spectacle: move window right half         */
#define WLOWR     LCTL(LGUI(KC_RIGHT))       /* Spectacle: move window lower right corner */
#define KC_TABP   LGUI(LSFT(KC_LCBR))        /* Tab previous */
#define KC_TABN   LGUI(LSFT(KC_RCBR))        /* Tab next */

#define ARROWS MO(_POINTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |Sptlgt| Alt  | GUI  |Lower |Space | |Enter |Raise |Arrows|      |Adjust|      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  KC_LCTL, SPTLGHT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   ARROWS,  _______, ADJUST,  _______ \
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |      |      | |      |      |      |   (  |   )  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |TLEFT |      | TRGHT|      |      | |      |      |      |   {  |   }  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |MLEFT |      | MRGHT|      |      | |      |   _  |   +  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |LLEFT |      | LRGHT|      | Bksp | |      |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______,    _______,    KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, WTOPL,   _______, WTOPR,   _______, _______, _______, _______,    _______,    KC_LCBR, KC_RCBR, KC_DEL,
  KC_DEL,  WMIDL,   _______, WMIDR,   _______, _______, _______, KC_UNDS,    KC_PLUS,    KC_LBRC, KC_RBRC, KC_PIPE,
  _______, WLOWL,   _______, WLOWR,   _______, KC_BSPC, _______, S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |  (   |   )  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |   _  |   +  |  {   |   }  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |  [   |   ]  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |Tab P |Tab N |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TABP, KC_TABN, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Pointers
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |BTN 1 | M Up |BTN 2 |Mw Up | |Mw Up |      | Up   |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |MLeft |MDown |MRight|Mw Dn | |Mw Dn | Left | Down | Right|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |Arrows|      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_POINTER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_U, _______, KC_UP,   _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_D, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, ARROWS,  _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn| |Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm| |AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
