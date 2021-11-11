#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int parts_count(char *boundary)
{
    FILE *eml_file;
    char line[500];
    eml_file = fopen("1.ics", "r");
    if (eml_file == NULL)
    {
        return -1;
    }

    int i = 0;
    int j = 0;
    while (fgets(line, sizeof(line), eml_file) != NULL)
    {
        if (boundary != NULL)
        {
            if (strstr(line, boundary))
            {

                i++;
            }
        }
    }

    if (i == 0)
    {
        i = 666;
    }

    fclose(eml_file);

    return i;
}
