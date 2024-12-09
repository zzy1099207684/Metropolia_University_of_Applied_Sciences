//
// Created by zhiyo on 2024/9/24.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            count++;
        }
    }


    return count;
}



#include <stdio.h>
#include <string.h>


void replace(char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 't') {
            str[i] = '*';
        }
    }
}


void input_array(int matrix[5][3]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i+j*5+1;
        }
    }
}

#include <stdio.h>
#include <string.h>
#include <math.h>


struct point
{
    int x;
    int y;
};


double distance(struct point a, struct point b) {
    int x = a.x - b.x;
    int y = a.y - b.y;
    return sqrt((x*x)+(y*y));

}

//
// int main(void)
// {
//     struct point p1 = { 5, 8 };
//     struct point p2 = { -3, 3 };
//     struct point p3 = { 0, 4 };
//     struct point p4 = { 3, 0 };
//
//     printf("%.3f\n", distance(p1, p2));
//     printf("%.3f\n", distance(p3, p4));
//
//     return 0;
// }


