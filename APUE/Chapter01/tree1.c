//
// Created by king on 7/19/18.
//
#include <dirent.h>
#include <stdlib.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "apue/apue.h"

void tree(DIR * dp, short level, char const* root_path);
void nfl_printf(char *buf, char *dname, int is_dir, int is_last);

typedef struct files_tag {
    char *name;
    int is_dir;
    struct files_tag *children;
} file;

int main(int argc, char const* argv[])
{
    struct stat s_buf;
    char file_type;
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        err_quit("usage: tree directory_name");
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can’t open %s", argv[1]);
    printf("%s\n", argv[1]);
    tree(dp, 0, argv[1]);
    return 0;
}

void tree(DIR *dp, short level, char const* root_path) {
    struct stat s_buf;
    struct dirent *dirp;
    char buf[MAXLINE];

    //首先计算当前文件夹下的最后一个文件的名字

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        buf[0] = '\0';
        int i;
        for (i = 0; i < level; ++i)
            snprintf(buf+strlen(buf), MAXLINE - strlen(buf) - 1, "%s    ", "┃");

        char file_path[1024];
        file_path[0] = '\0';
        strncat(file_path, root_path, strlen(root_path));
        strncat(file_path, "/", strlen("/"));
        strncat(file_path, dirp->d_name, strlen(dirp->d_name));
        stat(file_path, &s_buf);
        if (S_ISDIR(s_buf.st_mode)) {
            DIR *temp_dp;
            if ((temp_dp = opendir(file_path)) != NULL) {
                nfl_printf(buf, dirp->d_name, 1, 0);
                tree(temp_dp, (short)(level + 1), file_path);
            }
        }else {
            nfl_printf(buf, dirp->d_name, 0, 0);
        }
    }
    closedir(dp);
}

void nfl_printf(char *buf, char *dname, int is_dir, int is_last)
{
    char *tab = "┣━━";
    if (is_last)
        tab = "┗━━";
    snprintf(buf+strlen(buf), MAXLINE- strlen(buf) - 1, "%s %s\n", tab, dname);
    fputs(buf, stdout);
    fflush(NULL);
}
