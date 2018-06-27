#include <stdio.h>

int bitcount(unsigned);
int bitlength(unsigned);

int main(int argc, char const* argv[])
{
    int x = -7;
    printf("bitcount: %d\n", bitcount(x));
    printf("bitlength: %d\n", bitlength(x));
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for (b=0; x; x >>= 1)
        if (x & 01)
            ++b;
    return b;
}

int bitlength(unsigned x)
{
    int b;
    for (b=0; x; x >>= 1)
        ++b;
    return b;
}
