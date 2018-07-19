//
// Created by king on 7/17/18.
//
#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>
#include <setjmp.h>
#include <zconf.h>

jmp_buf buf;

void sighandler(int);
void jump(void);

int main(void)
{
    signal(SIGINT, sighandler);
    int ret;
    ret = setjmp(buf);
    printf("ret=%d\n", ret);
    if (ret) {
        printf("111\n");
        signal(SIGINT, sighandler);
    } else {
        printf("first through\n");
        jump();
    }
    while(1);
    return 0;
}

void sighandler(int sig)
{
    char c;
    printf("Hitted Ctrl+C! Really want to quit?[y/n]:");
    c = (char) getc(stdin);
    if (c == 'y')
        exit(1);
    else {
        c = (char) getc(stdin);
        longjmp(buf, 1);
    }

}

void jump()
{
    longjmp(buf, 1);
}
