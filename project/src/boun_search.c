

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "content_type_search.c"

char *boun_search(void)
{
    char *content = content_type_search();
    printf("content-->|||%s|||\n", content);

    char *boun;

    if (strstr(content, "boundary=\""))
    {
        char *y = strstr(content, "boundary=\"");

        boun = y + 8;
    }
    else if (strstr(content, "boundary="))
    {

        char *x = strstr(content, "boundary=");
        boun = x + 7;
    }
    else
    {

        return NULL;
    }
    boun[0] = '-';
    boun[1] = '-';

    if (boun[strlen(boun) - 1] == '"')
    {
        boun[strlen(boun) - 1] = '\n';
    }
    else
    {
        boun[strlen(boun)] = '\n';
    }

    printf("start-->%s\n", boun);

    return boun;
}