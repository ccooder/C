//
// Created by king on 7/21/18.
//
#include "apue/apue.h"

int main(int argc, char const* argv[])
{
    fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(*argv);
    return 0;
}