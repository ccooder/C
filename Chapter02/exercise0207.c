#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    printf("%d\n", invert(8, 1, 2));
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    return ~(x ^ (~((~(~0 << n)) << p)));
}
