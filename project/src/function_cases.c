#include "function_cases.h"
#define WRITE_ABOUT_CLIENT          1
#define WRITE_TRANSACTION           2
#define REWRITE_CLIENT_CREDITLIMIT  3
void function_cases(void) {
int choice = 0;

    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");

    while ( scanf("%d", &choice) != -1 ) {
        switch (choice) {
        case WRITE_ABOUT_CLIENT:
            Ptr = fopen("record.dat", "r+");   // r+  Открывает файл для чтения/записи
            if ( Ptr == NULL ) {
                puts("Not acess");
            } else {
                master_write(Ptr, client_data);
                fclose(Ptr);   // close
            }
            break;
        case WRITE_TRANSACTION:
            Ptr = fopen("transaction.dat", "r+");  // r+  Открывает файл для чтения/записи
            if ( Ptr == NULL ) {
                puts("Not acess");
            } else {
                transaction_write(Ptr, transfer);
                fclose(Ptr);
            }
            break;
        case REWRITE_CLIENT_CREDITLIMIT:
            Ptr = fopen("record.dat", "r");                 // r открытие файла для чтения.
            Ptr_2 = fopen("transaction.dat", "r");         // r открытие файла для чтения.
            blackrecord = fopen("blackrecord.dat", "w");   // w  создать файл для е будут уничтожены.
            if ( Ptr == NULL || Ptr_2 == NULL || blackrecord == NULL ) {
                puts("exit");
            } else {
                black_record(Ptr, Ptr_2, blackrecord, client_data, transfer);
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
}
