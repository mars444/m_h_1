#define _GNU_SOURCE  
#include "../include/parser.h"      
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#define FROM    "\nFrom:"
#define TO      "\nTo:"
#define DATE    "\nDate:"

#define CONTENT_TYPE        "\nContent-Type:"
#define BOUNDARY            "boundary="



char* parser(char * line, char *target) {

char *mail_from;

if (strstr(line,target)) {

    char* from_begin = strstr(line,target);
    

    from_begin = from_begin + strlen(target);

    while(from_begin[0] == ' ') {
        from_begin++;
    }

    char *go_line = "";
    char *from_end; 
    char *nextline_start; 

    char *nextline_end;

    char *from_end_itog;
    from_end = strchr(from_begin, '\n');

    while(!strstr(go_line, ":")) {

        nextline_start = from_end + 1;
        nextline_end = strchr(nextline_start, '\n');
        go_line = strndup(nextline_start, nextline_end - nextline_start);
        from_end_itog = from_end;
        from_end = nextline_end;

        if(nextline_start[0] == '\n') {
            break;
        }
        
    }

    if(go_line[0] == '\t' || go_line[0] == ' '){

        mail_from = strndup(from_begin, from_end - from_begin);
    } else {

        mail_from = strndup(from_begin, from_end_itog - from_begin);
    }

   

}
        for(int i=0;mail_from[i]!='\0';i++) {
            if(mail_from[i]== '\n') {
            mail_from[i] = ' ';
            }
  
        }
    

 return mail_from;
}

