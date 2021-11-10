#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "boun_search.c"

int main()
{
    FILE *ics;
    char line[700];
    ics = fopen("1.ics", "r");
    if (ics == NULL)
    {
        return -1;
    }

    char *bounq = boun_search();
    printf("eto bounq-->|||%s|||\n", bounq);
    int i = 0;
    int j = 0;
    while (fgets(line, sizeof(line), ics) != NULL)
    {
        if (bounq != NULL)
        {

            if (strstr(line, bounq))
            {

                i++;
            }
        }
    }

    if (i == 0)
    {
        i = 666;
    }

    printf("i--> %d\n", i);
    fclose(ics);

    return 0;
}
