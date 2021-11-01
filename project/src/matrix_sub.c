#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *sub(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols == 0 || l->rows == 0 ||
        r->cols == 0 || r->rows == 0) {
        return NULL;
    }
    Matrix *matrix_sub;
    matrix_sub = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_sub) {
        free(matrix_sub);
        return NULL;
    }
    size_t i, j;
    matrix_sub->rows = l->rows;
    matrix_sub->cols = l->cols;
    matrix_sub->arr = (double **)malloc(l->rows * sizeof(double *));
    if (!matrix_sub->arr) {
        free(matrix_sub);
        return NULL;
    }
    for (i = 0; i < l->rows; i++) {
        matrix_sub->arr[i] = (double *)malloc(l->cols * sizeof(double));
        if (!matrix_sub->arr[i]) {
            free(matrix_sub);
            return NULL;
        }
        for (j = 0; j < l->cols; j++) {
            matrix_sub->arr[i][j] = l->arr[i][j] - r->arr[i][j];
        }
    }
    return matrix_sub;
}
