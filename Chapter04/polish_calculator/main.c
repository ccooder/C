#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

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
