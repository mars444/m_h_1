#include "../include/free_eml_t.h"
#include "../include/parser.h"

#include <stdio.h>

void letter_print(eml_t *mail) {
    printf("%s|%s|%s|%d\n",
           mail->mail_from,
           mail->mail_to,
           mail->mail_date,
           mail->mail_parts);
}