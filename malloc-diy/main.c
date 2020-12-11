#include <stdio.h>
#include <stddef.h>
#include "memalloc.h"

int main() {
  int  *p=(int *)aloca(100*sizeof(int));
  int  *r=(int *)aloca(100*sizeof(int));
  int  *k=(int *)aloca(500*sizeof(int));
  char *q=(char *)aloca(250*sizeof(char));
  char *w=(char *)aloca(700);

  libera(p);
  libera(p);
  libera(r);
  libera(q);
}
