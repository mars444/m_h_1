
#include "../include/get_line.h"
#include "../include/parser.h"
#include "../include/get_boundary_value.h"
#include "../include/parts_search.h"
#include "../include/free_eml_t.h"

int main(int argc, char **argv){

    if (argc != 2) {
        return -1;
    }

    char *path_to_eml = argv[1];

    char *one_line = get_line(path_to_eml);

    eml_t *from = parser(one_line, FROM);
    printf("%s|", from->mail_target);
    free_eml_t(from);

    eml_t *to = parser(one_line, TO);
    printf("%s|", to->mail_target);
    free_eml_t(to);

    eml_t *date = parser(one_line, DATE);
    printf("%s|", date->mail_target);
    free_eml_t(date);

    eml_t *content = parser(one_line, CONTENT_TYPE);

    char *boundary = get_boundary_value(content->mail_target);

    int parts = parts_search(one_line, boundary);

    printf("%d\n", parts);

    free_eml_t(content);

    return 0;
}