#include <stdio.h>

int array[] = {23, 24, 46, 56, 204, 99, 28};

#define TOTAL_ELEMENTS (sizeof array / sizeof(array[0]))

int main(void)
{
    int d, x;
    d = -1;
    unsigned int ud = d;
    printf("%d\n", ud);
    if (d <= (int) TOTAL_ELEMENTS -2) {
        x = array[d+1];
        printf("%d\n", x);
    }else {
        printf("%s\n", "bug appeared!");
    }
    return 0;
}
