#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"
#include "write_client_to_file.h"
#include "write_transaction.h"
#include "write_to_file_test.h"
#include "black_record.h"
#include "read_from_file_test.h"


Data client_data;
Data transfer;
FILE *Ptr, *Ptr_2, *blackrecord, *test;

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
                fclose(Ptr_2);
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
    .Number = 444,
    .Name = "Petr",
    .Surname = "Pamuzhak",
    .addres = "Podolsk",
    .TelNumber = "+79251415930",
    .indebtedness = 1000,
    .credit_limit = 9999999,
    .cash_payments = 55555};

    test = fopen("my_test.dat", "w");   // w  Открывает файл для записи
    write_to_file(test, my_data);
    fclose(test);
    Data my_data_2 = {0};
    test = fopen("my_test.dat", "r");
    read_from_file(test, my_data_2, my_data);
    fclose(test);
    return 0;
}
