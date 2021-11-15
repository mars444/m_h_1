#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/parser.h"
char *get_boundary_value(char *key) {
    
  

    char *boun;

    if (strstr(key, BOUNDARY)) {
        char *y = strstr(key, BOUNDARY);

        boun = y + 7;
         if ((y[0] = '"')) {

            boun++;
        }
    }
   
    
    else {

        return NULL;
    }

    boun[0] = '-';
    boun[1] = '-';

    if (boun[strlen(boun) - 1] == '"') {

        boun[strlen(boun) - 1] = '\n';

    } else {
        boun[strlen(boun)] = '\n';
    }

    return boun;
}