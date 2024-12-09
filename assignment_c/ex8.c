#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




void print_numbers(const int *array, int count);
void ex8();

// int main(void) {
//     setbuf(stdout, NULL);
//     ex8();
//     return 0;
// }


//ex8
/*
Write a function called print_numbers that takes two parameters: pointer to constant integers and
number of integers to print.
void print_numbers(const int *array, int count);
The function prints the numbers on separate lines in eight characters wide field.
Write a program that defines an array of 15 integers and fills the array with random numbers and
then uses the function to print the array contents.
*/

void ex8() {
    srand(time(NULL));
    int array[15];
    for (int i = 0; i < 15; i++) {
        array[i] = rand();
    }
    print_numbers(array, 15);
}


void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d", array[i]);
    }
}


