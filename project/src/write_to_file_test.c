#include "write_to_file_test.h"
int write_to_file(FILE *filename, Data Client) {
fprintf(filename, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",    // 12 11 выведет максимум
                Client.Number,
                Client.Name,
                Client.Surname,
                Client.addres,
                Client.TelNumber,
                Client.indebtedness,
                Client.credit_limit,
                Client.cash_payments);
                return 0;
}
