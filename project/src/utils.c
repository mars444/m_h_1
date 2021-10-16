#include <stdio.h>

size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i >=0; i--) {
        ++counter;
        if (i != 0) {
        printf("%d ", i);
        } else {
             printf("%d", i);
             printf("\n");
        }
    }
    return counter;
}



// функция возводит в степень
int custom_pow(int base, int power) {
    if ( base == 1 ) {
        return base;
    } else {
    int current = 1;
    for ( int i = 1; i <= power; i++ ) {
        current *= base;
    }
    return current;
    }
}


