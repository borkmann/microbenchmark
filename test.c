#include <stdio.h>
#include <x86intrin.h>

extern int testb (int, int, int, int);
extern int testw (int, int, int, int);
extern int testl (int, int, int, int);
extern int testq (int, int, int, int);

#define LOOP 3000

int
main ()
{
  int i;
  unsigned long long start, end;
  unsigned long long diff;

  start = __rdtsc ();
  for (i = 0; i < LOOP; i++)
    testb (i, i - 30, i + 4, i - 3);
  end = __rdtsc ();
  diff = end - start;

  printf ("testb  : %lld\n", diff);

  start = __rdtsc ();
  for (i = 0; i < LOOP; i++)
    testw (i, i - 30, i + 4, i - 3);
  end = __rdtsc ();
  diff = end - start;

  printf ("testw  : %lld\n", diff);

  start = __rdtsc ();
  for (i = 0; i < LOOP; i++)
    testl (i, i - 30, i + 4, i - 3);
  end = __rdtsc ();
  diff = end - start;

  printf ("testl  : %lld\n", diff);

  start = __rdtsc ();
  for (i = 0; i < LOOP; i++)
    testq (i, i - 30, i + 4, i - 3);
  end = __rdtsc ();
  diff = end - start;

  printf ("testq  : %lld\n", diff);

  return 0;
}
