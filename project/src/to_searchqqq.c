#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keys_writing.c"

typedef struct {
    char *eml_from;
    char *from;
} eml_t;
char *to_search(char *key) {
    if (key == NULL) {
        return NULL;
    }

    int step = strlen(key);
   


    int count_lines = 0;
    eml_t *mail;
    mail = calloc(1, sizeof(eml_t));

    FILE *eml_file;
    char line[5000];
    char *itogo;

    eml_file = fopen("1.ics", "r");
    if (eml_file == NULL) {
        free(mail);
        return NULL;
    }

    char *startline_from;
    char *startline_to;
    char *from_begin = "";
    char *to_begin = "";

    char **arr = arr_keys();



    int k = 0;
    while (fgets(line, sizeof(line), eml_file) != NULL) {

        if (mail->from) {
            for (size_t i = 0; arr[i] != NULL; i++) {

                if (
                    (strstr(line, arr[i]) ||
                    (line[0] == '\n' &&
                    line[0]==key[0]) &&
                    line[1]==key[1])) {
                        
                    k = 5;
                }
            }
            if (k == 5) {

                if (mail->from) {

                    mail->from[strlen(mail->from) - 1] = '\0';
                }
                mail->eml_from = mail->from;

                mail->from = NULL;
            }

                if (mail->from) {

                    mail->from = strcat(mail->from, line);
                    mail->from[strlen(mail->from) - 1] = ' ';
                }

                k=0; 
        }
        

        if ((line[0] != ' ') && (line[0] != '\t') && (line[0]==key[0]) && (line[1]==key[1])) {

            printf("line--->%d\n", line[0]);
            printf("key--->%d\n", key[0]);

            
            startline_from = strstr(line, key);

            if (startline_from != NULL && mail->eml_from == NULL) {

                from_begin = startline_from + step;
                int i = 0;

                while (from_begin[i] == ' ') {
                    from_begin = from_begin + 1;
                    i++;
                }

                char *from_end = strchr(from_begin, '\n');
                from_end[0] = ' ';
                mail->from = strndup(from_begin, from_begin - from_end);
            }
        }
    }

    itogo = mail->eml_from;


    fclose(eml_file);
    return itogo;
}
