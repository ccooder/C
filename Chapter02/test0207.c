#include <stdio.h>

int atoi(char s[]);

int main() {
    printf("%d\n", atoi("1a3"));
    return 0;
}

int atoi(char s[]) {
    int n = 0;
    for(int i=0; s[i] > '0' && s[i] < '9'; i++) {
        n = n*10 + (s[i] - '0');
    }
    return n;
}
