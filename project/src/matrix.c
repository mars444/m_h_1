#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix* matrix;
    matrix = (Matrix *)malloc(sizeof(Matrix));
    size_t i, j;
    matrix->cols = cols;
    matrix->rows = rows;
    matrix->arr = (double**)malloc(rows*sizeof(double*));
    for ( i = 0; i < rows; i++ ) {
        matrix->arr[i]=(double*)malloc(cols*sizeof(double));
        for ( j = 0; j < cols; j++ ) {
            matrix->arr[i][j] = 0;
        }
    }
    return matrix;
}

Matrix* create_matrix_from_file(const char* path_file) {
    Matrix* matrix;
    matrix = (Matrix *)malloc(sizeof(Matrix));
  
    int  i, j;
    double a;
    FILE* Ptr;
    Ptr = fopen(path_file, "r");
    int rows = 0, cols = 0;
        fscanf(Ptr, "%d%d", &rows,&cols);
        matrix->rows = rows;
        matrix->cols = cols;
         matrix->arr = (double**)malloc(rows*sizeof(double*));
        for (i = 0; i < rows; i++) {
            matrix->arr[i] = (double*)malloc(cols*sizeof(double));
            for (j = 0; j < cols; j++) {
                fscanf(Ptr, "%lf", &a);
                matrix->arr[i][j] = a;
      }
    }
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


int get_cols(const Matrix* matrix, size_t* cols) {  //   получить количество столбцов.
*cols = matrix->cols;
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

Matrix* mul_scalar(const Matrix* matrix, double val) {  //  умножение матрицы на число

Matrix* matrix_num;
matrix_num = (Matrix *)malloc(sizeof(Matrix));
size_t i, j, rows = matrix->rows, cols = matrix->cols;
matrix_num->rows = matrix->rows;
matrix_num->cols = matrix->cols;


    matrix_num->arr = (double**)malloc(rows*sizeof(double*));
    for ( i = 0; i < rows; i++ ) {
        matrix_num->arr[i]=(double*)malloc(cols*sizeof(double));
        for ( j = 0; j < cols; j++ ) {
           matrix_num->arr[i][j] =  matrix->arr[i][j] * val;
        }
    }
    return matrix_num;
}

Matrix* transp(const Matrix* matrix) {  //  транспонирование матрицы

Matrix* matrix_t;
matrix_t = (Matrix *)malloc(sizeof(Matrix));
size_t i, j, rows = matrix->rows, cols = matrix->cols;
matrix_t->rows = matrix->cols;
matrix_t->cols = matrix->rows;

    matrix_t->arr = (double**)malloc(cols*sizeof(double*));
    for ( i = 0; i < cols; i++ ) {
        matrix_t->arr[i]=(double*)malloc(rows*sizeof(double));
        for ( j = 0; j < rows; j++ ) {
            matrix_t->arr[i][j] = matrix->arr[j][i];
        }
    }
    return matrix_t;
}




Matrix* sum(const Matrix* l, const Matrix* r) {
Matrix* matrix_sum;
matrix_sum = (Matrix *)malloc(sizeof(Matrix));
    size_t i, j;
    matrix_sum->rows = l->rows;
    matrix_sum->cols = l->cols;
    matrix_sum->arr = (double**)malloc(l->rows*sizeof(double*));
    for ( i = 0; i < l->rows; i++ ) {
        matrix_sum->arr[i]=(double*)malloc(l->cols*sizeof(double));
        for ( j = 0; j < l->cols; j++ ) {
            matrix_sum->arr[i][j] = l->arr[i][j] + r->arr[i][j];
        }
    }
     
    return matrix_sum;
}


Matrix* sub(const Matrix* l, const Matrix* r) {
Matrix* matrix_sub;
matrix_sub = (Matrix *)malloc(sizeof(Matrix));
    size_t i, j;
    matrix_sub->rows = l->rows;
    matrix_sub->cols = l->cols;
    matrix_sub->arr = (double**)malloc(l->rows*sizeof(double*));
    for ( i = 0; i < l->rows; i++ ) {
        matrix_sub->arr[i]=(double*)malloc(l->cols*sizeof(double));
        for ( j = 0; j < l->cols; j++ ) {
            matrix_sub->arr[i][j] = l->arr[i][j] - r->arr[i][j];
        } 
    } 
     
    return matrix_sub;
}



Matrix* mul(const Matrix* l, const Matrix* r) {
Matrix* matrix_mul;

matrix_mul = (Matrix *)malloc(sizeof(Matrix));
     size_t i, j, k;
    matrix_mul->rows = l->rows;
    matrix_mul->cols = r->cols;
    matrix_mul->arr = (double**)malloc(l->rows*sizeof(double*));
    for ( i = 0; i < l->rows; i++ ) {
        matrix_mul->arr[i]=(double*)malloc(r->cols*sizeof(double));
        for ( j = 0; j < r->cols; j++ ) {
            matrix_mul->arr[i][j] = 0;
      
      for (k = 0; k < r->rows; k++) {
       
        matrix_mul->arr[i][j] = matrix_mul->arr[i][j] +  (r->arr[k][j] * l->arr[i][k]);
       
      }
        }
    }

    return matrix_mul;
}


int det(const Matrix* matrix, double* val) {
*val = matrix->rows;
return 0;
}

Matrix* adj(const Matrix* matrix) {
Matrix* matrix_sub;
matrix_sub = (Matrix *)malloc(sizeof(Matrix));
matrix_sub->arr[4][4] = matrix->arr[4][2];
return matrix_sub;
}

Matrix* inv(const Matrix* matrix) {
    Matrix* matrix_sub;
matrix_sub = (Matrix *)malloc(sizeof(Matrix));
matrix_sub->arr[4][4] = matrix->arr[4][2];
return matrix_sub;
}