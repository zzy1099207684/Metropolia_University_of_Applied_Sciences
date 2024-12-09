#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
const int LOW_NUM = 1;
const int HIGH_NUM = 6;

int read_range(int low, int high);

void dice_game(void);

// int main(void) {
//     setbuf(stdout, NULL);
//     dice_game();
//     return 0;
// }

//ex5
/*
Write a function read_range that takes two integer parameters and returns an integer. The function
asks user to enter a number in the range given as parameters. The first parameter is the lowest
acceptable value and the second is the highest acceptable value. When user enters a number the
input is validated in the following ways:
• A number was successfully read
• The number is in the specified range
If the input is invalid then a descriptive error message is printed and user is asked to enter number
again. The function returns only if correct input is given. The function returns the entered number.
The declaration of the function is:
int read_range(int low, int high);
Write a program that “plays” a dice game with user. The game consists of three rounds where
program asks user to roll a die and enter the result (1 – 6). The program must use read_range to
validate input.
The program cheats and always claims to have one higher than what user rolled except when user
rolls six – then program says that it is a tie.
*/
void dice_game(void) {
    int dice_player = 0;
    int game_count = 0;
    printf("Let's play!\n");

    while (game_count < 3) {
        game_count++;
        printf("Roll a die and enter your result.\n");
        dice_player = read_range(LOW_NUM, HIGH_NUM);
        if (dice_player == HIGH_NUM) {
            printf("I got %d. It is a tie!\n", dice_player);
            continue;
        }
        printf("I got %d. I win!\n", ++dice_player);
    }
    printf("Better luck next time. Bye!\n");
}


int read_range(int low, int high) {
    int input_num;
    int check = 0;
    while (true) {
        printf("Enter a number between 1 and 6:");
        check = scanf("%d", &input_num);
        if (check == 0 || input_num < low || input_num > high) {
            printf("Invalid input, please again!\n");
            scanf("%*s");
            continue;
        }
        break;
    }
    return input_num;
}
