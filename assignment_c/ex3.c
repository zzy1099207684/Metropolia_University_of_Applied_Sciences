#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void ex3(void);

// int main(void) {
//     ex3();
//     return 0;
// }

//ex3
/*
That asks number of students and creates an array of that many integers.
Program then initializes the array elements to -1.
Then the program asks user to enter student number in range 1 – nr of students or zero to stop. If
valid non zero number is given the program asks user to enter grade in the range 0-5 or -1 to not
enter a grade for the student.
When user stops by entering 0 then program prints student numbers followed by grade or N/A if
grade is -1.
*/
void ex3(void) {
    setbuf(stdout, NULL);
    int total_student_number;
    int select_student_number;
    int grade;
    const int stop = 0;
    const int cancel = -1;
    const char na[] = "N/A";
    char *na_pointer = na;
    int index;


    printf("How many students:");
    scanf("%d", &total_student_number);

    int student_number[total_student_number];
    int student_grades[total_student_number];

    // init
    for (index = 0; index < total_student_number; index++) {
        student_number[index] = index + 1;
        student_grades[index] = cancel;
    }

    while (true) {
        printf("\nEnter student number (1 - %d) or 0 to stop:", total_student_number);
        scanf("%d", &select_student_number);

        if (select_student_number == stop) {
            //show_table();
            printf("%8s\t  %8s\n", "Student", "Grade");
            for (int i = 0; i < total_student_number; i++) {
                if (student_grades[i] == -1) {
                    printf("%8d\t%8s\n", student_number[i], na_pointer);
                    continue;
                }
                printf("%8d\t%8d\n", student_number[i], student_grades[i]);
            }
            break;
        }

        if (select_student_number < 1 || select_student_number > total_student_number) {
            printf("Invalid student number!\n\n");
            continue;
        }
        index = select_student_number - 1;

        while (true) {
            printf("Enter grade (0 - 5) for student %d or -1 to cancel:", select_student_number);
            scanf("%d", &grade);

            if (grade == cancel) {
                break;
            }

            if (grade < 0 || grade > 5) {
                printf("Invalid grade!\n");
                continue;
            }

            student_grades[index] = grade;
            break;
        }
    }
}
