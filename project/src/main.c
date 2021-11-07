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

    char *boudary;
    boudary  = search();

    FILE *ics;
    char line[300];
    int i = 0;

    ics = fopen("1.ics", "r");
    if (ics == NULL)
    {

        return -1;
    }

    while (fgets(line, sizeof(line), ics) != NULL)
    {

        printf("line :  |||%s|||\n", line);

           
                if (  boudary!= NULL)
                {

     

                    if ( !strstr(line, "boundary=") &&strstr(line, boudary))
                    {
                        i++;
                    }
                }
                else
                {
                    i = 666;
                }
            
        printf("i itog :  |||%d|||\n", i);
    }


    printf("i itog :  |||%d|||\n", i);

    return 0;
}

