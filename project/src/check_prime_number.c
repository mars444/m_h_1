#define NUMBER_IS_PRIME           1
#define NUMBER_IS_NOT_PRIME       0

// функция проверяет - простое ли число n
int is_prime_number(int n) {
    if (n > 1) {
        for (int i = 2; i < n; i++)
            if (n % i == 0) {
                return NUMBER_IS_NOT_PRIME;
            }
        return NUMBER_IS_PRIME;
    } else {
        return NUMBER_IS_NOT_PRIME;
           }
}
