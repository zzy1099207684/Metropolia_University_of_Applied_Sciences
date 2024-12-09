//
// Created by zhiyo on 2024/9/12.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 100
#define WORD_SIZE 10


int ex12();

int count_words(const char* str, const char *word);
void fgets_change_line_ex12(char *str);
//
// int main(void) {
//     setbuf(stdout, NULL);
//     ex12();
//
//     return 0;
// }


//ex12
/*
Write a function count_words that takes two strings as a parameter and returns an integer. The
function counts the number of times the second string occurs in the first string and returns the
count. Use strstr() from standard library to find the strings. Note that if the string is found you need
to advance past the current occurrence before searching again. Hint: use a pointer to the string and
use pointer arithmetic to advance it past the current match.
Prototype of the function:
int count_words(const char* str, const char *word);
Write a program that asks user to enter a string and a word. Then program calls count_words and
prints the return value. If the word was “stop” the program stops otherwise it asks user to enter a
string and a word again.
*/


void fgets_change_line_ex12(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

// void count_words(char *str, char *word, int *count, char *p) {
//     char *current = str;
//     while (strstr(current, word) != NULL) {
//         p = strstr(current, word);
//         (*count)++;
//         current += p - current + strlen(word);
//     }
// }

int count_words(const char* str, const char *word){
    int count = 0;
    char *p;
    const char *current = str;
    while (strstr(current, word) != NULL) {
        p = strstr(current, word);
        count++;
        current += p - current + strlen(word);
    }
    return count;
}

int ex12() {
    setbuf(stdin, NULL);
    char word[ARRAY_SIZE];
    char str[ARRAY_SIZE];
    int count = 0;
    // char *p = 0;
    while (strcmp("stop", word) != 0) {
        printf("Please enter a new string: ");
        fgets(str, ARRAY_SIZE, stdin);
        printf("Please enter that it will be find word(DO NOT EXCEED 10 CHARS): ");
        fgets(word, WORD_SIZE, stdin);
        fgets_change_line_ex12(str);
        fgets_change_line_ex12(word);
        count = count_words(str, word);
        printf("the word occurs %d times \n", count);
    }

    return 1;
}


