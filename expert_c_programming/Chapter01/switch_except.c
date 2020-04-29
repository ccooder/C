#include <stdio.h>

int main(void)
{
    int a;
    printf("请输入一个整数:");
    scanf("%d", &a);
    const int two = 2;
    switch (a) {
        case 1:
            printf("case 1\n");
            //break;
        case 2:
            printf("case 2\n");
            //break;
        case 3:
            printf("case 3\n");
            //break;
        default:
            printf("default\n");
            //break;
    }
    return 0;
}
