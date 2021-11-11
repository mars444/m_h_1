#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *keys_arr[50];

char **arr_keys(void)
{

    FILE *eml_file;
    char line[500];

    eml_file = fopen("1.ics", "r");
    if (eml_file == NULL) {
        return NULL;
    }

    int i = 0;

    while (fgets(line, sizeof(line), eml_file) != NULL) {

        char *key;
        char *tail;
        char *separator;

        if (line[0] == '\t' || line[0] == ' ') {
            continue;

        } else if (line[0] == '\n') {
            break;
        } else {

            if ((tail = strchr(line, '\n')) != NULL) {
                *tail = '\0';
            }

            separator = strpbrk(line, ":");

            if (separator == NULL) {
                continue;
            }
                
            *separator = '\0';
            key = line;
            char *a = strndup(key, strlen(key));
            strcat(a, ":");
            keys_arr[i] = a;
       
        }

        i++;
    }

    fclose(eml_file);
    return keys_arr;
}
