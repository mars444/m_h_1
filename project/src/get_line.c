#include "../include/get_line.h"
#include <string.h>

int get_line(const char *path_to_file) {

    int file_eml = open(path_to_file, O_RDONLY);

    if (file_eml == 0) {
        return -1;
    }

    struct stat buf;
    char *one_line;

    fstat(file_eml, &buf);

    one_line = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, file_eml, 0);
    printf("%s\n", one_line);

    char *a = strstr(one_line, "</HTML>");
    printf("%s\n", a);

    return 0;
}