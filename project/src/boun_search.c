

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *boun_search(char *key)
{
    
  

    char *boun;

    if (strstr(key, "boundary=\""))
    {
        char *y = strstr(key, "boundary=\"");

        boun = y + 8;
    }
    else if (strstr(key, "boundary="))
    {

        char *x = strstr(key, "boundary=");
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

   

    return boun;
}