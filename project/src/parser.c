#include "../include/parser.h"


eml_t* parser(char * line, char *target) {

eml_t *mail = calloc(sizeof(eml_t), 1);

mail->mail_target = calloc(sizeof(char), 1);



    
if (strstr(line,target)) {

    char* from_begin = strstr(line,target);
    

    from_begin = from_begin + strlen(target);

    

    while(from_begin[0] == ' ') {
        from_begin++;
    }

    char *go_line = "";
    char *from_end ; 
   

    char *nextline_end;
    char *finish_value;
    char *from_end_itog = "";



    from_end = strchr(from_begin, '\n');

    while(!strstr(go_line, ":")) {

         char *nextline_start; 

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

         finish_value = strndup(from_begin, from_end - from_begin);
         if(finish_value ==NULL){
             free(mail);
             free(finish_value);
             return NULL;
         }
    } else {

        finish_value = strndup(from_begin, from_end_itog - from_begin);

          if(finish_value ==NULL){
            
             free(mail);
             free(finish_value);
             return NULL;
         }
    }
    

   mail->mail_target = finish_value;


}
        for(int i=0;mail->mail_target[i]!='\0';i++) {
            if(mail->mail_target[i]== '\n') {
            mail->mail_target[i] = ' ';
            }
  
        }

 
 return mail;
}

