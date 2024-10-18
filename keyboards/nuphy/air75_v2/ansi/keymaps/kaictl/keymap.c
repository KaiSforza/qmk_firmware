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
#include "../../user_kb.h"
#include "../../side.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// layer Mac
[0] = LAYOUT_75_ansi(
    KC_ESC,     KC_BRID,   KC_BRIU,     KC_MCTL,   MAC_SEARCH, MAC_VOICE,   MAC_DND,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     MAC_PRTA,   KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    KC_CAPS,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_HOME,
    KC_LSFT,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_END,
    KC_LCTL,    KC_LALT,   KC_LGUI,                                         KC_SPC,                             KC_RGUI,   TT(1),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer Mac Fn
[1] = LAYOUT_75_ansi(
    _______,    KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      SYS_PRT,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   KC_P7,      KC_P8,       KC_P9,     KC_P0,      KC_PMNS,    KC_PPLS,                 _______,    _______,
    _______,    RGB_SPD,    RGB_VAI,    RGB_SPI,   _______,    _______,     _______,   KC_P4,      KC_P5,       KC_P6,     KC_PSLS,    KC_PAST,    _______,                 BAT_SHOW,   _______,
    KC_CAPS,    RGB_MOD,    RGB_VAD,    RGB_HUI,   _______,    _______,     _______,   KC_P1,      KC_P2,       KC_P2,     _______,    _______,                             KC_PENT,    KC_VOLU,
    TT(4),                  _______,    _______,   RGB_TEST,   _______,     BAT_NUM,   _______,    KC_P0,       KC_PCMM,   KC_PDOT,    _______,                 _______,    KC_MUTE,    KC_VOLD,
    _______,    KC_APP,     _______,                                        _______,                            TT(4),     TT(1),      _______,                 KC_MPRV,    KC_MPLY,    KC_MNXT),

// layer win
[2] = LAYOUT_75_ansi(
    KC_ESC,     KC_F1,     KC_F2,       KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_HOME,    KC_END,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_INS,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PSCR,
    KC_LCTL,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_PGUP,
    KC_LSFT,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_PGDN,
    TT(3),      KC_LGUI,   KC_LALT,                                         KC_SPC,                             KC_RALT,   TT(3),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer win Fn
[3] = LAYOUT_75_ansi(
    _______,    KC_BRID,    KC_BRIU,    G(KC_TAB), KC_FIND,    LAG(KC_K),  _______,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,     KC_VOLU,     KC_NUM,     _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   KC_P7,      KC_P8,       KC_P9,     KC_P0,      KC_PMNS,    KC_PPLS,                 _______,    _______,
    _______,    RGB_SPD,    RGB_VAI,    RGB_SPI,   _______,    _______,     _______,   KC_P4,      KC_P5,       KC_P6,     KC_PSLS,    KC_PAST,    _______,                 BAT_SHOW,   _______,
    KC_CAPS,    RGB_MOD,    RGB_VAD,    RGB_HUI,   _______,    _______,     _______,   KC_P1,      KC_P2,       KC_P2,     _______,    _______,                             KC_PENT,    KC_VOLU,
    TT(4),                  _______,    _______,   RGB_TEST,   _______,     BAT_NUM,   _______,    KC_P0,       KC_PCMM,   KC_PDOT,    KC_RGUI,                 _______,    _______,    KC_VOLD,
    _______,    KC_APP,     _______,                                        _______,                            TT(4),     TT(3),      _______,                 _______,    _______,    _______),

// layer 4
[4] = LAYOUT_75_ansi(
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,    SLEEP_MODE, DEV_RESET,  EE_CLR,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                RF_DFU,     DB_TOGG,
    _______,    SIDE_SPD,   SIDE_VAI,   SIDE_SPI,  _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,     QK_BOOT,
    _______,    SIDE_MOD,   SIDE_VAD,   SIDE_HUI,  _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                KC_BTN1,    KC_BTN2,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                 _______,    KC_MS_U,    _______,
    MO(4),      _______,    _______,                                        _______,                            _______,   MO(4),      _______,                 KC_MS_L,    KC_MS_D,    KC_MS_R)
};

//bool rgb_matrix_indicators_user(void) {
//    /*
//    if (host_keyboard_led_state().caps_lock) {
//        user_set_rgb_color(59, 0x00, 0x55, 0x00);
//    }
//    if (get_highest_layer(layer_state) >= 3) {
//        if (host_keyboard_led_state().num_lock) {
//            user_set_rgb_color(13, 0x00, 0x55, 0x00);
//        }
//    }
//    //switch (get_highest_layer(layer_state)) {
//    //    case 4:
//    //        //user_set_rgb_color(78, 0x55, 0x00, 0x00);
//    //        side_rgb_set_color(0, 0x55, 0x00, 0x00);
//    //        break;
//    //    case 3:
//    //        //user_set_rgb_color(78, 0x55, 0x00, 0x55);
//    //        side_rgb_set_color(0, 0x55, 0x00, 0x55);
//    //        break;
//    //    //case 2:
//    //    //    user_set_rgb_color(78, 0x00, 0x55, 0x00);
//    //    //    break;
//    //    default:
//    //        //user_set_rgb_color(78, 0x55, 0x55, 0x55);
//    //        break;
//    //}
//        uint8_t nl_num_keys[] = {
//            23, 22, 21,
//            38, 39, 40,
//            52, 51, 50,
//            67
//        };
//        uint8_t nl_keys[] = {
//                        20, 19, 18,
//                        41, 42,
//
//                68, 69
//        };
//        for (uint8_t i = 0; i < 7; i++) {
//            user_set_rgb_color(nl_keys[i], 0x22, 0x00, 0x00);
//        }
//        for (uint8_t i = 0; i < 10; i++) {
//            user_set_rgb_color(nl_num_keys[i], 0x22, 0x22, 0x00);
//        }
//        */
//    led_power_handle();
//    return true;
//}
