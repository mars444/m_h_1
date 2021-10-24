#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"
#include "write_client_to_file.h"
#include "write_transaction.h"
#include "write_to_file_test.h"


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

    return 0;
}

void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer) {
    while ( fscanf(ofPTR, "%d%20s%20s%30s%15s%lf%lf%lf",
                  &client_data.Number,
                  client_data.Name,
                  client_data.Surname,
                  client_data.addres,
                  client_data.TelNumber,
                  &client_data.indebtedness,
                  &client_data.credit_limit,
                  &client_data.cash_payments) != -1 ) {
        while ( fscanf(ofPTR_2, "%d %lf", &transfer.Number, &transfer.cash_payments) != -1 ) {
            if (client_data.Number == transfer.Number && transfer.cash_payments != 0) {
                client_data.credit_limit += transfer.cash_payments;
            }
        }
        fprintf(blackrecord, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                client_data.Number,
                client_data.Name,
                client_data.Surname,
                client_data.addres,
                client_data.TelNumber,
                client_data.indebtedness,
                client_data.credit_limit,
                client_data.cash_payments);
        rewind(ofPTR_2);
    }
}
