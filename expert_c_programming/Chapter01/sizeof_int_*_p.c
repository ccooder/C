#include <stdio.h>

int main(void)
{
    double d, *p;
    int apple;
    d = 2.2;
    p = &d;
    printf("%g\n", *p);
    apple = sizeof ((int) *p);
    printf("apple=%d\n", apple);
    return 0;
}
