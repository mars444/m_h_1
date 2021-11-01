#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void free_matrix(Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}
