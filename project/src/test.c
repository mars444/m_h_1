#include "write_to_file_test.h"
#include "read_from_file_test.h"

FILE *test;
Data my_data = {
    .Number = 444,
    .Name = "Petr",
    .Surname = "Pamuzhak",
    .addres = "Podolsk",
    .TelNumber = "+79251415930",
    .indebtedness = 1000,
    .credit_limit = 9999999,
    .cash_payments = 55555};

int test_write_function(void) {
    test = fopen("my_test.dat", "w");    // w  Открывает файл для записи
    write_to_file(test, my_data);
    fclose(test);
    Data my_data_2 = {0};
    test = fopen("my_test.dat", "r");
    read_from_file(test, my_data_2, my_data);
    fclose(test);
    return 0;
}
