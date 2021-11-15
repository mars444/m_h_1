#include "main.h"
#include "write_client_to_file.h"
void read_from_file(FILE *ofPTR, client Client_data, client my_data) {
    fscanf(ofPTR, "%d%20s%20s%30s%15s%lf%lf%lf",
        &Client_data.client_number,
        Client_data.client_name,
        Client_data.client_surname,
        Client_data.client_addres,
        Client_data.client_tel_number,
        &Client_data.client_indebtedness,
        &Client_data.client_credit_limit,
        &Client_data.client_cash_payments);

    if ( (Client_data.client_number ==   my_data.client_number) &&
        (*Client_data.client_name ==   *my_data.client_name)  &&
        (*Client_data.client_surname ==     *my_data.client_surname) &&
        (*Client_data.client_addres ==  *my_data.client_addres) &&
        (*Client_data.client_tel_number ==   *my_data.client_tel_number) &&
        (Client_data.client_indebtedness ==  my_data.client_indebtedness) &&
        (Client_data.client_credit_limit ==    my_data.client_credit_limit) &&
        (Client_data.client_cash_payments ==      my_data.client_cash_payments) ) {
            printf("Тест записи и чтения с файла выполнен УСПЕШНО!!!\n\n");
    } else {
            printf("Тест записи и чтения НЕ ПРОЙДЕН((( \n");
    }
}
