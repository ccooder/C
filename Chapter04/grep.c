#include <stdio.h>

#define MAXLINE 1000

int my_getline(char[], unsigned);
int strindex(char[], char[]);
int rstrindex(char[], char[]);

int main(int argc, char const* argv[])
{
    char s[MAXLINE];
    char t[] = "ould";
    int len, found;
    found = 0;
    while ((len = my_getline(s, MAXLINE)) > 0)
        if (rstrindex(s, t) != -1) {
            printf("%s\n", s);
            ++found;
        }
    return 0;
}

int my_getline(char s[], unsigned lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    int sl;
    int l_count = 0;
    for (sl=0; s[sl] != '\0'; ++sl);
    printf("s的长度是：%d\n", sl);
    for (i = 0; s[i] != '\0'; ++i) {
        printf("i=%d, j=%d \n", i, j);
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; ++j, ++k){
           ++l_count;
        }
        if (k >0 && t[k] == '\0') {
            printf("循环了%d次\n", l_count);
            return i;
        }
    }
    printf("未查找到结果循环了%d次.\n", l_count);
    return -1;
}

int rstrindex(char s[], char t[])
{
    int i, j, k, sl, tl;
    for (sl=0; s[sl] != '\0'; ++sl);
    for (tl=0; t[tl] != '\0'; ++tl);

    for(i=sl-1; i>0; --i) {
        for (j=i, k=tl-1; s[j] == t[k] && j >= 0 && k >= 0; --j, --k)
            ;
        if (k == 0)
            return i+1-tl;
    }
    return -1;
}
