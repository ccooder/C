#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100

static char buf[BUFSIZE]; /*buffer for un-read character*/
static int bufp; /*next free position in buffer*/

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > BUFSIZE)
        printf("%s\n", "[ungetch]Error:too many characters!");
    else
        buf[bufp++] = c;
}
