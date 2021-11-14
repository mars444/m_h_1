#include <stdio.h>
#include <stdlib.h>

#include "get_line.c"

int main() {

  const char *path_to_eml = "1.eml";

  char* one_line = get_line(path_to_eml);

  
  printf("%s\n", one_line);



  return 0;
}