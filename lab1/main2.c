//#include <stdio.h>
//#include <hardware/clocks.h>
//
//#include "pico/stdlib.h"
//#include "hardware/pwm.h"
//#define LED_PIN_D2 21
//#define ON 1
//#define OFF 0
//
//#define BUTTON_PIN_SW0 9
//#define BUTTON_PIN_SW1 8
//#define BUTTON_PIN_SW2 7
//
//#define PWM_RANGE_MIN 0
//#define PWM_RANGE_MAX 999
//
//#define GPIO_OUT 1
//#define GPIO_IN 0
//
//#define BRIGHTNESS_STEP 5
//
//void interrupt_callback_control_LED() __attribute__ ((interrupt ("IRQ")));
//
//
//static bool sw1_pressed = false;
//
//static int last_brightness = PWM_RANGE_MAX;
//static bool on_or_off = OFF; //0:off, 1:on
//
//static uint last_time = 0;
//const static uint time_interval = 10;
//
//static uint slice_num = 0;
//
//static uint channel = 0;
//
//void set_brightness(int brightness) {
//    last_brightness = brightness;
//}
//
//void set_on_or_off(int on_or_off_val) {
//    on_or_off = on_or_off_val;
//}
//
//void set_slice_num(uint slice_num_val) {
//    slice_num = slice_num_val;
//}
//
//void set_channel(uint channel_val) {
//    channel = channel_val;
//}
//
///**
// *
// * @param pin
// * @param in_or_put GPIO_IN:0; GPIO_OUT:1
// */
//void led_pin_init(int pin, int in_or_put) {
//    gpio_init(pin);
//    gpio_set_dir(pin, in_or_put);
//}
//
//
//void interrupt_callback_control_LED(uint gpio, uint32_t events) {
//    // get current time
//    uint current_time = to_ms_since_boot(get_absolute_time());
//
//    // use time to control
//    // if current time distance last time 100ms
//    // the way also use to prevent switch bounce
//    if (current_time - last_time >= time_interval) {
//        last_time = current_time;
//
//        if (gpio == BUTTON_PIN_SW1) {
//            // !pressed !0  use event GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE to prevent switch bounce
//            if (!sw1_pressed) {
//                sw1_pressed = true;
//                if (on_or_off == OFF) {
//                    pwm_set_chan_level(slice_num, channel, last_brightness);
//                    set_on_or_off(ON);
//                } else if (on_or_off == ON) {
//                    if (last_brightness == 0) {
//                        last_brightness = PWM_RANGE_MAX * 0.5;
//                        pwm_set_chan_level(slice_num, channel, last_brightness); // set last_brightness
//                    } else {
//                        pwm_set_chan_level(slice_num, channel, 0);
//                        set_on_or_off(OFF);
//                    }
//                }
//            } else if (events & GPIO_IRQ_EDGE_RISE) {
//                // release use event GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE to prevent switch bounce
//                sw1_pressed = false;
//            }
//        } else if (on_or_off == ON) {
//            int brightness = last_brightness;
//
//            //sw0 increase;   sw2 decrease
//            if (gpio == BUTTON_PIN_SW0 && brightness < PWM_RANGE_MAX) {
//                brightness += BRIGHTNESS_STEP;
//                if (brightness > PWM_RANGE_MAX) {
//                    brightness = PWM_RANGE_MAX;
//                }
//            } else if (gpio == BUTTON_PIN_SW2 && brightness > PWM_RANGE_MIN) {
//                brightness -= BRIGHTNESS_STEP;
//                if (brightness < PWM_RANGE_MIN) {
//                    brightness = PWM_RANGE_MIN;
//                }
//            }
//            pwm_set_chan_level(slice_num, channel, brightness);
//            set_brightness(brightness);
//        }
//    }
//}
//
//
//void gpio_button_init(int button_pin, int in_or_put) {
//    gpio_init(button_pin);
//    gpio_set_dir(button_pin, in_or_put);
//    gpio_pull_up(button_pin); //PULL UP DEFAULT:1 PRESS:0
//}
//
//
//void pmw_init(void) {
//    // init pwm
//    // set pwm
//    gpio_set_function(LED_PIN_D2, GPIO_FUNC_PWM);
//    // slice_num
//    uint slice_num = pwm_gpio_to_slice_num(LED_PIN_D2);
//
//    // get channel
//    uint channel = pwm_gpio_to_channel(LED_PIN_D2);
//    set_channel(channel);
//
//    // close firstly
//    pwm_set_enabled(slice_num, false);
//
//    set_slice_num(slice_num);
//
//    // pmw frequency divider
//    float sys_clk_dev = (float)clock_get_hz(clk_sys)/1000000;
//    pwm_set_clkdiv(slice_num, sys_clk_dev);
//
//    // set PWM slice highest value
//    pwm_set_wrap(slice_num, PWM_RANGE_MAX);
//    // start pwm
//    pwm_set_enabled(slice_num, true);
//}
//
//int main() {
//    setbuf(stdout, NULL);
//    // Initialize LED pin
//    led_pin_init(LED_PIN_D2, GPIO_OUT);
//
//    // init botton
//    gpio_button_init(BUTTON_PIN_SW0, GPIO_IN);
//    gpio_button_init(BUTTON_PIN_SW1, GPIO_IN);
//    gpio_button_init(BUTTON_PIN_SW2, GPIO_IN);
//
//    // Initialize chosen serial port
//    stdio_init_all();
//
//
//    pmw_init();
//
//
//    gpio_set_irq_enabled_with_callback(BUTTON_PIN_SW1, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true,
//                                       &interrupt_callback_control_LED);
//    gpio_set_irq_enabled_with_callback(BUTTON_PIN_SW0, GPIO_IRQ_LEVEL_LOW, true, &interrupt_callback_control_LED);
//    gpio_set_irq_enabled_with_callback(BUTTON_PIN_SW2, GPIO_IRQ_LEVEL_LOW, true, &interrupt_callback_control_LED);
//
//    while (1) {
//        // bool is_pressed1 = gpio_get(BUTTON_PIN_SW1);
//        // bool is_pressed2 = gpio_get(BUTTON_PIN_SW2);
//        // bool is_pressed0 = gpio_get(BUTTON_PIN_SW0);
//        // if (is_pressed1 || is_pressed2 || is_pressed0) {
//        //     printf("Button pressed\n");
//        // }
//        tight_loop_contents();
//    }
//}
