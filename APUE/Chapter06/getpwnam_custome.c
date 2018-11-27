//
// Created by king on 7/25/18.
//
#include "apue/apue.h"
#include <pwd.h>

struct passwd *my_getpwnam(char *name);

int main(int argc, char const* argv[])
{
    struct passwd *ptr;
    if ((ptr = my_getpwnam("iii")) != NULL)
        printf("%d\n", my_getpwnam("iii")->pw_gid);
    else
        printf("User Not Found");
    return 0;
}

struct passwd *my_getpwnam(char *name)
{
    struct passwd *ptr;
    while ((ptr = getpwent()) != NULL)
        if (strncmp(ptr->pw_name, name, strlen(name)) == 0)
            break;
    endpwent();
    return ptr;
}