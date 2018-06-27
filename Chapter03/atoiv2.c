#include <stdio.h>
#include <ctype.h>

int atoi(char[]);

int main(int argc, char const* argv[])
{
    char s[] = "  +123a45";
    printf("%d\n", atoi(s));
    return 0;
}

/*atoi v2: convert s to integer */
int atoi(char s[])
{
    int i, sign, n;
    for (i=0; isspace(s[i]); ++i);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (n = 0; isdigit(s[i]); ++i)
        n = n*10 + (s[i] - '0');

    return n;
}
