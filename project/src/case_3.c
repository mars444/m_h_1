// функция проверяет - простое ли число n
int isPrime(int n) {
    if (n > 1) {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;
        return 1;
    } else {
        return 0;
    }
}
