#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int get_rows(const Matrix *matrix, size_t *rows) {
    *rows = matrix->rows;
    return 0;
}

int get_cols(const Matrix *matrix, size_t *cols) {
    *cols = matrix->cols;
    return 0;
}

int get_elem(const Matrix *matrix, size_t row, size_t col, double *val) {
    *val = matrix->arr[row][col];
    return 0;
}

int set_elem(Matrix *matrix, size_t row, size_t col, double val) {
    matrix->arr[row][col] = val;
    return 0;
}
