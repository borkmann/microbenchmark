typedef long long cost_t;

struct arc
{
  int id;
};

typedef struct basket
{
    struct arc *a;
    cost_t abs_cost;
} BASKET;

extern int compare(BASKET **, BASKET **);
