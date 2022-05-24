#include "matrix.h"

#include <math.h>

Matrix *adj(const Matrix *matrix) {
    if (matrix == NULL ||  matrix->arr == NULL) {
        return NULL;
    }
    if (matrix->rows < 1 || matrix->cols < 1 || matrix->rows != matrix->cols) {
        return NULL;
    }

    typedef double Matrix_adj;

    Matrix* matrix_transp = transp(matrix);
    if (matrix_transp == NULL) {
        return NULL;
    }

    Matrix* matrix_adj = create_matrix(matrix->rows, matrix->cols);
    if (matrix_adj == NULL) {
        free_matrix(matrix_transp);
        return NULL;
    }

    if (matrix->rows == 1 && matrix->cols == 1) {
        matrix_adj->arr[0][0] = matrix->arr[0][0];

        free(matrix_transp);
        return matrix_adj;
    }

    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            Matrix* matrix_tim = create_matrix(matrix->rows - 1, matrix->cols - 1);

            if (matrix_tim == NULL) {
                free_matrix(matrix_adj);
                free_matrix(matrix_transp);
                return NULL;
            }

            minor(matrix_transp, matrix_tim, j, i);
            Matrix_adj det_matrix_adj = 0;

            int det_matrix_tim = det(matrix_tim, &det_matrix_adj);
            if (det_matrix_tim != 0) {
                free_matrix(matrix_transp);
                free_matrix(matrix_adj);
                free_matrix(matrix_tim);
                return NULL;
            }

            matrix_adj->arr[i][j] = det_matrix_adj * pow(-1, i + j);
            free_matrix(matrix_tim);
        }
    }

    free_matrix(matrix_transp);

    return matrix_adj;
}
