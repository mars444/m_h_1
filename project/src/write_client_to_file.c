#include "main.h"
#include "write_client_to_file.h"

int write_client_to_file(FILE *filename, client client) {
    fprintf(filename, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
            client.client_number,
            client.client_name,
            client.client_surname,
            client.client_addres,
            client.client_tel_number,
            client.client_indebtedness,
            client.client_credit_limit,
            client.client_cash_payments);

    return 0;
}
