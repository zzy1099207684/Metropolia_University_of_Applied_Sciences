#include <stdio.h>
#define INCOME 12
#define TAX 12

void ex2(void);

// int main(void) {
//     ex2();
//     return 0;
// }

//ex2
/*
Write a program that defines two floating-point arrays of 12 elements each. The program then asks
user to enter tax percentage and yearly income limit up to which the percentage applies to and the
(greater) tax percentage that will be applied to income that is over the limit. Then program asks user
to enter salary of each month and stores the values in the array. After user has entered all monthly
salaries, the program calculates tax for each month.
The program prints all salaries with two decimal precision and the amount of tax for each month.
*/
void ex2(void) {

    float income[INCOME];
    float tax[TAX];
    float tax_rate;
    float income_limit;
    float income_over_limit_tax_rate;
    float total_income = 0;

    printf("Enter tax rate:");
    scanf("%f", &tax_rate);
    printf("Enter income limit:");
    scanf("%f", &income_limit);
    printf("Enter tax rate for income over the limit:");
    scanf("%f", &income_over_limit_tax_rate);

    // input income
    for (int i = 0; i < 12; i++) {
        printf("Enter income for month %d:", i+1);
        scanf("%f", &income[i]);
        printf("\n");

        total_income += income[i];

        if (total_income < income_limit) {
            tax[i] = income[i] * (tax_rate/100);
        } else {
            tax[i] = income[i] * (income_over_limit_tax_rate/100);
        }
    }

    printf("%4s\t%8s\t%8s\n","month","income","tax");
    for (int i = 0; i < 12; i++) {
        printf("%4d\t%8.2f\t%8.2f\n", i+1, income[i], tax[i]);
    }
}


