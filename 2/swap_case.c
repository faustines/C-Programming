#include <stdio.h>

int
main(void) {
    char letter;

    printf("Enter a letter: ");
    scanf("%c", &letter);
    if ('a' <= letter && letter <= 'z') {
        printf("%c\n", letter + 'A' - 'a');
    } else if ('A' <= letter && letter <= 'Z') {
        printf("%c\n", letter + 'a' - 'A');
    } else {
        printf("That's not a letter! Try again next time.\n");
    }

    return 0;
}
