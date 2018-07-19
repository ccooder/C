//
// Created by king on 7/19/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    int size, i;
    char *dynamic;
    char input[10];
    printf("请输入动态数组的大小:");
    size = atoi(fgets(input, 7, stdin));
    dynamic = (char *) calloc((size_t) size, sizeof(char));
    for (i = 0; i < size-1; ++i) {
        *(dynamic+i) = (char) ('0' + i);
    }
    dynamic[size-1] = '\0';
    printf("dynamic size is %d\n", (int) strlen(dynamic));
    printf(dynamic);
    free(dynamic);
    dynamic = NULL;
    return 0;
}
