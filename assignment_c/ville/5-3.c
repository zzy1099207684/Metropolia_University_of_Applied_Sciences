// //
// // Created by zhiyo on 2024/10/13.
// //
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <stdbool.h>
//
//
//
// #define MAX_LEN 32
//
// typedef struct student_ {
//     char name[MAX_LEN];
//     int group;
//     int id;
// } student;
//
// typedef enum { byGroup, byLastName, byFirstName } sort_order;
//
// void sort_students(student *students, int count, sort_order sb);
//
// // by compare_by_group
// int compare_by_group(const student *a, const student *b) {
//     const student *item1 = a;
//     const student *item2 = b;
//
//     if (item1->group > item2->group) {
//         return 1;
//     }
//     if (item1->group < item2->group) {
//         return -1;
//     }
//     return 0;
// }
//
//
// // by compare_by_first_name
// int compare_by_first_name(const student *a, const student *b) {
//     const student *item1 = a;
//     const student *item2 = b;
//
//     char *name_1 = item1->name;
//     char *pos_1 = strchr(name_1, ' ');
//     int blank_index_1 = pos_1-name_1;
//     char first_name_1[10];
//     strncpy(first_name_1, name_1, 10);
//     first_name_1[blank_index_1] = '\0';
//
//
//     char *name_2 = item2->name;
//     char *pos_2 = strchr(name_2, ' ');
//     int blank_index_2 = pos_2-name_2;
//     char first_name_2[10];
//     strncpy(first_name_2, name_2, 10);
//     first_name_2[blank_index_2] = '\0';
//     if (strcmp(first_name_1, first_name_2) == 0) {
//         return compare_by_group(b, a);
//     }
//     return strcmp(first_name_1, first_name_2);
// }
//
// // by compare_by_last_name
// int compare_by_last_name(const student *a, const student *b) {
//     const student *item1 = a;
//     const student *item2 = b;
//
//     char *name_1 = item1->name;
//     char *pos_1 = strchr(name_1, ' ');
//     int blank_index_1 = pos_1-name_1;
//     char *last_name_1 = name_1+blank_index_1+1;
//
//     char *name_2 = item2->name;
//     char *pos_2 = strchr(name_2, ' ');
//     int blank_index_2 = pos_2-name_2;
//     char *last_name_2 = name_2+blank_index_2+1;
//
//     return strcmp(last_name_1, last_name_2);
// }
//
// void sort_students(student *students, int count, sort_order sb){
//     int total_student_count = 0;
//     for(int i = 0; students[i].id != 0; i++) {
//         total_student_count++;
//     }
//     if (count <= 0) {
//         // all students sort
//         if (sb == byLastName) {
//             qsort(students, total_student_count, sizeof(students[0]), compare_by_last_name);
//         } else if (sb == byFirstName) {
//             qsort(students, total_student_count, sizeof(students[0]), compare_by_first_name);
//         } else { // by group
//             qsort(students, total_student_count, sizeof(students[0]), compare_by_group);
//         }
//     }else {
//         if (sb == byLastName) {
//             qsort(students, count, sizeof(students[0]), compare_by_last_name);
//         } else if (sb == byFirstName) {
//             qsort(students, count, sizeof(students[0]), compare_by_first_name);
//         } else { // by group
//             qsort(students, count, sizeof(students[0]), compare_by_group);
//         }
//     }
// }
//
//
//
// int main() {
//     student students[] = {
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
//         {"", 0, 0}  // 数组结束标志
//     };
//
//     sort_students(students, 0, byFirstName);  // 只对前10个学生按组号排序
//
//     // 打印排序后的结果
//     for (int i = 0; i < 10; i++) {
//         printf("Name: %s, Group: %d, ID: %d\n", students[i].name, students[i].group, students[i].id);
//     }
//
//     return 0;
// }
