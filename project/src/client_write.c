#include "main.h"
#include "client_write.h"
#include "write_to_file_from_flow.h"
#include "print_client_fields.h"

void client_write(FILE *out, client client, int stop_write) {
      print_client_fields();

      while (stop_write != -1) {
            stop_write = write_to_file_from_flow(out, client);

            print_client_fields();
      }
}
