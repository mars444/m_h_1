#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
