/*
 * binary_matrix.h
 * Name / StudentID
 * An implementation of a Binary Matrix
 */

#ifndef _BINARY_MATRIX_H_
#define _BINARY_MATRIX_H_

typedef struct {
    int** data;         /* The matrix */
    int num_rows;       /* number of rows in the matrix */
    int num_cols;       /* number of columns in the matrix */
} BinaryMatrix;

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
BinaryMatrix* ConstructBinaryMatrix(int num_rows, int num_cols);

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix to delete
 * Summary:
 *      De-allocates M, including data, row by row
 */
void DeleteBinaryMatrix(BinaryMatrix* M);

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
void UpdateEntry(BinaryMatrix* M, int row, int col, int element);

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix
 *      int row, an index for a row of *M
 *      int col, an index for a column of *M
 * Summary:
 *      Checks if (row,col) is a valid index of the BinaryMatrix
 *      pointed to by M
 */
int IsMatrixIndex(BinaryMatrix* M, int row, int col);

/*
 * Input:
 *      BinaryMatrix* M, a pointer to a BinaryMatrix to print
 * Summary:
 *      Prints entries of the BinaryMatrix pointed to by M
 *      as 1's and 0's without spaces between columns
 */
void PrintMatrix(BinaryMatrix* M);

#endif /* _BINARY_MATRIX_H_ */
