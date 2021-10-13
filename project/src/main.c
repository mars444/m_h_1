#include <stdlib.h>
#include <stdio.h>
#include </home/mars444/Рабочий стол/mi/mail-homework/project/include/utils.h>
#include </home/mars444/Рабочий стол/mi/mail-homework/project/include/case_3.h>
#include </home/mars444/Рабочий стол/mi/mail-homework/project/include/case_4.h>
#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_MOD_4       4

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    int Test_case = atoi(argv[1]);
    const char* data;
    data = argv[2];

    switch (Test_case) {
        case TST_FOO_FIX: {
            int to = atoi(data);
            size_t ticks_count = timer_from(to);
            printf("%zu\n", ticks_count);
            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                 int base = atoi(data);
                int pow =  atoi(argv[3]);
                int res = custom_pow(base, pow);   // TODO(@mars444):
                printf("%i\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }
        case TST_MOD_IMPL: {
            int num = atoi(data);    // TODO(@mars444):
            int result = isPrime(num);
             printf("%d\n", result);
             break;
        }
        case TST_MOD_4: {
            int num = atoi(data);    // TODO(@mars444):
            int result = numbers_before_n(num);
             printf("%d\n", result);
             break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}
