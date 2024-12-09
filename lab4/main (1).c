s#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#define STR_LEN 128
#define SW_0 9
#define UART_TX_PIN 4
#define UART_RX_PIN 5

#define BAUD_RATE 9600
#define TIMEOUT_US 500000

typedef enum {START, TRY, VERSION, DEVEUI} states;

bool button_pressed(uint btn);
int uart_send_lora_command (const char *cmd, char *response, int response_size);
int try_connect_lora(const char *cmd, char *response, int response_size, int times);
void parse_version (char *response);
void parse_DevEui (char *response);

int main() {
    gpio_init(SW_0);
    gpio_set_dir(SW_0, GPIO_IN);
    gpio_pull_up(SW_0);
    uart_init(uart1, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    stdio_init_all();
    const char cmd_test[] = "AT\r\n";
    const char cmd_version[] = "AT+VER\r\n";
    const char cmd_deveui[] = "AT+ID=DevEui\r\n";
    const char no_respond[] = "Module stopped responding\n";
    const char connect_success[] = "Connected to LoRa module\n";
    char response[STR_LEN];
    states state = START;

    while (true) {
        switch (state) {
            case START:
                if (button_pressed(SW_0)) {
                    while(!gpio_get(SW_0));
                    state = TRY;
                }
                break;
            case TRY:
                if (try_connect_lora(cmd_test, response, STR_LEN, 5)) {
                    printf(connect_success);
                    state = VERSION;
                } else {
                    printf(no_respond);
                    state = START;
                }
                break;
            case VERSION:
                if (uart_send_lora_command(cmd_version, response, STR_LEN)) {
                    parse_version(response);
                    printf("%s\n", response);
                    state = DEVEUI;
                } else {
                    printf(no_respond);
                    state = START;
                }
                break;
            case DEVEUI:
                if (uart_send_lora_command(cmd_deveui, response, STR_LEN)) {
                    parse_DevEui(response);
                    printf("%s\n", response);
                } else printf(no_respond);
                state = START;
                break;
        }
    }
}

int uart_send_lora_command (const char *cmd, char *response, int response_size) {
    memset(response, 0, response_size);
    uart_write_blocking(uart1, (uint8_t *)cmd, strlen(cmd));
    int pos = 0;
    while (uart_is_readable_within_us(uart1, TIMEOUT_US)) {
        char c = uart_getc(uart1);
        if (pos < response_size - 1 && c!='\r' && c!='\n' && c!='\0') {
            response[pos++] = c;
        }
        response[pos] = '\0';
    }
    return (pos==0) ? 0 : 1;
}

int try_connect_lora(const char *cmd, char *response, int response_size, int times) {
    while (times > 0) {
        printf("Trying to connect to LoRa...\n");
        if (uart_send_lora_command(cmd, response, response_size)&&!strcmp(response, "+AT: OK")) return 1;
        times--;
    }
    return 0;
}

void parse_version (char *response) {
    char *start = strstr(response, "+VER: ");
    start += strlen("+VER: ");
    char *dst = response;
    while (*start) {
        *dst++ = *start;
        start++;
    }
    *dst = '\0';
}

void parse_DevEui (char *response) {
    char *start = strstr(response, "+ID: DevEui, ");
    start += strlen("+ID: DevEui, ");
    char *dst = response;
    while (*start) {
        if (*start != ':') {
            *dst++ = (*start >= 'A' && *start <= 'F') ? *start + ('a' - 'A') : *start;
        }
        start++;
    }
    *dst = '\0';
}

bool button_pressed(uint btn) {
    int press = 0;
    int release = 0;
    while (press < 3 && release < 3) {
        if (!gpio_get(btn)) {
            press++;
            release = 0;
        } else {
            release++;
            press = 0;
        }
        sleep_ms(10);
    }
    return (press > release);
}
