#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define DECIMAL 10
#define ARRAY_TIMES 5
#define READ_SIZE 50

#include "debug.h"

void fgets_change_line_ex20(char *str);

bool is_number_ex20(char *str);
int ex20();

/**
 *ex20
* Implement a program that consists of three files: main.c, debug.c and debug.h.
Debug.c contains two functions:
• set_debug_level
• dprintf
Set_debug_level takes one integer parameter (debug level) and stores the value in a static variable
that is accessible to all functions in the file but not globally.
void set_debug_level(int debug_level);
Dprintf works like printf but there is an extra integer parameter (debug level) that comes before the
usual printf parameters:
int dprintf(int debug_level, const char *fmt, …);
If dprintf debug level is lower or equal to the stored debug level then function prints the output to
stderr prefixed with [DBGx] , where x is the debug level given as parameter. Otherwise, function
prints nothing and returns zero.
Write a program that asks user to enter debug level in range 0 – 4 and calls set_debug_level with the
number. Then program prints five messages with a random debug level in range 0 – 4 using dprintf.
Get a new random debug level for each message. The messages must have at least one numerical
argument that is a running index that starts from one. First message has index 1,second message 2,
etc
 *
 */

// int main(void) {
//     setbuf(stdout, NULL);
//     setbuf(stdin, NULL);
//     setbuf(stderr, NULL);
//     ex20();
// }

int ex20() {
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);
    srand(time(NULL));
    char read_debug_level[READ_SIZE];
    memset(read_debug_level, 0, sizeof(read_debug_level));
    printf("please set debug level(0-4): ");
    fgets(read_debug_level, sizeof(read_debug_level), stdin);
    fgets_change_line_ex20(read_debug_level);

    long temp = strtol(read_debug_level, NULL, DECIMAL);
    while (!is_number_ex20(read_debug_level) || temp < 0 || temp > 4) {
        printf("please set debug level(0-4): ");
        fgets(read_debug_level, READ_SIZE, stdin);
        fgets_change_line_ex20(read_debug_level);
        printf("\n");
        temp = strtol(read_debug_level, NULL, DECIMAL);
    }

    set_debug_level(strtol(read_debug_level, NULL, DECIMAL));

    for (int i = 0; i < ARRAY_TIMES; i++) {
        int random_num = rand() % 5;
        dprintf(random_num, "index %d\n", i + 1);
    }
    return 0;
}


void fgets_change_line_ex20(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

bool is_number_ex20(char *str) {
    int num = 0;
    fgets_change_line_ex20(str);
    if (sscanf(str, "%d", &num) != 1) {
        return false;
    }

    char str2[10];
    snprintf(str2, sizeof(str2), "%d", num);
    if (strlen(str2) == strlen(str)) {
        return true;
    }
    return false;
}
