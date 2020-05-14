#include "binary_matrix.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Input:
 *      int num_rows, number of rows for new BinaryMatrix
 *      int num_cols, number of cols for new BinaryMatrix
 * Output:
 *      A BinaryMatrix* pointing to a newly allocated BinaryMatrix
 * Summary:
 *      Allocates a new BinaryMatrix with num_rows rows and
 *      num_cols cols and returns a pointer to it
 */
BinaryMatrix* ConstructBinaryMatrix(int num_rows, int num_cols) {
    BinaryMatrix* result;
    int row;
    if (num_rows <= 0 || num_cols <= 0) {
        printf("Error in CreateMatrix: number of rows and columns must be positive\n");
        exit(EXIT_FAILURE);
    }
    result = (BinaryMatrix*) malloc(sizeof(BinaryMatrix));
    if (result == (BinaryMatrix*) NULL) {
        return (BinaryMatrix*) NULL;
    }
    result->num_rows = num_rows;
    result->num_cols = num_cols;
    result->data = (int**) malloc(sizeof(int*) * num_rows);
    for (row = 0; row < num_rows; row++) {
        result->data[row] = (int*) calloc(num_cols, sizeof(int));
        if (result->data[row] == (int*) NULL) {
            result->num_rows = row;
            DeleteBinaryMatrix(result);
            return (BinaryMatrix*) NULL;
        }
    }
    return result;
}

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix to delete
 * Summary:
 *      De-allocates M, including data, row by row
 */
void DeleteBinaryMatrix(BinaryMatrix* M) {
    int row;
    for (row = 0; row < M->num_rows; row++) {
        free(M->data[row]);
    }
    free(M->data);
    free(M);
    return;
}

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix to update
 *      int row, an index for a row of *M
 *      int col, an index for a column of *M
 *      int element, a binary element for the BinaryMatrix
 * Summary:
 *      Updates the (row,col) entry of the BinaryMatrix pointed to
 *      by M with the entry element
 */
void UpdateEntry(BinaryMatrix* M, int row, int col, int content) {
    if (!IsMatrixIndex(M, row, col)) {
        printf("Error in UpdateEntry: index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    if (content != 0 && content != 1) {
        printf("Error in UpdateEntry: content must be 0 or 1\n");
        exit(EXIT_FAILURE);
    }
    M->data[row][col] = content;
    return;
}

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix
 *      int row, an index for a row of *M
 *      int col, an index for a column of *M
 * Summary:
 *      Checks if (row,col) is a valid index of the BinaryMatrix
 *      pointed to by M
 */
int IsMatrixIndex(BinaryMatrix* M, int row, int col) {
    int row_check, col_check;
    if (M == (BinaryMatrix*) NULL) {
        printf("IsMatrixIndex Error: NULL parameter passed\n");
        exit(EXIT_FAILURE);
    }
    row_check = 0 <= row && row < M->num_rows;
    col_check = 0 <= col && col < M->num_cols;
    return row_check && col_check;
}

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix to print
 * Summary:
 *      Prints entries of the BinaryMatrix pointed to by M
 *      as 1's and 0's without spaces between columns
 */
void PrintMatrix(BinaryMatrix* M) {
    int row, col;
    for (row = 0; row < M->num_rows; row++) {
        for (col = 0; col < M->num_cols; col++) {
            printf("%d", M->data[row][col]);
        }
        printf("\n");
    }
    return;
}
