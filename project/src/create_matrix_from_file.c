#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix_from_file(const char *path_file) {
    if (path_file == NULL) {
        return NULL;
    }

    FILE *Ptr;
    Matrix *matrix;

    matrix = (Matrix *)malloc(sizeof(Matrix));

    if (!matrix) {
        free(matrix);
        return NULL;
    }
    Ptr = fopen(path_file, "r");

    fscanf(Ptr, "%zu%zu", &matrix->rows, &matrix->cols);

    matrix->arr = (double **)malloc(matrix->rows * sizeof(double *));

    if (!matrix->arr) {
        fclose(Ptr);
        free(matrix);
        return NULL;
    }

    if (matrix->rows < 1 || matrix->cols < 1) {
        fclose(Ptr);
        free(matrix);
        return NULL;
    }

    for (size_t i = 0; i < matrix->rows; i++) {
        matrix->arr[i] = (double *)malloc(matrix->cols * sizeof(double));
        if (!matrix->arr[i]) {
            fclose(Ptr);
            free(matrix);
            return NULL;
        }
        for (size_t j = 0; j < matrix->cols; j++) {
            fscanf(Ptr, "%lf", &matrix->arr[i][j]);
        }
    }

    fclose(Ptr);
    return matrix;
}
