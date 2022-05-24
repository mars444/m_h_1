#include "matrix.h"

void minor(const Matrix* l, const Matrix* r, size_t cols, size_t rows) {
    size_t r_rows = 0, r_cols = 0;

    for (size_t i = 0; i < l->rows; i++) {
        if (i == rows) {
            continue;
        }
        r_cols = 0;

        for (size_t j = 0; j < l->cols; j++) {
            if (j != cols) {
                r->arr[r_rows][r_cols] = l->arr[i][j];
                r_cols++;
            }
        }
        r_rows++;
    }
}
