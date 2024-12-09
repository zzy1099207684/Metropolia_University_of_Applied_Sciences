//
// Created by zhiyo on 2024/10/3.
//

#include <stdio.h>
#include <stdlib.h>

void a(char *ptr) {
    printf("aaaa- %s\n", ptr);
}

void b(char *ptr) {
    printf("bbbb- %s\n", ptr);
}

void c(char *ptr) {
    printf("cccc- %s\n", ptr);
}
int d(char *ptr) {
    return atoi(ptr);
}

//创建一个和目标函数们一样类型的指针函数,然后等于它们以区分.
void (*point_function)(char *ptr);

// 把函数当参数了
int point_function2( int (*func_name_self_define)(char *ptr) ){
    return func_name_self_define("12");
}


// int main() {
//
//     point_function = a;
//     point_function("qqqq");
//     point_function = b;
//     point_function("qqqq");
//     point_function = c;
//     point_function("qqqq");
//
//     int ddd = point_function2(d);
//     printf("dddddddddd----%d",ddd);
// }