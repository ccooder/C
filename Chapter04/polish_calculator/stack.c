#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static double val[MAXVAL]; /*value stack*/
static int sp; /*next free position in value stack*/

double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

void push(double op)
{
    if (sp == MAXVAL)
        printf("Error: stack full, can't push %g\n", op);
    else
        val[sp++] = op;
}
