#pragma once

#include <stdio.h>

struct about_bank_client {
    int client_number;
    char client_name[20];
    char client_surname[20];
    char client_addres[30];
    char client_tel_number[15];
    double client_indebtedness;
    double client_credit_limit;
    double client_cash_payments;
};

typedef struct about_bank_client client;
