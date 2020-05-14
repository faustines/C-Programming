/*
 * is_palindrome.c
 * Name / Student ID
 * Reads a string until whitespace is found, then checks if it
 * is a palindrome. "Palindrome" here is stricter than the usual
 * definition: abba is a palindroma, but Abba is not.
 */
#include <stdio.h>

int main() {
    char string_to_check[31];
    int i, length;

    /* Read null-terminated string from scanf */
    printf("Enter a string to test: ");
    scanf("%s", &string_to_check);
    length = 0;
    /* Calculate length of string */
    while (string_to_check[length++] != '\0') {}
    --length;
    /* scan from both ends towards the middle, checking equality as we go */
    /* Note: for(i = 0; i < length; i++) works too, */
    for (i = 0; i < length - 1 - i; i++) {
        if (string_to_check[i] != string_to_check[length - 1 - i]) {
            printf("%s is not a palindrome\n", string_to_check);
            return 0;
        }
    }
    printf("%s is a palindrome\n", string_to_check);
    return 0;
}
