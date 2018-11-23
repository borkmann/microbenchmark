#include <stdio.h>
#include <x86intrin.h>

extern int foo (int);
extern int foo_no_table (int);

int global = 20;

#define LOOP 30000

int
main ()
{
  int i;
  unsigned long long start, end;
  unsigned long long diff;

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    foo_no_table (i);
  end = __rdtscp (&i);
  diff = end - start;

  printf ("no jump table: %lld\n", diff);

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    foo (i);
  end = __rdtscp (&i);
  diff = end - start;

  printf ("jump table   : %lld\n", diff);

  return 0;
}
