#ifndef  PROJECT_INCLUDE_MAIN_H_
#include <stdio.h>
#define  PROJECT_INCLUDE_MAIN_H_



struct masterRecord { int Number;
                      char Name[20];
                      char Surname[20];
                      char addres[30];
                      char TelNumber[15];
                      double indebtedness;
                      double credit_limit;
                      double cash_payments;};
typedef struct masterRecord Data;



void masterWrite(FILE *ofPTR, Data Client);
void transactionWrite(FILE *ofPTR2, Data transfer);
void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer);

    Data client_data;
    Data transfer;
    FILE *Ptr, *Ptr_2, *blackrecord;


#endif   //  PROJECT_INCLUDE_MAIN_H_
//   pragma ""
