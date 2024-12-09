//
// Created by zhiyo on 2024/9/12.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 100
#define FIX 3


int ex11();
int replace_char(char *str, const char *repl);
void fgets_change_line_ex11(char *str);

// int main(void) {
//     setbuf(stdout, NULL);
//     ex11();
//     return 0;
// }


//ex11
/*
Write a function called replace_char that takes two strings as parameters and returns an integer.
The first string is the string to modify and the second is a string containing two characters. The
function finds every occurrence of the first character of the second string and replaces them with
the second character. For example:
char text[80] = “I am so tired of Python. C is much better language”;
count = replace_char(test, “e3”);
The call above will find every occurrence of ‘e’ and replace it with ‘3’.
Prototype of the function:
int replace_char(char *str, const char *repl);
The function returns the number of characters replaced. The return value can be zero if no
characters were found or if the second string does not contain two characters.
Write a program that asks user to enter both strings and then calls replace_char. The program prints
both return value and the modified string if the return value is greater than zero. If the return value
is zero program prints “String was not modified”.
*/


int ex11() {
    setbuf(stdin, NULL);
    char str[ARRAY_SIZE];
    char repl[FIX];
    printf("Please enter will be change string(do not exceed 10 chars): ");
    fgets(str, ARRAY_SIZE, stdin);
    fgets_change_line_ex11(str);
    printf("please enter two char, first char will be change to second char: ");
    fgets(repl, FIX, stdin);
    fgets_change_line_ex11(repl);

    int res = replace_char(str, repl);
    if (res == 0) {
        printf("String was not modified.\n");
        return 0;
    }
    printf("%d\n", res);
    printf("%s\n", str);
    return str;
}


int replace_char(char *str, const char *repl) {
    int replace_count = 0;
    if (strlen(str) == 0 || (strlen(repl) != 2)) {
        return 0;
    }
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == repl[0]) {
            str[i] = repl[1];
            replace_count++;
        }
    }

    return replace_count;
}


void fgets_change_line_ex11(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}