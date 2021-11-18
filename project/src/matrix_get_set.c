#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

int get_rows(const Matrix *matrix, size_t *rows) {
    if (matrix == NULL || rows == NULL) {
        return -1;
    }

    *rows = matrix->rows;
    return 0;
}

int get_cols(const Matrix *matrix, size_t *cols) {
    if (matrix == NULL || cols == NULL) {
        return -1;
    }

    *cols = matrix->cols;
    return 0;
}

int get_elem(const Matrix *matrix, size_t row, size_t col, double *val) {
    if (matrix == NULL) {
        return -1;
    }

    *val = matrix->arr[row][col];
    return 0;
}

int set_elem(Matrix *matrix, size_t row, size_t col, double val) {
    if (matrix == NULL) {
        return -1;
    }

    matrix->arr[row][col] = val;
    return 0;
}
