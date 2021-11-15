#include "../include/parser.h"      
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>




int parts_search(char * line, char *boundary) {

if (line == NULL || boundary == NULL){
    return 1;
}
int parts = 0;
char *boun_begin;

while (1) {
        boun_begin=strstr(line,boundary);
        if (boun_begin==NULL) {
            break;
        } 
        parts++;
        line=boun_begin+1;
    }

   

 return parts;
}

