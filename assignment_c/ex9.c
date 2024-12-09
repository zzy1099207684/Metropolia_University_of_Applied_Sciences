#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void ex9();
int find_first(const unsigned int *array, unsigned int what);
void checkRepeat(int *array, int *i, int *checkRepeatResult, int *randomNum);
bool isNumber(char *str);

// int main(void) {
//     setbuf(stdout, NULL);
//     ex9();
//     return 0;
// }


//ex9
/*
Write a function called find_first that takes two parameters: pointer to constant unsigned integers
and an unsigned integer to find and returns an integer.
int find_first(const unsigned int *array, unsigned int what);
The function searches for the given number in the array until it is found or the current number in the
array is zero. If the number is not found until a zero is seen the program returns -1. If the number is
found function returns the index at which the number was found. Note that we don’t pass the size of
the array as a parameter but we use zero as an end marker to stop at the end of the array.
Write a program that defines an array of 20 integers and fills the first 19 elements with random
numbers in range 1 - 20 and puts a zero as the last number in the array. The program prints the array
one number per line.
Program then asks user to enter number to search for or zero to stop. If the number is not zero
program calls find_first to see if the number occurs in the array. If the number is found it prints the
index where the number is found or “not found”. If user enters zero, the program stops otherwise
program asks again user to enter a number to find.
*/

void checkRepeat(int *array, int *i, int *checkRepeatResult, int *randomNum) {
    *checkRepeatResult = 0;
    *randomNum = rand() % 20 + 1;
    for (int j = 0; j < *i; j++) {
        if (*randomNum == array[j]) {
            *checkRepeatResult = -1;
            (*i)--;
            break;
        }
    }
}

void ex9() {
    setbuf(stdin, NULL);
    srand(time(NULL));

    unsigned int array[20];
    char input_number[20];
    int what_number;


    for (int i = 0; i < 20; i++) {
        if (i == 19) {
            array[i] = 0;
            printf("%4d\n", array[i]);
            break;
        }
        int checkRepeatResult;
        int randomNum;
        checkRepeat(array, &i, &checkRepeatResult, &randomNum);

        if (checkRepeatResult == -1) {
            continue;
        }
        array[i] = randomNum;
        printf("%4d\n", array[i]);
    }
    //------------------------------------------------
    //------------------------------------------------

    while (true) {
        printf("input number to find from array: ");
        int temp = scanf("%s", &input_number);
        bool isNumberCheck = isNumber(input_number);
        if (temp != 1 || !isNumberCheck) {
            printf("wrong input\n");
            continue;
        }

        //Parse out the desired format from the str
        sscanf(input_number, "%d", &what_number);

        if (what_number == 0) {
            printf("bye!\n");
            break;
        }

        int result = find_first(array, what_number);
        if (result == -1) {
            printf("not found\n");
            continue;
        }
        printf("the index of number is %d in array\n", result);
    }
}


int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}

bool isNumber(char *str) {
    setbuf(stdout, NULL);
    int num = 0;
    // The string fegets enters comes with a newline at the end,
    // so you might want to handle it without a newline,
    // and the newline should be handled elsewhere
    if(str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    //Parse out the desired format from the str,
    //and if it can't parse out the default value defined by the variable above
    if (sscanf(str, "%d", &num) != 1) {
        return false;
    }

    char str2[10];
    // The number goes to string, and the second argument is to define the buffer size, safe
    snprintf(str2, sizeof(str2), "%d", num);
    // Check whether the length is consistent, the consistent proof is the same as when the input began,
    // otherwise it is different, and the proof is mixed with something else
    if(strlen(str2) == strlen(str)) {
        return true;
    }
    return false;
}
