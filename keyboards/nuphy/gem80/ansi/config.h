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

#define DEV_MODE_PIN             C0
#define SYS_MODE_PIN             C1
#define DC_BOOST_PIN             C2
#define NRF_RESET_PIN            B4
#define NRF_TEST_PIN             B5
#define NRF_WAKEUP_PIN           B8

#define WS2812_PWM_DRIVER        PWMD3
#define WS2812_PWM_CHANNEL       2
#define WS2812_PWM_PAL_MODE      1
#define WS2812_DMA_STREAM        STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL       3
#define WS2812_PWM_TARGET_PERIOD 800000

#define DRIVER_RGB_DI_PIN        A7
#define DRIVER_LED_CS_PIN        C6
#define DRIVER_SIDE_PIN          C8
#define DRIVER_SIDE_CS_PIN       C9

#define SERIAL_DRIVER            SD1
#define SD1_TX_PIN               B6
#define SD1_TX_PAL_MODE          0
#define SD1_RX_PIN               B7
#define SD1_RX_PAL_MODE          0

// USB sleep workaround :D
#ifdef USB_SUSPEND_WAKEUP_DELAY
#    undef USB_SUSPEND_WAKEUP_DELAY
#endif

#define WS2812_SPI_USE_CIRCULAR_BUFFER

// debounce override - for clangd compliance - info_json.h - doesn't work most of the times
#define DEBOUNCE 5
// use dedicated timer for wait_us interrupts instead on ChibiOS defaulting to minimum 100us even if you sleep for 10us
#define WAIT_US_TIMER GPTD14

#define EECONFIG_KB_DATA_SIZE 14

/*
 * DEFAULT VALUES FOR INITIAL CONFIG to allow override in user keymap
 */
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_position_mode
#define RGB_DEFAULT_COLOR 168

#define DEFAULT_SIDE_MODE            0
#define DEFAULT_SIDE_LIGHT           3
#define DEFAULT_SIDE_SPEED           2
#define DEFAULT_SIDE_RGB             1
#define DEFAULT_SIDE_COLOR           0
#define DEFAULT_LOGO_MODE            0
#define DEFAULT_LOGO_LIGHT           3
#define DEFAULT_LOGO_SPEED           2
#define DEFAULT_LOGO_RGB             1
#define DEFAULT_LOGO_COLOR           0
#define DEFAULT_DEBOUNCE             DEBOUNCE
#define DEFAULT_LIGHT_SLEEP_DELAY    2
#define DEFAULT_DEEP_SLEEP_DELAY     6
#define DEFAULT_SLEEP_ENABLE         true
/*
 * END OF DEFAULT VALUES
 */
