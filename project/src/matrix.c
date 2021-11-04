#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *adj(const Matrix *matrix) {
    Matrix *matrix_sub;
    matrix_sub = (Matrix *)malloc(sizeof(Matrix));
    matrix_sub->cols = matrix->cols;
    return matrix_sub;
}

Matrix *inv(const Matrix *matrix) {
    Matrix *matrix_sub;
    matrix_sub = (Matrix *)malloc(sizeof(Matrix));
    matrix_sub->cols = matrix->cols;
    return matrix_sub;
}

int det(const Matrix *matrix, double *val) {
    if (matrix && val) {
        return -1;
    }
    return 0;
}
