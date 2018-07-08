#include <stdio.h>

void reverse(char[], int, int);

int main(void)
{
    int i;
    char s[] = "!dlrow olleh";

    for (i=0; s[i] != '\0'; ++i);
    printf("字符串长度是%d\n", i);
    reverse(s, 0, i-1);
    printf("%s\n", s);
    return 0;
}
void reverse(char s[], int left, int right)
{
    int temp;
    if (left < right) {
        reverse(s, left+1, right-1);
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}
