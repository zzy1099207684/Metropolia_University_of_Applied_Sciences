#include <stdio.h>
#include <hardware/clocks.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_PIN_D1 20
#define TOTAL_LED_NUM 3

#define ON 1
#define OFF 0

#define BUTTON_PIN_SW0 9
#define BUTTON_PIN_SW1 8
#define BUTTON_PIN_SW2 7

#define PWM_RANGE_MIN 0
#define PWM_WARP_MAX 999

#define GPIO_OUT 1
#define GPIO_IN 0

#define BRIGHTNESS_STEP 50
#define SYS_CLK_DEV 125

static int last_brightness = PWM_WARP_MAX+1;
static bool on_or_off = OFF; //0:off, 1:on
static uint slice_num_arr[4];
static uint channel_arr[4];

/**
 *
 * @param pin
 * @param in_or_put GPIO_IN:0; GPIO_OUT:1
 */
void led_pin_init(int pin, int in_or_put) {
    gpio_init(pin);
    gpio_set_dir(pin, in_or_put);
}

void gpio_button_init(int button_pin, int in_or_put) {
    gpio_init(button_pin);
    gpio_set_dir(button_pin, in_or_put);
    gpio_pull_up(button_pin); //PULL UP DEFAULT:1 PRESS:0
}


void init_pmw(uint pin, uint index) {
    // init pwm
    // set pwm
    gpio_set_function(pin, GPIO_FUNC_PWM);
    // slice_num
    uint slice_num = pwm_gpio_to_slice_num(pin);
    slice_num_arr[index] = slice_num;

    // get channel
    uint channel_val = pwm_gpio_to_channel(pin);
    channel_arr[index] = channel_val;

    // close firstly
    pwm_set_enabled(slice_num, false);


    // pmw frequency divider
    // float sys_clk_dev = (float) clock_get_hz(clk_sys) / 1000000;
    pwm_set_clkdiv(slice_num, SYS_CLK_DEV);

    // set PWM slice highest value 0-999  INDEX1000
    pwm_set_wrap(slice_num, PWM_WARP_MAX);
    // start pwm
    pwm_set_enabled(slice_num, true);
}

bool pressed(uint pin) {
    int press = 0;
    int release = 0;
    while (press < 3 && release < 3) {
        if (!gpio_get(pin)) {
            press++;
            release = 0;
        } else {
            release++;
            press = 0;
        }
        sleep_ms(40); // wait 40 ms
    }
    if (press > release) return true;
    else return false;
}

void loop_pwm_set_chan_level(int index_num, uint *slice_num_arr, uint *channel_arr, uint brightness) {
    for (int i = 0; i < index_num; ++i) {
        pwm_set_chan_level(slice_num_arr[i], channel_arr[i], brightness);
    }
}

int main() {
    for (int i = 0; i < TOTAL_LED_NUM; ++i) {
        // Initialize LED pin
        led_pin_init(LED_PIN_D1 + i, GPIO_OUT);
        // Initialize LED pmw
        init_pmw(LED_PIN_D1 + i, i);
        // init botton
        gpio_button_init(BUTTON_PIN_SW2 + i, GPIO_IN);
    }


    while (1) {
        bool SW2 = gpio_get(BUTTON_PIN_SW2);
        bool SW0 = gpio_get(BUTTON_PIN_SW0);
        if (pressed(BUTTON_PIN_SW1)) {
            if (on_or_off == OFF) {
                loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, last_brightness);
                on_or_off = ON;
            } else {
                if (last_brightness == 0) {
                    last_brightness = PWM_WARP_MAX * 0.5;
                    loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, last_brightness);
                } else {
                    loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, 0);
                    on_or_off = OFF;
                }
            }
            while (!gpio_get(BUTTON_PIN_SW1));
        } else if (on_or_off == ON) {
            int brightness = last_brightness;

            //sw0 increase;   sw2 decrease
            if (!SW0) {
                brightness += BRIGHTNESS_STEP;
                if (brightness >= PWM_WARP_MAX) {
                    brightness = PWM_WARP_MAX+1;
                }
            } else if (!SW2) {
                brightness -= BRIGHTNESS_STEP;
                if (brightness < PWM_RANGE_MIN) {
                    brightness = PWM_RANGE_MIN;
                }
            }
            loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, brightness);
            last_brightness = brightness;
        }
    }
}
