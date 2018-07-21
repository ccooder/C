//
// Created by king on 7/19/18.
//
#include <dirent.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "apue/apue.h"

int main(int argc, char const* argv[])
{
    struct stat s_buf;
    char file_type;
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        err_quit("usage: ls directory_name");
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can’t open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL) {
        char file_path[200];
        bzero(file_path, 200);
        strncat(file_path, argv[1], strlen(argv[1]));
        strcat(file_path, "/");
        strcat(file_path, dirp->d_name);
        stat(file_path, &s_buf);
        if (S_ISDIR(s_buf.st_mode))
            file_type = 'd';
        if (S_ISREG(s_buf.st_mode))
            file_type = 'f';

        printf("%s's type is %c\n", dirp->d_name, file_type);

    }
    closedir(dp);
    return 0;
}
