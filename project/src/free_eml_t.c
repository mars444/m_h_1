#include "../include/free_eml_t.h"
#include "../include/parser.h"

void free_eml_t(eml_t *mail) {
    free(mail->mail_from);
    free(mail->mail_to);
    free(mail->mail_date);
    free(mail);
}