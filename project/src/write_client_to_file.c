#include "write_client_to_file.h"

int a = 0;
int write_about_client_to_file(FILE *filename, Data Client) {
    if ( scanf("%d%20s%20s%30s%15s%lf%lf%lf",
                 &Client.Number,
                 Client.Name,
                 Client.Surname,
                 Client.addres,
                 Client.TelNumber,
                 &Client.indebtedness,
                 &Client.credit_limit,
                 &Client.cash_payments) != -1 ) {
fprintf(filename, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",    // 12 11 выведет максимум
                Client.Number,
                Client.Name,
                Client.Surname,
                Client.addres,
                Client.TelNumber,
                Client.indebtedness,
                Client.credit_limit,
                Client.cash_payments);} else {
                    a = -1;
                }
                return 0;
}

////////////////////////////////////////////////////////////////////////////////////////

void masterWrite(FILE *ofPTR, Data Client) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
           "1 Number account: ",
           "2 Client name: ",
           "3 Surname: ",
           "4 Addres client: ",
           "5 Client Telnum: ",
           "6 Client indebtedness: ",
           "7 Client credit limit: ",
           "8 Client cash payments: ");

    while ( a != -1 ) {
  write_about_client_to_file(ofPTR, Client);
  printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
               "1 Number account: ",
               "2 Client name: ",
               "3 Surname: ",
               "4 Addres client: ",
               "5 Client Telnum: ",
               "6 Client indebtedness: ",
               "7 Client credit limit: ",
               "9 Client cash payments:");
    }
}
