#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pico/util/queue.h>
#include <sys/stat.h>

#include "pico/stdlib.h"

#define ELEMENT_COUNT 10
#define ARRAY_SIZE 10
#define INFO_SIZE 100
#define DELAY_MS 50
#define CHECK_CONNECT "AT\r\n"
#define CHECK_FIRMWARE_VERSION "AT+VER\r\n"
// #define READ_DEVEUI "AT+ID=DevEui\r\n"
#define READ_DEVEUI "AT+MODE=LWOTAA\r\n"

enum PRESS_PIN {
    SW_0_PIN = 9,
};

enum ON_HIGH_OFF_LOW_STATE {
    ON_HIGH = 1,
    OFF_LOW = 0,
};

enum UART_INFO {
    BAUD_RATE = 9600,
    TX_PIN = 4,
    RX_PIN = 5,
    TIMEOUT_US = 500000,
    ANSWER_LIMIT_STEP_2 = 5,
    ANSWER_LIMIT_STEP_3_4 = 10
};
static uart_inst_t *uart_id = uart1;

enum STEP {
    STEP_1 = 1,
    STEP_2 = 2,
    STEP_3 = 3,
    STEP_4 = 4
};

static queue_t events;
static uint32_t button_last_time = 0;
static const uint32_t button_time_interval = 50;

void init_gpio(int button_pin, int in_or_put, int is_pullup);

static void gpio_handler(uint gpio, uint32_t event_mask);

void init_uart(uart_inst_t *uart_id_val, uint baud_rate_val, uint uart_tx_pin, uint uart_rx_pin);

bool check_is_answer_in_limit(uint limit, char *message);

void uart_gets(char response_info[][INFO_SIZE], uart_inst_t *UART_ID);

void print_response_message(char response_info[][INFO_SIZE], char *prefix,
                            void (*func)(char array[][INFO_SIZE], char *));

void print_response_message_common(char response_info[][INFO_SIZE], char *prefix);

void print_hex_val_from_response_step4(char response_info[][INFO_SIZE], char *prefix);

int main() {
    // Initialize chosen serial port
    stdio_init_all();
    int sw0 = 0;
    uint state = 1;
    char response_info_array[ARRAY_SIZE][INFO_SIZE] = {0};

    // Initialize LED pin
    init_gpio(SW_0_PIN, GPIO_IN, ON_HIGH);

    queue_init(&events, sizeof(int), ELEMENT_COUNT);

    init_uart(uart_id, BAUD_RATE, TX_PIN, RX_PIN);

    //interrupt sw0
    gpio_set_irq_enabled_with_callback(SW_0_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_handler);


    // Loop forever
    while (1) {
        switch (state) {
            case STEP_1:
                while (queue_try_remove(&events, &sw0)) {
                    state = STEP_2;
                }
                break;
            case STEP_2:
                uart_puts(uart_id, CHECK_CONNECT);
                if (check_is_answer_in_limit(ANSWER_LIMIT_STEP_2, CHECK_CONNECT)) {
                    printf("Connected to LoRa module\n");
                    state = STEP_3;
                } else {
                    printf("module not responding\n");
                    state = STEP_1;
                }
                break;
            case STEP_3:
                sleep_ms(DELAY_MS);
                uart_puts(uart_id, CHECK_FIRMWARE_VERSION);
                if (!check_is_answer_in_limit(ANSWER_LIMIT_STEP_3_4, CHECK_FIRMWARE_VERSION)) {
                    printf("Module stopped responding\n");
                    state = STEP_1;
                } else {
                    uart_gets(response_info_array, uart_id);
                    print_response_message(response_info_array, "STEP3: ", print_response_message_common);
                    memset(response_info_array, 0,ARRAY_SIZE * INFO_SIZE);
                    state = STEP_4;
                }
                break;
            case STEP_4:
                sleep_ms(DELAY_MS);
                uart_puts(uart_id, READ_DEVEUI);
                if (!check_is_answer_in_limit(ANSWER_LIMIT_STEP_3_4, READ_DEVEUI)) {
                    printf("Module stopped responding\n");
                } else {
                    uart_gets(response_info_array, uart_id);
                    print_response_message(response_info_array, "STEP4: ", print_hex_val_from_response_step4);
                }
                state = STEP_1;
                break;
            default: ;
        }
    }
}


void init_gpio(int button_pin, const int in_or_put, const int is_pullup) {
    gpio_init(button_pin);
    gpio_set_dir(button_pin, in_or_put);
    if (is_pullup) {
        gpio_pull_up(button_pin); //PULL UP DEFAULT:1 PRESS:0
    }
}


static void gpio_handler(uint gpio, uint32_t event_mask) {
    uint current_time = to_ms_since_boot(get_absolute_time());
    if (gpio == SW_0_PIN && (event_mask & GPIO_IRQ_EDGE_FALL)) {
        if (current_time - button_last_time >= button_time_interval) {
            queue_try_add(&events, &gpio);
            button_last_time = current_time;
        }
    }
}

void init_uart(uart_inst_t *uart_id_val, uint baud_rate_val, uint uart_tx_pin, uint uart_rx_pin) {
    uart_init(uart_id_val, baud_rate_val);
    gpio_set_function(uart_tx_pin, GPIO_FUNC_UART);
    gpio_set_function(uart_rx_pin, GPIO_FUNC_UART);
}

bool check_is_answer_in_limit(uint limit, char *message) {
    int no_answer_count = 0;
    while (no_answer_count < limit && !uart_is_readable_within_us(uart_id, TIMEOUT_US)) {
        uart_puts(uart_id, message);
        ++no_answer_count;
    }
    return no_answer_count < limit;
}


void uart_gets(char response_info[][INFO_SIZE], uart_inst_t *UART_ID) {
    int index = 0;
    int pos = 0;
    ulong start_time = to_ms_since_boot(get_absolute_time());
    ulong timeout = 1000;
    //uart data is not continuous, eg. 1s have data, 2s no data, 3s have data...keep geting data during 1000ms
    while (to_ms_since_boot(get_absolute_time()) - start_time < timeout) {
        if (uart_is_readable(UART_ID)) {
            char c = uart_getc(UART_ID);
            if (c == '\r' || c == '\n') {
                response_info[index][pos] = '\0';
                if (c == '\n' && index + 1 < ARRAY_SIZE) {
                    index++;
                    pos = 0; // start over after line is printed
                }
            } else if (pos < INFO_SIZE - 1) {
                response_info[index][pos++] = c;
            }
            start_time = to_ms_since_boot(get_absolute_time());
        }
    }
}

void print_response_message(char response_info[][INFO_SIZE], char *prefix,
                            void (*func)(char array[][INFO_SIZE], char *)) {
    func(response_info, prefix);
}

void print_response_message_common(char response_info[][INFO_SIZE], char *prefix) {
    for (int i = 0; response_info[i][0] != '\0'; ++i) {
        printf("%s%s\n", prefix, response_info[i]);
    }
}

void print_hex_val_from_response_step4(char response_info[][INFO_SIZE], char *prefix) {
    int i;
    for (i = 0; response_info[i][0] != '\0' && !(response_info[i][0] == '+' && response_info[i][1] == 'I' && response_info[i][2] == 'D'); ++i){};
    char *temp_str = response_info[i];
    char *index = strchr(temp_str, ',');
    if (index != NULL) {
        int position = index - temp_str + 1;
        temp_str = temp_str + position;
        char *temp_slip_str = strtok(temp_str, ":");
        printf("%s", prefix);
        while (temp_slip_str != NULL) {
            printf("%x", strtol(temp_slip_str, NULL, 16));
            temp_slip_str = strtok(NULL, ":");
        }
        printf("\n\n");
    }
}
