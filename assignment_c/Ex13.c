#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ARRAY_SIZE 100
#define MAX_FILENAME_LENGTH 100


void ex13();

char *str_append_ex13(const char *oldStr, const char *addStr);

void fgets_change_line_ex13(char *str);

// int main(void) {
//     setbuf(stdout, NULL);
//     ex13();
//
//     return 0;
// }


//ex13
/*
Write a program that asks user to enter a filename. Then program tries to open the file in text mode
for reading. If opening the file fails the program prints an error message with the filename to stderr
and then exits. If the file is opened the program starts reading integers from the file until reading
fails or the file ends. When reading stops the program prints the count of numbers and the lowest
and highest number that was read from the file. Then program closes the file.
For testing make a few text files with integers using your favourite text editor.
*/


void ex13() {
    setbuf(stdin, NULL);
    char read_name[MAX_FILENAME_LENGTH];
    int read_data;
    int biggest_num = INT_MIN;
    int smallest_num = INT_MAX;
    int count = 0;

    printf("Please make sure the file and programme file are in the same place!!!\n");
    printf("please input file name: ");
    fgets(read_name, MAX_ARRAY_SIZE, stdin);
    fgets_change_line_ex13(read_name);

    char *file_name = str_append_ex13("../", read_name);

    FILE *my_file = fopen(file_name, "r");

    if (my_file == NULL) {
        // output error information
        fprintf(stderr, "%s is error file name\n", read_name);
        free(file_name);
        return;
    }
    free(file_name);

    // loop to read integer
    while (fscanf(my_file, "%d", &read_data) == 1) {
        if (read_data > biggest_num) {
            biggest_num = read_data;
        }
        if (read_data < smallest_num) {
            smallest_num = read_data;
        }
        count++;
    }

    if (count == 0) {
        fprintf(stderr, "%s is empty\n", read_name);
    }

    if (count > 0) {
        printf("The count of numbers is: %d\n", count);
        printf("The biggest number is: %d\n", biggest_num);
        printf("The smallest number is: %d\n", smallest_num);
    }

    fclose(my_file);
}


void fgets_change_line_ex13(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}


char *str_append_ex13(const char *old_str, const char *add_str) {
    // allocate new memory
    char *new_str = malloc(strlen(old_str) + strlen(add_str) + 1);

    if (new_str == NULL) {
        perror("malloc error");
        return NULL;
    }
    // init new memory to 0
    memset(new_str, 0, strlen(old_str) + strlen(add_str) + 1);

    strncat(new_str, old_str, strlen(old_str));
    strncat(new_str, add_str, strlen(add_str));
    return new_str;
}
