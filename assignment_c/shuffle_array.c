#include <stdlib.h>
#include <string.h>
#include <time.h>
//
// Created by zhiyo on 2024/10/3.
//
//打乱数组
// void fisher_yates(char *arr) {
//     srand(time(NULL));
//     int arr_len = strlen(arr);
//
//     for (int i = arr_len - 1; i > 0; i--) {
//         // random choose a num from 0 to i
//         int j = rand() % (i + 1);
//         // change
//         char temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
// }