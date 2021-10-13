int numbers_before_n(int n) {
    if ( n > 1 ) {
numbers_before_n(n-1);
    }
    return n;
}
