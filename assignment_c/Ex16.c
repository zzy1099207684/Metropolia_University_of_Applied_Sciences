#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INT_SIZE 100


void ex16();

char *str_append_ex16(const char *oldStr, const char *addStr);

void fgets_change_line_ex16(char *str);

void get_number(char *read_data);

bool is_number_ex16(char *str);

bool check_int_range_ex16(char *num);

bool check_input(char *read_data);


// int main(void) {
//     setbuf(stdout, NULL);
//     ex16();
//     return 0;
// }


//ex16
/*
Ex16
Write a program that asks user to enter numbers or to enter end to stop entering numbers. If user
enters any other text except end the program prints an error message and discards the input. The
program must store the numbers in a linked list where each node is dynamically allocated.
typedef struct node {
 int number;
 struct node *next;
} nnode;
When user enters end the program prints all entered numbers, frees the allocated memory and then
ends.
*/

typedef struct node {
    int number;
    struct node *next;
} nnode;

nnode *create_node(int number);

void print_node(nnode *node);

void free_node(nnode *head);


void ex16() {
    setbuf(stdin, NULL);
    char read_data[INT_SIZE];

    nnode *head = NULL;
    nnode *tail = NULL;

    // creat linkedList
    get_number(read_data);
    while (strcmp("end", read_data) != 0) {
        if (check_input(read_data)) continue;

        if (head == NULL) {
            head = create_node(atoi(read_data));
            tail = head;
        } else if (tail != NULL) {
            tail->next = create_node(atoi(read_data));
            tail = tail->next;
        }

        get_number(read_data);
    }

    if (head != NULL && tail != NULL) {
        print_node(head);
        free_node(head);
    }
}

bool check_input(char *read_data) {
    if (!is_number_ex16(read_data) || !check_int_range_ex16(read_data)) {
        printf("Invalid input ");
        get_number(read_data);
        return true;
    }
    return false;
}

void get_number(char *read_data) {
    setbuf(stdin, NULL);
    memset(read_data, '\0', INT_SIZE);
    printf("enter numbers or to enter end to stop: ");
    fgets(read_data, INT_SIZE, stdin);
    fgets_change_line_ex16(read_data);
}

bool check_int_range_ex16(char *num) {
    long int n = strtol(num, NULL, 10); //third param is decimal 10
    if (n >= INT_MIN && n <= INT_MAX) {
        return true;
    }
    return false;
}

nnode *create_node(int number) {
    nnode *node = malloc(sizeof(nnode));
    if (node != NULL) {
        node->number = number;
        node->next = NULL;
        return node;
    }
    fprintf(stderr, "Memory allocation error");
    return NULL;
}

// loop show numbers and free
void print_node(nnode *node) {
    while (node != NULL) {
        printf("%d\n", node->number);
        node = node->next;
    }
}

void free_node(nnode *head) {
    while (head != NULL) {
        nnode *temp = head->next;
        free(head);
        head = temp;
    }
}

void fgets_change_line_ex16(char *str) {
    int str_len = strlen(str);
    if (str_len > 0 && str[str_len - 1] == '\n') {
        str[str_len - 1] = '\0';
    }
}


bool is_number_ex16(char *str) {
    setbuf(stdout, NULL);
    int num = 0;
    fgets_change_line_ex16(str);
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
