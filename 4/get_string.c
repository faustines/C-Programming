/*
 * get_string.c
 * Name / Student ID
 * Reads a string from stdin, stores it in an array, and prints it back
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_BUFFER_SIZE 16

char* IncreaseBuffer(char* buffer, int* buffer_size);

int main() {
    char c;
    int buffer_size = INITIAL_BUFFER_SIZE, string_size = 0, buffer_increases = 0;
    char* buffer = malloc(sizeof(char) * buffer_size);

    printf("Enter a string: ");
    /* Read string one character at a time */
    c = getchar();
    while(c != '\n' && c != EOF) {
        /* Resize buffer as needed */
        if (string_size == buffer_size) {
            buffer = IncreaseBuffer(buffer, &buffer_size);
            buffer_increases++;
        }
        buffer[string_size++] = c;
        c = getchar();
    }
    /* Resize buffer as needed and add null terminator */
    if (string_size == buffer_size) {
        buffer = IncreaseBuffer(buffer, &buffer_size);
        buffer_increases++;
    }
    buffer[string_size] = '\0'; 
    printf("String size: %d\n", string_size);
    printf("Buffer increases: %d\n", buffer_increases);
    printf("You entered: %s\n", buffer);
    free(buffer);
    return EXIT_SUCCESS;
}


/*
 * Input:
 *      char* buffer, an array of strings
 *      int* buffer_size, the current max size of buffer
 * Output:
 *      A char* to the buffer of increased size
 * Summary:
 *      Doubles the size of buffer, copying characters.
 */
char* IncreaseBuffer(char* buffer, int* buffer_size) {
    int i;
    char* result;
    result = malloc(sizeof(char) * 2 * *buffer_size);
    /* copy contents from buffer to result */ 
    for (i = 0; i < *buffer_size; ++i) {
        result[i] = buffer[i];
    }
    *buffer_size *= 2;
    free(buffer);
    return result;
}
