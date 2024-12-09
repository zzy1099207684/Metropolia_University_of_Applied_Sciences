#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//
// Created by zhiyo on 2024/9/12.
// 还可以用isdigital去循环判断字符串, 如果出现不是数字的字符就false
//
// bool isNumber(char *str) {
//     setbuf(stdout, NULL);
//     int num = 0;
//     // fegets输入的字符串会在末尾自带换行符,所以可能要处理掉让他不换行,换行应该在其他地方处理
//     if(str[strlen(str) - 1] == '\n') {
//         str[strlen(str) - 1] = '\0';
//     }
//     //从str中解析出需要格式的内容,如果解析不出来就是上面变量定义的默认值
//     if (sscanf(str, "%d", &num) != 1) {
//         return false;
//     }
//
//     char str2[10];
//     // 数字转string, 第二个参数是定义缓冲区大小,安全
//     snprintf(str2, sizeof(str2), "%d", num);
//     // 检查长度是否一致,一致证明和开始输入时一样,否则不一样,证明掺了别的东西
//     if(strlen(str2) == strlen(str)) {
//         return true;
//     }else {
//         return false;
//     }
// }


// int main(void) {
//     int i  = isdigit('A');
//     printf("%d\n", i);
// }