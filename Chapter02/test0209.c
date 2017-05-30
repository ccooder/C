#include <stdio.h>

int main() {
    int n = 1;
    n = n & 0177;
    printf("%d\n", n);
    return 0;
}
