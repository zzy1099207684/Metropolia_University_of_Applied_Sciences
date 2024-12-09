#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

enum I2C_INFO {
    I2C_SDA = 16,
    I2C_SCL = 17,
    BAUD_RATE = 400*1000
};

#define I2C_PORT i2c0
#define EEPROM_ADDRESS 0b1010000


int i2c_write(uint8_t *addr_buf, uint8_t *data, int data_len) {
    uint8_t write_buf[64] = {0};
    memcpy(write_buf, addr_buf, 2);
    memcpy(&write_buf[2], data, data_len);
    return i2c_write_blocking(I2C_PORT, EEPROM_ADDRESS, write_buf, data_len+2, false);
}

int i2c_read(uint8_t *addr_buf, uint8_t *read_buf, int data_len) {
    int red1 =i2c_write_blocking(I2C_PORT, EEPROM_ADDRESS, addr_buf, 2, true);
    printf("red1: %d\n",red1 < 0);
    return i2c_read_blocking(I2C_PORT, EEPROM_ADDRESS, read_buf, data_len, false);
}

int main() {
    timer_hw->dbgpause = 0;

    // Initialize chosen serial port
    stdio_init_all();
    i2c_init(I2C_PORT, BAUD_RATE);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    sleep_ms(1000);

    uint8_t addr_buf[] = {0x00, 0xFF};
    uint8_t read_buf[64]={0};
    uint8_t data[]="hello world";

    //write 将 0xA5 写入地址 0
    int res1 = i2c_write(addr_buf, data, sizeof(data));
    printf("res1: %d\n",res1 < 0);

    busy_wait_ms(1000);

    //read
    int red2=i2c_read(addr_buf, read_buf,32);
    printf("red2: %d\n",red2 < 0);
    printf("Data read from address 0x%02X: %s\n", 0x00FF, (char*)read_buf);


    while (1) {
        sleep_ms(1000); // 暂停1秒
    }
}
