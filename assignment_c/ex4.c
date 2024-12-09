#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_integer(void);

// int main(void) {
//     read_integer();
//
//     // printf("%c\n", c);
//     return 0;
// }

//ex4
/*
Write a function called read_integer that takes no parameters and returns an integer. The function
reads a single integer. If the reading fails the function prints “invalid input” and tries to read an
integer again. When an integer is successfully read the function returns the integer.
The declaration of the function is:
int read_integer(void);
Write a program that asks user to enter positive integers or a negative number to stop. The program
must use read_integer-function to read the number. The program calculates and prints the average
of the entered numbers excluding the negative number. For example, if user enters: 1 3 4 2
7 -1, the program prints 3.4 as the average.
The program must print the average with three decimal precision.
*/
int read_integer(void) {
    float read_integer;
    char read_integer_str[20];
    int sum = 0;
    int count = 0;
    double result = 0.0;
    int check_scanf;
    int temp = 0;
    int check_after_point = 0;

    while (true) {
        printf("Enter positive numbers or negative to stop: ");
        // check_scanf = scanf("%s", &read_integer);
        check_scanf = scanf("%f", &read_integer);
        if (check_scanf == 0) {
            printf("Invalid input\n");
            scanf("%*s"); // lost val
            continue;
        }
        sprintf(read_integer_str, "%f", read_integer);
        for (int i = 0; i < strlen(read_integer_str); i++) {
            temp = read_integer_str[i];
            check_after_point += temp - '0';
            if (read_integer_str[i] == '.') {
                check_after_point = 0;
            }
        }

        if (check_after_point != 0) {
            read_integer = 0;
            continue;
        }

        if (read_integer < 0) {
            break;
        }
        sum += read_integer;
        count++;
    }

    result = (float) sum / count;

    printf("The sum of the digits is: %.3f\n", result);

    return result;
}
