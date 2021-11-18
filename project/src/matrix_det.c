#include "matrix.h"

#include <math.h>

int det(const Matrix *matrix, double *val) {
    if (matrix == NULL || val == NULL) {
        return -1;
    }

    if (!matrix->arr || matrix->cols < 1 || matrix->rows < 1 || matrix->rows != matrix->cols) {
        return -1;
    }

    if (matrix->rows == 1) {
        *val = matrix->arr[0][0];
        return 0;

    } else if (matrix->rows == 2) {
        *val = (matrix->arr[0][0] * matrix->arr[1][1] - matrix->arr[1][0] * matrix->arr[0][1]);
        return 0;
    } else {
        for (size_t i = 0; i < matrix->cols; i++) {
            Matrix* matrix_acc = create_matrix(matrix->rows - 1, matrix->cols - 1);
            if (matrix_acc == NULL) {
                return -1;
            }
            minor(matrix, matrix_acc, i, 0);

            double cur = *val;
            *val = 0;

            det(matrix_acc, val);
            *val = cur + (pow(-1, i) * matrix->arr[0][i] * *val);
            free_matrix(matrix_acc);
        }
    }
    return 0;
}
