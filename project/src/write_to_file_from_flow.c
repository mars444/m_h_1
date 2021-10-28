#include "main.h"
#include "write_to_file_from_flow.h"
#include "write_to_file.h"
   int a;
int write_to_file_from_flow(FILE *filename, Data Client) {
if ( scanf("%d%20s%20s%30s%15s%lf%lf%lf",
                 &Client.Number,
                 Client.Name,
                 Client.Surname,
                 Client.addres,
                 Client.TelNumber,
                 &Client.indebtedness,
                 &Client.credit_limit,
                 &Client.cash_payments) != -1) {
        write_to_file(filename, Client);
                  } else {
                        a = -1;
                        return a;
                    }
    return 0;
}
