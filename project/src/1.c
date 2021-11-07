#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define _POSIX_C_SOUCRE 200809L

size_t strnlen(const char *str, size_t len)
{
    for (size_t size = 0; size < len; size++)
    {
        if (str[size] == '\0')
            return size;
    }
    return len;
}
char *strndup(const char *str, size_t len)
{
    size_t act = strnlen(str, len);
    char *dst = malloc(act + 1);
    if (dst != 0)
    {
        memmove(dst, str, act);
        dst[act] = '\0';
    }
    return dst;
}



char *search(void)
{
    char *istr = "";
    char *boudary_value_begin;
    char *boudary_value_end;
    char *string = "";
    FILE *ics;
    char lineq[150];

    ics = fopen("1.ics", "r");
    if (ics == NULL)
        return NULL;
    while (fgets(lineq, sizeof(lineq), ics) != NULL)
    {

    
        char *red = "boundary=";

        if (!strstr(lineq, red))
        {
            istr = strstr(lineq, red);
        }


        if (istr != NULL)
        {

            printf("istr   %s\n", istr);
          
            fclose(ics);

            //  с кавычками и без)
           
            printf("istr   %s", istr);
            char *boudary_value = istr + 9;
            printf("boudary_value   %s", boudary_value);
            if (boudary_value[0] == '"')
            {
              
                boudary_value_begin = istr + 10;
               
                boudary_value_end = strchr(boudary_value_begin, '"');
                printf("11\n");
            }
            else
            {
                boudary_value_begin = istr + 9;
                boudary_value_end = strchr(boudary_value_begin, '\n');
            }

            int a = boudary_value_end - boudary_value_begin + 1;
            char *asd = strndup(boudary_value_begin, a);

            printf("a = %d\n", a);

            printf(" итоговая строка  до  |||%s|||\n", asd);

            asd[a - 1] = '\n';

            printf("eto aa : %d\n", a);

            printf("boudary_value_beigin  |||%s|||\n", boudary_value_begin);

            printf("boudary_value_end  |||%s|||\n", boudary_value_end);

            printf(" итоговая строка   |||%s|||\n", asd);

            printf("boudary_value  |||%s|||\n", boudary_value);

            printf("aaaa %s\n", asd);
            string = asd;
        } else {
            string = NULL;
        }
    }
    
    return string;
}
