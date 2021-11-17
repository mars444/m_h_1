#include "main.h"
#include "write_client_to_file.h"
#include <string.h>
void read_from_file(FILE *ofPTR, client client_data, client my_data) {
    fscanf(ofPTR, "%d%20s%20s%30s%15s%lf%lf%lf",
        &client_data.client_number,
        client_data.client_name,
        client_data.client_surname,
        client_data.client_addres,
        client_data.client_tel_number,
        &client_data.client_indebtedness,
        &client_data.client_credit_limit,
        &client_data.client_cash_payments);

    if ( (client_data.client_number ==   my_data.client_number) &&
        (strcmp(client_data.client_name, my_data.client_name)) &&
        (strcmp(client_data.client_surname, my_data.client_surname)) &&
        (strcmp(client_data.client_addres, my_data.client_addres)) &&
        (strcmp(client_data.client_tel_number, my_data.client_tel_number)) &&
        (client_data.client_indebtedness ==  my_data.client_indebtedness) &&
        (client_data.client_credit_limit ==    my_data.client_credit_limit) &&
        (client_data.client_cash_payments ==      my_data.client_cash_payments) ) {
            printf("Тест записи и чтения с файла выполнен УСПЕШНО!!!\n\n");

    } else {
            printf("Тест записи и чтения НЕ ПРОЙДЕН((( \n");
    }
}
