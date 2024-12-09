//
// Created by zhiyo on 2024/9/10.
//
/*
*   “rb”：只读模式，用来读取二进制文件。
    “wb”：只写模式，用来创建或覆盖二进制文件。
    “ab”：追加模式，往二进制文件末尾加内容，文件不存在则新建。
    “rb+”：读写模式，可读可写二进制文件。
    “wb+”：读写模式，先清空文件再读写，文件不存在则新建。
    “ab+”：读写追加模式，可读可往二进制文件末尾追加内容，文件不存在则新建。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// int main() {
//     setbuf(stdout, NULL);
//     char str[100] = {};
//     FILE *fp;
//     size_t readNum;
//     size_t writeNum;
//     char writeStr[20] = "\nfwrite测试666";
//
//     fp = fopen("E:/program_files/notepad_files/temp.txt", "rb+");
//     if (fp == NULL || ferror(my_file)) {
//         perror("Error opening file\n");
//     }
//     fp->_bufsiz;
//     // 读取
//     //fread 就是以二进制读取文件数据, 读取的数据不会有任何变化, 这个挺好的
//     readNum = fread(str, sizeof(char), 100, fp);
//
//     if (readNum == 0) {
//         perror("Error reading file\n");
//     }
//     printf("%s", str);
//     printf("\n");
//
//     // 二进制写入
//     // fwrite
//     writeNum = fwrite(writeStr, sizeof(char), strlen(writeStr), fp);
//
//     if (writeNum == 0) {
//         perror("Error writing file\n");
//     }
//
//     fclose(fp);
//
// }