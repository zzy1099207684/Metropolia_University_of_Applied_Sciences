#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void playGame();

bool read_positive(int *value);


// int main(void) {
//     setbuf(stdout, NULL);
//     playGame();
//     return 0;
// }

//ex7
/*
Write a function named read_positive. The function takes a pointer to int as a parameter and
returns a bool.
bool read_positive(int *value);
The function asks (=prints) user to enter a positive number. If user enters a valid number and the
number is positive the function stores the number using the pointer and returns true. If reading
number fails or number is not positive function returns false without making changes to the value
using pointer.
Write a program that “plays” a guessing game with user. The program asks user to guess how much
money it has and after the guess claims to twice as much plus 20 euros. Program must use the
function above to ask user to enter the number. If reading fails, function returns false, program asks
to enter a number again. Program stops when user has entered an incorrect value three times.
*/
void playGame() {
    int value;
    int error_count = 0;
    while (true) {
        value = 0;
        printf("Guess how much money I have!\n");
        bool read_result = read_positive(&value);
        if (!read_result) {
            printf("Incorrect input\n");
            error_count++;
            if (error_count >= 3) {
                printf("I give up! See you later!\n");
                break;
            }
            continue;
        }
        printf("You didn’t get it right. I have %d euros.\n", value * 2 + 20);
    }
}


bool read_positive(int *value) {
    setbuf(stdin, NULL); //disable buffer
    int number;
    printf("Enter a positive number: ");
    int res = scanf("%d", &number);
    if (res != 1 || number <= 0) {
        // scanf("%*s");
        return false;
    }
    *value = number;
    return true;
}
