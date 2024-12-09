// //
// // Created by zhiyo on 2024/10/13.
// //
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <stdbool.h>
// #define MY_STR_SIZE 100
//
//
// char my_getchar(void);
//
// static const char *test_input =
//         "Endymion\n"
//         "Book IV\n"
//         "MUSE of my native land! loftiest Muse!\n"
//         "O first-born on the mountains! by the hues\n"
//         "Of heaven on the spiritual air begot:\n"
//         "Long didst thou sit alone in northern grot,\n"
//         "While yet our England was a wolfish den;\n"
//         "Before our forests heard the talk of men;\n"
//         "Before the first of Druids was a child;—\n"
//         "Long didst thou sit amid our regions wild\n"
//         "Rapt in a deep prophetic solitude.\n"
//         "There came an eastern voice of solemn mood:—\n"
//         "Yet wast thou patient. Then sang forth the Nine,\n"
//         "Apollo’s garland:—yet didst thou divine\n"
//         "Such home-bred glory, that they cry’d in vain,\n"
//         "\"Come hither, Sister of the Island!\" Plain\n"
//         "Spake fair Ausonia; and once more she spake\n"
//         "A higher summons:—still didst thou betake\n"
//         "Thee to thy native hopes. O thou hast won\n"
//         "A full accomplishment! The thing is done,\n"
//         "Which undone, these our latter days had risen\n"
//         "On barren souls. Great Muse, thou know’st what prison\n"
//         "Of flesh and bone, curbs, and confines, and frets\n"
//         "Our spirit’s wings: despondency besets\n"
//         "Our pillows; and the fresh to-morrow morn\n"
//         "Seems to give forth its light in very scorn\n"
//         "Of our dull, uninspired, snail-paced lives.\n";
//
// static int input_index = 0;
//
// char my_getchar(void) {
//     if (test_input[input_index] != '\0') {
//         return test_input[input_index++];
//     } else {
//         return '\0'; // 模拟输入结束
//     }
// }
//
// //
// int filter_alpha(char *str, int max_size, char (*function_pointer)(void)) {
//     int str_index = 0;
//     int count = 0;
//     char c;
//
//     for (int i = 0; (c=function_pointer()) != 0 && str_index < max_size-1; i++) {
//         if (isalpha(c)) {
//             str[str_index++] = c;
//         }
//         count++;
//         if(c == '\n'){
//             break;
//         }
//     }
//     str[str_index] = '\0';
//     return count;
// }
//
// int main(int arcg, char **argv) {
//     char str[MY_STR_SIZE] = {0};
//     int count = 0;
//
//     do {
//         count = filter_alpha(str, MY_STR_SIZE, my_getchar);
//         printf("%d:%d:%s\n", count, strlen(str), str);
//     } while (count > 0);
//
//     return 0;
// }
