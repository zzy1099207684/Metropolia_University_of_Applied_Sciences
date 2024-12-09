#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INT_SIZE 10
#define EXIT "-1"
#define READ_DATA_SIZE 256
#define DATA_ARRAY 100
#define HEX_SIZE 20
#define NAME_SIZE 20


void ex21();

void change_line_to_end_symbol_ex21(char *str);

void get_file_ex21(char **data_array, char *file_path, char *mode);

void calculate_xor_show(char **data_array);

void delete_blank_ex21(char *str);

char *str_append_ex21(const char *old_str, const char *add_str);


// int main(void) {
//     setbuf(stdout, NULL);
//     ex21();
//     return 0;
// }


//ex21
/*
Write a program that asks user to enter a file name. Program opens the file in text mode. The file is
supposed to contain NMEA (GPS) data. Program looks for lines that start with ‘$’ and have an
asterisk ‘*’ later on the line. If a line meeting the condition is found the program verifies the
checksum of the line. If checksum is ok line is printed prefixed with [ OK ] otherwise line is
prefixed with [FAIL].
Checksum is calculated by XORing all characters after ‘$’ and before ‘*’. The result is checked against
the two-digit hexadecimal value that follows ‘*’. If they are equal line is ok.
*/


void ex21() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char *data_array[DATA_ARRAY];
    char read_name[NAME_SIZE];

    memset(data_array, 0, sizeof(data_array));
    printf("Please make sure the file and programme file are in the same place!!!\n");
    printf("please input file name: ");
    fgets(read_name, NAME_SIZE, stdin);
    change_line_to_end_symbol_ex21(read_name);

    char *file_path = str_append_ex21("../", read_name);
    char *mode = "r";
    // get data
    get_file_ex21(data_array, file_path, mode);

    //calculate XOR and print
    calculate_xor_show(data_array);
}

void calculate_xor_show(char **data_array) {
    for (int i = 0; i < DATA_ARRAY && data_array[i] != NULL; i++) {
        char *line_data = data_array[i];
        // delete blank
        delete_blank_ex21(line_data);
        long int asterisk_index = strchr(line_data, '*') - line_data;
        long int result = 0;
        char *end_hex_data = line_data + asterisk_index + 1;
        char hex_str[HEX_SIZE];
        // jump over $
        for (int j = 1; j < asterisk_index; j++) {
            result ^= line_data[j];
        }
        snprintf(hex_str, sizeof(hex_str), "%02X", result);
        if (strcmp(hex_str, end_hex_data) == 0) {
            printf("[ OK ]%s\n", line_data);
        } else {
            printf("[FAIL]%s\n", line_data);
        }
        free(line_data);
    }
}

void get_file_ex21(char **data_array, char *file_path, char *mode) {
    FILE *my_file = fopen(file_path, mode);
    free(file_path);
    if (my_file == NULL) {
        //file was not opened
        printf("Error opening file\n");
        return;
    }
    char *read_data = malloc(sizeof(char) * READ_DATA_SIZE);
    int array_index = 0;
    for (int i = 0; i < DATA_ARRAY && fgets(read_data, READ_DATA_SIZE - 1, my_file) != NULL; i++) {
        change_line_to_end_symbol_ex21(read_data);
        //check data format
        char *command_prompt = strchr(read_data, '$');
        char *asterisk = strchr(read_data, '*');
        if (command_prompt != NULL && asterisk != NULL) {
            long int command_prompt_index = command_prompt - read_data;
            long int asterisk_index = asterisk - read_data;

            if (command_prompt_index == 0 && strlen(read_data) - (asterisk_index + 1) == 2) {
                data_array[array_index] = read_data;
                array_index++;
                read_data = malloc(sizeof(char) * READ_DATA_SIZE);
            }
        }
    }
    fclose(my_file);
}


void change_line_to_end_symbol_ex21(char *str) {
    int str_len = strlen(str);
    if (str_len > 0 && str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }
}

void delete_blank_ex21(char *str) {
    char *start = str;
    char *end;
    while (isspace(*start)) start++;
    if (*start == 0) {
        str[0] = '\0';
        return;
    }
    end = start + strlen(start) - 1;
    while (end > start && isspace(*end)) end--;
    *(end + 1) = '\0';
    memmove(str, start, end - start + 2);
}

char *str_append_ex21(const char *old_str, const char *add_str) {
    size_t new_str_size = strlen(old_str) + strlen(add_str) + 1;

    char *new_str = malloc(new_str_size);

    if (new_str == NULL) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }

    snprintf(new_str, new_str_size, "%s%s", old_str, add_str);

    return new_str;
}
