#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NAME_SIZE 51
#define ARRAY_SIZE 40
#define BUFFER_SIZE 100
#define SEMICOLON ";"


void ex15();

char *str_append_ex15(const char *oldStr, const char *addStr);

void fgets_change_line_ex15(char *str);


// int main(void) {
//     setbuf(stdout, NULL);
//     ex15();
//
//     return 0;
// }


//ex15
/*
Write a program that reads data from a text file into an array of structures. The size of the array is 40
elements.
The structure is defined as:
typedef struct menu_item_ {
 char name[50];
 double price;
} menu_item;
The program asks user to enter a filename. Then program tries to open the file in textmode for
reading. If opening the file fails the program prints an error message with the filename to stderr and
then exits.
Program reads data from the text file into the array until end of file or the array is full. Each row of
the file contains data of one structure. The members are separated by semicolons. For example:
Mega double burger with bacon and cheese; 23.50
Belgian style fries with vegan mayo; 5.60
When reading ends the program closes the file and prints the content of the array in formatted
columns. Price is printed into a field of eight characters with two decimals precision followed by the
name of the item. Unused elements are not printed.
*/

typedef struct menu_item_ {
    char name[NAME_SIZE];
    double price;
} menu_item;


void ex15() {
    setbuf(stdin, NULL);
    char read_name[NAME_SIZE];
    menu_item data_list[ARRAY_SIZE];
    // init data_list
    memset(data_list, 0, sizeof(data_list));
    char read_buffer[BUFFER_SIZE];
    int total_dl_count = 0;
    char *split_str;
    bool checkFormat = true;
    char semico = ';';


    printf("Please make sure the file and programme file are in the same place!!!\n");
    printf("please input file name: ");
    fgets(read_name, ARRAY_SIZE, stdin);
    fgets_change_line_ex15(read_name);

    char *file_name = str_append_ex15("../", read_name);

    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        // output error information
        fprintf(stderr, "%s is error file name\n", read_name);
        free(file_name);
        return;
    }

    for (int dl_index = 0; dl_index < ARRAY_SIZE
                           && fgets(read_buffer, BUFFER_SIZE, file) != NULL
                           && checkFormat; ++dl_index) {
        fgets_change_line_ex15(read_buffer);
        // before string
        if (strchr(read_buffer, semico) != NULL) {
            split_str = strtok(read_buffer, SEMICOLON);
            if (split_str != NULL) {
                // set before string into struct name
                strncpy(data_list[dl_index].name, split_str, NAME_SIZE - 1);
                data_list[dl_index].name[NAME_SIZE - 1] = '\0';
            }
            // behind string
            split_str = strtok(NULL, SEMICOLON);
            if (split_str != NULL) {
                // char -> double to struct price
                data_list[dl_index].price = strtod(split_str, NULL);
            } else {
                checkFormat = false; // price error
                fprintf(stderr, "no.%d price error\n", total_dl_count + 1);
            }
        } else {
            checkFormat = false; // SEMICOLON error
            fprintf(stderr, "no.%d SEMICOLON error\n", total_dl_count + 1);
        }

        if (checkFormat) {
            total_dl_count++;
        }
    }


    // print
    for (int dl_index = 0; dl_index < total_dl_count; ++dl_index) {
        printf("%8.2f %s\n", data_list[dl_index].price, data_list[dl_index].name);
    }


    fclose(file);
    free(file_name);
}


void fgets_change_line_ex15(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}


char *str_append_ex15(const char *old_str, const char *add_str) {
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
