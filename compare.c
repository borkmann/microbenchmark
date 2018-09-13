#include "compare.h"

int
compare (BASKET **b1, BASKET **b2)
{
  if ((*b1)->abs_cost < (*b2)->abs_cost)
    return 1;
  if ((*b1)->abs_cost > (*b2)->abs_cost)
    return -1;
  if ((*b1)->a->id > (*b2)->a->id)
    return 1;
  else
    return -1;
}
