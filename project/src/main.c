#include <stdio.h>
#include <stdlib.h>

#include "get_line.c"

#include "parser.c"

int main() {

  const char *path_to_eml = "1.eml";

  char* one_line = get_line(path_to_eml);

  parser(one_line, DATE);


  return 0;
}