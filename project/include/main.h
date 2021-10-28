#pragma once
#include <stdio.h>

struct user_sber { int Number;
                      char Name[20];
                      char Surname[20];
                      char addres[30];
                      char TelNumber[15];
                      double indebtedness;
                      double credit_limit;
                      double cash_payments;};
typedef struct user_sber Data;

Data client_data;
Data transfer;
FILE *Ptr, *Ptr_2, *blackrecord;
//   pragma ""
