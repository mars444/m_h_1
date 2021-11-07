#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* search(void)
{
    char *istr;
    char *boudary_value_begin;
    char *boudary_value_end;
    char *string;
    FILE *ics;
    char  lineq[150];

    ics = fopen("1.ics", "r");
    if (ics == NULL)
        return NULL;
    while (fgets(lineq, sizeof(lineq), ics) != NULL)
    {
        
        printf("3\n");
        char *red = "boundary=";
        
          if (!strstr(lineq, red)){}
            istr = strstr(lineq, red);

            if (istr != NULL) {



        printf("istr   %s\n", istr);
        printf("7\n");
        fclose(ics);


    //  с кавычками и без)
    printf("8\n");
    printf("istr   %s", istr);
    char *boudary_value = istr + 9;
    printf("boudary_value   %s", boudary_value);
    if (boudary_value[0] == '"') {
        printf("9\n");
        boudary_value_begin = istr + 10;
        printf("10\n");
        boudary_value_end = strchr(boudary_value_begin, '"');
        printf("11\n");
    } else {
        boudary_value_begin = istr + 9;
        boudary_value_end = strchr(boudary_value_begin, '\n');
    }
   
    int a = boudary_value_end - boudary_value_begin + 1;
    char *asd = strndup(boudary_value_begin, a);

    printf("a = %d\n", a);

    printf(" итоговая строка  до  |||%s|||\n",asd);

    asd[a-1] = '\n';

    printf("eto aa : %d\n", a);

printf("boudary_value_beigin  |||%s|||\n", boudary_value_begin);

printf("boudary_value_end  |||%s|||\n", boudary_value_end);

printf(" итоговая строка   |||%s|||\n",asd);


printf("boudary_value  |||%s|||\n", boudary_value);

string = asd;
   

            }

      
}
 return string;
}


