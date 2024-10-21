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

#include "ansi.h"
#include "config.h"
#include "usb_main.h"
#include "user_kb.h"

extern bool            f_rf_sw_press;
extern bool            f_sleep_show;
extern bool            f_power_togg_show;
extern bool            f_dev_reset_press;
extern bool            f_rf_dfu_press;
extern bool            f_bat_hold;
extern uint32_t        no_act_time;
extern uint8_t         rf_sw_temp;
extern uint16_t        rf_sw_press_delay;
extern uint16_t        rf_linking_time;
extern user_config_t   user_config;
extern DEV_INFO_STRUCT dev_info;
extern uint16_t        rf_link_show_time;

extern bool f_bat_num_show;
extern bool f_deb_show;
extern bool f_l_sleep_show;
extern bool f_d_sleep_show;

/**
 * @brief  qmk pre process record - used to catch light sleep wake up faster
 */
bool pre_process_record_kb(uint16_t keycode, keyrecord_t *record) {
    no_act_time     = 0;
    rf_linking_time = 0;
    // wakeup check for light sleep/no sleep - fire this immediately to not lose wake keys.
    if (f_wakeup_prepare) {
        f_wakeup_prepare = 0;
        f_goto_sleep     = 0;
        exit_light_sleep();
    }

    return pre_process_record_user(keycode, record);
}

/**
 * @brief  qmk process record
 */
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    no_act_time = 0;

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

        case WIN_LOCK:
            if (record->event.pressed) {
                keymap_config.no_gui = !keymap_config.no_gui;
            } else
                unregister_code16(keycode);
            break;

        case MAC_VOICE:
            if (record->event.pressed) {
                host_consumer_send(0xcf);
            } else {
                host_consumer_send(0);
            }
            return false;

        case MAC_DND:
            if (record->event.pressed) {
                host_system_send(0x9b);
            } else {
                host_system_send(0);
            }
            return false;

        case SIDE_VAI:
            if (record->event.pressed) {
                light_level_control(1);
            }
            return false;

        case SIDE_VAD:
            if (record->event.pressed) {
                light_level_control(0);
            }
            return false;

        case SIDE_MOD_A:
            if (record->event.pressed) {
                side_mode_a_control();
            }
            return false;

        case SIDE_MOD_B:
            if (record->event.pressed) {
                side_mode_b_control();
            }
            return false;

        case SIDE_HUI:
            if (record->event.pressed) {
                side_colour_control();
            }
            return false;

        case SIDE_SPI:
            if (record->event.pressed) {
                light_speed_contol(1);
            }
            return false;

        case SIDE_SPD:
            if (record->event.pressed) {
                light_speed_contol(0);
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

        case DEB_I:
            if (record->event.pressed) {
                handle_debounce_change(1);
            }
            return false;

        case DEB_D:
            if (record->event.pressed) {
                handle_debounce_change(0);
            }
            return false;

        case DEB_SHOW:
            f_deb_show = record->event.pressed;
            return false;

        case DEB_RESET:
            if (record->event.pressed) {
                user_config.debounce = DEFAULT_DEBOUNCE;
                eeconfig_update_kb_datablock(&user_config);
            } else {
                unregister_code16(keycode);
            }
            return false;

        case L_SLP_I:
            if (record->event.pressed) {
                handle_light_sleep_change(1);
            }
            return false;

        case L_SLP_D:
            if (record->event.pressed) {
                handle_light_sleep_change(0);
            }
            return false;

        case L_SLP_SHOW:
            f_l_sleep_show = record->event.pressed;
            return false;

        case L_SLP_RESET:
            if (record->event.pressed) {
                user_config.light_sleep_delay = DEFAULT_LIGHT_SLEEP_DELAY;
                eeconfig_update_kb_datablock(&user_config);
            } else {
                unregister_code16(keycode);
            }
            return false;

        case D_SLP_I:
            if (record->event.pressed) {
                handle_deep_sleep_change(1);
            }
            return false;

        case D_SLP_D:
            if (record->event.pressed) {
                handle_deep_sleep_change(0);
            }
            return false;

        case D_SLP_SHOW:
            f_d_sleep_show = record->event.pressed;
            return false;

        case D_SLP_RESET:
            if (record->event.pressed) {
                user_config.deep_sleep_delay = DEFAULT_DEEP_SLEEP_DELAY;
                eeconfig_update_kb_datablock(&user_config);
            } else {
                unregister_code16(keycode);
            }
            return false;

        case PWR_SHOW:
            if (record->event.pressed) {
                user_config.power_on_show = !user_config.power_on_show;
                eeconfig_update_kb_datablock(&user_config);
                f_power_togg_show = 1;
            } else {
                unregister_code16(keycode);
            }
            return false;

        default:
            return true;
    }
    return true;
}

/**
   qmk keyboard post init
 */
void keyboard_post_init_kb(void) {
    gpio_init();
    rf_uart_init();
    wait_ms(500);
    rf_device_init();
    break_all_key();
    eeconfig_read_kb_datablock(&user_config);
    dial_sw_fast_scan();
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    // check if any show flags are on and display
    stat_show();

    // light up corresponding BT mode key during connection and  link show time
    if (!f_power_show && (rf_blink_cnt || rf_link_show_time < RF_LINK_SHOW_TIME)) {
        if (dev_info.link_mode >= LINK_BT_1 && dev_info.link_mode <= LINK_BT_3) {
            user_set_rgb_color(16 + dev_info.link_mode, 0, 0, 0x80);
        } else if (dev_info.link_mode == LINK_RF_24) {
            user_set_rgb_color(20, 0, 0x80, 0);
        }
    }

    if (keymap_config.no_gui) {
        user_set_rgb_color(72, 0x00, 0x80, 0x00);
    }

    // power down unused LEDs
    if (!f_power_show) {
        led_power_handle();
    }
    return true;
}

/**
   housekeeping_task_user
 */
void housekeeping_task_kb(void) {
    timer_pro();

    uart_receive_pro();

    uart_send_report_repeat();

    dev_sts_sync();

    long_press_key();

    dial_sw_scan();

    side_led_show();

    sleep_handle();
}
