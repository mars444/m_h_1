#include "black_record.h"
void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer) {
    while ( fscanf(ofPTR, "%d%20s%20s%30s%15s%lf%lf%lf",
                  &client_data.Number,
                  client_data.Name,
                  client_data.Surname,
                  client_data.addres,
                  client_data.TelNumber,
                  &client_data.indebtedness,
                  &client_data.credit_limit,
                  &client_data.cash_payments) != -1 ) {
        while ( fscanf(ofPTR_2, "%d %lf", &transfer.Number, &transfer.cash_payments) != -1 ) {
            if (client_data.Number == transfer.Number && transfer.cash_payments != 0) {
                client_data.credit_limit += transfer.cash_payments;
            }
        }
        fprintf(blackrecord, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                client_data.Number,
                client_data.Name,
                client_data.Surname,
                client_data.addres,
                client_data.TelNumber,
                client_data.indebtedness,
                client_data.credit_limit,
                client_data.cash_payments);
        rewind(ofPTR_2);
    }
}
