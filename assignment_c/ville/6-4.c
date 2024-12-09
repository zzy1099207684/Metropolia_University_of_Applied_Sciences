//
// Created by zhiyo on 2024/10/14.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>

int count_args(int *total_char_num, ...) {
    int chars_count = 0;
    *total_char_num = 0;

    va_list args;
    va_start(args, total_char_num);
    char *str = NULL;
    while ((str = va_arg(args, char*)) != NULL) {
        chars_count++;
        *total_char_num += strlen(str);
    }
    va_end(args);
    return chars_count;
}
