#include <stdio.h>
#include <string.h>
#include <pico/util/queue.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

enum I2C_INFO {
    I2C_SDA = 16,
    I2C_SCL = 17,
    BAUD_RATE = 400 * 1000,
    EEPROM_DEVICE_ADDR = 0b1010000
};

#define MEM_ADDR {0x7F, 0xFF - 1}

#define I2C_PORT i2c0
#define WRITE_BUF_SIZE 10
#define ADDR_BUFF_SIZE 2
#define INIT_LED_STATE 0b010
#define ON_HIGH 1
#define OFF_LOW 0

enum LED_PIN_AND_BUTTON_PIN {
    LED_PIN_D1 = 20,
    LED_PIN_D2 = 21,
    LED_PIN_D3 = 22,
    BUTTON_PIN_SW0 = 9,
    BUTTON_PIN_SW1 = 8,
    BUTTON_PIN_SW2 = 7,
};

typedef struct led_state {
    uint8_t state;
    uint8_t not_state;
} led_state_D1_D2_D3;

static queue_t events;
volatile static uint button_last_time = 0;
const static uint button_time_interval = 300;
static bool button_pressed = false;
static uint64_t start_time_point = 0;

//renew the LED state
void set_led_state(led_state_D1_D2_D3 *ls, const uint8_t value) {
    ls->state = value;
    ls->not_state = ~value;
}

bool led_state_is_valid(const led_state_D1_D2_D3 *ls) {
    return ls->state == (uint8_t) ~ls->not_state;
}

int i2c_write(const uint8_t *addr_buf, const uint8_t *data, const int data_len) {
    uint8_t write_buf[WRITE_BUF_SIZE] = {0};
    memcpy(write_buf, addr_buf, ADDR_BUFF_SIZE);
    memcpy(&write_buf[ADDR_BUFF_SIZE], data, data_len);
    return i2c_write_blocking(I2C_PORT, EEPROM_DEVICE_ADDR, write_buf, data_len + 2, false);
}

int i2c_read(const uint8_t *addr_buf, uint8_t *read_buf, const int data_len) {
    i2c_write_blocking(I2C_PORT, EEPROM_DEVICE_ADDR, addr_buf, ADDR_BUFF_SIZE, true);
    return i2c_read_blocking(I2C_PORT, EEPROM_DEVICE_ADDR, read_buf, data_len, false);
}

void init_I2C(void) {
    i2c_init(I2C_PORT, BAUD_RATE);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

void gpio_button_init(const int button_pin, const int in_or_put) {
    gpio_init(button_pin);
    gpio_set_dir(button_pin, in_or_put);
    gpio_pull_up(button_pin); //PULL UP DEFAULT:1 PRESS:0
}

void led_pin_init(const int pin, const int in_or_put) {
    gpio_init(pin);
    gpio_set_dir(pin, in_or_put);
}

static void gpio_handler(uint gpio, uint32_t event_mask) {
    uint current_time = to_ms_since_boot(get_absolute_time());
    if (event_mask & GPIO_IRQ_EDGE_FALL && (current_time - button_last_time >= button_time_interval)) {
        queue_try_add(&events, &gpio);
        button_pressed = true;
        button_last_time = current_time;
    }
}

void init_LED_BUTTON() {
    for (int i = 0; i < 3; ++i) {
        // Initialize LED pin
        led_pin_init(LED_PIN_D1 + i, GPIO_OUT);
        // init button
        gpio_button_init(BUTTON_PIN_SW2 + i, GPIO_IN);
        gpio_set_irq_enabled_with_callback(BUTTON_PIN_SW2 + i, GPIO_IRQ_EDGE_FALL, true, &gpio_handler);
    }
}

/**
 * @param val
 * @param state_arr
 */
void to_binary(uint8_t val, uint8_t *state_arr) {
    for (int i = 0; i < 3; ++i) {
        state_arr[i] = ((val & (1 << i)) ? 1 : 0);
    }
}

void led_on_off(const uint8_t *state_arr) {
    for (int i = 0; i < 3; ++i) {
        gpio_put(LED_PIN_D1 + i, state_arr[i]);
    }
}

void get_time_from_start_to_current(uint8_t led_state_arr[3]) {
    double used_time = (time_us_64() - start_time_point) / 1000000.0;
    printf("used_time: %.6f seconds\n", used_time);
    printf("led state: D3:%d, D2:%d, D1:%d\n", led_state_arr[0], led_state_arr[1], led_state_arr[2]);
}

int main() {
    // timer_hw->dbgpause = 0;
    queue_init(&events, sizeof(int), 10);
    led_state_D1_D2_D3 led_states = {0};
    start_time_point = time_us_64();
    uint8_t mem_addr[] = MEM_ADDR;
    uint8_t led_state_arr[3] = {0};
    uint8_t read_buf[30] = {0};
    uint8_t data[3] = {0};
    int gpio_pin = 0;
    int rd = 0;
    int wt = 0;

    // Initialize chosen serial port
    stdio_init_all();
    init_I2C();
    init_LED_BUTTON();
    sleep_ms(1000);

    //init led state from eeprom
    rd = i2c_read(mem_addr, read_buf, 3);
    if (rd) {
        led_states.state = read_buf[0];
        led_states.not_state = read_buf[1];
        if (led_state_is_valid(&led_states)) {
            to_binary(led_states.state, led_state_arr);
        } else {
            to_binary(INIT_LED_STATE, led_state_arr);
        }
        led_on_off(led_state_arr);
        get_time_from_start_to_current(led_state_arr);

        busy_wait_ms(100);
    } else {
        printf("read error\n");
    }
    while (1) {
        while (queue_try_remove(&events, &gpio_pin)) {
            if (gpio_pin == BUTTON_PIN_SW0) {
                led_state_arr[0] = !gpio_get(LED_PIN_D1);
            } else if (gpio_pin == BUTTON_PIN_SW1) {
                led_state_arr[1] = !gpio_get(LED_PIN_D2);
            } else if (gpio_pin == BUTTON_PIN_SW2) {
                led_state_arr[2] = !gpio_get(LED_PIN_D3);
            }
            set_led_state(&led_states, (led_state_arr[2] << 2) | (led_state_arr[1] << 1) | led_state_arr[0]);
            led_on_off(led_state_arr);
            get_time_from_start_to_current(led_state_arr);
            data[0] = led_states.state;
            data[1] = led_states.not_state;
            wt = i2c_write(mem_addr, data, sizeof(data));
            rd = i2c_read(mem_addr, read_buf, 3);
            if (wt < 0) {
                printf("write error\n");
            }
        }
    }
}
