#include <stdio.h>
#include <time.h>
#include <limits.h>

int main(void)
{
    time_t biggest = 0x7FFFFFFF;
    printf("biggest = %s\n", asctime(gmtime(&biggest)));
    float b =.3;
    printf("%f\n", b);
    printf("The biggest int is %d\n", INT_MAX);
    return 0;
}
