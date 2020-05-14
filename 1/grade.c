#include <stdio.h>

int main() {
    float desired_average, current_average;
    int final_percentage;
    printf("Enter desired average: ");
    scanf("%f", &desired_average);
    printf("What is your current average? ");
    scanf("%f", &current_average);
    printf("How much is your final worth, as a percent? ");
    scanf("%d", &final_percentage);
    float p = (float) final_percentage / 100;
    float required_score = (desired_average - current_average*(1 - p)) / p;
    printf("You need %.0f percent on your final to get your desired average.\n", required_score);
    return 0;
}
