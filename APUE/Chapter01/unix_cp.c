//
// Created by king on 7/21/18.
//
#include "apue/apue.h"

#define BUFSIZE 4096

int main(int argc, char const* argv[])
{
    int n;
    char buf[BUFSIZE];
stdin
    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read_error");
    return 0;
}

