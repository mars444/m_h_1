#include "my_test.h"
#include "read_from_file_test.h"
#include "write_to_file.h"

void my_test(void) {
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

    test = fopen("my_test.dat", "w");
    write_to_file(test, my_data);
    fclose(test);
    Data my_data_2 = {0};
    test = fopen("my_test.dat", "r");
    read_from_file(test, my_data_2, my_data);
    fclose(test);
}
