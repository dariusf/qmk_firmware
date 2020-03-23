/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
     * |---------------------------------------------------------------|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shif|   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Fn0 |Alt |Gui |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = LAYOUT( \
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_NO,KC_TRNS, KC_DEL, \
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_NO, \
        KC_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,KC_TRNS,      KC_NO,\
        KC_LSPO,KC_NO,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSPC,     KC_TRNS,  KC_NO,\
        KC_LCTL,KC_LALT,KC_LGUI,               KC_SPC,           MO(1),KC_ENT,  MO(2),     KC_TRNS,KC_TRNS,KC_TRNS \
    ),
    [1] = LAYOUT( \
        KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_MUTE,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F7,KC_F8,KC_F9,KC_TRNS,     KC_TRNS,KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,               KC_TRNS,          KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS  \
    ),
    [2] = LAYOUT( \
        RESET,KC_BRMD,  KC_BRMU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MEDIA_REWIND,  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_FAST_FORWARD,  KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_TRNS,KC_TRNS,KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,\
        KC_TRNS,KC_TRNS,KC_TRNS,               KC_TRNS,          KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS  \
    ),
};

// https://www.reddit.com/r/olkb/comments/9eohzf/qmk_using_ctrl_as_fnkey_only_for_a_few_keys/e5qpbdz/
static bool lalt = false;
static bool ralt = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
    case KC_LALT:
      if(record->event.pressed) {
        lalt = true;
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
        lalt = false;
      }
      return false;
    case KC_RALT:
      if(record->event.pressed) {
        ralt = true;
        register_code(KC_RALT);
      } else {
        unregister_code(KC_RALT);
        ralt = false;
      }
      return false;
    case KC_I:
      if (lalt || ralt){
        if(record->event.pressed) {
          unregister_code(KC_LALT);
          unregister_code(KC_RALT);
          register_code(KC_BSPC);
        } else {
          unregister_code(KC_BSPC);
          if (lalt)
            register_code(KC_LALT);
          if (ralt)
            register_code(KC_RALT);
        }
      } else {
        unregister_code(KC_BSPC);
        return true;
      }
      return false;
  case KC_U:
    if (lalt || ralt){
      if(record->event.pressed) {
        unregister_code(KC_LALT);
        unregister_code(KC_RALT);
        register_code(KC_ENT);
      } else {
        unregister_code(KC_ENT);
        if (lalt)
          register_code(KC_LALT);
        if (ralt)
          register_code(KC_RALT);
      }
    } else {
      unregister_code(KC_ENT);
      return true;
    }
    return false;
  case KC_H:
    if (lalt || ralt){
      if(record->event.pressed) {
        unregister_code(KC_LALT);
        unregister_code(KC_RALT);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
        if (lalt)
          register_code(KC_LALT);
        if (ralt)
          register_code(KC_RALT);
      }
    } else {
      unregister_code(KC_LEFT);
      return true;
    }
    return false;
    case KC_J:
      if (lalt || ralt){
        if(record->event.pressed) {
          unregister_code(KC_LALT);
          unregister_code(KC_RALT);
          register_code(KC_DOWN);
        } else {
          unregister_code(KC_DOWN);
          if (lalt)
            register_code(KC_LALT);
          if (ralt)
            register_code(KC_RALT);
        }
      } else {
        unregister_code(KC_DOWN);
        return true;
      }
      return false;
    case KC_K:
      if (lalt || ralt){
        if(record->event.pressed) {
          unregister_code(KC_LALT);
          unregister_code(KC_RALT);
          register_code(KC_UP);
        } else {
          unregister_code(KC_UP);
          if (lalt)
            register_code(KC_LALT);
          if (ralt)
            register_code(KC_RALT);
        }
      } else {
        unregister_code(KC_UP);
        return true;
      }
      return false;
    case KC_L:
      if (lalt || ralt){
        if(record->event.pressed) {
          unregister_code(KC_LALT);
          unregister_code(KC_RALT);
          register_code(KC_RGHT);
        } else {
          unregister_code(KC_RGHT);
          if (lalt)
            register_code(KC_LALT);
          if (ralt)
            register_code(KC_RALT);
        }
      } else {
        unregister_code(KC_RGHT);
        return true;
      }
      return false;

    default:
      return true;
    }
}
