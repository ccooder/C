//
// Created by king on 7/17/18.
//
#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>
#include <zconf.h>

void INThandler(int);

int  main(void)
{
    signal(SIGINT, INThandler);
    while (1)
        pause();
    return 0;
}

void  INThandler(int sig)
{
    char  c;
    printf("OUCH, did you hit Ctrl-C?\n"
           "Do you really want to quit? [y/n] ");
    c = (char) getc(stdin);
    if (c == 'y' || c == 'Y')
        exit(0);
    c = (char) getc(stdin);//需要把换行符接收以免影响后续期望结果
}
