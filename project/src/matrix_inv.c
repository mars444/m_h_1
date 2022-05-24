#include "matrix.h"

Matrix *inv(const Matrix *matrix) {
  if (matrix == NULL || matrix->cols != matrix->rows || matrix->rows < 1 || matrix->cols < 1) {
        return NULL;
    }

    if (matrix->rows == 1) {
        Matrix* matrix_inv = create_matrix(1, 1);
        matrix_inv->arr[0][0] = 1 / matrix->arr[0][0];

        return matrix_inv;
    }

    Matrix* matrix_adj = adj(matrix);
    if (matrix_adj == NULL) {
        return NULL;
    }

    double det_matrix = 0;

    int det_acc = det(matrix, &det_matrix);

    if (det_acc != 0) {
        free_matrix(matrix_adj);
        return NULL;
    }

    det_matrix = (1 / det_matrix);

    Matrix* matrix_inv = mul_scalar(matrix_adj, det_matrix);
    if (matrix_inv == NULL) {
        free_matrix(matrix_adj);
        return NULL;
    }

    free_matrix(matrix_adj);

    return matrix_inv;
}
