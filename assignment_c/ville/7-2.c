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



void print_binaryw(uint32_t value, uint32_t width) {
    if (value == 0) {
        for (int i = 0; i < width; i++) {
            printf("%d",0);
        }
    }
    // be sure bite
    int most_bite = sizeof(value) * 8 - 1;
    // the index of first 1 in value of binary
    int first_one_index = 0;
    // be sure first 1 index
    int i = 0;
    for (i = most_bite; i >= 0 && !(value&(1<<i)); i--){}
    first_one_index = i;

    // print binary
    if (first_one_index < width) {
        int rest_of_bite = width-first_one_index-1;
        for (i = rest_of_bite; i > 0; i--) {
            printf("%d", 0);
        }
    }
    for (i = first_one_index; i >= 0; i--) {
        printf("%d", value&(1<<i) ? 1 : 0);
    }


}

// int main() {
//     print_binaryw(0, 8);
//     // int s = sizeof(1) * 8;
//     // printf("%d\n", s);
// }