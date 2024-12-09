#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int BUFFER_SIZE = 20;
const int NEW_BUFFER_SIZE = 30;
//
// Created by zhiyo on 2024/9/16.
//
// int main() {
//     char *ptr;
//     ptr = (char *) malloc(BUFFER_SIZE);
//     //规范必须判空
//     if (ptr == NULL) {
//         printf("Memory allocation failed\n");
//         return -1;
//     }
//     //初始化
//     memset(ptr, 0, BUFFER_SIZE);
//
//     // 这里控制赋值大小要比实际分配大小小1,限制越界的可能并且给下面手动赋值留了一个空间
//     strncpy(ptr, "123456789abcdefghij", BUFFER_SIZE - 1);
//     // 手动在最后一个索引处加停止符号
//     ptr[BUFFER_SIZE - 1] = '\0';
//
//     printf("1111-%s\n", ptr);
//     printf("1111-%llu\n", strlen(ptr));
//
//
//     //改变原来内存块大小要记得用新指针变量接收, 不要用原来的,以免新分配失效
//     // 底层会看能不能改变原来内存块,如果原内存块后面空间充足它会扩展原来的,否则就是复制新内存块.
//     char *new_ptr;
//     new_ptr = (char *)realloc(ptr, 30);
//     if (new_ptr == NULL) {
//         printf("Memory allocation failed\n");
//         return -1;
//     }
//
//     //只清空新分配的地方
//     memset(ptr+ BUFFER_SIZE, 0, NEW_BUFFER_SIZE-BUFFER_SIZE);
//
//     //赋值, 将指针挪到上一个内存结束的位置, 否则因为上一个内存的\0会导致赋值失败,  最后一个参数-1防止越界
//     strncpy(ptr + BUFFER_SIZE-1, "123456789a", NEW_BUFFER_SIZE-BUFFER_SIZE);
//     ptr[NEW_BUFFER_SIZE-1] = '\0';
//
//     printf("2222-%s\n", ptr);
//     printf("2222-%llu\n", strlen(ptr));
//
//     free(ptr);
//     free(new_ptr);
//
//     return 0;
// }
