//
// Created by zhiyo on 2024/10/14.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>


int printd(const char *format, ...) {
    int count = 0;
    count+=printf("DEBUG: ");
    va_list args;
    va_start(args, format);
    count+=vprintf(format, args);
    va_end(args);
    return count;
}

// int main(void) {
//     int num = printd("test");
//     printf("%d\n", num);
// }

//

// Characters: %c %c
// Decimals: %d %ld
// Preceding with blanks: %10d
// Preceding with zeros: %010d
// Some different radices: %d %x %o %#x %#o
// floats: %4.2f %+.0e %E
// Width trick: %*d
// %s Total number of chars: %d
// count = 207
