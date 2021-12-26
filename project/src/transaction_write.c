#include "main.h"
#include "transaction_write.h"

int exit_transaction = 0;

int write_transaction_to_file(FILE *out_transaction, client transfer) {
    if (scanf("%d %lf", &transfer.client_number, &transfer.client_cash_payments) != -1) {
        fprintf(out_transaction, "%-3d%-6.2f\n", transfer.client_number, transfer.client_cash_payments);

    } else {
        exit_transaction = -1;
    }

    return 0;
}

void transaction_write(FILE *out_transaction, client transfer) {
    printf("%s\n%s\n",
           "1 Number account: ",
           "2 Client cash payments: ");

    while (exit_transaction != -1) {
        write_transaction_to_file(out_transaction, transfer);
        printf("%s  %d\n%s  %lf\n",
               "1 Number account:", transfer.client_number,
               "2 Client cash payments: ", transfer.client_cash_payments);
    }
}
