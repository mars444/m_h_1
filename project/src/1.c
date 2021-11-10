#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *search(void)
{
    
    FILE *ics;
    int i = 0;

    char *boundary_final;

    ics = fopen("1.ics", "r");
    if (ics == NULL)
    {

        return NULL;
    }

   

       char * line = content_type_search();

        if (strstr(line, "boundary="))
        {
            char *start_boundary = strstr(line, "boundary=");

            char *boudary_begin = start_boundary + 9;
            if (boudary_begin[0] == '"')
            {

                boudary_begin++;
            }
            char *boudary_end = strchr(boudary_begin, '"');
            boudary_end[0] = '\n';
            boundary_final = strndup(boudary_begin, boudary_end - boudary_begin+1);
            printf("boundaty_begin :  |||%s|||\n", boudary_begin);
            printf("boundaty_end:  |||%s|||\n", boudary_end);

            printf("boundary final :  |||%s|||\n", boundary_final);

           
               
                 
            
        
    }

    return boundary_final;
}
