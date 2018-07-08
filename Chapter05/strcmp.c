#include <stdio.h>

int strcmp(char*, char*);

int main(void)
{
    char *s = "I am a String";
    char *t = "I am a String";
    printf("%d \n", strcmp(s, t));
    return 0;
}

/*Array subscript version*/
/*int strcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; ++i)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}*/

/*str compare: pointer version*/
int strcmp(char *s, char *t)
{

    for (;*s++ == *t++;)
        if (*(s-1) == '\0')
            return 0;
    return *--s - *--t;
}
