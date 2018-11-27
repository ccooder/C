//
// Created by king on 7/21/18.
//
#include "apue/apue.h"
int
main(void)
{
    int  c;
    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("output error");
    if (ferror(stdin))
        err_sys("input error");
    exit(0);
}

