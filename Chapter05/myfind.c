#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int my_getline(char *, unsigned);

int main(int argc, char const* argv[])
{
    int c, except=0, number=0, found = 0, lineno;
    char line[MAXLINE];
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch(c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option '%c'\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else {
        while (my_getline(line, MAXLINE) > 0) {
            ++lineno;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("ld:%d\n", lineno);
                found = 1;
            }
            printf("%s\n", line);
        }
        printf("%s\n", *argv);
        printf("argc=%d\n", argc);
        printf("except=%d\n", except);
        printf("number=%d\n", number);
    }

    return found;
}

int my_getline(char *s, unsigned lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        ++i;
    }
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}
