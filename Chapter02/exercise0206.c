#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main() {
    printf("%d\n", setbits(4, 3, 2, 1));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
    return x | (~(~0 << n) << p);
}
