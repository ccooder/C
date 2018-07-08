#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop();

char buf[BUFSIZE]; /*buffer for un-read character*/
int bufp = 0; /*next free position in buffer*/

double val[MAXVAL]; /* value stack */
int sp = 0; /* next free position for value stack*/

int main(void)
{
    char s[MAXOP];
    double op;
    int type;
    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op = pop();
            push(pop() - op);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op = pop();
            if (op != 0.0)
                push(pop() / op);
            else
                printf("Error: zero divisor\n");
            break;
        case '%':
            op = pop();
            if (op != 0.0)
                push((int) pop() % (int) op);
            else
                printf("Error: zero divisor\n");
        case '\n':
            printf("%.8g\n", pop());
            break;
        default:
            printf("Error:unknown operator %c\n", type);
            break;
        }
    }
    return 0;
}

int getop(char s[])
{
    int i, c, sign;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    if (c == '-') {
        if (!isdigit((sign = getch()))) {
            ungetch(sign);
            return c;
        }else {
            i = 0;
            c = sign;
            s[++i] = sign;
        }
    }else {
        i = 0;
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;

}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

void push(double op)
{
    if (sp == MAXVAL)
        printf("Error: stack full, can't push %g\n", op);
    else
        val[sp++] = op;
}

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > BUFSIZE)
        printf("%s\n", "[ungetch]Error:too many characters!");
    else
        buf[bufp++] = c;
}
