#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char[]);
int my_getline(char[], unsigned);

int main(int argc, char const* argv[])
{
    char s[MAXLINE];
    while (my_getline(s, MAXLINE) > 0) {
        printf("%f \n", atof(s));
    }
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    int i, sign;
    double val, power;
    for (i = 0; isspace(s[i]); ++i);
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
}

int my_getline(char s[], unsigned lim)
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
