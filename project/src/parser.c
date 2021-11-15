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

    
    // если строка начинается  с табами или пробелом
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


} else {
 mail->mail_target = NULL;

}
        // замена переводов строки на пробел

        for(int i=0;mail->mail_target[i]!='\0';i++) {


            if(mail->mail_target[i]== '\n') {
            mail->mail_target[i] = ' ';
            }
  
        }

 
           
       
        // замена нескольких пробелов на 1

        for (size_t i = 0; i < strlen(mail->mail_target); i++) {

            char a,b;
            a = mail->mail_target[i];
            b = mail->mail_target[i+1];

            if (a == ' ' && b == ' ') {

                if (mail->mail_target[i + 1] == '\0'){

                    mail->mail_target[i] = '\0';
                    
                } else {               
                    size_t s = strlen(mail->mail_target + i + 1);
                    memmove(mail->mail_target + i, mail->mail_target + i + 1, s+1);
                    --i;
                }
            }
        }
    

    return mail;
}

