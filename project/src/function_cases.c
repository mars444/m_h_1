#include "main.h"
#include "function_cases.h"

#define WRITE_ABOUT_CLIENT          1
#define WRITE_TRANSACTION           2
#define REWRITE_CLIENT_CREDITLIMIT  3

#define RECORD_PATH           "record.dat"
#define TRANSACTION_PATH      "transaction.dat"
#define BLACKRECORD_PATH      "blackrecord.dat"

#define ENTERS "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n"


client client_data;
client transfer;
FILE *client_values, *transfer_values, *from_write;

void function_cases(void) {
int choice = 0;

    printf("%s", ENTERS);

    while ( scanf("%d", &choice) != -1 ) {
        switch (choice) {
            case WRITE_ABOUT_CLIENT:
                client_values = fopen(RECORD_PATH, "r+");

                if ( client_values == NULL ) {
                    puts("Not acess");
                } else {
                    int ex = 0;
                    client_write(client_values, client_data, ex);
                    fclose(client_values);
                }
                break;

            case WRITE_TRANSACTION:
                transfer_values = fopen(TRANSACTION_PATH, "r+");

                if ( transfer_values == NULL ) {
                    fclose(transfer_values);
                    puts("Not acess");
                } else {
                    transaction_write(transfer_values, transfer);
                    fclose(transfer_values);
                }
                break;

            case REWRITE_CLIENT_CREDITLIMIT:
                client_values = fopen(RECORD_PATH, "r");
                transfer_values = fopen(TRANSACTION_PATH, "r");
                from_write = fopen(BLACKRECORD_PATH, "w");

                if ( client_values == NULL || transfer_values == NULL || from_write == NULL ) {
                    fclose(client_values);
                    fclose(transfer_values);
                    fclose(from_write);
                    puts("exit");

                } else {
                    black_record(client_values, transfer_values, from_write, client_data, transfer);
                    fclose(client_values);
                    fclose(transfer_values);
                    fclose(from_write);
                }
                break;

            default:
                puts("error");
                break;
        }
            printf("%s", ENTERS);
    }
}
