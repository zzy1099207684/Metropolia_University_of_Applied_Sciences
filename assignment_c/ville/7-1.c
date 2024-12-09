//
// Created by zhiyo on 2024/10/15.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


uint32_t get_bits(uint32_t value, uint32_t shift, uint32_t bits) {

    /**
     * 1的二进制是0001, 前面都是0
     * 然后用左移就可以移成各种各样的数字,无论什么进制的数字在C里都是二进制,
     * 因此,所有数字的运算,理论上都可以用左移右移再配合其他四则运算符运算.
     *
     *
     */
    uint32_t mask = (1 << bits) - 1;


    value = value>>shift;
    value = value & mask;

    return value;
}
// 17-8-4
// get_bits(0X11, 8, 4) --> 0X7
// 2019-4-6
// get_bits(0X7E3, 4, 6) --> 0X9
// 42-2-8
// get_bits(0X2A, 2, 8) --> 0X7
// 537085184-24-16
// get_bits(0X20034500, 24, 16) --> 0X10
// 2072751423-16-16
// get_bits(0X7B8BAD3F, 16, 16) --> 0X11
// 115520-9-6
// get_bits(0X1C340, 9, 6) --> 0XB
// 0-1-8
// get_bits(0, 1, 8) --> 0X6
// 2072751423-1-24
// get_bits(0X7B8BAD3F, 1, 24) --> 0X10
// -889274641-18-12
// get_bits(0XCAFEBEEF, 18, 12) --> 0X11



// int main(void) {
//
//
//     // 调用函数并输出结果
//     unsigned int result = get_bits(0X7E3, 4, 6);
//     // uint32_t binary_val = convert_decimal_to_binary(2019);
//     // printf("%u\n--", binary_val);
//
//     // uint32_t mask = (1U << 4) - 1;
//     // uint32_t mask = (1U << 3);
//     // printf("%u\n", mask);
//
//     return 0;
//
// }
