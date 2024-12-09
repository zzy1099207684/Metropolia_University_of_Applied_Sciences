#include <stdio.h>
#include <hardware/clocks.h>
#include <pico/util/queue.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_PIN_D1 20
#define TOTAL_LED_NUM 3

#define ON_HIGH 1
#define OFF_LOW 0

#define CLOCKWISE 1
#define ANTICLOCKWISE 0

#define BUTTON_PIN_SW0 9
#define BUTTON_PIN_SW1 8
#define BUTTON_PIN_SW2 7
#define ROT_A 10
#define ROT_B 11
#define ROT_SW 12
#define ELEMENT_COUNT 10

#define PWM_WARP_LIGHT_MIN 0
#define PWM_WARP_MAX 999
#define PWM_LIGHT_MAX 1000

#define GPIO_OUT 1
#define GPIO_IN 0

#define BRIGHTNESS_STEP 50

static bool sw1_pressed = false;
volatile static uint button_last_time = 0;
volatile static uint rot_last_time = 0;
const static uint button_time_interval = 20;
const static uint rot_time_interval = 5; // prevent shake

static int last_brightness = PWM_LIGHT_MAX;
static bool on_or_off = OFF_LOW; //0:off, 1:on
static uint slice_num_arr[4];
static uint channel_arr[4];
static queue_t events;

/**
 *
 * @param pin
 * @param in_or_put GPIO_IN:0; GPIO_OUT:1
 */
void led_pin_init(int pin, int in_or_put) {
    gpio_init(pin);
    gpio_set_dir(pin, in_or_put);
}

/**
 *
 * @param button_pin
 * @param in_or_put
 * @param is_pullup 1:pull up 0
 */
void gpio_button_init(int button_pin, int in_or_put, int is_pullup) {
    gpio_init(button_pin);
    gpio_set_dir(button_pin, in_or_put);
    if (is_pullup == ON_HIGH) {
        gpio_pull_up(button_pin); //PULL UP DEFAULT:1 PRESS:0
    }
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
    float sys_clk_dev = (float) clock_get_hz(clk_sys) / 1000000;
    pwm_set_clkdiv(slice_num, sys_clk_dev);

    // set PWM slice highest value
    pwm_set_wrap(slice_num, PWM_WARP_MAX);
    // start pwm
    pwm_set_enabled(slice_num, true);
}

static void gpio_handler(uint gpio, uint32_t event_mask) {
    uint current_time = to_ms_since_boot(get_absolute_time());
    if (gpio == ROT_SW && (event_mask & GPIO_IRQ_EDGE_FALL)) {
        if (current_time - button_last_time >= button_time_interval) {
            queue_try_add(&events, &gpio);
            button_last_time = current_time;
        }
    } else {
        if (current_time - rot_last_time >= rot_time_interval) {
            rot_last_time = current_time;
            if (gpio == ROT_A && (event_mask & GPIO_IRQ_EDGE_RISE)) {
                uint type = ANTICLOCKWISE;
                if (gpio_get(ROT_B) == OFF_LOW) {
                    type = CLOCKWISE;
                }
                queue_try_add(&events, &type);
            }
        }
    }
}

void loop_pwm_set_chan_level(int index_num, uint *slice_num_arr, uint *channel_arr, uint brightness) {
    for (int i = 0; i < index_num; ++i) {
        pwm_set_chan_level(slice_num_arr[i], channel_arr[i], brightness);
    }
}

int main() {
    stdio_init_all();
    int gpio_pin = 0;

    queue_init(&events, sizeof(int), ELEMENT_COUNT);

    for (int i = 0; i < TOTAL_LED_NUM; ++i) {
        int is_pull_up = OFF_LOW;
        // Initialize LED pmw
        init_pmw(LED_PIN_D1 + i, i);
        // init botton
        if (ROT_A + i == ROT_SW) {
            is_pull_up = ON_HIGH;
        }
        gpio_button_init(ROT_A + i, GPIO_IN, is_pull_up);
    }

    gpio_set_irq_enabled_with_callback(ROT_SW, GPIO_IRQ_EDGE_FALL, true, &gpio_handler);
    gpio_set_irq_enabled_with_callback(ROT_A, GPIO_IRQ_EDGE_RISE, true, &gpio_handler);

    while (1) {
        while (queue_try_remove(&events, &gpio_pin)) {
            printf("Got event: %d\r\n", gpio_pin);
            if (gpio_pin == ROT_SW) {
                if (!sw1_pressed) {
                    sw1_pressed = true;
                    if (on_or_off == OFF_LOW) {
                        loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, last_brightness);
                        on_or_off = ON_HIGH;
                    } else {
                        if (last_brightness == 0) {
                            last_brightness = PWM_LIGHT_MAX * 0.5;
                            loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, last_brightness);
                        } else {
                            loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, 0);
                            on_or_off = OFF_LOW;
                        }
                    }
                } else {
                    sw1_pressed = false;
                }
                while (!gpio_get(ROT_SW));
            } else if (on_or_off == ON_HIGH) {
                int brightness = last_brightness;

                //sw0 increase;   sw2 decrease
                if (gpio_pin == CLOCKWISE && brightness < PWM_LIGHT_MAX) {
                    brightness += BRIGHTNESS_STEP;
                    if (brightness >= PWM_LIGHT_MAX) {
                        brightness = PWM_LIGHT_MAX;
                    }
                } else if (gpio_pin == ANTICLOCKWISE && brightness > PWM_WARP_LIGHT_MIN) {
                    brightness -= BRIGHTNESS_STEP;
                    if (brightness <= PWM_WARP_LIGHT_MIN) {
                        brightness = PWM_WARP_LIGHT_MIN;
                    }
                }
                loop_pwm_set_chan_level(TOTAL_LED_NUM, slice_num_arr, channel_arr, brightness);
                last_brightness = brightness;
            }
        }
    }
}
