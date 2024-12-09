#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *menu[] = {
    "Roll_D6",
    "Roll_D10",
    "Quit"
};


void random_choose(void);


// int main(void) {
//     setbuf(stdout, NULL);
//     random_choose();
//     return 0;
// }

//ex6
/*
Write a program that prints a menu and asks user to select an operation. The operations are:
• Roll D6
• Roll D10
• Quit
Input must be validated and a descriptive error message must be printed if input is invalid. Rolling
D6 prints a random number in the range of 1 – 6 and rolling D10 prints a random number in the
range of 1 – 10. If user does not select quit the program prints the menu again.
Use functions to structure your program.
See: https://en.cppreference.com/w/c/numeric/random/rand for how to produce random numbers
in a range.
*/
void random_choose(void) {
    srand(time(NULL));
    char input_val[15];
    int random_number = 0;
    int len = sizeof(menu)/sizeof(menu[0]);

    while (true) {
        char *val = input_val;
        for (int i = 0; i < len; ++i) {
            printf("* %s\n", menu[i]);
        }
        printf("please input menu name:");
        scanf("%s", val);
        if (strcmp(val, "Roll_D6") == 0) {
            random_number = rand() % 6 + 1;
            printf("the random of number of 1 to 6: %d\n\n", random_number);
        }else if (strcmp(val, "Roll_D10") == 0) {
            random_number = rand() % 10 + 1;
            printf("the random of number of 1 to 10: %d\n\n", random_number);
        }else if (strcmp(val, "Quit") == 0) {
            printf("bye\n");
            break;
        }else {
            printf("invalid input, enter again\n\n");
        }
    }
}
