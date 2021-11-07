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
    int count_lines = 0;
    eml_t *abcd;
    abcd = calloc(1, sizeof(eml_t));
    int a = 0, b = 0, c = 0;
    FILE *ics;
    char line[300];
    int i = 0;

    ics = fopen("1.ics", "r");
    if (ics == NULL)
    {
        free(abcd);
        return -1;
    }

    printf("2\n");
    char *red;
    printf("2\n");
    red = search();

    while (fgets(line, sizeof(line), ics) != NULL)
    {
        char *separator;
        char *key;
        char *tail;
        char *value;

        if (red != NULL)
        {
            if (!strstr(line, "boundary") && strstr(line, red))
            {
                i++;
            }
        }
        else
        {
            i = 1;
        }

        if ((tail = strchr(line, '\n')) != NULL)
        {
            *tail = '\0';
        }
        separator = strpbrk(line, ":");
        if (separator == NULL)
            continue;
        *separator = '\0';

        
        key = line;
        value = separator + 2;
        printf("tail:   %s  |||| value:  %s\n\n", line, value);

        if (a == 0)
        {
            if (!strcmp(key, "From"))
            {
                char *from_begin = value;
                char *from_end = strchr(from_begin, '\n');
                abcd->eml_from = strndup(from_begin, from_begin - from_end);
                a++;
            }
        }
        if (b == 0)
        {
            if (!strcmp(key, "To"))
            {
                char *to_begin = value;
                char *to_end = strchr(to_begin, '\n');
                abcd->eml_to = strndup(to_begin, to_begin - to_end);
                b++;
            }
        }
        if (c == 0)
        {
            if (!strcmp(key, "Date"))
            {
                char *date_begin = value;
                char *date_end = strchr(date_begin, '\n');
                abcd->eml_date = strndup(date_begin, date_begin - date_end);
                c++;
            }
        }
        count_lines++;
    }
    abcd->eml_parts = i;

    fclose(ics);

    printf("||%s | %s | %s | %d||\n", abcd->eml_from, abcd->eml_to, abcd->eml_date, abcd->eml_parts);
    free(abcd);
    return 0;
}
