#include "drivers/led.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <time.h>
void init_gpio(int button_pin, const int in_or_put, const int is_pullup) {
    gpio_init(button_pin);
    gpio_set_dir(button_pin, in_or_put);
    if (is_pullup) {
        gpio_pull_up(button_pin); // PULL UP DEFAULT:1 PRESS:0
    }
}

int main(void) {// 压感测试
    stdio_init_all();
    printf("Hello from test_example!\n");
    init_gpio(27, GPIO_IN, 1);

    while (true) {
        uint start_time = to_ms_since_boot(get_absolute_time());
        uint i = gpio_get(27);
        sleep_ms(5);
        if (i == 0) {
            double current_time = to_ms_since_boot(get_absolute_time());
            double diff_time = current_time - start_time;
            if (diff_time <= 84 && diff_time >= 0.4) { // 轮子转速调整配合
                printf("i2: %d\n", i);
                printf("button pressed\n");
            }
        }
    }
}