#include <stdio.h>

void strcpy(char*, char*);

int main(void)
{
    char s[20], *t;
    t = "I am a string";
    strcpy(s, t);
    printf("%s \n", s);
    return 0;
}

/*str copy version1:use array indices*/
/*void strcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        ++i;
}*/

/*str copy version2: use pointer*/
/*void strcpy(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        ++s;
        ++t;
    }
}*/

/*str copy final abbriviation version */
void strcpy(char *s, char *t)
{
    while (*s++ = *t++);
}
