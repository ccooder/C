#include <stdio.h>
#include <string.h>

int htoi(char s[]);
int power(int, int);

int main() {
    char str[] = "0x20A";
    printf("%d\n", htoi(str));
    return 0;
}

int power(int n, int p) {
    printf("power:\nn=%d,p=%d.\n", n, p);
    int base = 1;
    if(p < 0) {
        return 0;
    }else if(p == 0){
        base = 1;
    }else if(p == 1) {
        base =  16;
    }else{
        for(int i=0; i<p; i++) {
           base *= 16;
        }
    }
    return n*base;

}

int htoi(char s[]) {
    char s0 = s[0];
    char s1 = s[1];
    int sLength = strlen(s);
    printf("s length is %d.\n", sLength);
    int i = 0;
    int n = 0;
    if(s0 == '0') {
        if(s1 == 'x' || s1 == 'X') {
            i = 2;
        }else {
            return 0;
        }
    }
    printf("i=%d.\n", i);
    for(;i < sLength;i++){
        int si = 0;
        if(s[i] >= '0' && s[i] <= '9') {
            si = s[i] - '0';
        }else if(s[i] >= 'a' && s[i] <= 'f') {
            si = s[i] - 'a' + 10;
        }else if(s[i] >= 'A' && s[i] <= 'F') {
            si = s[i] - 'A' + 10;
        }else{
            return 0;
        }
        printf("si=%d.\n", si);
        n = n+power(si, sLength-i-1);
    }
    return n;
}
