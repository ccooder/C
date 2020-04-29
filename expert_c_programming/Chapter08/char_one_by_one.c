//
// Created by king on 7/17/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int kbhit(void);

int main(int argc, char const* argv[])
{
    /*int c;
    system("stty raw");
    getc(stdin)
    printf("\n%c", c);
    system("stty cooked");
    return 0;*/
    int i = 0;
    int c = 0;
    system("stty raw -echo");
    printf("enter 'q' to quit \n");
    for (;c!='q';i++) {
        if (kbhit()) {
            c=getchar();
            printf("\n got %c, on iteration %d",c, i);
        }
    }
    system("stty cooked echo");
}

int kbhit()
{
    int i;
    ioctl(0, FIONREAD, &i);
    return i;
}