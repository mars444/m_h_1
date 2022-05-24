#include "matrix.h"

Matrix *transp(const Matrix *matrix) {   //  транспонирование матрицы
    if (matrix == NULL || matrix->cols < 1 || matrix->rows < 1) {
        return NULL;
    }

    size_t rows = matrix->rows, cols = matrix->cols;
    Matrix *matrix_t;

    matrix_t = (Matrix *)malloc(sizeof(Matrix));

    if (!matrix_t) {
        free(matrix_t);
        return NULL;
    }

    matrix_t->rows = matrix->cols;
    matrix_t->cols = matrix->rows;

    matrix_t->arr = (double **)malloc(cols * sizeof(double *));

    if (!matrix_t->arr) {
        free(matrix_t);
        return NULL;
    }

    for (size_t i = 0; i < cols; i++) {
        matrix_t->arr[i] = (double *)malloc(rows * sizeof(double));

        if (!matrix_t->arr[i]) {
            free(matrix_t);
            return NULL;
        }

        for (size_t j = 0; j < rows; j++) {
            matrix_t->arr[i][j] = matrix->arr[j][i];
        }
    }
    return matrix_t;
}
