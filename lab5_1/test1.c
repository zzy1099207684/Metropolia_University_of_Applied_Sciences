#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

enum I2C_INFO {
    I2C_SDA = 16,
    I2C_SCL = 17,
    BAUD_RATE = 400*1000
};

#define I2C_PORT i2c0
#define EEPROM_ADDRESS (0xA0>>1)


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

    uint8_t addr_buf[] = {0x00, 0x00};
    uint8_t write_data = 0xA5;
    uint8_t read_buf[64]={0};

    //write 将 0xA5 写入地址 0
    uint8_t write_buf[] = {0x00, 0x00, 0xA5};

    int res1 = i2c_write_blocking(I2C_PORT, EEPROM_ADDRESS, write_buf, sizeof(write_buf), false);
    // int res1 = i2c_write_blocking(I2C_PORT, EEPROM_ADDRESS, addr_buf, 2, true);
    // int res2 = i2c_write_blocking(I2C_PORT, EEPROM_ADDRESS, &write_data, 1, false);
    //
    printf("res1: %d\n",res1 < 0);
    // printf("res2: %d\n",res2 < 0);
    printf("Data 0x%02X written to address 0x%02X\n", write_data, 0x00);
    busy_wait_ms(1000);

    //read
    int red1 =i2c_write_blocking(I2C_PORT, EEPROM_ADDRESS, addr_buf, 2, true);
    printf("red1: %d\n",red1 < 0);

    // uint8_t addr_buf[] = {0};
    int red2 =i2c_read_blocking(I2C_PORT, EEPROM_ADDRESS, read_buf, 64, false);
    printf("red2: %d\n",red2 < 0);
    printf("Data read from address 0x%02X: 0x%02X\n", 0x00, read_buf[0]);


    while (1) {
        sleep_ms(1000); // 暂停1秒
    }
}