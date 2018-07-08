#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define SIZE 100

int getint(int*);

int main()
{
    int array[SIZE], n;
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n)
        ;

    for (n=0; n < SIZE; ++n)
        printf("%d ", array[n]);
    return 0;
}

int getint(int *pn)
{
    int c, sign;
    //首先还是过滤掉空格
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
