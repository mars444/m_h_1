#include <stdio.h>
#include <math.h>

size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i > 0; --i) {
        ++counter;
        printf("%d", i);
    }
    return counter;
}



// TODO(@mars444):

// функция возводит в степень
int custom_pow(int base, int power) {
    int current = 1;
    for ( int i = 1; i < power; i++ ) {
        current *= base;
    }
    return current;
}


