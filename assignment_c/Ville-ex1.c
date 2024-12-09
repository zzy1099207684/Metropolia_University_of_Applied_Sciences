//
// Created by zhiyo on 2024/9/12.
//
#include <stdio.h>
#include <string.h>


// void sequence(int num1, int num2) {
//     if (num1 > num2) {
//         for (int i = num2; i <= num1; ++i) {
//             printf("%d\n", i);
//         }
//     }else {
//         for (int i = num1; i <= num2; ++i) {
//             printf("%d\n", i);
//         }
//     }
//     printf("\n");
// }


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// setbuf(stdout, NULL);

// int readint(void) {
//     srand(time(NULL));
//     return rand() % 10;
// }


// int main(void) {
//     setbuf(stdout, NULL);
//     int totalNum = 0;
//     int count = 0;
//     while(1){
//         int readNum = readint();
//         if(readNum <= 0){
//             double res = (double)totalNum/count;
//             printf("%.4lf",res);
//             break;
//         }
//         count++;
//         totalNum+=readNum;
//     }
//
//
//
// }

// #include <stdio.h>
// #include <string.h>
//
//
// int largest(int *numbers, int count) {
//     int max = 0;
//     for (int i = 0; i < count; i++) {
//         if (numbers[i] > max) {
//             max = numbers[i];
//         }
//     }
//     return max;
// }
// void sort3(int *a, int *b, int *c) {
//     int temp = 0;
//     if (*a > *b) {
//         temp = *b;
//         *b = *a;
//         *a = temp;
//     }
//     if (*a > *c) {
//         temp = *c;
//         *c = *a;
//         *a = temp;
//     }
//     if (*b > *c) {
//         temp = *c;
//         *c = *b;
//         *b = temp;
//     }
//
// }

// void merge_whitespace(char *str) {
//     char result[strlen(str) + 1];
//     memset(result, 0, strlen(str) + 1);
//     int j = 0;
//     for (int i = 0; str != NULL && str[i] != '\0'; ++i) {
//         if (isspace(str[i])) {
//             if ( (i == 0 || (i <= (strlen(str) - 1)) && isspace(str[i]) != isspace(str[i - 1])) ) {
//                 result[j++] = ' ';
//             }
//
//         } else {
//             result[j++] = str[i];
//         }
//     }
//     result[j] = '\0';
//     strcpy(str, result);
// }

#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


#define TEST_SIZE 12

void sort3(int *pa[3]);

/* write a function that implements the function declared above */


// void sort3(int *pa[3]) {
//     int *temp;
//     for (int i = 0; i < 3; i++) {
//         for (int j = i+1; j < 3; j++) {
//             if(*pa[i] > *pa[j]) {
//                 temp = pa[i];
//                 pa[i] = pa[j];
//                 pa[j] = temp;
//             }
//         }
//     }
// }


// #define MAX_LEN 32
// #define TEST_SIZE 16
//
// typedef struct student_ {
//     char name[MAX_LEN];
//     int group;
//     int id;
// } student;
//
// bool delElementInArray(student *arr, student element) {
//     if (arr != NULL) {
//         for (int i = 0; arr[i].id != 0; i++) {
//             if (arr[i].id == element.id && arr[i].group == element.group && strcmp(arr[i].name, element.name) == 0) {
//                 for (int j = i; arr[j].id != 0; j++) {
//                     arr[j] = arr[j + 1];
//                 }
//                 return true;
//             }
//         }
//     }
//     return false;
// }
//
//
// int move(student *source, int group, student *target, int size) {
//     int i = 0; // source index
//     int j = 0; // target index
//     int move_to_target_num = 0;
//     int target_first_index_count = 0;
//     const int target_size = size - 1;
//
//     for (i = 0; i < target_size && target_first_index_count==0; i++) {
//         if (target[i].id == 0) {
//             j = i;
//             target_first_index_count++;
//         }
//     }
//
//     if (target_first_index_count == 0) {
//         return 0;
//     }
//
//
//     for (i = 0; source[i].id != 0; ++i) {
//         if (source[i].group == group) {
//             // add element to target
//             if (j < target_size) {
//                 //  if the target already has (size-1) elements+
//                 target[j] = source[i];
//                 j++;
//                 move_to_target_num++;
//
//                 //del source element
//                 if (delElementInArray(source, source[i]) && i > 0) {
//                     --i;
//                 };
//             } else {
//                 target[j].id = 0; // The target must also have an end marker.
//                 return 0; //  Function returns zero if the target list is full.
//             }
//         }
//     }
//     target[j].id = 0;
//     return move_to_target_num;
// }
//
// int main() {
//     setbuf(stdout, NULL); // 禁用缓冲区，确保立即输出
//     student source[TEST_SIZE] = {
//         {"Ian McShane", 1, 2019001},
//         {"John Woo", 3, 2019007},
//         {"Nick Name", 3, 2019019},
//         {"Molly Westwood", 2, 2019021},
//         {"Peter Thornton", 2, 2019031},
//         {"Sammy Davis", 3, 2019671},
//         {"Will Smith", 1, 2019761},
//         {"Patti Smith", 4, 2018492},
//         {"Willy Wonka", 2, 2016290},
//         {"Jack Daniels", 4, 2016892},
//         {"Ernie West", 1, 2015192},
//         {"Sean Bean", 2, 2016112},
//         {"Eric Idle", 2, 2017822},
//         {"Susan Sarandon", 5, 2016034},
//         {"Nick Cave", 5, 2015002},
//         {"End", 0, 0}
//     };
//
//
//     student target[11];
//     // Moved 3 elements
//     memset(target, 0, sizeof(target));
//     int movedCount3 = move(source, 3, target, 11);
//     printf("Moved %d elements\n Array after removals:\n", movedCount3);
//     // for (int i = 0; source[i].id != 0; i++) {
//     //     printf("%d\n", source[i].group);
//     // }
//
//     // Moved 2 elements
//     int movedCount2 = move(source, 2, target, 11);
//     printf("Moved %d elements\n Array after removals:\n", movedCount2);
//
//     // Moved 5 elements
//     int movedCount5 = move(source, 5, target, 11);
//     printf("Moved %d elements\n Array after removals:\n", movedCount5);
//     for (int i = 0; source[i].id != 0; i++) {
//         printf("%d\n", source[i].group);
//     }
//
//     // Moved 1 elements 失败应该
//     int movedCount6 = move(source, 1, target, 11);
//     printf("Moved %d elements\n Array after removals:\n", movedCount6);
//     for (int i = 0; source[i].id != 0; i++) {
//         printf("%d\n", source[i].group);
//     }
//
//     return 0;
// }

// typedef enum { English, Italian, Spanish } language;
//
// const char *month(int number, language lang);
//
// const char *lang2str(language lang);
//
//
// const char *lang2str(language lang) {
//     char *result = NULL;
//     if (lang == English) {
//         result = "English";
//     } else if (lang == Italian) {
//         result = "Italian";
//     } else if (lang == Spanish) {
//         result = "Spanish";
//     } else {
//         result = "Error";
//     }
//     return result;
// }
//
// const char *month(int number, language lang) {
//     char *result = "Error";
//
//     if (number < 1 || number > 12) {
//         return "Error";
//     }
//
//     static char *monthsEnglish[] = {
//         "January", "February", "March", "April", "May", "June",
//         "July", "August", "September", "October", "November", "December"
//     };
//
//     // Months in Italian
//     static char *monthsItalian[] = {
//         "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno",
//         "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"
//     };
//
//     // Months in Spanish
//     static char *monthsSpanish[] = {
//         "enero", "febrero", "marzo", "abril", "mayo", "junio",
//         "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
//     };
//
//     if (lang == Spanish) {
//         result = monthsSpanish[number - 1];
//     } else if (lang == English) {
//         result = monthsEnglish[number - 1];
//     } else if (lang == Italian) {
//         result = monthsItalian[number - 1];
//     }
//     return result;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define TEST_SIZE 999


// void change_line_ve(char *str) {
//     if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
//         str[strlen(str) - 1] = '\0';
//     }
// }
//
//
// char *my_gets(char *line, int size, FILE *stream) {
//     fgets(line, size, stream); // my_gets works the same way as fgets.
//     change_line_ve(line);
//     return line;
// }

// int count_chars(const char *characters, FILE *stream) {
//     char line[TEST_SIZE];
//     memset(line, 0, TEST_SIZE);
//     int total_num = 0;
//
//     if (characters != NULL) {
//         while (my_gets(line, TEST_SIZE, stream) != NULL) {
//             //  The function must call my_gets to read the file
//             for (int j = 0; characters[j] != '\0'; j++) {
//                 for (int i = 0; line[i] != '\0'; i++) {
//                     if (characters[j] == line[i]) {
//                         total_num++;
//                     }
//                 }
//             }
//         }
//
//     }
//     return total_num;
// }

// #define TEST_SIZE 100
//
// bool read_line(char *line, size_t size);
//
// bool is_number_ve(char *str) {
//     setbuf(stdout, NULL);
//     int num = 0;
//     if (str[strlen(str) - 1] == '\n') {
//         str[strlen(str) - 1] = '\0';
//     }
//     if (sscanf(str, "%d", &num) != 1) {
//         return false;
//     }
//
//     char str2[10];
//     snprintf(str2, sizeof(str2), "%d", num);
//     if (strlen(str2) == strlen(str)) {
//         return true;
//     } else {
//         return false;
//     }
// }

// bool check_symbol(char *str) {
//     bool flag = false;
//     const char *symbols[] = {"add", "sub", "mul", "div"};
//     if (strcmp(str, symbols[0]) == 0 ||
//         strcmp(str, symbols[1]) == 0 ||
//         strcmp(str, symbols[2]) == 0 ||
//         strcmp(str, symbols[3]) == 0) {
//         flag = true;
//     }
//
//     return flag;
// }

// int main() {
//     char line[TEST_SIZE];
//
//     const char *symbols[] = {"add", "sub", "mul", "div"};
//     while (read_line(line, TEST_SIZE)) {
//         char num1[TEST_SIZE], num2[TEST_SIZE], symbol[TEST_SIZE];
//         sscanf(line, "%s %s %s", num1, num2, symbol);
//         if(is_number_ve(num1)&is_number_ve(num2)&check_symbol(symbol)) {
//             int n1 = atoi(num1);
//             int n2 = atoi(num2);
//             if(strcmp(symbol, symbols[0]) == 0) {
//                 printf("%d + %d = %d\n", n1,n2, n1+n2);
//             }else if(strcmp(symbol, symbols[1]) == 0) {
//                 printf("%d - %d = %d\n", n1,n2, n1-n2);
//             }else if(strcmp(symbol, symbols[2]) == 0) {
//                 printf("%d * %d = %d\n", n1,n2, n1*n2);
//             }else if(strcmp(symbol, symbols[3]) == 0) {
//                 printf("%d / %d = %d\n", n1,n2, n1/n2);
//             }
//         }else if (!is_number_ve(num1)) {
//             printf("Input: \"%s\" ", line);
//             printf("Invalid argument in position: 1\n");
//         } else if(!is_number_ve(num2)) {
//             printf("Input: \"%s\" ", line);
//             printf("Invalid argument in position: 2\n");
//         }else if(!check_symbol(symbol)) {
//             printf("Input: \"%s\" ", line);
//             printf("Unknown command: %s\n",symbol);
//         }
//     }
//     return 0;
// }


// #define MAX_LEN 32
//
// typedef struct student_ {
//     char name[MAX_LEN];
//     int group;
//     int id;
//     struct student_ *next;
// } student;
//
// int move(student **source, int group, student **target) {
//     for (int i = 0; source[i]->next == NULL; i++) {
//         printf("name:%s; group:%d; id:%d; ",source[i]->name, source[i]->group, source[i]->id);
//     }
//     return 1;
// }
//
// student* create_student(const char* name, int group, int id) {
//     student* new_student = (student*)malloc(sizeof(student)); // 动态分配内存
//     if (new_student != NULL) {
//         strncpy(new_student->name, name, MAX_LEN); // 复制姓名
//         new_student->group = group;                 // 设置组别
//         new_student->id = id;                       // 设置ID
//         new_student->next = NULL;                   // 初始化next指针
//     }
//     return new_student; // 返回新节点
// }






/*Ian McShane    , 1,  2019001
John Woo       , 3,  2019007
Nick Name      , 3,  2019019
Molly Westwood , 2,  2019021
Peter Thornton , 2,  2019031
Sammy Davis    , 3,  2019671
Will Smith     , 1,  2019761
Patti Smith    , 4,  2018492
Willy Wonka    , 2,  2016290
Jack Daniels   , 4,  2016892
Ernie West     , 1,  2015192
Sean Bean      , 2,  2016112
Eric Idle      , 2,  2017822
Susan Sarandon , 5,  2016034
Nick Cave      , 5,  2015002*/



