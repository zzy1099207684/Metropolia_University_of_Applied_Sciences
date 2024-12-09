#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main() {
//     FILE *my_file;
//     /*
//     *   "r"：只读，不能写入。
//         "w"：写入，如果文件存在则清空文件，如果不存在则创建新文件。
//         "a"：追加，在文件末尾添加数据，如果文件不存在则创建新文件。
//
//         以下仨模式要写入时得先把文件指针rewind回头部,但胜在可读可写方便👇👇👇👇
//         "r+"：以读写方式打开文件。文件必须存在,写入前rewind会加在数据头部。
//         "w+"：以读写方式创建新文件或截断现有文件。
//         "a+"：以读写方式打开文件，在文件末尾追加数据或读取。
//      */
//     my_file = fopen("E:/program_files/notepad_files/temp.txt", "a+");
//     if(my_file == NULL) {
//         /* file was not opened */
//         printf("Error opening file\n");
//     }
//     else {
//         /* file was successfully opened */
//         printf("File opened successfully\n");
//
//         // // 重置文件指针到文件开始, 用a+ w+ r+ 必须要
//         rewind(my_file);
//
//
//         char str[100];
//         // 读取字符串直到遇到空格或换行符
//         int scanfReturn = fscanf(my_file, "%s", str);
//         printf("%s\n", str);
//         printf("scanfReturn: %d\n", scanfReturn);

// 从文件中读取整数
//    while (fscanf(file, "%d", &number) != EOF) {
//        printf("读取到的整数: %d\n", number);
//    }
// //
//         // 读取到下一个字符  这里返回int没错, 自己转char
//         char ch = getc(my_file);
//         printf("Next character: %c\n", ch);
//
//
//         // 读取整个文件流
//         char *str2 = NULL;
//         char *strArray[10]={NULL};
//         int i = 0;
//         while(!feof(my_file)) {
//             str2 = malloc(10 * sizeof(char));
//             if(fgets(str2, 100, my_file) != NULL) {
//                 strArray[i] = str2;
//             }
//             // 没有数据的数据块要释放
//             if (str2 != NULL && strArray[i] == NULL) {
//                 free(str2);
//             }
//             i++;
//         }
//
//         for (int i = 0; strArray[i] != NULL; ++i) {
//             printf("%s\n", strArray[i]);
//         }
//
//         // // 重置文件指针到文件开始
//          rewind(my_file);
//         // 写入字符
//         int putcReturn = putc('X', my_file);
//         putcReturn = putc('\n', my_file);
//         printf("putcReturn: %d\n", putcReturn);
//
//         // 写入字符串
//         int fprintfReturn = fprintf(my_file, "fprintf\n");
//         printf("fprintfReturn: %d\n", fprintfReturn);
//         int fputsReturn = fputs("fputsTest\n", my_file);
//         printf("fputsReturn: %d\n", fputsReturn);
//
//
//
//
//     }
//     //关闭文件流
//     fclose(my_file);
//     return 0;
// }

// int main() {
//     char str[100];
//     strcpy(str, "Hello World");
//
//     // for (int i = 0; i < strlen(str); ++i) {
//     //     str[i] = toupper(str[i]);
//     // }
//     toupper(str);
//     printf("%s\n", str);
//
//
// }