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

