/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _FUNK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  FUNK,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Funk | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {FUNK, KC_LCTL, KC_LALT, KC_LCMD, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RCMD, KC_RALT, KC_RCTL, KC_ENT }
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Power|  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |  F21 |  F22 |  F23 |  F24 |      |      |      |BL_DEC|BL_INC|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |   Space     |Raise |      |      |      |BKLIGT|
 * `-----------------------------------------------------------------------------------'
 */
[_FUNK] = {
  {RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLU},
  {KC_POWER,KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_VOLD},
  {KC_CAPS, KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_INC,  XXXXXXX, KC_RSFT},
  {_______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, BL_TOGG}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | ISO ~| INS  | HOME | PGUP |      | Left | Down |  Up  | Right|      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps | ISO || DEL  | END  | PGDN |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |PSCRN | Ctrl | Alt  | GUI  |Lower |   Space     |Raise |  GUI |RALT  |Ctrl  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL}, 
  {_______, S(KC_NUHS), KC_INS,  KC_HOME, KC_PGUP, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_PIPE},
  {KC_LSFT, S(KC_NUBS), KC_DEL,  KC_END,  KC_PGDN, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______},
  {KC_PSCREEN,   KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_ENT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | ISO #| INS  | HOME | PGUP |      | Left | Down |  Up  | Right|      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps | ISO  | DEL  | END  | PGDN |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |PSCRN | Ctrl | Alt  | GUI  |Lower |   Space     |Raise | GUI  | RALT | Ctrl |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {KC_DEL,  KC_NUHS, KC_INS,  KC_HOME, KC_PGUP, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLS},
  {KC_LSFT, KC_NUBS, KC_DEL,  KC_END,  KC_PGDN, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______},
  {KC_PSCREEN, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_ENT}
},
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |  F1  | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | F11  | F12  |Aud on|Audoff|AGnorm|AGswap|PageDN|PageUp|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_PGDN, KC_PGUP, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


}; bool process_record_user(uint16_t keycode, keyrecord_t *record) { switch (keycode) { case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case FUNK:
      if (record->event.pressed) {
        layer_on(_FUNK);
      } else {
        layer_off(_FUNK);
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}
