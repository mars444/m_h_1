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

int write_about_client_to_file(FILE *ofPTR, Data Client);
int write_transaction_to_file(FILE *ofPTR2, Data transfer);
void masterWrite(FILE *ofPTR, Data Client);
void transactionWrite(FILE *ofPTR2, Data transfer);
void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer);

    Data client_data;
    Data transfer;
    FILE *Ptr, *Ptr_2, *blackrecord;


#endif   //  PROJECT_INCLUDE_MAIN_H_
//   pragma ""
