#include <stdio.h>
#include <stdlib.h>

#include "get_line.c"

#include "parser.c"
#include "get_boundary_value.c"
#include "parts_search.c"

int main() {

  const char *path_to_eml = "1.eml";

  char* one_line = get_line(path_to_eml);

  char* from = parser(one_line, FROM);
  char* to = parser(one_line, TO);
  char* date = parser(one_line, DATE);
  char* content = parser(one_line, CONTENT_TYPE);


  printf("From-->|||%s|||\nto-->|||%s|||\nDate-->|||%s|||\nContent-->|||%s|||\n",from, to, date, content);

  char *boundary = get_boundary_value(content);


  int parts = parts_search(one_line,boundary);

printf("Parts-->|||%d|||\n" ,parts);


  return 0;
}