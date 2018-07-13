#include <stdio.h>

int main(void)
{
    int x, y, z;
    x = 1;
    y = 1;
    z = (x++)+(++y);
    //z = x+(++y);
    printf("%d\n", z);
    return 0;
}
