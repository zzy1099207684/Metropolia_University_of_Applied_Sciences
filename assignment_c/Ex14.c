#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LINE_SIZE 81
#define MAX_ARRAY_SIZE 100
#define MAX_FILENAME_LENGTH 100

const int s = 2;

void ex14();

char *str_append_ex14(const char *oldStr, const char *addStr);

void fgets_change_line_ex14(char *str);


// int main(void) {
//     setbuf(stdout, NULL);
//     ex14();
//
//     return 0;
// }


//ex14
/*
Write a program that reads lines of text in to an array of strings. The maximum length of the line is
80 characters and the maximum number of lines is 100.
The program asks user to enter a filename. Then program tries to open the file in text mode for
reading. If opening the file fails the program prints an error message with the filename to stderr and
then exits. The program reads lines from the file into the array until the file ends or the array is full
(100 lines read). Then program closes the file.
Then program converts all letters to upper case (see toupper() – function).
Then program opens the file for writing in text mode and writes all read lines to file and closes the
file.
*/

typedef struct string_array_list_ {
    char read_data[MAX_LINE_SIZE];
} dataList;

void ex14() {

    setbuf(stdin, NULL);
    char read_name[MAX_FILENAME_LENGTH];
    dataList data_list[MAX_ARRAY_SIZE];
    // init data_list
    memset(data_list, 0, sizeof(data_list));
    int total_dl_count = 0;

    printf("Please make sure the file and programme file are in the same place!!!\n");
    printf("please input file name: ");
    fgets(read_name, MAX_ARRAY_SIZE, stdin);
    fgets_change_line_ex14(read_name);

    char *file_name = str_append_ex14("../", read_name);

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        // output error information
        fprintf(stderr, "%s is error file name\n", read_name);
        free(file_name);
        return;
    }

    while (total_dl_count < MAX_ARRAY_SIZE && fgets(data_list[total_dl_count].read_data, (MAX_LINE_SIZE - 1), file) != NULL) {
        // toupper
        for (int rd_index = 0; rd_index < strlen(data_list[total_dl_count].read_data); ++rd_index) {
            data_list[total_dl_count].read_data[rd_index] = toupper(data_list[total_dl_count].read_data[rd_index]);
        }
        total_dl_count++;
    }
    fclose(file);

    //write
    file = fopen(file_name, "w");
    for (int dl_index = 0; dl_index < total_dl_count; ++dl_index) {
        int write_result = fprintf(file, "%s", data_list[dl_index].read_data);
        if (write_result < 0) {
            fprintf(stderr, "Error writing to file in line %d\n", dl_index + 1);
        }
    }

    fclose(file);
    free(file_name);
    printf("Total %d datas change to success", total_dl_count);
}


void fgets_change_line_ex14(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}


char *str_append_ex14(const char *old_str, const char *add_str) {
    // allocate new memory
    char *new_str = malloc(strlen(old_str) + strlen(add_str) + 1);

    if (new_str == NULL) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    // init new memory to 0
    memset(new_str, 0, strlen(old_str) + strlen(add_str) + 1);

    strncat(new_str, old_str, strlen(old_str));
    strncat(new_str, add_str, strlen(add_str));
    return new_str;
}
