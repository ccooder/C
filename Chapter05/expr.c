#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXOP 100

double pop();
void push(double);

static double val[MAXVAL];
static int sp = 0;

int main(int argc, char const* argv[])
{
    double op;
    char const *p;
    char s[MAXOP];
    char flag;
    int i;
    while (--argc > 0) {
        p = *++argv;
        printf("%s\n", p);
        if (*p == '+' || *p == '-') {
            s[0] = *p;
            i = 1;
            if (*(p + 1) == '\0')
                flag = *p;
            else if (isdigit(*(p + 1))) {
                flag = '0';
                while (*++p) {
                    s[i++] = *p;
                }
            }
        }else {
            if (*p == '*' || *p == '/')
                flag = *p++;
            else if (!isdigit(*p) && *p != '.')
                continue;
            else {
                flag = '0';
                while (s[i++] = *p++);
            }
        }
        //s[i] = '\0';
        switch(flag) {
            case '0':
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
                printf("执行了除法运算");
                op = pop();
                if (op == 0)
                    printf("Error：zero divisor\n");
                else{
                    double result = pop() / op;
                    printf("%f\n", result);
                    push(result);
                }
                break;
            default:
                break;

        }
        s[0] = '\0';
        i = 0;
    }
    printf("sp=%d\n", sp);
    printf("result=%g\n", pop());

    printf("%g\n", -0 / 2);

    return 0;
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error:stack empty!\n");
        return 0.0;
    }
}

void push(double d)
{
    if (sp <= MAXVAL)
        val[sp++] = d;
    else
        printf("Error: full stack!\n");
}
