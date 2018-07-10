#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define MAXVA 100

void miniprinf(char *, ...);

struct utype {
    unsigned int is_string : 1;
    unsigned int is_integer : 1;
    unsigned int is_float : 1;
};

typedef struct {
    struct utype ut;
    union {
        int ival;
        double dval;
        char *sval;
    } val;
} av;

int main(void)
{
    miniprinf("%d %s\n", 3, "123");
    return 0;
}

void miniprinf(char *fmt, ...)
{
    va_list ap;
    char *p;
    int lim;
    av *av_list[MAXVA];
    av *aval;
    char c[2];
    va_start(ap, fmt);
    for (p = fmt, lim = 0; *p && lim < MAXVA; ++p) {
        if (*p != '%') {
            aval = (av *) malloc(sizeof(av));
//                struct utype flags2;
            struct utype flags;
            flags.is_integer = flags.is_float = 0;
            flags.is_string = 1;
            aval->ut = flags;
            c[0] = *p;
            c[1] = '\0';
            aval->val.sval = strdup(c);
            av_list[lim++] = aval;
            continue;
        }
        switch (*++p) {
            case 'd':
                aval = (av *) malloc(sizeof(av));
                struct utype flags;
                flags.is_float = flags.is_string = 0;
                flags.is_integer = 1;
                aval->ut = flags;
                aval->val.ival = va_arg(ap, int);
                av_list[lim++] = aval;
                break;
            case 'f':
                aval = (av *) malloc(sizeof(av));
                //struct utype flags;
                flags.is_integer = flags.is_string = 0;
                flags.is_float = 1;
                aval->ut = flags;
                aval->val.dval = va_arg(ap, double);
                av_list[lim++] = aval;
                break;
            case 's':
                aval = (av *) malloc(sizeof(av));
//                struct utype flags2;
                flags.is_integer = flags.is_float = 0;
                flags.is_string = 1;
                aval->ut = flags;
                aval->val.sval = va_arg(ap, char*);
                av_list[lim++] = aval;
                break;
            default:
                break;
        }
    }

    av **pal = av_list;
    for (lim -= 1; lim >= 0; --lim, ++pal) {
        if ((*pal)->ut.is_integer == 1)
            printf("%d", (*pal)->val.ival);
        else if ((*pal)->ut.is_float == 1)
            printf("%f", (*pal)->val.dval);
        else if ((*pal)->ut.is_string == 1)
            printf("%s", (*pal)->val.sval);

    }

    va_end(ap);

}
