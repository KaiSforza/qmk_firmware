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

#pragma once

#include "quantum.h"

#define SIDE_BRIGHT_MAX 4
#define SIDE_SPEED_MAX 4
#define SIDE_COLOUR_MAX 8

#define SIDE_LINE 6
#define SIDE_LED_NUM 12

#define RF_LED_LINK_PERIOD 500
#define RF_LED_PAIR_PERIOD 250

void side_colour_control(void);
void set_left_rgb(uint8_t r, uint8_t g, uint8_t b);
void side_rgb_set_color(int i, uint8_t r, uint8_t g, uint8_t b);
void side_ws2812_setleds(rgb_led_t *ledarray, uint16_t leds);
void rgb_matrix_update_pwm_buffers(void);

