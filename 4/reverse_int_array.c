/*
 * reverse_int.c
 * Name / Student ID
 * Reads an int from stdin and reverses it
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char c, number[1000];
    int leading_zeros = 1, negative = 0, digits_read = 0;
    int first_character = 1;
    printf("Enter a number to reverse: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (first_character && c == '-') {
            /* negative sign on first character */
            negative = 1;
        } else if(isdigit(c)) {
            /* read & process digit */
            number[digits_read++] = c;
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
    /* Print number */
    if (negative) {
        printf("-");
    }
    while (digits_read > 0) {
        if (number[--digits_read] != '0') {
            leading_zeros = 0;
        }
        if (!leading_zeros) {
            printf("%c", number[digits_read]);
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}

