#include <stdio.h>

#define HASHSIZE 101

unsigned int hash(char *);

int main(void)
{
    char *s = "fenglu";
    printf("%d\n", hash(s));
    return 0;
}

unsigned int hash(char *s)
{
    unsigned int hashvalue;
    for (hashvalue = 0; *s != '\0'; ++s)
        hashvalue = *s + 31 * hashvalue;
    return hashvalue % HASHSIZE;
}
