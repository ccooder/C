#include <stdio.h>

void printd(int);

int main(void)
{
    printd(-10);
    return 0;
}

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
