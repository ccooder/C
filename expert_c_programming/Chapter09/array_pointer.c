//
// Created by king on 7/18/18.
//
#include <stdio.h>

void printCa(char []);
void printPa(char *);

int main(int argc, char const* argv[])
{
    char ca[10] = "hello";
    int ia[10] = {1, 2, 3};
    printf("%d\n", sizeof ca / sizeof (ca[0]));
    printPa(ca);
    return 0;
}

void printCa(char ca[])
{
    printf("%d\n", &ca);
    printf("%d\n", &ca[0]);
    printf("%d\n", &ca[1]);
}

void printPa(char *pa)
{
    printf("%d\n", &pa);
    printf("%d\n", &(pa[0]));
    printf("%d\n", &(pa[1]));
    printf("%d\n", ++pa);
}
