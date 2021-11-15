#include "../include/parser.h"      
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>




int parts_search(char * line, char *boundary) {

int parts = 0;

if(!strstr(line, "multipart")) {
    parts = 1;
}

while(strstr(line, boundary)){

    parts++;

}

   

 return parts;
}

