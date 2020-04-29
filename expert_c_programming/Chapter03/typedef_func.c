#include <stdio.h>

typedef void (*ptr_to_func)(int);
ptr_to_func signal(int, ptr_to_func);
void printi(int);

int main(void)
{
    ptr_to_func fun;
    fun = signal(9, &printi);
    fun(2);

    return 0;
}

void printi(int i)
{
    printf("printi:i=%d\n", i);
}

ptr_to_func signal(int s, ptr_to_func callback)
{
    printf("signal=%d\n", s);
    return callback;
}
