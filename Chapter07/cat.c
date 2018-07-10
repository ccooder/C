#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char const* argv[])
{
    FILE *fp;
    if (argc == 1)
        filecopy(stdin, stdout);
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) != NULL) {
                filecopy(fp, stdout);
                fclose(fp);
            }else {
                printf("Can't open %s\n", *argv);
            }
        }
    }
    return 0;
}

void filecopy(FILE *ipf, FILE *opf)
{
    int c;
    while ((c = getc(ipf)) != EOF)
        putc(c, opf);
}
