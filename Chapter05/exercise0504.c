#include <stdio.h>

int strend(char *, char *);

int main(void)
{
    char *s = "abcdef";
    char *t = "def";
    printf("%d\n",strend(s, t));
    return 0;
}

int strend(char *s, char *t)
{
    char *pt;
    for (pt = t;*s != '\0'; ++s)
        if (*pt != '\0' && *s == *pt)
            ++pt;
        else
            pt = t;
    if (*s == '\0' && *pt == '\0')
        return 1;
    return 0;
}
