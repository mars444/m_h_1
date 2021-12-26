#include "main.h"
#include "write_to_file_from_flow.h"
#include "write_client_to_file.h"

int write_to_file_from_flow(FILE *filename, client client) {
if (scanf("%d%20s%20s%30s%15s%lf%lf%lf",
              &client.client_number,
              client.client_name,
              client.client_surname,
              client.client_addres,
              client.client_tel_number,
              &client.client_indebtedness,
              &client.client_credit_limit,
              &client.client_cash_payments) != -1) {
        write_client_to_file(filename, client);

    } else {
        int stop_scanf;
        stop_scanf = -1;
        return stop_scanf;
    }

    return 0;
}
