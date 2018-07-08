#include <stdio.h>

int main(int argc, char const* argv[])
{
    /* 1st version, array subscipt.
    int i;
    for (i = 1; i < argc; ++i)
        printf("%s%s", argv[i], argc-1 > i ? " " : "");
    printf("\n");
    return 0;
    */

    /*2nd version: pointers*/
    while (--argc > 0)
        printf(argc > 1 ? "%s " : "%s", *++argv);
        //printf("%s%s", *++argv, argc > 1 ? " " : "");
    printf("\n");
}
