#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix *mul(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols < 1 || l->rows < 1 ||
        r->cols < 1 || r->rows < 1) {
        return NULL;
    }

    Matrix *matrix_mul;

    matrix_mul = (Matrix *)malloc(sizeof(Matrix));

    if (!matrix_mul) {
        free(matrix_mul);
        return NULL;
    }
    matrix_mul->rows = l->rows;
    matrix_mul->cols = r->cols;

    matrix_mul->arr = (double **)malloc(matrix_mul->rows * sizeof(double *));

    if (!matrix_mul->arr) {
        free(matrix_mul);
        return NULL;
    }

    for (size_t i = 0; i < matrix_mul->rows; i++) {
        matrix_mul->arr[i] = (double *)malloc(matrix_mul->cols * sizeof(double));

        if (!matrix_mul->arr[i]) {
            free(matrix_mul);
            return NULL;
        }

        for (size_t j = 0; j < matrix_mul->cols; j++) {
            matrix_mul->arr[i][j] = 0;

            for (size_t k = 0; k < r->rows; k++) {
                matrix_mul->arr[i][j] = matrix_mul->arr[i][j] + (r->arr[k][j] * l->arr[i][k]);
            }
        }
    }

    return matrix_mul;
}
