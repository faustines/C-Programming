#include <stdlib.h>
#include <stdio.h>

char GetInput(void);
void SellUpgrade(int q_limit, int mbps, int mbps_increase, int price, int price_increase);
void PrintWelcomeStatement(void);
void PayBill();

int main() {
    int initial_option;
    char option;
    PrintWelcomeStatement();
    while (1) {
        while((option = getchar()) == '\n') {}
        switch (option) {
            case '1':
                SellUpgrade(2, 10, 1, 50, 1);
                break;
            case '2':
                SellUpgrade(5, 100, 10, 80, 20);
                break;
            case '3':
                SellUpgrade(5, 40, 5, 60, 10);
                break;
            case '4':
                PayBill();
                break;
            default:
                printf("Please enter a number between 1 and 4. ");
                break;
        }
    }
    return 0;
}

void PrintWelcomeStatement(void) {
    printf("Welcome to CableCom! Please make a choice from the ");
    printf("following options:\n");
    printf("1) Change your password\n");
    printf("2) Cancel your service\n");
    printf("3) Schedule a service call\n");
    printf("4) Pay your bill\n");
    return;
}

char GetInput(void) {
    char result;
    do {
        printf("Please enter your choice (y for yes, n for no, q for quit) ");
        while ((result = getchar()) == '\n') {}
    } while (result != 'y' && result != 'n' && result != 'q');
    return result;
}

void SellUpgrade(
    int q_limit,
    int mbps,
    int mbps_increase,
    int price,
    int price_increase) {
    int q = 0;
    while (1) {
        printf("You are eligible for a limited time offer. ");
        printf("You can get %d megabits per second for the low ",
               mbps);
        printf("promotional rate of $%d a month. Act now while ",
               price);
        printf("supplies last.\n");
        switch (GetInput()) {
            case 'y':
                printf("Great choice. Goodbye.\n");
                exit(1);
            case 'q':
                q = q + 1;
                if (q == q_limit) {
                    exit(0);
                }
            case 'n':
                mbps = mbps + mbps_increase;
                price = price + price_increase;
                break;
        }
    }
    return;
}

void PayBill(){
    printf("We already have your credit card information and ");
    printf("have charged you. Thanks for being a loyal customer!\n");
    exit(EXIT_SUCCESS);
}

