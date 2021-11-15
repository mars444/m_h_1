#include "main.h"
#include "function_cases.h"

#define WRITE_ABOUT_CLIENT          1
#define WRITE_TRANSACTION           2
#define REWRITE_CLIENT_CREDITLIMIT  3

#define RECORD_PATH           "record.dat"
#define TRANSACTION_PATH      "transaction.dat"
#define BLACKRECORD_PATH      "blackrecord.dat"


client client_data;
client transfer;
FILE *Ptr, *Ptr_2, *blackrecord;
void function_cases(void) {
int choice = 0;
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    while ( scanf("%d", &choice) != -1 ) {
        switch (choice) {
        case WRITE_ABOUT_CLIENT:
            Ptr = fopen(RECORD_PATH, "r+");
            if ( Ptr == NULL ) {
                puts("Not acess");
            } else {
                int ex = 0;
                client_write(Ptr, client_data, ex);
                fclose(Ptr);
            }
            break;
        case WRITE_TRANSACTION:
            Ptr = fopen(TRANSACTION_PATH, "r+");
            if ( Ptr == NULL ) {
                fclose(Ptr);
                puts("Not acess");
            } else {
                transaction_write(Ptr, transfer);
                fclose(Ptr);
            }
            break;
        case REWRITE_CLIENT_CREDITLIMIT:
            Ptr = fopen(RECORD_PATH, "r");
            Ptr_2 = fopen(TRANSACTION_PATH, "r");
            blackrecord = fopen(BLACKRECORD_PATH, "w");
            if ( Ptr == NULL || Ptr_2 == NULL || blackrecord == NULL ) {
                fclose(Ptr);
                fclose(Ptr_2);
                fclose(blackrecord);
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
