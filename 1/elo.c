#include <stdio.h>
#include <math.h>

int main() {
    int your_rating, opponent_rating;
    printf("Enter your rating: ");
    scanf("%d", &your_rating);
    printf("Enter your opponents rating: ");
    scanf("%d", &opponent_rating);
    float expected_score = 1 / (1 + pow(10, (float) (opponent_rating - your_rating) / 400));
    int new_rating = your_rating + floor(0.5 + 32*(1 - expected_score));
    printf("After beating your opponent, your new rating is %d\n", new_rating);
    return 0;
}
