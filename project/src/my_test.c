#include "main.h"
#include "my_test.h"
#include "read_from_file_test.h"
#include "write_client_to_file.h"

void my_test(void) {
FILE *test;

client my_data = {
    .client_number = 444,
    .client_name = "Petr",
    .client_surname = "Pamuzhak",
    .client_addres = "Podolsk",
    .client_tel_number = "+79251415930",
    .client_indebtedness = 1000,
    .client_credit_limit = 9999999,
    .client_cash_payments = 55555};

    test = fopen("my_test.dat", "w");

    write_client_to_file(test, my_data);

    fclose(test);

    client my_data_2 = {0};

    test = fopen("my_test.dat", "r");

    read_from_file(test, my_data_2, my_data);

    fclose(test);
}
