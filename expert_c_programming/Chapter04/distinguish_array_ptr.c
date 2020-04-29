#include <stdio.h>

//extern char *p;

int main(void)
{
    char *p = "abcdef";
    *p = 'b';
    printf("%c\n", *p);
    return 0;
}
