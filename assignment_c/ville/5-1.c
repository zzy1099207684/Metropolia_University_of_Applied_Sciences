// #include <ctype.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <string.h>
// #define DATA_ARRAY 100
// #define READ_DATA_SIZE 256
//
// void delete_blank_5_1(char *str);
//
// void change_line_to_end_symbol_5_1(char *str);
//
// bool binary_reader(const unsigned int *value);
//
// static char *buffer;
//
// void read_line(char *read_data);
//
// void binary_change_to_unsigned_int(const char *binary_str, unsigned int **result);
//
// int digit_counter(unsigned int val);
//
//
// int main(int arcg, char **argv){
//     unsigned int number = 0;
//
//     while(binary_reader(&number)) {
//         printf("%11u: %08X, %d\n", number, number, digit_counter(number));
//     };
//
//     return 0;
//
// }
//
// // void delete_blank_5_1(char *str) {
// //     char *start = str;
// //     char *end;
// //     while (isspace(*start)) start++;
// //     if (*start == 0) {
// //         str[0] = '\0';
// //         return;
// //     }
// //     end = start + strlen(start) - 1;
// //     while (end > start && isspace(*end)) end--;
// //     *(end + 1) = '\0';
// //     memmove(str, start, end - start + 2);
// // }
//
// // void change_line_to_end_symbol_5_1(char *str) {
// //     int str_len = strlen(str);
// //     if (str_len > 0 && str[str_len - 1] == '\n') {
// //         str[str_len - 1] = '\0';
// //     }
// // }
//
// // void binary_change_to_unsigned_int(const char *binary_str, unsigned int **result) {
// //     *result = 0;
// //     //jump over 0b
// //     for (int i = 2; i < strlen(binary_str); i++) {
// //         **result += **result << 1 + (binary_str[i] - '0');
// //     }
// // }
//
// bool read_line(char *line, size_t size) {
//     return fgets(line, size, stdin) != NULL;
// }
//
// /* 解析二进制数字并返回 */
// bool binary_reader(unsigned int *pu) {
//     char line[100];
//     if (!read_line(line, sizeof(line))) {
//         return false;
//     }
//
//     char *p = line;
//     while (isspace(*p)) {
//         p++;
//     }
//
//     if (p[0] != '0' || p[1] != 'b') {
//         return false;
//     }
//     p += 2;
//
//     unsigned int value = 0;
//
//     while (*p == '0' || *p == '1') {
//         value = (value << 1) | (*p - '0');
//         p++;
//     }
//
//     *pu = value;
//     return true;
// }
//
// int digit_counter(unsigned int nr) {
//     if (nr == 0) {
//         return 1;
//     }
//
//     int hex_digits = 0;
//
//     while (nr > 0) {
//         hex_digits++;
//         nr >>= 4;
//     }
//
//     return hex_digits;
// }