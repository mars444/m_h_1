#include <stdio.h>
int num_1_to_n(int n, int m) {
    if ( n > 1 ) {
    num_1_to_n(n - 1, m);
    } else if ( n < 1 ) {
       num_1_to_n(n + 1, m);
    }
    if (n != m) {
        printf("%d ", n);
    } else {
    printf("%d", n);
    }
    return 0;
}
