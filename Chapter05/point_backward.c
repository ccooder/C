#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int *pa = arr;
    printf("%d\n", pa[-2]);
    printf("%d\n", pa[2]);
    printf("%d\n", pa[1]);
    return 0;
}
