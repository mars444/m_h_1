#include <stdio.h>
int numbers_before_n(int n, int m) {
    if ( n > 1 ) {
    numbers_before_n(n - 1, m);
    } else if ( n < 1 ) {
        numbers_before_n(n + 1, m);
    }
    if (n != m) {
        printf("%d ", n);
    } else {
    printf("%d", n);
    }
    return 0;
}
