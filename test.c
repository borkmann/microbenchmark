#include <stdio.h>
#include <x86intrin.h>

extern int foo (int);
extern int foo_no_table (int);
extern int foo_no_retpol (int);

int global = 20;

#define LOOP 800000000

int
main ()
{
  int i;
  unsigned long long start, end;
  unsigned long long diff1, diff2, diff3;

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    foo_no_retpol (i);
  end = __rdtscp (&i);
  diff1 = end - start;
  printf ("no retpoline : %15lld\n", diff1);

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    foo_no_table (i);
  end = __rdtscp (&i);
  diff2 = end - start;
  printf ("no jump table: %15lld (no retpoline: %.2f%%)\n", diff2, 100.0f * diff2 / diff1);

  start = __rdtscp (&i);
  for (i = 0; i < LOOP; i++)
    foo (i);
  end = __rdtscp (&i);
  diff3 = end - start;
  printf ("jump table   : %15lld (no retpoline: %.2f%%, no jump table: %.2f%%)\n", diff3, 100.0f * diff3 / diff1, 100.0f * diff3 / diff2);

  return 0;
}
