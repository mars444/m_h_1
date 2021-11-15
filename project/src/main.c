#include <stdio.h>
#include <stdlib.h>

#include "get_line.c"

#include "parser.c"
#include "get_boundary_value.c"
int main() {

  const char *path_to_eml = "1.eml";

  char* one_line = get_line(path_to_eml);

  char* ger = parser(one_line, CONTENT_TYPE);

  char *aaa = get_boundary_value(ger);




  return 0;
}