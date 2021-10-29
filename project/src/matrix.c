#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* create_matrix(size_t rows, size_t cols) {
    int** matrix;
    size_t i, j, k;
    matrix = (int**)malloc(rows*sizeof(int*));
    for ( i = 0; i < rows; i++ ) {
        matrix[i]=(int*)malloc(cols*sizeof(int));
        for ( j = 0; j < cols; j++ ) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

Matrix* create_matrix_from_file(const char* path_file) {
    int** matrix;
    int  i, j ,k;
    int a;
    FILE* qwe;
    qwe = fopen(path_file, "r");
    int rows, cols;
        fscanf(qwe, "%d", &rows);
        fscanf(qwe, "%d", &cols);
        matrix = (int**)malloc(rows*sizeof(int*));
        for (i = 0; i < rows; i++)
            matrix[i] = (int*)malloc(cols*sizeof(int));
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                fscanf(qwe, "%d", &a);
                printf("%5d",  a);
                *(*(matrix+i)+j) = a;
      }
      printf("\n");
    }
    fclose(qwe);
    for ( k = 0; k < rows; k++ ) {
        free(matrix[k]);
    }
    free(matrix);
    return 0;
}
