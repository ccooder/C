#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c, sign;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    if (c == '-') {
        if (!isdigit((sign = getch()))) {
            ungetch(sign);
            return c;
        }else {
            i = 0;
            c = sign;
            s[++i] = sign;
        }
    }else {
        i = 0;
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;

}
