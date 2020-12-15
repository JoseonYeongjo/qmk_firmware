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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _NOINPUT,
  _1HAND,
  _RHINO,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  NOINPUT,
  RHINO,
  LOWER,
  RAISE,
  RHBOX,
  RHRECT,
  RHLINE,
  RHMOVE
};

float NOINPUTsong[][2] = SONG(NOINPUT_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|1 hand| GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,   KC_ENT,
  KC_LCTL, TT(_1HAND), KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|1 hand| GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,   KC_ENT,
  KC_LCTL, TT(_1HAND), KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|1 hand| GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  KC_LCTL, TT(_1HAND), KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* NoInput
 * ,-----------------------------------------------------------------------------------.
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  NO  |  NO  |  NO  |  NO  | Lower|   N O P E   | Raise|  NO  |  NO  |  NO  |  NO  |
 * `-----------------------------------------------------------------------------------'
 */
[_NOINPUT] = LAYOUT_preonic_grid(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   LOWER,   KC_NO,   KC_NO,   RAISE,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* One Handed
 * ,-----------------------------------------------------------------------------------.
 * |      |   6  |   7  |   8  |   9  |   0  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Y  |   U  |   I  |   O  |   P  |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   H  |   J  |   K  |   L  |   ;  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   N  |   M  |   ,  |   .  |   /  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_1HAND] = LAYOUT_preonic_grid(
  _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______, _______, _______, _______,
  _______,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______, _______, _______, _______, _______, _______,
  _______,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______, _______, _______, _______, _______, _______,
  _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Rhino
 * ,-----------------------------------------------------------------------------------.
 * |      | Line |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Rctngl|      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Move |      |      |      |      | Box  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RHINO] = LAYOUT_preonic_grid(
  _______,  RHLINE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,  RHRECT, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,  RHMOVE, _______, _______, _______,   RHBOX, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | Num7 | Num8 | Num9 | Num/ |Rhino1| F13  | F14  | F15  | F16  | F17  | F18  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Num4 | Num5 | Num6 | Num* | Bksp |MsWhUp|  M1  | MsUp |  M2  |  M5  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Num1 | Num2 | Num3 | Num- | Del  |MsWhDn|MsLeft|MsDown|MsRite|  M4  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |CapsLk| Num0 | Num. |NumEnt| Num+ |      |  M3  |MsSpd0|MsSpd1|MsSpd2|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  _______,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, OSL(_RHINO), KC_F13, KC_F14, KC_F15, KC_F16,  KC_F17,  KC_F18,
  _______,   KC_P4,   KC_P5,   KC_P6, KC_PAST, KC_BSPC, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN5, _______,
  _______,   KC_P1,   KC_P2,   KC_P3, KC_PMNS,  KC_DEL, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, _______,
  KC_CAPS,   KC_P0, KC_PDOT, KC_PENT, KC_PPLS, _______, KC_BTN3, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |  -   |  =   |PlayPs| Mute | PrtSc|ScrLck| PauBk|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  [   |  ]   |  \   | Rwnd | FFwd |  Ins | Home | PgUp |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  _   | Vol- | Vol+ |  Del |  End | PgDn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | RAlt |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, KC_MINS,  KC_EQL, KC_MPLY, KC_MUTE, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______,
  _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_MPRV, KC_MNXT,  KC_INS, KC_HOME, KC_PGUP, _______, _______,
  _______, _______, _______, _______, KC_UNDS, KC_VOLD, KC_VOLU,  KC_DEL,  KC_END, KC_PGDN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_RALT, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Qwerty|Colmak|Dvorak|NoInpt| Rhino|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Debug|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | MuScl|Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
    RESET,  QWERTY, COLEMAK,  DVORAK, NOINPUT,   RHINO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    DEBUG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______,  MU_MOD,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______,  MUV_DE,  MUV_IN,   MU_ON,  MU_OFF,   MI_ON,  MI_OFF, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case NOINPUT:
          if (record->event.pressed) {
            layer_invert(_NOINPUT);
            PLAY_SONG(NOINPUTsong);
          }
          return false;
          break;
        case RHINO:
          if (record->event.pressed) {
            layer_invert(_RHINO);
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
        case RHLINE:
          if (record->event.pressed) {
            SEND_STRING("! _Line ");
          }
          return false;
          break;
        case RHRECT:
          if (record->event.pressed) {
            SEND_STRING("! _Rectangle ");
          }
          return false;
          break;
        case RHBOX:
          if (record->event.pressed) {
            SEND_STRING("! _Box ");
          }
          return false;
          break;
        case RHMOVE:
          if (record->event.pressed) {
            SEND_STRING("! _Move ");
          }
          return false;
          break;
      }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
    case _QWERTY:
    case _COLEMAK:
    case _DVORAK:
      rgblight_setrgb(0x58, 0xFF, 0xFF);
      break;
    case _NOINPUT:
      rgblight_setrgb(0xFF, 0x00, 0x00);
      break;
    case _1HAND:
      rgblight_setrgb(0x40, 0xFF, 0x00);
      break;
    case _RHINO:
      rgblight_setrgb(0x00, 0xFF, 0x00);
      break;
    case _LOWER:
      rgblight_setrgb(0x00, 0xFF, 0xFF);
      break;
    case _RAISE:
      rgblight_setrgb(0xFF, 0xCA, 0x00);
      break;
    case _ADJUST:
      rgblight_setrgb(0x80, 0x00, 0xFF);
      break;
  }
  return state;
} 

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
