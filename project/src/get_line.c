#include "../include/get_line.h"
#include <string.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close


char *get_line( char *path_to_file) {

    if (path_to_file == NULL) {
        return NULL;
    }

    FILE *pFile;
    long size;

    pFile = fopen(path_to_file, "rb");

    if (!pFile)
        perror("Error opening file");
    else {
        fseek(pFile, 0, SEEK_END);
        size = ftell(pFile);
        fclose(pFile);
    }

    char *oneline;
    char *one_line;

    oneline = malloc(sizeof(char) * size);

    one_line = malloc(sizeof(char) * size);

    pFile = fopen(path_to_file, "r");
    
    if (pFile == NULL) {
        fclose(pFile);
        free(oneline);
        free(one_line);
        return NULL;
    }

    while (fgets(oneline, sizeof(oneline), pFile) != NULL) {

        strcat(one_line, oneline);
    }

    fclose(pFile);

    return one_line;
}