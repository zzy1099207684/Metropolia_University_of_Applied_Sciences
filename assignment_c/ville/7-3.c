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


#define DOT '.'
#define DASH '-'

typedef struct MorseCode_ {
    char symbol;
    char code[7];
} MorseCode;

const MorseCode ITU_morse[] = {
    {'A', {DOT, DASH}}, // A
    {'B', {DASH, DOT, DOT, DOT}}, // B
    {'C', {DASH, DOT, DASH, DOT}}, // C
    {'D', {DASH, DOT, DOT}}, // D
    {'E', {DOT}}, // E
    {'F', {DOT, DOT, DASH, DOT}}, // F
    {'G', {DASH, DASH, DOT}}, // G
    {'H', {DOT, DOT, DOT, DOT}}, // H
    {'I', {DOT, DOT}}, // I
    {'J', {DOT, DASH, DASH, DASH}}, // J
    {'K', {DASH, DOT, DASH}}, // K
    {'L', {DOT, DASH, DOT, DOT}}, // L
    {'M', {DASH, DASH}}, // M
    {'N', {DASH, DOT}}, // N
    {'O', {DASH, DASH, DASH}}, // O
    {'P', {DOT, DASH, DASH, DOT}}, // P
    {'Q', {DASH, DASH, DOT, DASH}}, // Q
    {'R', {DOT, DASH, DOT}}, // R
    {'S', {DOT, DOT, DOT}}, // S
    {'T', {DASH}}, // T
    {'U', {DOT, DOT, DASH}}, // U
    {'V', {DOT, DOT, DOT, DASH}}, // V
    {'W', {DOT, DASH, DASH}}, // W
    {'X', {DASH, DOT, DOT, DASH}}, // X
    {'Y', {DASH, DOT, DASH, DASH}}, // Y
    {'Z', {DASH, DASH, DOT, DOT}}, // Z
    {'1', {DOT, DASH, DASH, DASH, DASH}}, // 1
    {'2', {DOT, DOT, DASH, DASH, DASH}}, // 2
    {'3', {DOT, DOT, DOT, DASH, DASH}}, // 3
    {'4', {DOT, DOT, DOT, DOT, DASH}}, // 4
    {'5', {DOT, DOT, DOT, DOT, DOT}}, // 5
    {'6', {DASH, DOT, DOT, DOT, DOT}}, // 6
    {'7', {DASH, DASH, DOT, DOT, DOT}}, // 7
    {'8', {DASH, DASH, DASH, DOT, DOT}}, // 8
    {'9', {DASH, DASH, DASH, DASH, DOT}}, // 9
    {'0', {DASH, DASH, DASH, DASH, DASH}}, // 0
    {0, {0}} // terminating entry - Do not remove!
};

//
void print_morse(const char *str) {
    printf("%s\n", str);
    setbuf(stdout, NULL);
    char str2[100];
    strncpy(str2, str, 100);
    char *str3 = strtok(str2, " \n\t");

    while (str3 != NULL) {
        int str3_len = strlen(str3);
        int end_count = str3_len;
        for (int i = 0; i < str3_len; i++) {
            char str4 = toupper(str3[i]);
            bool print_count = false;
            for (int j = 0; ITU_morse[j].code[0] != 0; j++) {
                if (str4 == ITU_morse[j].symbol) {
                    end_count--;
                    print_count = true;
                    if (end_count == 0) {
                        printf("%s", ITU_morse[j].code);
                    } else {
                        printf("%s    ", ITU_morse[j].code);
                    }
                    break;
                }
            }
            if (print_count != true) {
                printf("%s    ", ITU_morse[23].code);
                end_count--;
            }
        }

        str3 = strtok(NULL, " \n\t");

        if (str3 != NULL) {
            printf("\n");
            printf("\n");
        }
    }
}

void print_morse2(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            printf("\n\n");
        } else if (isalpha(toupper(str[i])) || isdigit(str[i])) {
            for (int j = 0; ITU_morse[j].code[0] != 0; j++) {
                if (toupper(str[i]) == ITU_morse[j].symbol) {
                    printf("%s    ", ITU_morse[j].code);
                }
            }
        }else {
            printf("%s    ", ITU_morse[23].code);
        }
    }
}

// int main() {
//     // print_morse("I love c");
//     // print_morse("dirty dog");
//     print_morse("odd\nnum83rs");
//     // print_morse2("S#it happens	");
//     // print_morse("I love C programming !");
// }

// I love c
//
//
// end of string
//
// dirty dog
//
//
// end of string
//
// odd
// num83rs
//
//
// end of string
//
// S#it happens
//
//
// end of string
//
// I love C programming !
//
//
// end of string
