#include <stdio.h>

int bitcount(unsigned);

int main() 
{

    unsigned x = 7;
    printf("x bitcount is %d.\n", bitcount(x));
    return 0;
}

int bitcount(unsigned x) {
    int bc = 0;
    for(;x != 0; x &= (x-1)) {
        bc++;
    }
    return bc;
}
