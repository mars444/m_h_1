#include "matrix.h"

Matrix *mul_scalar(const Matrix *matrix, double val) {   //  умножение матрицы на число
    if (matrix == NULL || matrix->cols < 1 || matrix->rows < 1) {
        return NULL;
    }

    size_t rows = matrix->rows, cols = matrix->cols;
    Matrix *matrix_num;

    matrix_num = (Matrix *)malloc(sizeof(Matrix));

    if (!matrix_num) {
        free(matrix_num);
        return NULL;
    }
    matrix_num->rows = matrix->rows;
    matrix_num->cols = matrix->cols;

    matrix_num->arr = (double **)malloc(rows * sizeof(double *));
    if (!matrix_num->arr) {
        free(matrix_num);
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        matrix_num->arr[i] = (double *)malloc(cols * sizeof(double));

        if (!matrix_num->arr[i]) {
            free(matrix_num);
            return NULL;
        }

        for (size_t j = 0; j < cols; j++) {
            matrix_num->arr[i][j] = matrix->arr[i][j] * val;
        }
    }
    return matrix_num;
}
