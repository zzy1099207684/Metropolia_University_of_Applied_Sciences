//
// Created by zhiyo on 2024/9/12.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void ex10();

int readStrByFgets(char *str, const int *count);

void fgetsChangeLineEx10(char *str);

// int main(void) {
//     setbuf(stdout, NULL);
//     ex10();
//     return 0;
// }


//ex10
/*
Write a program that asks user to enter a string. Program must use fgets to read user input and
remove the linefeed at the end of the string. Then program prints the length of the string and checks
if the string is “stop”. If it is the program stops else program asks user to enter a new string (and
prints the length etc.).
*/
void ex10() {
    setbuf(stdout, NULL);
    int isBreak = 0;
    int count = 10;

    while (!isBreak) {
        char str[count];
        isBreak = readStrByFgets(str, &count);
    }
}

int readStrByFgets(char *str, const int *count) {
    printf("input a new string: ");
    fgets(str, *count, stdin);
    fgetsChangeLineEx10(str);
    if (!strcmp(str, "stop")) {
        return 0;
    }
    printf("string length is %llu \n", strlen(str));

    return 1;
}

void fgetsChangeLineEx10(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}