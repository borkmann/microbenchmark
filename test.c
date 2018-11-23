#include <stdio.h>
#include <x86intrin.h>
#include "compare.h"

extern int compare (BASKET **b1, BASKET **b2);
extern int compare_nop (BASKET **b1, BASKET **b2);

#define LOOP 30000

struct arc arc1 = { 30 };
struct arc arc2 = { 40 };
BASKET b1 = { &arc1, 40 };
BASKET b2 = { &arc2, 80 };

int
main ()
{
  int i;
  unsigned long long start, end;
  unsigned long long diff;
  BASKET *p1 = &b1;
  BASKET *p2 = &b2;

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    compare (&p1, &p2);
  end = __rdtscp (&i);
  diff = end - start;

  printf ("compare    : %lld\n", diff);

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    compare_nop (&p1, &p2);
  end = __rdtscp (&i);
  diff = end - start;

  printf ("compare_nop: %lld\n", diff);

  return 0;
}
