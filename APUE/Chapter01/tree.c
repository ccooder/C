//
// Created by king on 7/19/18.
//
#include <dirent.h>
#include <stdlib.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "apue/apue.h"

typedef struct files_tag {
    char *name;
    short is_dir;
    struct files_tag **children;
    int count;
} file;

void tree(DIR *dp, short level, char const *root_path, file *f);

void tree_print(file *root, int level, int *dc, int *fc);

void nfl_printf(char *buf, char *dname, int is_dir, int is_last);

int compare_file(file **f1, file **f2);

#define MAXFILE 4096

int main(int argc, char const *argv[]) {
    DIR *dp;
    if (argc != 2)
        err_quit("usage: tree directory_name");
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can’t open %s", argv[1]);
    printf("%s\n", argv[1]);
    file *f = (file *) malloc(sizeof(file));
    f->name = "root";
    f->is_dir = 1;
    tree(dp, 0, argv[1], f);
    int dc=0, fc=0;
    tree_print(f, 0, &dc, &fc);
    printf("\n%d directories, %d files\n", dc, fc);
    return 0;
}

void tree_print(file *root, int level, int *dc, int *fc) {
    int i, j;
    char buf[MAXLINE];
    if (root->children != NULL) {
        for (i = 0; i < root->count; ++i) {
            buf[0] = '\0';
            for (j = 0; j < level; ++j)
                snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, "%s    ", "┃");
            if ((*(root->children + i))->is_dir && root->count > 0) {
                (*dc)++;
                nfl_printf(buf, (*(root->children + i))->name, 1, (i+1) == root->count);
                tree_print(*(root->children + i), level + 1, dc, fc);
            } else {
                (*fc)++;
                nfl_printf(buf, (*(root->children + i))->name, 1, (i + 1) == root->count);
            }
        }
    }
}

void tree(DIR *dp, short level, char const *root_path, file *f) {
    struct stat s_buf;
    struct dirent *dirp;

    file **children = (file **) calloc(MAXFILE, sizeof(file));
    int count = 0;

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        char file_path[1024];
        file_path[0] = '\0';
        strncat(file_path, root_path, strlen(root_path));
        strncat(file_path, "/", strlen("/"));
        strncat(file_path, dirp->d_name, strlen(dirp->d_name));
        stat(file_path, &s_buf);
        if (S_ISDIR(s_buf.st_mode)) {
            DIR *temp_dp;
            if ((temp_dp = opendir(file_path)) != NULL) {
                file *dir_f = (file *) malloc(sizeof(file));
                dir_f->name = strndup(dirp->d_name, strlen(dirp->d_name));
                dir_f->is_dir = 1;
                children[count++] = dir_f;
                tree(temp_dp, (short) (level + 1), file_path, dir_f);
            }
        } else {
            file *reg_f = (file *) malloc(sizeof(file));
            reg_f->name = strndup(dirp->d_name, strlen(dirp->d_name));
            reg_f->is_dir = 0;
            reg_f->count = 0;
            children[count++] = reg_f;
        }
    }
    qsort(children, count, sizeof(*children), compare_file);
    f->children = children;
    f->count = count;
    closedir(dp);
}

int compare_file(file **f1, file **f2) {
    if ((*f1)->is_dir > (*f2)->is_dir) {
        return -1;
    } else if ((*f1)->is_dir == (*f2)->is_dir) {
        return strncmp((*f1)->name, (*f2)->name, strlen((*f1)->name));
    } else {
        return 1;
    }
}

void nfl_printf(char *buf, char *dname, int is_dir, int is_last) {
    char *tab = "┣━━";
    if (is_last)
        tab = "┗━━";
    snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, "%s %s\n", tab, dname);
    fputs(buf, stdout);
    fflush(NULL);
}