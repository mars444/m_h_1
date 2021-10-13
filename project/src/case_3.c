// функция возводит в степень
int custom_pow(int base, int power) {
    int current = 1;
    for ( int i = 1; i < power; i++ ) {
        current *= base;
    }
    return current;
}
