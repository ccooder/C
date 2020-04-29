//
// Created by king on 7/19/18.
//
#include <stdio.h>

void func(int[2][3][5]);
void func1(int[][3][5]);
void func2(int (*)[3][5]);
void func3(int (***));

void func4(int **);

int main(int argc, char const* argv[])
{
    int apricot[2][3][5];
    int (*r0)[3][5] = apricot;
    int (*r)[5] = &apricot[0][0]; //equals below
    int (*r1)[5] = apricot[0];

    int *t = apricot[0][0];

    int (*t1)[2][3][5] = &apricot;

    printf("%#x\n", apricot);
    printf("%#x\n", &apricot);

    printf("r0's address: %#x\n", r0);
    printf("r's address: %#x\n", r);
    printf("r1's address: %#x\n", r1);
    printf("t's address: %#x\n\n", t);
    // after offset + 1
    printf("r0's address: %#x\n", ++r0);
    printf("r's address: %#x\n", ++r);
    printf("r1's address: %#x\n", ++r1);
    printf("t's address: %#x\n", ++t);

    /*func(apricot);
    func1(apricot);
    func2(apricot);

    func(r0);
    func1(r0);
    func2(r0);*/

//    func(*t1);
//    func1(*t1);
//    func2(*t1);
//    func3(*t1);
    char *ca[2] = {
            {"ha"},
            {"h3"},
    };

    char **ia = ca;
    printf("%c\n", ia[0][0]);
    printf("%c\n", *(*(ia+1)+1));
    func4(ia);

    return 0;
}

void func(int fruit[2][3][5])
{
//    printf("%#x\n", ++fruit);
}

void func1(int fruit[][3][5])
{
//    printf("%#x\n", ++fruit);
}

void func2(int (*fruit)[3][5])
{
//    printf("%#x\n", ++fruit);
}

void func3(int ***pa)
{
    printf("%#x\n", *(**pa + 1));
}

void func4(int **pi)
{
    printf("%#x\n", *(*(pi+1) + 1));
}