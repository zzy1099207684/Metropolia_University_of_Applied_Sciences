#include <stdlib.h>
#include <sec_api/stdio_s.h>
#include <string.h>


#include <time.h>
//
// Created by zhiyo on 2024/8/23.
//
// int main(void) {
//     // ex1();
//     // ex2();
//     int a;
//     int b;
//     char c[1];
//     // scanf("%d#%c", &a,&c[0]);
//     //
//     // printf("%d\n", a);
//     // printf("%c\n", c[0]);
//
//     printf("Enter a number: ");
//     printf("-----zzzzzzzzzzzzzzzzzzz");
//     return 0;
// }
void swap1(int x, int y);

void swap2(int *x, int *y);

// 指针的传递
// int main()
// {
//     setbuf(stdout, NULL);
//     int m = 0, n = 1;
//     printf("Starting values: m, n = %d, %d\n", m, n);
//     swap1(m, n); /* call by value */
//     printf("After swap1(): m, n = %d, %d\n", m, n);
//     swap2(&m, &n); /* call by reference */
//     printf("After swap2(): m, n = %d, %d\n\n", m, n);
//     return 0;
// }
// /* swap1: swaps copies of values */
// void swap1(int x, int y)
// {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }
// /* swap2: swaps values at the addresses given */
// void swap2(int *x, int *y)
// {
//     int temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

//指针函数初次应用
char *strAppend(const char *oldStr, const char *addStr);

// int main(void) {
//
//     // setbuf(stdout, NULL);
//     // char strArr[] = "Hello World!";
//     // char *str = strArr;
//     // char newStrArr[] = "I am new string";
//     // // strcat(str, newStrArr);
//     // // 拼接两个字符串
//     // char *res = strAppend(strArr, newStrArr);
//     //
//     // printf("%s----%zu\n", res, strlen(res));
//     // free(res);
//
//     // int *k;
//     // int t[] = {1, 2, 3};
//     // k = &t[1];
//     //
//     // printf("%d\n", *k);
//
//
//     // int arr[5] = {10, 20, 30, 40, 50};
//     // int *pa;
//     // // pa = &arr[0];
//     // pa = arr;
//     //
//     // printf("%d\n", pa[1]);
//     // printf("%d\n", arr[1]);
//
//     // int a[10] = {1,2,3,4,5,6,7,8,9,10};
//     // int *p = a;//相当于p = a[0]
//     // printf("%d\n", *p);
//     // p+=3;//相当于p = a[0+3]
//     // printf("%d", *p);
//
//
//     // char *pa = "Hello";
//     // char *pas = "Hello";
//     // char *s = strAppend(pa, pas);
//     // printf("%s\n", s);
//
//
//
//
//     // char *const pas = "Hello";
//     // // *pas = 1;// 通过指针去修改数组不可以
//     //
//     // //不能修改就直接复制一个数组用咯
//     // char arr[strlen(pas)];
//     // for (int i = 0; i <= strlen(pas); ++i) {
//     //     if (i == strlen(pas)) {
//     //         arr[i] = '\0';
//     //     }
//     //     arr[i] = pas[i];
//     // }
//     //
//     // printf("%s\n", pas);
//     // printf("%d\n", strlen(pas));
//     // printf("%s\n", arr);
//
//
//     int a[16] = {};
//     //ptr指向a这个地址是无法变更的,一直指着a
//     int *const ptr = a; //指向地址固定
//
//     ptr[3] = 7;
//     *ptr = 3;//a[0]=3
//     printf("%d\n", ptr[3]);
//     printf("%d\n", a[3]);
//     printf("%d\n", *ptr);
//     printf("%d\n", a[0]);
//     // ptr+=1;//指向地址固定, 这句出错.
//     printf("%d\n", ptr);
//
//
//     // int a[10] = {1,2,3,4,5,6,7,8,9,10};
//     int *p = a;//相当于p = a[0]
//     printf("%d\n", *p);
//     p+=3;//相当于p = a[0+3]
//     printf("%d", *p);
//
// }

// // 拼接字符串
// // char *pa = "Hello";
// // char *pas = "Hello";
// // char *s = strAppend(pa, pas);

// char *strAppend(const char *oldStr, const char *addStr) {
//     // allcate new memory
//     char *newStr = (char *) malloc(strlen(oldStr) + strlen(addStr) + 1);
//     if (newStr == NULL) {
//         perror("malloc");
//         return NULL;
//     }
//     // init new memory to 0
//     memset(newStr, 0, strlen(oldStr) + strlen(addStr) + 1);
//
//     strcat(newStr, oldStr);
//     strcat(newStr, addStr);
//     return newStr;
// }

// int main(void) {
//     setbuf(stdout, NULL);
//     // char input_val[15];
//     // while (input_val != "stop") {
//     //     char *val = input_val;
//     //     scanf("%s", input_val);
//     //     printf("%s\n", val);
//     // }
//随机数
//     srand(time(NULL));
//     int randomNumber = rand() % 6 + 1;
//     printf("1-100: %d\n", randomNumber);
//
// }

// int main(void) {
// char str1[20] = "hello";
// char str2[20] = "world";
// char str3[20] = "KK";
// char *str4 = "MM";
//
// char *StringArrayList[5];
// memset(StringArrayList, 0, sizeof(StringArrayList));// init StringList
//
//
//
// StringArrayList[0] = str1;
// StringArrayList[1] = str2;
// StringArrayList[2] = str3;
//
// // StringAppend
// strcat(str1, str2);
// strcat(str2, str3);
// strcat(str3, str4);
//
// // printf("%s\n", str1);
// // printf("%s\n", str2);
// // printf("%s\n", str3);
//
//
// for (int i = 0; i < strlen(StringArrayList); i++) {
//     if (StringArrayList[i] != NULL) {
//         printf("%s,%d\n", StringArrayList[i], i);
//     }
// }


// numbers = (int *)malloc(13 * sizeof(int));

// for (int i = 3; i < 13; i++) {
//     printf("%d\n", numbers[i]);
// }
//
// free(numbers);

// return 0;

// }
// int main() {
//     char *st4 = "MM\n";
//     printf("%s\n", st4);
//     return 0;
// }

// int main(void) {
//     int *numbers = (int *) malloc(10 * sizeof(int));
//     if (numbers == NULL) {
//         return 1;
//     }
//
//     memset(numbers, 0, 10 * sizeof(int));
//     for (int i = 0; i < 10; i++) {
//         numbers[i] = i+1;
//     }
//
//
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", numbers[i]);
//     }
//     // 重新分配之前一定要free掉之前的内存块
//     free(numbers);
//     printf("\n");
//
//     //重新分配内存块
//     numbers = malloc(20 * sizeof(int));
//     if (numbers == NULL) {
//         return 1;
//     }
//     memset(numbers, 0, 20 * sizeof(int));
//     for (int i = 0; i < 20; i++) {
//         numbers[i] = i+1;
//     }
//
//     for (int i = 0; i < 20; i++) {
//         printf("%d ", numbers[i]);
//     }
//
//     free(numbers);
// }


// int main(void) {
//
//     char str1[100] = "zzy", str2[100] = "zzy";
//     char *s = "zzy";
//     char *k = "zzy";
//     // 相当于equal对比字符串  s<k -1; s==k 0;  s>k 1
//     int i = strcmp(s, k);
//     printf("%d\n", i);
//     return 0;
// }

// 判断输入是否为数字
// int main(void) {
//     setbuf(stdout, NULL);
//     char str[10];
//     int num = 0;
//     // gets(str); //废弃不用,不限制输入长度,一个不好就内存泄露
//     fgets(str, sizeof(str), stdin);//指定大小,很nice
//     // fegets输入的字符串会在末尾自带换行符,所以可能要处理掉让他不换行,换行应该在其他地方处理
//     if(str[strlen(str) - 1] == '\n') {
//         str[strlen(str) - 1] = '\0';
//     }
//     printf("%s+++++++++\n", str);
//     //从str中解析出需要格式的内容,如果解析不出来就是上面变量定义的默认值
//     sscanf(str, "%d", &num);
//
//     char str2[10];
//     // 数字转string, 第二个参数是定义缓冲区大小,安全
//     snprintf(str2, sizeof(str2), "%d", num);
//     // 检查长度是否一致
//     if(strlen(str2) == strlen(str)) {
//         printf("%d-------------\n", num);
//     }else {
//         printf("error input");
//     }
// }

#include "Student.h"

void structTestPrint(Student *st);

// int main(void) {
//     Student student;
//     student.age = 18;
//     student.gender = 'f';
//     student.name = "Joy";
//
//     student.age = student.age * 10;
//     // printf("Student name: %s\n", student.name);
//     // printf("Student age: %d\n", student.age);
//     // printf("Student gender: %c\n", student.gender);
//     printf("\n");
//
//
//     // 可以定义指针
//     Student *st;
//     st = &student;
//     st->age = 12;
//     st->gender = 'm';
//     st->name = "adassa";
//     // printf("Student name: %s\n", st->name);
//     // printf("Student age: %d\n", st->age);
//     // printf("Student gender: %c\n", st->gender);
//
//     // structTestPrint(st);
//
//     //直接初始化
//     Student student3={ "test",23,'g'};
//
//
//     Student studentList[2];
//     studentList[0] = student;
//     studentList[1] = student3;
//
//     for (int i = 0; i < 2; i++) {
//         structTestPrint(&studentList[i]);
//     }
// }

//不可以返回局部定义的指针,因为局部变量在程序结束后会因为变量被删除而丢失指向
// void structTestPrint(Student *st) {
//     // st->age = 12;
//     // st->gender = 'm';
//     // st->name = "KKK";
//
//     printf("Student name: %s\n", st->name);
//     printf("Student age: %d\n", st->age);
//     printf("Student gender: %c\n", st->gender);
// }



// int main(int argc, char *argv[]) {
//     int n1 = rand() % 20 + 10;
//     printf("%d\n", n1);
//     printf("%d\n", 100);
// }