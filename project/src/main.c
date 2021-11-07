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
    char *from;
    char *to;
} eml_t;

typedef struct
{
    char *from;
} temp_t;

int main(void)
{
    int count_lines = 0;
    eml_t *abcd;
    temp_t *vrem;
    abcd = calloc(1, sizeof(eml_t));
    vrem = calloc(1, sizeof(temp_t));
    int a = 0, b = 0, c = 0;
    FILE *ics;
    char line[300];
    int i = 0;
    int wr = 0;

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
    char *startline_from;
    char *startline_to;
    char *from_begin = "";
    char *to_begin = "";

    while (fgets(line, sizeof(line), ics) != NULL)
    {

        if (abcd->from)
        {
            if (strstr(line, "Subject:") ||
                strstr(line, "From:") ||
                strstr(line, "X-Mailer:") ||
                strstr(line, "To:") ||
                strstr(line, "Content-Type:") ||
                strstr(line, "Date:") ||
                strstr(line, "Message-ID:") ||
                strstr(line, "Mime-Version:") ||
                strstr(line, "Received:"))
            {

                abcd->eml_from = abcd->from;

                abcd->from = NULL;
            }
            if (abcd->from)
            {
                abcd->from = strcat(abcd->from, line);
                abcd->from[strlen(abcd->from) - 1] = '\0';
            }
        }

        startline_from = strstr(line, "From:");

        if (startline_from != NULL)
        {

            from_begin = startline_from + 5;
            int i = 0;
            while (from_begin[i] == ' ')
            {
                from_begin = from_begin + 1;
                i++;
            }
            char *from_end = strchr(from_begin, '\n');
            from_end[0] = ' ';

            abcd->from = strndup(from_begin, from_begin - from_end);
        }
    }

    printf("line itog :  |||%s|||\n", abcd->eml_from);
    free(abcd);
    return 0;
}
