#include "../include/get_line.h"
#include <string.h>

char* get_line(const char *path_to_file) {

    int file_eml = open(path_to_file, O_RDONLY);

    if (file_eml == 0) {
        return NULL;
    }

    struct stat buf;
    char *one_line;

    fstat(file_eml, &buf);

    one_line = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, file_eml, 0);

    return one_line;
}