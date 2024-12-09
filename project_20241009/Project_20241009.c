#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROOM_NAME_SIZE 100
#define TEMPERATURE_ARRAY_SIZE 100
#define TEMPERATURE_ROOM_ARRAYLIST_SIZE 50
#define READ_DATA_SIZE 100
#define SIZE 100
#define EXIT "stop"
#define DECIMAL 10
#define TEMPERATURE_MAX 30
#define TEMPERATURE_MIN 0

typedef struct temperature_room {
    char temperature[TEMPERATURE_ARRAY_SIZE];
    char room[ROOM_NAME_SIZE];
} TemperatureRoomArrayList;


void project();

void fgets_change_line_project(char *str);

bool get_num_project(char *read_data, char *message, int range);

void get_file(TemperatureRoomArrayList *temperature_room_arrays, char *file_path, char *mode);

bool is_double_project(char *str);

void show_temperature_dashes(char *room_index_str, int room_index, TemperatureRoomArrayList *temperature_room_arrays,
                             int index, char *record_menu[SIZE], bool check_res);

void print_temperature_pic(double temperature);

void show_menu(TemperatureRoomArrayList *temperature_room_arrays, int *index, char *record_menu[SIZE]);

void delete_blank(char *str);


int main(void) {
    setbuf(stdout, NULL);
    project();
    return 0;
}

//project require
/*
CSV reader
CSV (Comma-Separated Values) files are a common way to store tabular data, making them a
valuable format for data interchange between applicaDons. Write a program that reads house
temperature data from a CSV-file and prints a horizontal bar graph of the temperature in the selected
room. The CSV file starts with a header row and then conDnues with lines of comma separated data.
The header row contains two Dtles: Room and Temperature. Data lines contain room name and the
temperature separated by commas.
Temperature,Room
22.5,Kitchen
18.7,Living Room
24.2,Bedroom
20.1,Kitchen
12.3,Living Room
23.8,Bedroom
16.9,Kitchen
19.4,Living Room
13.7,Bedroom
21.8,Kitchen
11.5,Living Room
24.9,Bedroom
Program must ask user to select a room and then print the temperatures with one decimal precision
followed with a bar graph using dashes (-). Each dash corresponds to 0.5 cenDgrade and
temperatures in the range of 0 – 30 are printed as horizontal bars. Temperatures that are outside or
the range are printed as a single X on the lee. If the selected room does not exist then program must
print an error message.
For example, (not based on the data above):
Bedroom
20.4 ----------------------------------------
22.5 -------------------------------------------
21.4 ------------------------------------------
21.6 -----------------------------------------
32.3 X
18.2 ------------------------------------
18.8 -------------------------------------
19.5 --------------------------------------
21.3 -----------------------------------------
*/

// main
void project() {
    setbuf(stdin, NULL);
    char room_index_str[ROOM_NAME_SIZE];
    int room_index = 0;
    TemperatureRoomArrayList temperature_room_arrays[TEMPERATURE_ROOM_ARRAYLIST_SIZE];
    memset(temperature_room_arrays, 0, sizeof(temperature_room_arrays));
    char *file_path = "../Temperatures.csv";
    char *mode = "r";
    // get data form cvs
    get_file(temperature_room_arrays, file_path, mode);

    int index = 0;
    char *record_menu[SIZE];
    // show menu
    show_menu(temperature_room_arrays, &index, record_menu);


    //user input and check user input
    bool check_res = get_num_project(room_index_str,
                                     "please choose room number from menu or input 'stop' to exit program: ",
                                     index);

    // show  "temperature" and "----------"
    while (strcmp(room_index_str,EXIT) != 0) {
        show_temperature_dashes(room_index_str, room_index, temperature_room_arrays, index, record_menu, check_res);
        check_res = get_num_project(room_index_str,
                                    "please choose room number from menu or input 'stop' to exit program: ",
                                    index);
    }
    printf("bye!\n");
}




//-------function 👇👇👇👇👇👇-------------------------------------------------------------------------------------

void show_menu(TemperatureRoomArrayList *temperature_room_arrays, int *index, char *record_menu[SIZE]) {
    printf("\n");
    int count = 0;
    *index = 0;
    //show menu to support user to choose
    for (int i = 0; temperature_room_arrays[i].room[0] != '\0'; i++) {
        for (int j = 0; record_menu[j] != NULL; j++) {
            if (strcmp(temperature_room_arrays[i].room, record_menu[j]) == 0) {
                count++;
            }
        }
        if (count == 0) {
            record_menu[*index] = temperature_room_arrays[i].room;
            if (*index > 0) {
                printf("%d. %s\n", *index, temperature_room_arrays[i].room);
            }
            *index += 1;
        }
        count = 0;
    }
}

void print_temperature_pic(double temperature) {
    printf("%.1f ", temperature);
    if (temperature >= TEMPERATURE_MIN && temperature <= TEMPERATURE_MAX) {
        int dashes_num = temperature / 0.5;
        for (int j = 0; j < dashes_num; j++) {
            printf("-");
        }
    } else {
        printf("X");
    }
    printf("\n");
}

void show_temperature_dashes(char *room_index_str, int room_index, TemperatureRoomArrayList *temperature_room_arrays,
                             int index, char *record_menu[SIZE], bool check_res) {
    if (check_res) {
        room_index = strtol(room_index_str, NULL, 10);
        for (int i = 0; temperature_room_arrays[i].room[0] != '\0' &&
                        strcmp(room_index_str,EXIT) != 0; i++) {
            if (strcmp(temperature_room_arrays[i].room, record_menu[room_index]) == 0) {
                //temperature ---------------
                double temperature = strtod(temperature_room_arrays[i].temperature, NULL);
                print_temperature_pic(temperature);
            }
        }
    }
}


/**
 * strtok_r is safe split
 * @param read_data
 * @param temperature
 * @param room
 * @return
 */
bool check_data_format(char *read_data, char **temperature, char **room) {
    fgets_change_line_project(read_data);
    char *check = NULL;
    while (isspace(*read_data)) read_data++;
    *temperature = strtok_r(read_data, ",", &check);
    *room = strtok_r(NULL, ",", &check);
    if (*temperature == NULL || *room == NULL) {
        printf("lack of temperature or room\n");
        return false;
    }
    if (strtok_r(NULL, ",", &check) != NULL) {
        printf("comma more than one!\n");
        return false;
    }
    return true;
}

/**
 *
 * @param csv_arr
 * @param file_path include file_name
 * @param mode
 *      "r" only read
 *      "w" write
 *      "a" append
 */
void get_file(TemperatureRoomArrayList *temperature_room_arrays, char *file_path, char *mode) {
    FILE *my_file;
    my_file = fopen(file_path, mode);
    if (my_file == NULL) {
        //file was not opened
        printf("Error opening file\n");
        return;
    }
    char read_data[READ_DATA_SIZE];
    // memset(read_data, 0, sizeof(read_data));
    int line = 0;
    for (int i = 0; i < TEMPERATURE_ROOM_ARRAYLIST_SIZE && fgets(read_data, READ_DATA_SIZE-1, my_file) != NULL; i++) {
        //check data missing
        char *temperature = NULL;
        char *room = NULL;
        //check data format
        if (check_data_format(read_data, &temperature, &room)) {
            //strtok
            strncpy(temperature_room_arrays[i].temperature, temperature, TEMPERATURE_ARRAY_SIZE - 1);
            temperature_room_arrays[i].temperature[TEMPERATURE_ARRAY_SIZE - 1] = '\0';
            strncpy(temperature_room_arrays[i].room, room, ROOM_NAME_SIZE - 1);
            temperature_room_arrays[i].room[ROOM_NAME_SIZE - 1] = '\0';
        } else {
            printf("Error: line %d is invalid data format, skipping.\n", line + 1);
            i--;
        }
        line++;
    }
    fclose(my_file);
}

/**
 * @param str
 */
void fgets_change_line_project(char *str) {
    int str_len = strlen(str);
    if (str_len > 0 && str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }
}

/**
 * @param read_data
 * @param message
 */
bool get_num_project(char *read_data, char *message, int range) {
    setbuf(stdin, NULL);
    memset(read_data, '\0', READ_DATA_SIZE);
    printf(message);
    if (fgets(read_data, READ_DATA_SIZE-1, stdin) != NULL) {
        //delete_blank
        delete_blank(read_data);
        if (is_double_project(read_data) && strcmp(read_data, "0")
            != 0) {
            int num = strtol(read_data, NULL, DECIMAL);
            if (num >= 0 && num < range) {
                fgets_change_line_project(read_data);
                return true;
            }
        }
    }
    return false;
}


bool is_double_project(char *str) {
    setbuf(stdout, NULL);
    double num = 0.0;
    fgets_change_line_project(str);

    if (sscanf(str, "%lf", &num) != 1) {
        return false;
    }

    char str2[SIZE];
    snprintf(str2, sizeof(str2), "%.15g", num);

    if (strlen(str2) == strlen(str)) {
        return true;
    }

    return false;
}


void delete_blank(char *str) {
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
