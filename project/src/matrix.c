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

void free_matrix(Matrix* matrix) {

for (size_t i = 0; i < matrix->rows;i++) {
    free(matrix->arr[i]);
}
free(matrix);
}



int get_rows(const Matrix* matrix, size_t* rows) {  //  получить количество строк.
*rows = matrix->rows;
    return 0;
}


int get_rows(const Matrix* matrix, size_t* cols) {  //   получить количество столбцов.
*cols = matrix->rows;
    return 0;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) { 
// получить значение элемента на позиции [<row>, <col>]
*val = matrix->arr[row][col];
return 0;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    //установить значение val элементу на позиции [<row>, <col>]
matrix->arr[row][col] = val;
return 0;
}

Matrix* mul_scalar(const Matrix* matrix, double val) {

    for (size_t i = 0; i < matrix->cols; i++) {
        for (size_t j = 0; j < matrix->rows; j++) {

                matrix->arr[i][j] =  matrix->arr[i][j] * val;
      }
    }
}
