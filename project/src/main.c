#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "to_searchqqq.c"
#include "parts_count.c"
#include "boun_search.c"


int main()
{
  char *to = "To:";
  char *from = "From:";
  char *date = "Date:";
  char *content = "Content-Type:";

  char *fromt = to_search(to);
  printf("From: |||%s|||\n", fromt);


  return 0;
}
