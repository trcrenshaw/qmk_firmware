/* Copyright 2019 Tim Crenshaw
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

#define BASE 0
#define SYMB 1
#define FNKEYS 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐  Left Hand
   KC_EQUAL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_EQUAL,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  KC_DELETE,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   OSL(1),
//├────────┼────────┼────────┼────────┼────────┼────────┤        │
  KC_BSPACE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
  KC_LSHIFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
//├────────┼────────┼────────┼────────┼────────┼────────┘   ┌────────┬────────┐
   KC_LCTRL,KC_LGUI,LALT(KC_LSHIFT),KC_LEFT,KC_RIGHT,        KC_TRNS, KC_TRNS,
//└────────┴────────┴────────┴────────┴────────┘   ┌────────┼────────┼────────┤
                                                                      KC_HOME,
//                                                 │        │        ├────────┤
                                                    KC_SPACE,KC_ENTER, KC_END,
//                                                 └────────┴────────┴────────┘
// Right Hand  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                KC_RIGHT,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINUS,
//             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                 OSL(2),   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLASH,
//             │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCOLON,KC_QUOTE,
//             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                           KC_N,    KC_M,  KC_COMMA, KC_DOT, KC_SLASH,KC_RSHIFT,
//┌────────┬────────┐   └────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TRNS, KC_DELETE,            KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,  MO(1),
//├────────┼────────┼────────┐   └────────┴────────┴────────┴────────┴────────┘
   KC_PGUP,
//├────────┤        │        │
  KC_PGDOWN,KC_BSPACE, MO(1)
//└────────┴────────┴────────┘
) ,
  [SYMB] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐  Left Hand
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TRNS, KC_EXLM,  KC_AT,  KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┤        │
  KC_TRNS,  KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
  KC_TRNS,  KC_PERC, KC_CIRC, KC_LBRC,KC_RBRC,  KC_TILD,
//├────────┼────────┼────────┼────────┼────────┼────────┘   ┌────────┬────────┐
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_MNXT, KC_MNXT,
//└────────┴────────┴────────┴────────┴────────┘   ┌────────┼────────┼────────┤
                                                                      KC_VOLU,
//                                                 │        │        ├────────┤
                                                    KC_TRNS, KC_MPLY, KC_VOLD,
//                                                 └────────┴────────┴────────┘
// Right Hand  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                KC_TRNS,  KC_UP,    KC_7,    KC_8,    KC_9,  KC_ASTR,  KC_F12,
//             │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                         KC_DOWN,   KC_4,    KC_5,    KC_6,  KC_PLUS, KC_TRNS,
//             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                         KC_AMPR,   KC_1,    KC_2,    KC_3,  KC_BSLS, KC_TRNS,
//┌────────┬────────┐   └────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TRNS, KC_TRNS,              KC_TRNS,  KC_DOT,   KC_0,  KC_EQUAL,KC_TRNS,
//├────────┼────────┼────────┐   └────────┴────────┴────────┴────────┴────────┘
   KC_TRNS,
//├────────┤        │        │
   KC_TRNS, KC_TRNS, KC_TRNS
//└────────┴────────┴────────┘
) ,
  [FNKEYS] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐  Left Hand
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TRNS, KC_TRNS,   KC_F1,   KC_F2,  KC_F3,  KC_TRNS, KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┤        │
   KC_TRNS, KC_TRNS,   KC_F4,   KC_F5,  KC_F6,  KC_TRNS, 
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
   KC_TRNS, KC_TRNS,   KC_F7,   KC_F8,  KC_F9,  KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┘   ┌────────┬────────┐
   KC_TRNS, KC_TRNS,   KC_F10,  KC_F11, KC_F12,              KC_TRNS, KC_TRNS,
//└────────┴────────┴────────┴────────┴────────┘   ┌────────┼────────┼────────┤
                                                                      KC_TRNS,
//                                                 │        │        ├────────┤
                                                    KC_MEH,  KC_HYPR, KC_TRNS,
//                                                 └────────┴────────┴────────┘
// Right Hand  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                KC_TRNS, KC_TRNS,  KC_F13,  KC_F14,  KC_F15, KC_TRNS, KC_TRNS,
//             │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                         KC_TRNS,  KC_F16,  KC_F17,  KC_F18, KC_TRNS, KC_TRNS,
//             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                         KC_TRNS,  KC_F19,  KC_F20,  KC_F21, KC_TRNS, KC_TRNS,
//┌────────┬────────┐   └────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TRNS, KC_TRNS,               KC_F22,  KC_F23,  KC_F24, KC_TRNS, KC_TRNS, 
//├────────┼────────┼────────┐   └────────┴────────┴────────┴────────┴────────┘
   KC_TRNS,                                
//├────────┤        │        │
   KC_TRNS, KC_HYPR,  KC_MEH  
//└────────┴────────┴────────┘
) ,
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
