#include <stddef.h>
#include <stdio.h>

size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i > 0; --i) {
        ++counter;
        printf("%d", i);
    }
    return counter;
}



// TODO: Implement `power of` function

int custom_pow(int base, int power) {
    return 0;
}

