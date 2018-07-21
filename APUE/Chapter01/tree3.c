//
// Created by king on 7/19/18.
//
#include <dirent.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "apue/apue.h"

typedef struct files_tag {
    char *name;
    int is_dir;
    struct files_tag **children;
    int count;
} file;

int compare_file(file **f1, file **f2) {
    if ((*f1)->is_dir > (*f2)->is_dir) {
        return -1;
    } else if ((*f1)->is_dir == (*f2)->is_dir) {
        return strncmp((*f1)->name, (*f2)->name, strlen((*f1)->name));
    } else {
        return 1;
    }
    //return strncmp(f1->name, f2->name, strlen(f1->name));
}

void compare_fil() {
    file *f = (file *)malloc(sizeof(file));
    f->name = "test";
    f->is_dir = 1;
    f->count = 3;
    file **children = (file **) calloc(3, sizeof(file));

    file *f1 = (file *)malloc(sizeof(file));
    f1->is_dir = 0;
    f1->name = "wotshimingzi";
    f1->count = 0;
    f1->children = NULL;
    *(children + 0) = f1;

    file *f2 = (file *)malloc(sizeof(file));
    f2->is_dir = 1;
    f2->name = "twoshimingzi2";
    f2->count = 0;
    f2->children = NULL;
    *(children + 1) = f2;

    file *f3 = (file *)malloc(sizeof(file));
    f3->is_dir = 0;
    f3->name = "woshimingzi2";
    f3->count = 0;
    f3->children = NULL;
    *(children + 2) = f3;

    qsort(children, 3, sizeof(*(children)), compare_file);

    for (int i=0; i<f->count; ++i)
        printf("%s ", (*(children + i))->name);
    printf("\n");

    f->children = children;
}

int compare_int(const int **i1, const int **i2)
{
    printf("%d\n", **i1 - **i2);
    return **i1 - **i2;
}

void compare_in() {
    int **ppi = (int **)calloc(3, sizeof(int));
    int a=23, b=3, c=45;
    *(ppi+0) = &a;
    *(ppi+1) = &b;
    *(ppi+2) = &c;

    qsort(ppi, 3, sizeof(ppi+0), compare_int);

    for (int i = 0; i < 3; ++i) {
        printf("%d ", *(*(ppi + i)));
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    compare_fil();
    return 0;
}
