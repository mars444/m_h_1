#include <stdio.h>
void numbers_before_n(int n) {
    if ( n > 0 ) {
numbers_before_n(n-1);
printf("%d ", n);
    } else if ( n == 0 ) {
printf("%d", n);
    }
}
