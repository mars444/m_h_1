#include "main.h"
#include "black_record.h"
// black_record слепая запись
    void black_record(
        FILE *read_client_values,
        FILE *read_transfer_values,
        FILE *from_write,
        client client_data,
        client transfer) {
        while (

            fscanf(read_client_values, "%d%20s%20s%30s%15s%lf%lf%lf",
                  &client_data.client_number,
                  client_data.client_name,
                  client_data.client_surname,
                  client_data.client_addres,    // пока не встретил EOF (cntl + D)
                  client_data.client_tel_number,
                  &client_data.client_indebtedness,
                  &client_data.client_credit_limit,
                  &client_data.client_cash_payments) != -1 ) {
        while ( fscanf(read_transfer_values, "%d %lf",
                        &transfer.client_number,
                        &transfer.client_cash_payments) != -1 ) {
            if ( client_data.client_number == transfer.client_number && transfer.client_cash_payments != 0 ) {
                client_data.client_credit_limit += transfer.client_cash_payments;
            }
        }
        fprintf(from_write, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                client_data.client_number,
                client_data.client_name,
                client_data.client_surname,
                client_data.client_addres,   //  запись в  blackrecord
                client_data.client_tel_number,
                client_data.client_indebtedness,
                client_data.client_credit_limit,
                client_data.client_cash_payments);
        rewind(read_transfer_values);
    }
}
