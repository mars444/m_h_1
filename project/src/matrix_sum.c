#include "matrix.h"

Matrix *sum(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols < 1 || l->rows < 1 ||
        r->cols < 1 || r->rows < 1) {
        return NULL;
    }

    if (l->cols != r->cols || l->rows != r->rows) {
        return NULL;
    }

    Matrix *matrix_sum;

    matrix_sum = (Matrix *)malloc(sizeof(Matrix));

    if (!matrix_sum) {
        free(matrix_sum);
        return NULL;
    }

    matrix_sum->rows = l->rows;
    matrix_sum->cols = l->cols;

    matrix_sum->arr = (double **)malloc(l->rows * sizeof(double *));

    if (!matrix_sum->arr) {
        free(matrix_sum);
        return NULL;
    }

    for (size_t i = 0; i < l->rows; i++) {
        matrix_sum->arr[i] = (double *)malloc(l->cols * sizeof(double));

        if (!matrix_sum->arr[i]) {
            free(matrix_sum);
            return NULL;
        }

        for (size_t j = 0; j < l->cols; j++) {
            matrix_sum->arr[i][j] = l->arr[i][j] + r->arr[i][j];
        }
    }
    return matrix_sum;
}
