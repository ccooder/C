#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main() {
    int x, p, n, y;
    printf("%d\n", setbits(50, 4, 3, 6));
    for (x=0; x<=10000; ++x) {
        for (p=1; p<=7; ++p) {
            for (n=0; n<=p-1; ++n) {
                for (y=0; y<=100; ++y) {
                    printf("%d \n", setbits(x, p, n, y));
                }
            }
        }
    }
    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
    //return x | (~(~0 << n) << p);
    printf("x=%d;p=%d;n=%d;y=%d; %d-", x, p, n, y, x | (y << (p+1-n)));
    return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n));
}
