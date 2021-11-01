#include "matrix.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(size_t rows, size_t cols) {
    if (cols == 0 || rows == 0) {
        return NULL;
    }
    Matrix *matrix;
    matrix = (Matrix *)malloc(sizeof(Matrix));
    if (matrix == NULL) {
     free(matrix);
        return NULL;
    }
    size_t i, j;
    matrix->cols = cols;
    matrix->rows = rows;
    matrix->arr = (double **)malloc(rows * sizeof(double *));
    if (matrix->arr == NULL) {
        free(matrix);
        return NULL;
    }

    for (i = 0; i < rows; i++) {
        matrix->arr[i] = (double *)malloc(cols * sizeof(double));
        if (matrix->arr[i] == NULL) {
            free(matrix);
            return NULL;
        }
        for (j = 0; j < cols; j++) {
            matrix->arr[i][j] = 0;
        }
    }
    return matrix;
}

Matrix *create_matrix_from_file(const char *path_file) {
    if (path_file == NULL) {
        return NULL;
    }
    Matrix *matrix;
    matrix = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix) {
        free(matrix);
        return NULL;
    }
    size_t i, j;
    FILE *Ptr;
    Ptr = fopen(path_file, "r");
    fscanf(Ptr, "%zu%zu", &matrix->rows, &matrix->cols);
    matrix->arr = (double **)malloc(matrix->rows * sizeof(double *));
    if (!matrix->arr) {
        fclose(Ptr);
        free(matrix);
        return NULL;
    }
    if (matrix->rows == 0 || matrix->cols == 0) {
        fclose(Ptr);
        free(matrix);
        return NULL;
    }
    for (i = 0; i < matrix->rows; i++) {
        matrix->arr[i] = (double *)malloc(matrix->cols * sizeof(double));
        if (!matrix->arr[i]) {
            fclose(Ptr);
            free(matrix);
            return NULL;
        }
        for (j = 0; j < matrix->cols; j++) {
            fscanf(Ptr, "%lf", &matrix->arr[i][j]);
        }
    }
    fclose(Ptr);
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}

int get_rows(const Matrix *matrix, size_t *rows) {   //  получить количество строк.
    *rows = matrix->rows;
    return 0;
}

int get_cols(const Matrix *matrix, size_t *cols) {   //   получить количество столбцов.
    *cols = matrix->cols;
    return 0;
}

int get_elem(const Matrix *matrix, size_t row, size_t col, double *val) {
    // получить значение элемента на позиции [<row>, <col>]
    *val = matrix->arr[row][col];
    return 0;
}

int set_elem(Matrix *matrix, size_t row, size_t col, double val) {
    matrix->arr[row][col] = val;
    return 0;
}

Matrix *mul_scalar(const Matrix *matrix, double val) {   //  умножение матрицы на число
    if (matrix == NULL || matrix->cols == 0 || matrix->rows == 0) {
        return NULL;
    }
    Matrix *matrix_num;
    matrix_num = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_num) {
        free(matrix_num);
        return NULL;
    }
    size_t i, j, rows = matrix->rows, cols = matrix->cols;
    matrix_num->rows = matrix->rows;
    matrix_num->cols = matrix->cols;

    matrix_num->arr = (double **)malloc(rows * sizeof(double *));
    if (!matrix_num->arr) {
        free(matrix_num);
        return NULL;
    }
    for (i = 0; i < rows; i++) {
        matrix_num->arr[i] = (double *)malloc(cols * sizeof(double));
        if (!matrix_num->arr[i]) {
            free(matrix_num);
            return NULL;
        }
        for (j = 0; j < cols; j++) {
            matrix_num->arr[i][j] = matrix->arr[i][j] * val;
        }
    }
    return matrix_num;
}

Matrix *transp(const Matrix *matrix) {   //  транспонирование матрицы
    if (matrix == NULL || matrix->cols == 0 || matrix->rows == 0) {
        return NULL;
    }
    Matrix *matrix_t;
    matrix_t = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_t) {
        free(matrix_t);
        return NULL;
    }
    size_t i, j, rows = matrix->rows, cols = matrix->cols;
    matrix_t->rows = matrix->cols;
    matrix_t->cols = matrix->rows;

    matrix_t->arr = (double **)malloc(cols * sizeof(double *));
    if (!matrix_t->arr) {
        free(matrix_t);
        return NULL;
    }
    for (i = 0; i < cols; i++) {
        matrix_t->arr[i] = (double *)malloc(rows * sizeof(double));
        if (!matrix_t->arr[i]) {
            free(matrix_t);
            return NULL;
        }
        for (j = 0; j < rows; j++) {
            matrix_t->arr[i][j] = matrix->arr[j][i];
        }
    }
    return matrix_t;
}

Matrix *sum(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols == 0 || l->rows == 0 ||
        r->cols == 0 || r->rows == 0) {
        return NULL;
    }
    Matrix *matrix_sum;
    matrix_sum = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_sum) {
        free(matrix_sum);
        return NULL;
    }
    size_t i, j;
    matrix_sum->rows = l->rows;
    matrix_sum->cols = l->cols;
    matrix_sum->arr = (double **)malloc(l->rows * sizeof(double *));
    if (!matrix_sum->arr) {
        free(matrix_sum);
        return NULL;
    }
    for (i = 0; i < l->rows; i++) {
        matrix_sum->arr[i] = (double *)malloc(l->cols * sizeof(double));
        if (!matrix_sum->arr[i]) {
            free(matrix_sum);
            return NULL;
        }
        for (j = 0; j < l->cols; j++) {
            matrix_sum->arr[i][j] = l->arr[i][j] + r->arr[i][j];
        }
    }
    return matrix_sum;
}

Matrix *sub(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols == 0 || l->rows == 0 ||
        r->cols == 0 || r->rows == 0) {
        return NULL;
    }
    Matrix *matrix_sub;
    matrix_sub = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_sub) {
        free(matrix_sub);
        return NULL;
    }
    size_t i, j;
    matrix_sub->rows = l->rows;
    matrix_sub->cols = l->cols;
    matrix_sub->arr = (double **)malloc(l->rows * sizeof(double *));
    if (!matrix_sub->arr) {
        free(matrix_sub);
        return NULL;
    }
    for (i = 0; i < l->rows; i++) {
        matrix_sub->arr[i] = (double *)malloc(l->cols * sizeof(double));
        if (!matrix_sub->arr[i]) {
            free(matrix_sub);
            return NULL;
        }
        for (j = 0; j < l->cols; j++) {
            matrix_sub->arr[i][j] = l->arr[i][j] - r->arr[i][j];
        }
    }
    return matrix_sub;
}

Matrix *mul(const Matrix *l, const Matrix *r) {
    if (l == NULL || r == NULL || l->cols == 0 || l->rows == 0 ||
        r->cols == 0 || r->rows == 0) {
        return NULL;
    }
    Matrix *matrix_mul;

    matrix_mul = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix_mul) {
        free(matrix_mul);
        return NULL;
    }

    size_t i, j, k;
    matrix_mul->rows = l->rows;
    matrix_mul->cols = r->cols;
    matrix_mul->arr = (double **)malloc(matrix_mul->rows * sizeof(double *));
    if (!matrix_mul->arr) {
        free(matrix_mul);
        return NULL;
    }
    for (i = 0; i < matrix_mul->rows; i++) {
        matrix_mul->arr[i] = (double *)malloc(matrix_mul->cols * sizeof(double));
        if (!matrix_mul->arr[i]) {
            free(matrix_mul);
            return NULL;
        }
        for (j = 0; j < matrix_mul->cols; j++) {
            matrix_mul->arr[i][j] = 0;
            for (k = 0; k < r->rows; k++) {
                matrix_mul->arr[i][j] = matrix_mul->arr[i][j] + (r->arr[k][j] * l->arr[i][k]);
            }
        }
    }

    return matrix_mul;
}

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
    return matrix;
}
