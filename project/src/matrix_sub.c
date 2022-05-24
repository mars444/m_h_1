#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix *sub(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols < 1 || l->rows < 1 ||
        r->cols < 1 || r->rows < 1) {
        return NULL;
    }

    if (l->cols != r->cols || l->rows != r->rows) {
        return NULL;
    }

    Matrix *matrix_sub;

    matrix_sub = (Matrix *)malloc(sizeof(Matrix));

    if (!matrix_sub) {
        free(matrix_sub);
        return NULL;
    }

    matrix_sub->rows = l->rows;
    matrix_sub->cols = l->cols;
    matrix_sub->arr = (double **)malloc(l->rows * sizeof(double *));

    if (!matrix_sub->arr) {
        free(matrix_sub);
        return NULL;
    }

    for (size_t i = 0; i < l->rows; i++) {
        matrix_sub->arr[i] = (double *)malloc(l->cols * sizeof(double));

        if (!matrix_sub->arr[i]) {
            free(matrix_sub);
            return NULL;
        }

        for (size_t j = 0; j < l->cols; j++) {
            matrix_sub->arr[i][j] = l->arr[i][j] - r->arr[i][j];
        }
    }
    return matrix_sub;
}
