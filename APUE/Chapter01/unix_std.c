//
// Created by king on 7/21/18.
//
#include "apue/apue.h"

int main(int argc, char const* argv[])
{
    printf("pid:%ld\n", (long) getpid());
    printf("uid:%ld\n", (long) getuid());
    printf("gid:%ld\n", (long) getgid());
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        fprintf(stderr, "%s\n", "Can't seek");
    else
        fprintf(stdout, "%s\n", "Seek OK!");
    return 0;
}

