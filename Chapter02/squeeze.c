#include <stdio.h>

void squeeze(char[], int);

int main(int argc, char const* argv[])
{
    char s[] = "abcdeccdsddc";
    squeeze(s, 'c');
    printf("%s\n", s);
    return 0;
}

/* squeeze: delete all c from s*/
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
