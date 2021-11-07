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

int main(void)
{
    int count_lines = 0;
    eml_t *abcd;
    abcd = calloc(1000000, sizeof(eml_t));
   
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
    char *startline_to;

  
    char *to_begin = "";

    while (fgets(line, sizeof(line), ics) != NULL)
    {

        if (abcd->to)
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


                if (abcd->to)
            {
                
                abcd->to[strlen(abcd->to)-1] = '\0';
            }
                abcd->eml_to = abcd->to;

                abcd->to = NULL;
            }
            if (abcd->to)
            {
                abcd->to = strcat(abcd->to, line);
                abcd->to[strlen(abcd->to)-1] = ' ';
            }
        }

        startline_to = strstr(line, "To:");

        if (startline_to != NULL)
        {

            to_begin = startline_to + 5;
            int i = 0;
            while (to_begin[i] == ' ')
            {
                to_begin = to_begin + 1;
                i++;
            }
            char *to_end = strchr(to_begin, '\n');
            to_end[0] = ' ';

            abcd->to = strndup(to_begin, to_begin - to_end);
        }
    }

    printf("line itog :  |||%s|||\n", abcd->eml_to);
    free(abcd);
    return 0;
}
