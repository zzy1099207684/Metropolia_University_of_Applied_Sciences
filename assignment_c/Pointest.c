#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// void test(int **ptr) {
//     if (*ptr != NULL) {
//         **ptr = 42;
//     }
// }
//
// void test1(int *ptr) {
//     if (ptr != NULL) {
//         *ptr = 42;
//     }
// }
//
// int test2(int ptr) {
//     if (ptr != 0) {
//         ptr = 43;
//     }
//     return ptr;
// }
//
//
// int main() {
//     int *ptr;
//     ptr = (int *)malloc(100);
//     *ptr = 10;
//     printf("1111-%d\n", *ptr);
//     test(&ptr);
//     printf("2222-%d\n", *ptr);
//     *ptr = test2(*ptr);
//     printf("3333-%d\n", *ptr);
//
//     // int *pnn = malloc(sizeof(int *));
//     // *pnn = ptr;
//
//     // free(pnn);
//
//
//     free(ptr);
//
// }
//

void test(int *ptr) {
    ptr = malloc(sizeof(int));

    free(ptr);
}

void test2(int **ptr) {
    *ptr = malloc(sizeof(int));
    *ptr = 2;
    **ptr = 3;
}

// int main(void) {
//     int x = 5;      // 普通变量
//     int *p = &x;    // p 是指向 x 的指针
//     int **pp = &p;  // pp 是指向 p 的指针
//
//     printf("1111-%d\n", x);
//     printf("11111-%d\n", &x);
//     printf("2222-%d\n", *p);
//     printf("22222-%d\n", &p);
//     printf("3333-%d\n", **pp);
//
//     int s = 5;      // 普通变量
//     int *k = &s;    // p 是指向 x 的指针
//
//     printf("4444-%d\n", s);
//     printf("4444-%d\n", &s);
//     printf("4444-%d\n", *k);
//
//     int *ptr = NULL;
//     test(ptr);
//     test2(&ptr);
//
// }