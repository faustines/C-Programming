#include <stdio.h>

int main() {
    float check;
    int tip;
    printf("Enter your check balance: "),
    scanf("%f", &check);
    printf("How much would you like to tip, as a percent? ");
    scanf("%d", &tip);
    printf("Your tip is $%.2f\n", check * (float) tip / 100);
    return 0;
}
