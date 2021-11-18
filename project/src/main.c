#include <stdio.h>

#include "matrix.h"

int main(void) {
        char* file_1 = "2.txt";
        char* file_2 = "3.txt";

        Matrix* left;
        Matrix* right;

        left = create_matrix_from_file(file_1);
        right = create_matrix_from_file(file_2);

        sum(left, right);
        sub(left, right);
        mul(left, right);
        create_matrix(3, 0);
        mul_scalar(left, 5);
        //  rr
        free_matrix(left);
        free_matrix(right);

  return 0;
}
