#include <stdio.h>
#define TRUE    1 /*bool true*/
#define FALSE   0 /*bool false*/
#define MAXLINE 1000 /*maximum input line length*/

int my_getline(char[], int);
void copy(char[], char[]);
int is_leap_year(int);

int main(int argc, char const* argv[])
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("\n %s \n", longest);
    char str[] = "Hello, "
        " cccccccccc"
        "world";
    printf("%s \n", str);
    printf("%d\n", is_leap_year(2000));
    printf("%s\n", 2 % 1);
    printf("%s\n", 0);
    printf("%s\n", '\0');
    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int is_leap_year(int year)
{
    if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
        return TRUE;
    return FALSE;
}
