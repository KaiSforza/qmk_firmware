/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

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
//#include "user_kb.h"

enum layers{
    GAME,
    GAME_FN,
    WIN,
    WIN_FN,
    WIN_FN2,
    WIN_XTRA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[GAME] = LAYOUT_75_ansi(
    KC_ESC,     KC_F1,     KC_F2,       KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_HOME,    KC_END,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_INS,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PSCR,
    KC_LCTL,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_PGUP,
    KC_LSFT,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_PGDN,
    TT(GAME_FN),_______,   KC_LALT,                                         KC_SPC,                             KC_RALT,   TT(GAME_FN),KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),
// layer win Fn
[GAME_FN] = LAYOUT_75_ansi(
    _______,    KC_BRID,    KC_BRIU,    G(KC_TAB), KC_FIND,    LAG(KC_K),  _______,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,     KC_VOLU,    KC_NUM,     _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,    _______,   KC_P7,      KC_P8,       KC_P9,     KC_P0,      KC_PMNS,    KC_PPLS,                 _______,    _______,
    _______,    RGB_SPD,    RGB_VAI,    RGB_SPI,   _______,    _______,    _______,   KC_P4,      KC_P5,       KC_P6,     KC_PSLS,    KC_PAST,    _______,                 BAT_SHOW,   _______,
    KC_CAPS,    RGB_MOD,    RGB_VAD,    RGB_HUI,   _______,    _______,    _______,   KC_P1,      KC_P2,       KC_P2,     _______,    _______,                             KC_PENT,    KC_VOLU,
    TT(WIN_FN2),_______,    _______,    RGB_TEST,  _______,    BAT_NUM,    _______,   KC_P0,      KC_PCMM,     KC_PDOT,   KC_RGUI,                 _______,    _______,    KC_VOLD,
    _______,    KC_LGUI,    _______,                                       _______,                            TT(WIN_FN2),TT(GAME_FN),_______,                 _______,    _______,    _______),
// layer win
[WIN] = LAYOUT_75_ansi(
    KC_ESC,     KC_F1,     KC_F2,       KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_HOME,    KC_END,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_INS,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PSCR,
    KC_LCTL,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_PGUP,
    KC_LSFT,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_PGDN,
    TT(WIN_FN), KC_LGUI,   KC_LALT,                                         KC_SPC,                             KC_RALT,   TT(WIN_FN), KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer win Fn
[WIN_FN] = LAYOUT_75_ansi(
    _______,    KC_BRID,    KC_BRIU,    G(KC_TAB), KC_FIND,    LAG(KC_K),  _______,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,     KC_VOLU,    KC_NUM,     _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,    _______,   KC_P7,      KC_P8,       KC_P9,     KC_P0,      KC_PMNS,    KC_PPLS,                 _______,    _______,
    _______,    RGB_SPD,    RGB_VAI,    RGB_SPI,   _______,    _______,    _______,   KC_P4,      KC_P5,       KC_P6,     KC_PSLS,    KC_PAST,    _______,                 BAT_SHOW,   _______,
    KC_CAPS,    RGB_MOD,    RGB_VAD,    RGB_HUI,   _______,    _______,    _______,   KC_P1,      KC_P2,       KC_P2,     _______,    _______,                             KC_PENT,    KC_VOLU,
    TT(WIN_FN2),_______,    _______,    RGB_TEST,  _______,    BAT_NUM,    _______,   KC_P0,      KC_PCMM,     KC_PDOT,   KC_RGUI,                 _______,    _______,    KC_VOLD,
    _______,    KC_APP,     _______,                                       _______,                            TT(WIN_FN2),TT(WIN_FN),_______,                 _______,    _______,    _______),

// layer 4
[WIN_FN2] = LAYOUT_75_ansi(
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,    SLEEP_MODE, DEV_RESET,  EE_CLR,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                RF_DFU,     DB_TOGG,
    _______,    SIDE_SPD,   SIDE_VAI,   SIDE_SPI,  _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,     QK_BOOT,
    _______,    SIDE_MOD,   SIDE_VAD,   SIDE_HUI,  _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                KC_BTN1,    KC_BTN2,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                 _______,    KC_MS_U,    _______,
    MO(WIN_FN2),_______,    _______,                                        _______,                            _______,   MO(WIN_FN2),_______,                 KC_MS_L,    KC_MS_D,    KC_MS_R),

[WIN_XTRA] = LAYOUT_75_ansi(
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,    _______, _______,  _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,             _______,  _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,             _______,  _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                          _______,  _______,
    _______,                _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                 _______, _______,  _______,
    _______,    _______,    _______,                                        _______,                            _______,   _______,    _______,                 _______, _______,  _______)
};
