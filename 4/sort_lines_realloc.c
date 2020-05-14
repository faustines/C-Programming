/*
 * sort_lines.c
 * Name / Student ID
 * Reads an array of lines and sorts them.
 * The maximum line size is 100.
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 16
#define MAX_LINE_SIZE 100

char** IncreaseBuffer(char** buffer, int* buffer_size);
void PrintLines(char** lines, int line_count);
int MinLineIndex(char** buffer, int i, int j);
void SwapLines(char** lines, int i, int j);

int main() {
    /* Declare and initialize variables */
    char** line_buffer = malloc(sizeof(char*) * INITIAL_BUFFER_SIZE);
    int lines = 0, line_buffer_size = INITIAL_BUFFER_SIZE;
    int i = 0, min_index;
    for (i = 0; i < line_buffer_size; i++) {
        line_buffer[i] = malloc(sizeof(char) * MAX_LINE_SIZE);
    }
    /* Read lines */
    while(gets(line_buffer[lines++])) {
        if (lines == line_buffer_size) {
            line_buffer = IncreaseBuffer(line_buffer, &line_buffer_size);
        }
    }
    lines--;
    /* Sort lines and print */
    for (i = 0; i < lines; i++) {
        min_index = MinLineIndex(line_buffer, i, lines - 1);
        SwapLines(line_buffer, i, min_index);
    }
    PrintLines(line_buffer, lines);
    /* Clean up memory */
    for (i = 0; i < line_buffer_size; i++) {
        free(line_buffer[i]);
    }
    free(line_buffer);
    return 0;
}

/*
 * Input: 
 *      char** buffer, an array of C-style strings
 *      int* buffer_size, the max size of buffer
 * Output:
 *      A char** to the increased buffer
 * Summary:
 *      Doubles the size of buffer
 */
char** IncreaseBuffer(char** buffer, int* buffer_size) {
    int i;
    char** result = realloc(buffer, sizeof(char**) * 2 * *buffer_size);
    *buffer_size *= 2;
    for (i = *buffer_size / 2; i < *buffer_size; i++) {
        result[i] = malloc(sizeof(char) * MAX_LINE_SIZE);
    }
    return result;
}

/*
 * Input:
 *      char** lines, C-stye strings to print
 *      int line_count, number of lines to print
 * Summary:
 *      Prints line_count strings from lines
 */
void PrintLines(char** lines, int line_count) {
    int i;
    for (i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
    }
}

/*
 * Input:
 *      char** lines, C-style strings to search over
 * Output:
 *      an int index to the minimum element of lines
 * Summary:
 *      Searches over an array of C-style strings
 *      and returns the index of its minimal
 *      element, ordered by strcmp (alphabetically)
 */
int MinLineIndex(char** lines, int i, int j) {
    int min_index = i;
    for (i++; i <= j; i++) {
        if (strcmp(lines[i], lines[min_index]) < 0) {
            min_index = i;
        }
    }
    return min_index;
}

/*
 * Input:
 *      char** lines, array of C-style strings
 *      int i, index of first string to swap
 *      int j, index of second string to swap
 * Summary:
 *      Swaps the ith and jth strings of lines
 */
void SwapLines(char** lines, int i, int j) {
    char* temp = lines[j];
    lines[j] = lines[i];
    lines[i] = temp;
    return;
}
