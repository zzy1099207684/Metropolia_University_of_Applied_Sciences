//
// Created by zhiyo on 2024/9/30.
//

#include <stdio.h>

typedef struct test {
    int a:3; // a只支持3位的int类型的数字
} Test;

// int main() {
//     Test ts;
//     ts.a = 20; //20的二进制超3位了,是错的这里
//     printf("%d\n", ts.a);
//
// }