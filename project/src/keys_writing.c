#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "1.c"

typedef struct
{
    char *eml_from;
    char *eml_to;
    char *eml_date;
    int eml_parts;
} eml_t;

int main(void)
{

    eml_t *abcd;
    abcd = calloc(1, sizeof(eml_t));

    FILE *ics;
    char line[300];

    char *keys_arr[50];

    ics = fopen("1.ics", "r");
    if (ics == NULL)
    {
        free(abcd);
        return -1;
    }

    char *red;

    red = search();
    int i = 0;

    while (fgets(line, sizeof(line), ics) != NULL)
    {

        char *key;
        char *tail;
        char *separator;

        if (line[0] == ' ')
        {
            continue;
        }
        else if (line[0] == '\n')
        {
            break;
        }
        else
        {

            if ((tail = strchr(line, '\n')) != NULL)
            {
                *tail = '\0';
            }
            separator = strpbrk(line, ":");
            if (separator == NULL)
                continue;
            *separator = '\0';

            key = line;

            char *a = strndup(key, strlen(key));

            keys_arr[i] = a;

          
        }

       

        i++;
    }

    for (size_t i = 0; i < 10; i++)
    {
         printf ("keys arr ==  %s\n", keys_arr[i]);
    }
    

    return 0;
}
