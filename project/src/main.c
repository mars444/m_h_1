#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"
#include "write_client_to_file.h"
#include "write_transaction.h"
#include "write_to_file_test.h"
#include "black_record.h"


void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer);
int write_to_file(FILE *filename, Data Client);

    Data client_data;
    Data transfer;
    FILE *Ptr, *Ptr_2, *blackrecord, *test;
void read_from_file(FILE *ofPTR, Data client_data, Data my_data);



// потоки фсканф фпринтф дефайны тайпдефы хедеры
int main(void) {
    int choice = 0;

    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");

    while ( scanf("%d", &choice) != -1 ) {
        switch (choice) {
        case 1:
            Ptr = fopen("record.dat", "r+");   // r+  Открывает файл для чтения/записи
            if ( Ptr == NULL ) {
                puts("Not acess");
            } else {
                masterWrite(Ptr, client_data);
                fclose(Ptr);   // close
            }
            break;
        case 2:
            Ptr = fopen("transaction.dat", "r+");  // r+  Открывает файл для чтения/записи
            if ( Ptr == NULL ) {
                puts("Not acess");
            } else {
                transactionWrite(Ptr, transfer);
                fclose(Ptr);
            }
            break;
        case 3:
            Ptr = fopen("record.dat", "r");                 // r открытие файла для чтения.
            Ptr_2 = fopen("transaction.dat", "r");         // r открытие файла для чтения.
            blackrecord = fopen("blackrecord.dat", "w");   // w  создать файл для е будут уничтожены.
            if ( Ptr == NULL || Ptr_2 == NULL || blackrecord == NULL ) {
                puts("exit");
            } else {
                blackRecord(Ptr, Ptr_2, blackrecord, client_data, transfer);
                fclose(Ptr);
                fclose(Ptr_2);   // fopen(). Она сохраняет в файл данные, находящиеся в дисковом буфере
                fclose(blackrecord);
            }
            break;
        default:
            puts("error");
            break;
        }
        printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    }



Data my_data = {
    .Number = 12,
    .Name = "Petr",
    .Surname = "Pamuzhak",
    .addres = "Podolsk",
    .TelNumber = "+79251415930",
    .indebtedness = 123,
    .credit_limit = 124512,
    .cash_payments = 12525};
    test = fopen("my_test.dat", "w");
    write_to_file(test, my_data);
    printf("Heoolo\n\n");
    fclose(test);
    Data my_data_2 = {0};
    test = fopen("my_test.dat", "r");
    read_from_file(test, my_data_2, my_data);
        fclose(test);





    return 0;
}
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
                  printf("Записанные в новую структуру данные: \n");
                  printf("%d\n%s\n%s\n%s\n%s\n%.2lf\n%.2lf\n%.2lf\n",
                  client_data.Number,
                  client_data.Name,
                  client_data.Surname,
                  client_data.addres,
                  client_data.TelNumber,
                  client_data.indebtedness,
                  client_data.credit_limit,
                  client_data.cash_payments);

                   if ( (client_data.Number ==   my_data.Number) &&
                        (*client_data.Name ==   *my_data.Name)  &&
                        (*client_data.Surname ==     *my_data.Surname) &&
                        (*client_data.addres ==  *my_data.addres) &&
                        (*client_data.TelNumber ==   *my_data.TelNumber) &&
                        (client_data.indebtedness ==  my_data.indebtedness) &&
                        (client_data.credit_limit ==    my_data.credit_limit) &&
                        (client_data.cash_payments ==      my_data.cash_payments) ) {
        printf("Sucses\n");
    } else {
        printf("Error\n");
    }
}
