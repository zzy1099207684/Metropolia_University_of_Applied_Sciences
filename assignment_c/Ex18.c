#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INT_SIZE 10
#define EXIT "-1"


void ex18();

void fgets_change_line_ex18(char *str);

void get_number_ex18(char *read_data, char *message);

bool is_number_ex18(char *str);


// int main(void) {
//     setbuf(stdout, NULL);
//     ex18();
//     return 0;
// }


//ex18
/*
Ex18
Write a program that asks user to enter a number in the range from 0 to 15 or a negative number to
stop. If user enters a number between 0 and 15 the program generates a random number and prints
it in hexadecimal. Then program shifts the number to the right by the amount user entered and uses
bitwise and to clear all other bits except bits 0-5 and prints the result in hexadecimal with two digits
and leading zeros.
Note: bit numbering starts from 0
*/


void ex18() {
    setbuf(stdin, NULL);
    srand(time(NULL));
    char read_data[INT_SIZE];
    int user_input = -1;
    get_number_ex18(read_data, "enter a number in the range from 0 to 15 or a negative number to stop: ");

    while (strcmp(read_data, EXIT) != 0) {
        if (is_number_ex18(read_data)) {
            user_input = atoi(read_data);
            if (user_input >= 0 && user_input <= 15) {
                int rand_num = rand() % 16;
                //prints it in hexadecimal
                printf("%X\n", rand_num);
                // shifts the number to the right by the amount user entered
                int right_move = rand_num >> user_input;
                // uses bitwise and to clear all other bits except bits 0 - 5
                int save_zero_five = right_move & 0x3F;

                // prints the result in hexadecimal with two digits and leading zeros.
                printf("%02X\n", save_zero_five);

                get_number_ex18(read_data, "enter a number in the range from 0 to 15 or "
                                "a negative number to stop: ");
            } else {
                get_number_ex18(read_data, "enter a number in the range from 0 to 15 or "
                                "a negative number to stop: ");
            }
        } else {
            get_number_ex18(read_data, "enter a number in the range from 0 to 15 or "
                            "a negative number to stop: ");
        }
    }
    printf("bye\n");
}


void fgets_change_line_ex18(char *str) {
    int str_len = strlen(str);
    if (str_len> 0 && str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }
}

void get_number_ex18(char *read_data, char *message) {
    setbuf(stdin, NULL);
    memset(read_data, '\0', INT_SIZE);
    printf(message);
    if(fgets(read_data, INT_SIZE, stdin) != NULL) {
        fgets_change_line_ex18(read_data);
    }else {
        fprintf(stderr, "Error reading from stdin\n");
    }
}

bool is_number_ex18(char *str) {
    setbuf(stdout, NULL);
    int num = 0;
    fgets_change_line_ex18(str);
    if (sscanf(str, "%d", &num) != 1) {
        return false;
    }
    char str2[10];
    snprintf(str2, sizeof(str2), "%d", num);
    if (strlen(str2) == strlen(str)) {
        return true;
    }
    return false;
}
