#include <stdlib.h>
#include <stdio.h>
#include <../include/check_prime_number.h>
#include <../include/output_numbers_from_1_to_n.h>
#include <../include/utils.h>

#define ERROR_ARGUMENTS_COUNT            -1
#define ERROR_WRONG_CASE_NUMBER          -2
#define TEST_TIMER                        1
#define TEST_RISE_TO_THE_POWER            2
#define TEST_CHECK_PRIME_NUMBER           3
#define TEST_NUMBER_FROM_1_TO_N           4

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERROR_ARGUMENTS_COUNT;
    }

    int Test_case = stoi(argv[1]);
    const char* data;
    data = argv[2];

    switch (Test_case) {
        case TEST_TIMER: {
            int to = stoi(data);
            size_t ticks_count = timer_from(to);
            printf("%zu\n", ticks_count);
            break;
        }
        case TEST_RISE_TO_THE_POWER: {
            if (argc == 4) {
                int base = stoi(data);
                int pow =  stoi(argv[3]);
                int res = custom_pow(base, pow);
                printf("%d\n", res);
            } else {
                return ERROR_ARGUMENTS_COUNT;
            }
            break;
        }
        case TEST_CHECK_PRIME_NUMBER: {
            int num = stoi(data);
            int result = is_prime_number(num);
            printf("%d\n", result);
            break;
        }
        case TEST_NUMBER_FROM_1_TO_N: {
            int num = stoi(data);
            int num2 = num;
            numbers_before_n(num, num2);
            break;
        }
        default: {
            return ERROR_WRONG_CASE_NUMBER;
        }
    }
}
