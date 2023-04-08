#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    DVRK, // dvorak
    SYMB, // symbols
    MDIA,  // media keys
};

#define KC_NONE KC_NO

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   [  |   ]  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | MOL1 |           | MOL1 |   Y  |   U  |   I  |   O  |   P  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------| LGui |           | LGui |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |AltGui|  '"  |AltShf| LGui |  Alt |                                       |   #  |   \  |   -  |  =   |Version|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Del  | BS   |       | HOME  | END  |
 *                                 ,------|------|------|       |-------+------+------.
 *                                 |      |      | Home |       | PgUp  |      |      |
 *                                 | Ctrl/|BackSp|------|       |-------| Tab  |Enter |
 *                                 | Space|      | Alt  |       | PgDn  |      |      |
 *                                 `--------------------'       `---------------------'
 * removed but useful MO(SYMB) DF(BASE)
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                             Right hand
  KC_GRV,   KC_1,    KC_2,          KC_3,    KC_4,    KC_5,         KC_6,  KC_7,         KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,           KC_DEL,
  KC_TAB,   KC_Q,    KC_W,          KC_E,    KC_R,    KC_T,      KC_LALT,  KC_LALT,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_SLSH,
  KC_ESC,   KC_A,    KC_S,          KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,          KC_C,    KC_V,    KC_B,      KC_LGUI,  KC_LGUI,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,
   LALT(KC_LGUI), KC_QUOT, LALT(KC_LSFT), KC_HOME,  KC_END,                              KC_BSLS, KC_NUBS, KC_MINS, KC_EQL,  KC_TRNS,
                                                         KC_DEL,MO(SYMB),  KC_HOME,      KC_END,
                                                                 KC_HOME,  KC_PGUP,
                                         CTL_T(KC_SPC), KC_BSPC, KC_LALT,  KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 1: Dvorak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   [  |   ]  | BackSp |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |   #  |   \  |   -  |   =  |Version|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       |QWERTY|DVORAK|
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Ctrl | Alt  | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Tab  |Enter |
 *                                 |      |ace   | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DVRK] = LAYOUT_ergodox_pretty(
  // left hand                                                         Right hand
  KC_GRV,   KC_1,    KC_2,          KC_3,    KC_4,    KC_5,     KC_6,  KC_7,     KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,        KC_BSPC,
  KC_TAB,   KC_QUOT, KC_COMM,     KC_DOT,    KC_P,    KC_Y, MO(SYMB),  MO(SYMB), KC_F,    KC_G,    KC_C,    KC_R,    KC_L,           KC_SLSH,
  KC_ESC,   KC_A,    KC_O,          KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    LT(MDIA, KC_S), KC_MINS,
  KC_LSFT,  KC_SCLN ,KC_Q,          KC_J,    KC_K,    KC_X, TT(DVRK),  TT(DVRK), KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,           KC_RSFT,
   LALT(KC_LGUI), KC_QUOT, LALT(KC_LSFT), KC_LGUI, KC_LALT,                      KC_BSLS, KC_NUBS, KC_MINS, KC_EQL,  KC_TRNS,
                                                    KC_DEL, TT(SYMB),  DF(BASE), DF(DVRK),
                                                              KC_END,  KC_PGUP,
                                     CTL_T(KC_SPC), KC_BSPC, KC_HOME,  KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.         ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|         |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |         |      |   Up |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|         |------| Down |   4  |   5  |   6  |   +  |   F15  |
 * |---------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |         |      |   &  |   1  |   2  |   3  |   \  |   F16  |
 * `---------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                     |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                         KC_END,     KC_TRNS,
                                 CTL_T(KC_SPC), KC_BSPC, KC_HOME,  KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 3: Media and mouse keys
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft| MsUp |MsDown|MsRght|------|           |------| Left | Down | Up   |Right |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | WhUp | WhDn |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_WH_D,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                       KC_BTN1, KC_BTN2, KC_END,     KC_PGDN, ALT_T(KC_TAB), CTL_T(KC_ENT)
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
