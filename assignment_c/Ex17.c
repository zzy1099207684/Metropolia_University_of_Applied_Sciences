#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INT_SIZE 100
#define WORD_SIZE 32


void ex17();

bool create_password(char *password, int password_length, const char *word);

void fisher_yates(char *arr);

void fgets_change_line_ex17(char *str);

void get_number_ex17(char *read_data, char *message);

//
// int main(void) {
//     setbuf(stdout, NULL);
//
//     ex17();
//
//     return 0;
// }


//ex17
/*
Ex17
Write a password generator function that takes three parameters: character pointer, integer (size of
the array), a const char pointer (a word) and returns a bool. The function generates password and
stores it in the array and returns true. The length of the generated password is the
𝑙𝑒𝑛𝑔𝑡ℎ 𝑜𝑓 𝑤𝑜𝑟𝑑 × 2 + 1 characters. If the password does not fit in the string function returns false
and does not modify the string.
The password must contain the word given as a parameter so that password starts with a random
printable character and every other letter is a letter from the word and every other is a random
printable character. The password ends with a random printable character. Note that printable
characters are not limited to alphanumerical characters.
Write a program that asks user to enter a word to place in the password or to enter “stop” to stop
the program. The size of the string to read the word into must be 32. If user does not enter stop the
program generates a password using the generator function. If a password is generated successfully
the program prints it otherwise an error message is printed. Then the program asks for another
word.
For example:
User enters: metropolia
Program prints: #m%eGtqrHo&p2o+lBimaY
You don’t need to use colours. They are just a visual aid. The random characters will naturally be
different on your program.
*/


void ex17() {
    setbuf(stdin, NULL);
    srand(time(NULL));
    char word[WORD_SIZE];

    get_number_ex17(word, "Enter a word to be password or Enter 'stop' to exit: ");


    while (strcmp("stop", word) != 0) {
        char password[WORD_SIZE*2+2];
        memset(password, 0, sizeof(password));

        bool res = create_password(password, WORD_SIZE * 2 + 2, word);
        if (res) {
            printf("%s\n", password);
            get_number_ex17(word, "Enter a word to be password or Enter 'stop' to exit: ");
        } else {
            get_number_ex17(word, "can not create password, Enter a word to be password or Enter 'stop' to exit: ");
        }
    }
}

/*
 * password: array of store password
 * len: array length
 * word: self define word
 */
bool create_password(char *password, int password_design_length, const char *word) {
    // password actual length;
    if(word == NULL) {
        return false;
    }
    int pass_actual_len = pass_actual_len = strlen(word) * 2 + 1;
    if (pass_actual_len > password_design_length - 1) {
        return false;
    }

    //random char
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";


    // assemble password
    int word_index = 0;
    int charset_len = strlen(charset);
    // random char/ random word/random char...
    for (int i = 0; i < pass_actual_len; ++i) {
        if (i % 2 == 0) {
            password[i] = charset[rand() % charset_len];
        } else {
            password[i] = word[word_index++];
        }
    }
    password[pass_actual_len-1] = '\0';
    return true;
}

void fgets_change_line_ex17(char *str) {
    int str_len = strlen(str);
    if (str_len > 0 && str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }
}

void get_number_ex17(char *read_data, char *message) {
    setbuf(stdin, NULL);
    memset(read_data, '\0', WORD_SIZE);
    printf(message);
    fgets(read_data, WORD_SIZE, stdin);
    fgets_change_line_ex17(read_data);
}

