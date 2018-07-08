#include <stdio.h>
#include "fenglu.h"

int main(void)
{
    double x, y, t;
    x = 5.0;
    y = 2.0;
    dprint(x/y);
    swap(t, x, y);
    dprint(x / y);
    return 0;
}
