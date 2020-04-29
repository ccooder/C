#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void banana(void);

int main(void)
{
    int ret;
    ret = setjmp(buf);
    printf("setjmp=%d\n", ret);
    if (ret)
        printf("back in main.\n");
    else {
        printf("first time through\n");
        banana();
    }
    return 0;
}

void banana() {
    printf("in banana.\n");
    longjmp(buf, 'a');
    printf("You'll never see this, because i longjmped\n");
}
