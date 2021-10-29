#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix* matrix;
    matrix = (Matrix *)malloc(sizeof(Matrix));
    size_t i, j;
    matrix->arr = (double**)malloc(rows*sizeof(double*));
    for ( i = 0; i < rows; i++ ) {
        matrix->arr[i]=(double*)malloc(cols*sizeof(double));
        for ( j = 0; j < cols; j++ ) {
            matrix->arr[i][j] = 0;
            int a = matrix->arr[i][j];
            printf("%5d ", a );
        }
        printf("\n");
    }
    return matrix;
}

Matrix* create_matrix_from_file(const char* path_file) {
    Matrix* matrix;
    matrix = (Matrix *)malloc(sizeof(Matrix));
    int  i, j;
    int a;
    FILE* Ptr;
    Ptr = fopen(path_file, "r");
    int rows, cols;
        fscanf(Ptr, "%d", &rows);
        fscanf(Ptr, "%d", &cols);
         matrix->arr = (double**)malloc(rows*sizeof(double*));
        for (i = 0; i < rows; i++) {
            matrix->arr[i] = (double*)malloc(cols*sizeof(double));
            for (j = 0; j < cols; j++) {
                fscanf(Ptr, "%d", &a);
                printf("%5d",  a);
                matrix->arr[i][j] = a;
      }
      printf("\n");
    }
    printf("\n");
    fclose(Ptr);
    return matrix;
}

