#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "keys_writing.c"
#include "content_type_search.c"

int main(void)
{
    char* abc = content_type_search();

   

    printf("wau-->>|||%s|||\n", abc);
  
return 0;
}


