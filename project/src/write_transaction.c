#include "write_transaction.h"
int exit_transaction = 0;
int write_transaction_to_file(FILE *ofPTR2, Data transfer) {
    if ( scanf("%d %lf", &transfer.Number, &transfer.cash_payments) != -1 ) {
    fprintf(ofPTR2, "%-3d%-6.2f\n", transfer.Number, transfer.cash_payments);} else {
                    exit_transaction = -1;
                }
    return 0;
}
void transactionWrite(FILE *ofPTR2, Data transfer) {
    printf("%s\n%s\n",
           "1 Number account: ",
           "2 Client cash payments: ");
    while ( exit_transaction != -1 ) {
    write_transaction_to_file(ofPTR2, transfer);
    printf("%s  %d\n%s  %lf\n",
            "1 Number account:", transfer.Number,
            "2 Client cash payments: ", transfer.cash_payments);
    }
}
