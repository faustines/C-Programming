/*
 * reverse_int.c
 * Name / Student ID
 * Reads an int from stdin and reverses it
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char c;
    int digit_place = 1, result = 0, digits_read = 0;
    int first_character = 1;
    printf("Enter a number to reverse: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (first_character && c == '-') {
            /* negative sign on first character */
            digit_place *= -1;
        } else if(isdigit(c)) {
            /* read & process digit */
            digits_read++;
            result += digit_place * (c - '0');
            digit_place *= 10;
        } else {
            printf("Error: non-digit character entered\n");
            return EXIT_FAILURE;
        }
        first_character = 0;
    }
    if (digits_read == 0) {
        printf("Error: no digits have been read.\n");
        return EXIT_FAILURE;
    }
    printf("%d\n", result);
    return EXIT_SUCCESS;
}

