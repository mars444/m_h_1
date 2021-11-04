#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(size_t rows, size_t cols) {
    if (cols == 0 || rows == 0) {
        return NULL;
    }

    size_t i, j;
    Matrix *matrix;

    matrix = (Matrix *)malloc(sizeof(Matrix));

    if (matrix == NULL) {
     free(matrix);
        return NULL;
    }

    matrix->cols = cols;
    matrix->rows = rows;

    matrix->arr = (double **)malloc(rows * sizeof(double *));

    if (matrix->arr == NULL) {
        free(matrix);
        return NULL;
    }

    for (i = 0; i < rows; i++) {
        matrix->arr[i] = (double *)malloc(cols * sizeof(double));
        if (matrix->arr[i] == NULL) {
            free(matrix);
            return NULL;
        }
        for (j = 0; j < cols; j++) {
            matrix->arr[i][j] = 0;
        }
    }
    return matrix;
}
