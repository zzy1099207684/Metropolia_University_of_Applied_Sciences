//
// Created by zhiyo on 2024/10/3.
//
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // 包含 strtol 函数


bool check_range(char *num) {
    long int n = strtol(num, NULL, 10);  //third param is decimal 10
    if (n > INT_MIN && n < INT_MAX) {
        return true;
    }
    return false;
}



// int main() {
//     char str[] = "555555555555";
//     long int num;
//
//     // 使用 strtol 将字符串转换为长整型
//     bool res = check_range(str);
//     if(res) {
//         printf("true\n");
//     }else {
//         printf("false\n");
//     }
//
//
//
//     return 0;
// }

