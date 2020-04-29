//
// Created by king on 7/17/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_HASH 100
#define MAXFILENAME 100

typedef struct file_tag {
    char *filename;
    struct file_tag *flink;
} File;

int hash_filename(char *);
File *find_filename(char *);
File *allocate_file(char *);

File *hash_table[FILE_HASH];

int main(int argc, char const* argv[])
{
    char filename[MAXFILENAME];
    char *prs;
    int count, a[10];
    count = 0;
    a[1] = 2;
    printf("%d", 1[a]);

    while ( (prs = fgets(filename, MAXFILENAME, stdin)) != NULL && *prs != '\n') {
        *(prs + strlen(prs) - 1) = '\0';
        File * f = find_filename(prs);
        //fputs(f->filename, stdout);
    }

    printf("\n散列表已经生成!请输入要查找的文件名:");
    prs = fgets(filename, MAXFILENAME, stdin);
    *(prs + strlen(prs) - 1) = '\0';
    File *fp = find_filename(prs);
    for (;fp != NULL;fp = fp->flink) {
        printf("fp->flink%d is %s\n", count, fp->filename);
        ++count;
    }

    return 0;
}

int hash_filename(char *filename)
{
    int hash_value, length;
    length = (int) strlen(filename);
    hash_value = (length + 4 * (filename[0] + filename[length/2])) % FILE_HASH;
    printf("%s 's hash_value is %d\n", filename, hash_value);
    return hash_value;
}

File *find_filename(char *filename)
{
    int hash_value = hash_filename(filename);
    File *f = NULL;
    for (f = hash_table[hash_value]; f != NULL; f = f->flink) {
        if (strcmp(f->filename, filename) == 0)
            return f;
    }
    f = allocate_file(filename);
    f->flink = hash_table[hash_value];
    hash_table[hash_value] = f;
    return f;
}

File *allocate_file(char *filename)
{
    File *f = (File *)malloc(sizeof (File));
    f->filename = strdup(filename);
    f->flink = NULL;
    return f;
}