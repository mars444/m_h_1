#include "write_to_file.h"
void read_from_file(FILE *ofPTR, Data client_data, Data my_data) {
    fscanf(ofPTR, "%d%20s%20s%30s%15s%lf%lf%lf",
        &client_data.Number,
        client_data.Name,
        client_data.Surname,
        client_data.addres,
        client_data.TelNumber,
        &client_data.indebtedness,
        &client_data.credit_limit,
        &client_data.cash_payments);

    if ( (client_data.Number ==   my_data.Number) &&
        (*client_data.Name ==   *my_data.Name)  &&
        (*client_data.Surname ==     *my_data.Surname) &&
        (*client_data.addres ==  *my_data.addres) &&
        (*client_data.TelNumber ==   *my_data.TelNumber) &&
        (client_data.indebtedness ==  my_data.indebtedness) &&
        (client_data.credit_limit ==    my_data.credit_limit) &&
        (client_data.cash_payments ==      my_data.cash_payments) ) {
            printf("Тест записи и чтения с файла выполнен УСПЕШНО!!!\n\n");
    } else {
            printf("Тест записи и чтения НЕ ПРОЙДЕН((( \n");
    }
}
