#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 51
#define ARRAY_SIZE 40
#define BUFFER_SIZE 100
#define SEMICOLON ";"

typedef struct menu_item_ {
    char name[NAME_SIZE];
    double price;
} menu_item;


void ex19();

char *str_append_ex19(const char *oldStr, const char *addStr);

void fgets_change_line_ex19(char *str);

int compare_by_price_ex19(const menu_item *a, const menu_item *b);

int compare_by_name_ex19(const menu_item *a, const menu_item *b);

void sort_array(char *choose_num, menu_item *data_list, int total_dl_count);

// int main(void) {
//     setbuf(stdout, NULL);
//     ex19();
//
//     return 0;
// }


//ex19
/*
Extend program of Ex15 so that after reading the file content the program asks user to choose
sorting order of the menu. User can choose to sort by price or by name.
Write comparison functions for sorting by name and by price and use qsort() from standard library
to sort the array before printing.
*/



void ex19() {
    setbuf(stdin, NULL);
    char read_name[NAME_SIZE];
    char choose_num[NAME_SIZE];
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
    fgets_change_line_ex19(read_name);

    char *file_name = str_append_ex19("../", read_name);

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
        fgets_change_line_ex19(read_buffer);
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

    //sort by name or price
    sort_array(choose_num, data_list, total_dl_count);

    // print
    for (int dl_index = 0; dl_index < total_dl_count; ++dl_index) {
        printf("%8.2f %s\n", data_list[dl_index].price, data_list[dl_index].name);
    }


    fclose(file);
    free(file_name);
}


void sort_array(char *choose_num, menu_item *data_list, int total_dl_count) {
    //qsort()
    printf("\n1.price\n2.name\n");
    printf("please choose to sort by price or by name: ");
    fgets(choose_num, NAME_SIZE, stdin);
    fgets_change_line_ex19(choose_num);

    while(strcmp(choose_num, "1") != 0 && strcmp(choose_num, "2") != 0) {
        printf("\n1.price\n2.name\n");
        printf("please choose to sort by price or by name: ");
        fgets(choose_num, NAME_SIZE, stdin);
        fgets_change_line_ex19(choose_num);
    }
    if(strcmp(choose_num, "1") == 0) {
        // by price
        // array, elements_number, every element len, compare.
        qsort(data_list, total_dl_count, sizeof(data_list[0]), compare_by_price_ex19);
    }else {
        // by name
        qsort(data_list, total_dl_count, sizeof(data_list[0]), compare_by_name_ex19);
    }
}

// by price
int compare_by_price_ex19(const menu_item *a, const menu_item *b) {
    const menu_item *item1 = a;
    const menu_item *item2 = b;

    if (item1->price > item2->price) {
        return 1;
    }
    if (item1->price < item2->price) {
        return -1;
    }
    return 0;
}


// by name
int compare_by_name_ex19(const menu_item *a, const menu_item *b) {
    const menu_item *item1 = a;
    const menu_item *item2 = b;

    return strcmp(item1->name, item2->name);
}



void fgets_change_line_ex19(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}


char *str_append_ex19(const char *old_str, const char *add_str) {
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
