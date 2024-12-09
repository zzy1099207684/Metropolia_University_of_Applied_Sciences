#include <stdio.h>

void ex1(void);

// int main(void) {
//     ex1();
//     return 0;
// }


//ex1
/*
1. Asks user to enter the price of a bus ticket
2. Asks user to enter the price of a taxi trip
3. Asks user to enter how much money he/she has
4. If user has not enough money for either type tells user to walk and then the program stops
5. Asks user to choose taxi or bus (use numbers for selection)
6. Checks if user has enough money for the selected trip type
    o If User has enough money reduce the money by the selected trip’s price and print
    how much money is left, and go back to step 4
    o If user has not enough money for the selected trip type then tell that to user and go
    back to step 4
*/
void ex1(void) {
    float bus_ticket;
    float taxi_trip_price;
    float self_money;
    int select;

    printf("Enter price of bus ticket:");
    scanf("%f", &bus_ticket);

    printf("Enter price of taxi:");
    scanf("%f", &taxi_trip_price);

    printf("How much money you have:");
    scanf("%f", &self_money);

    printf("You have %.2f euros left\n", self_money);

    while (self_money > bus_ticket || self_money > taxi_trip_price) {
        printf("Do you want to take\n1) bus (%.2f euros) \n2) taxi (%.2f euros)\n", bus_ticket, taxi_trip_price);
        printf("Enter your selection:");
        scanf("%d", &select);

        if (select == 1) {
            printf("You chose bus.\n");
            if (bus_ticket < self_money) {
                self_money = self_money - bus_ticket;
            } else {
                printf("You don't have enough money for bus.\n");
            }
        } else if (select == 2) {
            printf("You chose taxi.\n");
            if (taxi_trip_price < self_money) {
                self_money = self_money - taxi_trip_price;
            } else {
                printf("You don't have enough money for taxi.\n");
            }
        }
        printf("You have %.2f euros left.\n", self_money);
    }
    printf("You need to walk. Bye");
}
