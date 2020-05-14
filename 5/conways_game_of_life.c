#include "conways_game_of_life.h"

#include <stdio.h>
#include <stdlib.h>

#include "binary_matrix.h"
#include "coordinate.h"

/*
 * Input:
 *      int num_rows, the number of rows in the game
 *      int num_cols, the number of cols in the game
 * Output:
 *      Returns a BinaryMatrix* that corresponds to the
 *      first generation game state
 * Summary:
 *      Returns the game state of the first generation
 */
BinaryMatrix* FirstGeneration(int num_rows, int num_cols, List* seed_cells) {
    BinaryMatrix* result = ConstructBinaryMatrix(num_rows, num_cols);
    ListNode* current_node;
    for (current_node = seed_cells->head; current_node != (ListNode*) NULL; current_node = current_node->next) {
        UpdateEntry(result, current_node->data.x, current_node->data.y, LIVE_CELL);
    }
    return result;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 * Output:
 *      Returns a BinaryMatrix*, a pointer to a game state
 * Summary:
 *      Calculates the game state of the generation directly
 *      after *generation and returns it
 */

BinaryMatrix* NextGeneration(BinaryMatrix* generation) {
    BinaryMatrix* result = ConstructBinaryMatrix(generation->num_rows, generation->num_cols);
    int i, j, live_neighbors;
    Coordinate cell;
    List* neighbors;
    for (i = 0; i < result->num_rows; i++) {
        for (j = 0; j < result->num_cols; j++) {
            cell = ConstructCoordinate(i, j);
            neighbors = NeighboringCells(cell, generation);
            live_neighbors = LivingNeighbors(generation, neighbors);
            if (Live(generation, cell) && (2 <= live_neighbors && live_neighbors <= 3)) {
                UpdateEntry(result, i, j, LIVE_CELL);
            } else if (live_neighbors == 3) {
                UpdateEntry(result, i, j, LIVE_CELL);
            } else {
                UpdateEntry(result, i, j, DEAD_CELL);
            }
            DeleteList(neighbors);
        }
    }
    return result;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      Coordinate coord, a cell of the game state
 * Output:
 *      Returns true if the cell is Live
 * Summary:
 *      Checks if coord is a valid index of *generation and
 *      its corresponding cell is Live
 */
int Live(BinaryMatrix* generation, Coordinate coord) {
    if (!IsMatrixIndex(generation, coord.x, coord.y)) {
        printf("Live Error: invalid coordinate\n");
        exit(EXIT_FAILURE);
    }
    return generation->data[coord.x][coord.y] == LIVE_CELL;
}

/*
 * Input:
 *      Coordinate coord, a cell of the game state
 *      BinaryMatrix* generation, a pointer to a game state
 * Output:
 *      Returns a List* to a List of neighboring cells
 * Summary:
 *      Calculates neighboring cells of *generation at coord and
 *      returns them as a List
 */
List* NeighboringCells(Coordinate coord, BinaryMatrix* generation) {
    List* result = ConstructList();
    int i, j;
    if (result == (List*) NULL) {
        printf("Error in NeighboringCells: List construction failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            Coordinate coord_neighbor = ConstructCoordinate(coord.x + i, coord.y + j);
            if (IsNeighbor(coord, coord_neighbor) && IsMatrixIndex(generation, coord.x + i, coord.y + j)) {
                PushFrontList(result, coord_neighbor);
            }
        }
    }
    return result;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      List* neighbors, a List of neighbors of a coordinate
 * Output:
 *      Returns the number of neighboring cells that are Live
 * Summary:
 *      Counts the number of Coordinates in *neighbors that
 *      correspond to live cells in *generation
 */
int LivingNeighbors(BinaryMatrix* generation, List* neighbors) {
    ListNode* ptr;
    int result = 0;
    if (generation == (BinaryMatrix*) NULL || neighbors == (List*) NULL) {
        printf("Error in LivingNeighbors: NULL parameter passed\n");
        exit(EXIT_FAILURE);
    }
    for (ptr = neighbors->head; ptr != (ListNode*) NULL; ptr = ptr->next) {
        result += generation->data[ptr->data.x][ptr->data.y];
    }
    return result;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      FILE* fp, a file opened for writing
 * Summary:
 *      Prints the game state of *generation to *fp
 */
void PrintGeneration(BinaryMatrix* generation, FILE* fp) {
    int i, j;
    for (i = 0; i < generation->num_rows; i++) {
        for (j = 0; j < generation->num_cols; j++) {
            if (Live(generation, ConstructCoordinate(i, j))) {
                fprintf(fp, "#");
            } else {
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }
    return;
}
