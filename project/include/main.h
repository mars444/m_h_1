#ifndef  PROJECT_INCLUDE_MAIN_H_
#define  PROJECT_INCLUDE_MAIN_H_

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
int test_write_function(void);
Data transfer;
FILE *Ptr, *Ptr_2, *blackrecord;

#endif   //  PROJECT_INCLUDE_MAIN_H_
//   pragma ""
