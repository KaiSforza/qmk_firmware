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

#include "user_kb.h"
#include "ansi.h"
#include "usb_main.h"

extern bool            f_rf_sw_press;
extern bool            f_sleep_show;
extern bool            f_dev_reset_press;
extern bool            f_rf_dfu_press;
extern bool            f_bat_num_show;
extern bool            f_rgb_test_press;
extern bool            f_bat_hold;
extern uint16_t        no_act_time;
extern uint8_t         rf_sw_temp;
extern uint16_t        rf_sw_press_delay;
extern uint16_t        rf_linking_time;
extern user_config_t   user_config;
extern DEV_INFO_STRUCT dev_info;
extern uint32_t        uart_rpt_timer;


/* qmk process record */
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    no_act_time     = 0;
    rf_linking_time = 0;
    uart_rpt_timer  = timer_read32();

    switch (keycode) {
        case RF_DFU:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) return false;
                f_rf_dfu_press = 1;
                break_all_key();
            } else {
                f_rf_dfu_press = 0;
            }
            return false;

        case LNK_USB:
            if (record->event.pressed) {
                break_all_key();
            } else {
                dev_info.link_mode = LINK_USB;
                uart_send_cmd(CMD_SET_LINK, 10, 10);
            }
            return false;

        case LNK_RF:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_RF_24;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case LNK_BLE1:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_BT_1;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case LNK_BLE2:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_BT_2;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case LNK_BLE3:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_BT_3;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case SIDE_VAI:
            if (record->event.pressed) {
                side_light_control(1);
            }
            return false;

        case SIDE_VAD:
            if (record->event.pressed) {
                side_light_control(0);
            }
            return false;

        case SIDE_MOD:
            if (record->event.pressed) {
                side_mode_control();
            }
            return false;

        case SIDE_HUI:
            if (record->event.pressed) {
                side_colour_control();
            }
            return false;

        case SIDE_SPI:
            if (record->event.pressed) {
                side_speed_control(1);
            }
            return false;

        case SIDE_SPD:
            if (record->event.pressed) {
                side_speed_control(0);
            }
            return false;

        case DEV_RESET:
            if (record->event.pressed) {
                f_dev_reset_press = 1;
                break_all_key();
            } else {
                f_dev_reset_press = 0;
            }
            return false;

        case SLEEP_MODE:
            if (record->event.pressed) {
                if (user_config.sleep_enable)
                    user_config.sleep_enable = false;
                else
                    user_config.sleep_enable = true;
                f_sleep_show = 1;
                eeconfig_update_kb_datablock(&user_config);
            }
            return false;

        case BAT_SHOW:
            if (record->event.pressed) {
                f_bat_hold = !f_bat_hold;
            }
            return false;

        case BAT_NUM:
            f_bat_num_show = record->event.pressed;
            return false;

        case RGB_TEST:
            f_rgb_test_press = record->event.pressed;
            return false;

        default:
            return true;
    }
    return true;
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (f_bat_num_show) {
        num_led_show();
    }

    // light up corresponding BT mode key during connection
    if (rf_blink_cnt && dev_info.link_mode >= LINK_BT_1 && dev_info.link_mode <= LINK_BT_3) {
        user_set_rgb_color(30 - dev_info.link_mode, 0, 0, 0x80);
    } else if (rf_blink_cnt && dev_info.link_mode == LINK_RF_24) {
        user_set_rgb_color(26, 0, 0x80, 0);
    }

    // power down unused LEDs
    led_power_handle();
    return true;
}

/* qmk keyboard post init */
void keyboard_post_init_kb(void) {
    gpio_init();
    rf_uart_init();
    wait_ms(500);
    rf_device_init();

    break_all_key();
    dial_sw_fast_scan();
    eeconfig_read_kb_datablock(&user_config);
    keyboard_post_init_user();
}

/* qmk housekeeping task */
void housekeeping_task_kb(void) {
    timer_pro();

    uart_receive_pro();

    uart_send_report_repeat();

    dev_sts_sync();

    long_press_key();

    dial_sw_scan();

    side_led_show();

    sleep_handle();

    housekeeping_task_user();
}

//led_config_t g_led_config = {
//    {
//        // Key layout thing
//        // Key Matrix to LED Index
//      //{ E, f1, f2, f3, f4, f5, f6, f7, f8, f9,f10,f11,f12, hm, en, dl},
//        { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15},

//      //{~`,  1,  2,  3,  4,  5,  6, *7, *8, *9, *0, *-, *=,     bs, in},
//        {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18,     17, 16},

//      //{tb,   q,  w,  e,  r,  t,  y, *u, *i, *o, *p, *[,  ],     \, ct},
//        {31,  32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,    44, 45},

//      //{cl,    a,  s,  d,  f,  g,  h, *j, *k, *l,  ;,  ',     *ent, pu}
//        {59,   58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48,       47, 46}

//      //{sh,     z,  x,  c,  v,  b,  n, *m, *<, *>,  /,      sh, up, pd},
//        {60,    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,      71, 72, 73},

//      //{ct,  wi, al, [-------- space, --------] al, fn, ct, lf, dn, ri}
//        {83,  82, 81,            80,             79, 78, 77, 76, 75, 74}
//        //
//    },
//    {
//        // LED Index to Physical Position
//        {0,0},  {10,0},  {20,0},  {30,0},  {40,0},  {50,0},  {60,0},  {70,0},  {80,0},  {90,0},  {100,0},  {110,0},  {120,0},  {130,0}, {140,0},   {150,0},  // {244,-4}
//        // Row 2 is reversed
//        {150,10},        {130,10},{120,10},{110,10},{100,10},{90,10}, {80,10}, {70,10}, {60,10}, {50,10},  {40,10},  {30,10}, {20,10},   {10,10},{0,10}
//        // Row 3 is normal? I think?
//        {6,30}, {26,30}, {40,30}, {55,30}, {70,30}, {84,30}, {99,30}, {114,30}, {129,30}, {143,30}, {158,30}, {173,30},           {196,30},           {224,30},
//        {9,45},          {33,45}, {48,45}, {62,45}, {77,45}, {92,45}, {106,45}, {121,45}, {136,45}, {151,45}, {165,45},           {185,45}, {209,49},
//        {2,60}, {20,60}, {39,60},                            {94,60},                               {147,60}, {162,60}, {176,60}, {195,64}, {209,64}, {224,64}
//    },
//    {
//        // RGB LED Index to Flag
//        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1,
//        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
//        8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,    1,
//        1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1, 1,
//        1, 1, 1,          4,          1, 1, 1, 1, 1, 1
//    }
//};
