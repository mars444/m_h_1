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
    char *date;
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
    char *startline_date;

  
    char *date_begin = "";

    while (fgets(line, sizeof(line), ics) != NULL)
    {


         startline_date = strstr(line, "Date:");

        if (startline_date != NULL && startline_date[-1] == '\0' )
        {

            date_begin = startline_date + 5;
            int i = 0;
            while (date_begin[i] == ' ')
            {
                date_begin = date_begin + 1;
                i++;
            }
            char *date_end = strchr(date_begin, '\n');
            date_end[0] = ' ';

        

            abcd->date = strndup(date_begin, date_begin - date_end);
          
        }


        if (abcd->date && abcd->eml_date == NULL)
        {
            if (strstr(line, "Subject:") ||
                strstr(line, "From:") ||
                strstr(line, "X-Mailer:") ||
                strstr(line, "To:") ||
                strstr(line, "Content-Type:") ||
                strstr(line, "Date:") ||
                strstr(line, "Message-ID:") ||
                strstr(line, "Mime-Version:") ||
                strstr(line, "Delivered-To:"))

            {


                if (abcd->date)
            {
                
                abcd->date[strlen(abcd->date)-1] = '\0';
            }
                abcd->eml_date = abcd->date;
                printf("line itog :  |||%s|||\n", abcd->eml_date);

                abcd->date = NULL;
            }
            if (abcd->date)
            {
                abcd->date = strcat(abcd->date, line);
                abcd->date[strlen(abcd->date)-1] = ' ';
            }
        }

       
    }

    
    free(abcd);
    return 0;
}
