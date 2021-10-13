#include <stddef.h>
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



// TODO(@mars444): Stuff.

// функция возводит в степень
int custom_pow(int base, int power) {
    return pow(base, power);
}

// функция проверяет - простое ли число n
int isPrime(int n) {
    // если n > 1
    if (n > 1) {
        // в цикле перебираем числа от 2 до n - 1
        for (int i = 2; i < n; i++)
            if (n % i == 0)   // если n делится без остатка на i - возвращаем false (число не простое)
                return 0;
        // если программа дошла до данного оператора, то возвращаем true (число простое) - проверка пройдена
        return 1;
    } else {
        return 0;
    }    // иначе возвращаем false (число не простое)
}
