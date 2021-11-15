#include "main.h"
#include "write_to_file_from_flow.h"
#include "write_client_to_file.h"

int write_to_file_from_flow(FILE *filename, client Client) {
//
if (scanf("%d%20s%20s%30s%15s%lf%lf%lf",
              &Client.client_number,
              Client.client_name,
              Client.client_surname,
              Client.client_addres,
              Client.client_tel_number,
              &Client.client_indebtedness,
              &Client.client_credit_limit,
              &Client.client_cash_payments) != -1) {
//
        write_client_to_file(filename, Client);
//
    } else {
//
        int stop_scanf;
        stop_scanf = -1;
        return stop_scanf;
//
    }
//
    return 0;
}
