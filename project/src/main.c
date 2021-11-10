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
    char line[500];
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
   
    char *startline_from;
    char *startline_to;
    char *from_begin = "";
    char *to_begin = "";
    printf("3\n");
    while (fgets(line, sizeof(line), ics) != NULL)
    {
printf("4\n");
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
                strstr(line, "Received:") || 
                line[0] == '\n')
            {


                if (abcd->from)
            {
                
                abcd->from[strlen(abcd->from)-1] = '\0';
            }
                abcd->eml_from = abcd->from;

                abcd->from = NULL;
            }
            if (abcd->from)
            {
                abcd->from = strcat(abcd->from, line);
                abcd->from[strlen(abcd->from)-1] = ' ';
            }
        }

        startline_from = strstr(line, "From:");

        if (startline_from != NULL && abcd->eml_from == NULL)
        {

            from_begin = startline_from + 3;
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
             printf("line itog :  |||%s|||\n", abcd->eml_from);
             printf("7\n");
        }
    }

   printf("line itog :  |||%s|||\n", abcd->eml_from);
    free(abcd);
    return 0;
}
