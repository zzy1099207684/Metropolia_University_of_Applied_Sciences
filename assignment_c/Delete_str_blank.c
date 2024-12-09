#include <ctype.h>
#include <string.h>
//
// Created by zhiyo on 2024/10/10.
//
void trim_whitespace(char *str) {
    char *start = str;  // 指向字符串的开始
    char *end;

    // 移动start指针，跳过前面的空格
    while (isspace((unsigned char)*start)) start++;

    // 如果字符串全是空格，直接返回空字符串
    if (*start == 0) {
        str[0] = '\0';
        return;
    }

    // 找到字符串的末尾
    end = start + strlen(start) - 1;

    // 移动end指针，去掉末尾的空格
    while (end > start && isspace((unsigned char)*end)) end--;

    // 重新设置字符串结束符
    *(end + 1) = '\0';

    // 将去掉空格后的字符串复制回原来的字符串
    memmove(str, start, end - start + 2);  // +2是为了包括最后的'\0'
}