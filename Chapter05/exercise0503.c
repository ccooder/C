#include <stdio.h>

void strcat(char*, char*);

int main(void)
{
    char s[10] = "abc";
    char *t = "def";
    printf("%s\n", s);
    strcat(s, t);
    printf("%s\n", s);
    return 0;
}

void strcat(char *s, char *t)
{
    while (*s != '\0')
        ++s;
    while ((*s++ = *t++) != '\0');
}
