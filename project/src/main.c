#include <stdio.h>
#include "matrix.h"
int main() {
       char* l = "2.txt";
       Matrix* ll;
       Matrix* rr;

       ll = create_matrix_from_file(l);
       char* r = "3.txt";
       rr = create_matrix_from_file(r);

       sum(ll, rr);
       sub(ll, rr);
       mul(ll, rr);
       create_matrix(3, 6);

       mul_scalar(ll, 5);

  return 0;
}






