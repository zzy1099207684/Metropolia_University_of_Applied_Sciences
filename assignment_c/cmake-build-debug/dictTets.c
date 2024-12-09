//
// Created by zhiyo on 2024/9/10.
//

#include <stdio.h>

typedef struct dict {
    char *key;
    char *value;
} Dict;

// int main() {
//     setbuf(stdout, NULL);
//     Dict dictArray[100] = {};
//     Dict dict1 = {"key1","val1"};
//     Dict dict2 = {"key2","val2"};
//     Dict dict3 = {"key3","val3"};
//     Dict dict4 = {"key4","val4"};
//     Dict dictEnd = {"","0"};
//
//     dictArray[0] = dict1;
//     dictArray[1] = dict2;
//     dictArray[2] = dict3;
//     dictArray[3] = dict4;
//     dictArray[5] = dictEnd;
//
//     // 将数组最后一个设置为0, 用作循环终止的条件
//     for (int i = 0; (int)dictArray[i].value < 0; i++) {
//         printf("{%s : %s }\n", dictArray[i].key, dictArray[i].value);
//     }
// }