#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *eml_from;
    char *eml_to;
    char *eml_date;
    int eml_parts;
    char *from;
    char *to;
} eml_t;

char *content_type_search(void)
{
    int count_lines = 0;
    eml_t *abcd;
    abcd = calloc(1000000, sizeof(eml_t));

    int a = 0, b = 0, c = 0;
    FILE *ics;
    char line[500];
    int i = 0;
    int wr = 0;
    char *itogo;

    ics = fopen("1.ics", "r");
    if (ics == NULL)
    {
        free(abcd);
        return NULL;
    }

    char *red;

    char *startline_from;
    char *startline_to;
    char *from_begin = "";
    char *to_begin = "";

    char **arr = arr_keys();
    int k = 0;
    while (fgets(line, sizeof(line), ics) != NULL)
    {

        if (abcd->from)
        {
            for (size_t i = 0; i < 20; i++)
            {

                if ((strstr(line, arr[i]) ||
                     line[0] == '\n'))
                {
                    k = 5;
                }
            }
            if (k == 5)
            {

                if (abcd->from)
                {

                    abcd->from[strlen(abcd->from) - 1] = '\0';
                }
                abcd->eml_from = abcd->from;

                abcd->from = NULL;
            }

                if (abcd->from)
                {

                    abcd->from = strcat(abcd->from, line);
                    abcd->from[strlen(abcd->from) - 1] = ' ';
                }
                k=0;
            
        }

        if (line[0] != ' ' || line[0] != '\t')
        {
            startline_from = strstr(line, "Content-Type:");
            if (startline_from != NULL && abcd->eml_from == NULL)
            {

                from_begin = startline_from + 13;
                int i = 0;
                while (from_begin[i] == ' ')
                {
                    from_begin = from_begin + 1;
                    i++;
                }
                char *from_end = strchr(from_begin, '\n');
                from_end[0] = ' ';
                printf("6\n");
                abcd->from = strndup(from_begin, from_begin - from_end);

                 printf("abcd->from -->>|||%s|||\n", abcd->from );
            }
        }
    }

    itogo = abcd->eml_from;
    fclose(ics);
    return itogo;
}
