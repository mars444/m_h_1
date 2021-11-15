#include "main.h"
#include "write_client_to_file.h"

int write_client_to_file(FILE *filename, client Client) {
    fprintf(filename, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
            Client.client_number,
            Client.client_name,
            Client.client_surname,
            Client.client_addres,
            Client.client_tel_number,
            Client.client_indebtedness,
            Client.client_credit_limit,
            Client.client_cash_payments);
    return 0;
}
