//
// Created by king on 7/25/18.
//
#include "apue/apue.h"
#include <shadow.h>
#include <time.h>
#include <sys/utsname.h>
#include <sys/time.h>
#include <locale.h>
#include <limits.h>

int main(int argc, char const* argv[]) {
//    struct spwd *ptr = getspnam("king");
//    printf("%s\n", ptr->sp_pwdp);
//    printf("%ld\n", ptr->sp_inact);
    struct utsname utsname1;
    if (uname(&utsname1) != -1) {
        printf("%s %s %s %s %s\n", utsname1.sysname, utsname1.nodename, utsname1.release, utsname1.version, utsname1.machine);
    }
    struct tm pltm;
    struct tm ptm;
    struct tm *ptm1;
    struct tm *ptm2;
    char buf[16];
    char buf1[64];
    time_t t;
    time_t *ptr = &t;
    if (time(ptr) != -1) {
        //setlocal
        setlocale(LC_ALL, "");
//        printf("Locale is %s \n", setlocale(LC_TIME, "zh_CN.UTF-8"));

        // Get broken-down time
        ptm1 = localtime(ptr);
//        ptm2 = gmtime(ptr);

        printf("%#d\n", ptm1);
//        printf("%#d\n", ptm2);

        localtime_r(ptr, &pltm);
        gmtime_r(ptr, &ptm);

        //fmt
//        printf("%s%+ld\n", ptm2->__tm_zone, ptm2->__tm_gmtoff / 60 / 60);
//        if (strftime(buf1, 64, "time and date: %r, %a %b %d, %Y", ptm2) == 0)
//            printf("buffer length 16 is too small.\n");
//        else
//            printf("%s\n", buf1);

        printf("%s%+ld\n", ptm1->__tm_zone, ptm1->__tm_gmtoff / 60 / 60);
        if (strftime(buf1, 64, "time and date: %T, %a %b %d, %Y", ptm1) == 0)
            printf("buffer length 16 is too small.\n");
        else
            printf("%s\n", buf1);

        printf("%s%+ld\n", pltm.__tm_zone, pltm.__tm_gmtoff / 60 / 60);
        if (strftime(buf1, 64, "time and date: %r, %a %b %d, %Y", &pltm) == 0)
            printf("buffer length 16 is too small.\n");
        else
            printf("%s\n", buf1);


        printf("%s%+ld\n", ptm.__tm_zone, ptm.__tm_gmtoff);
        if (strftime(buf1, 64, "time and date: %r, %a %b %d, %Y", &ptm) == 0)
            printf("buffer length 64 is too small.\n");
        else
            printf("%s\n", buf1);

        printf("%s", NULL);

        fprintf(stdout, "%s", NULL);
    }
    return 0;
}
