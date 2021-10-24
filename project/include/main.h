#ifndef  PROJECT_INCLUDE_MAIN_H_
#define  PROJECT_INCLUDE_MAIN_H_

#include <stdio.h>

struct masterRecord { int Number;
                      char Name[20];
                      char Surname[20];
                      char addres[30];
                      char TelNumber[15];
                      double indebtedness;
                      double credit_limit;
                      double cash_payments;};
typedef struct masterRecord Data;

Data client_data;
Data transfer;
FILE *Ptr, *Ptr_2, *blackrecord, *test;

#endif   //  PROJECT_INCLUDE_MAIN_H_
//   pragma ""
