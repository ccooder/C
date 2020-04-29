#include <stdio.h>
#include <string.h>

#define DUMPCOPY for (i = 0; i < 65536; ++i) \
                          destination[i] = source[i]

#define SMARTCOPY memcpy(destination, source, 65536)

#define BUFSIZE 1024

int main()
{
    int i, j, pos_source;
    FILE *stream;
    char buf[BUFSIZE], *prs, c, source[65536], destination[65536];
    stream = fopen("/home/king/C&C++/C/handouts/C_Knowledge_Point.md", "r");
    pos_source = 0;
    while ((prs = fgets(buf, BUFSIZE, stream)) != NULL) {
        while ((c = *prs++) != '\0') {
            source[pos_source++] = c;
            source[pos_source++] = c;
            source[pos_source++] = c;
            source[pos_source++] = c;
        }
    }
    printf("%s", source);
    printf("%d\n",strlen(source));
    //for(j = 0; j < 100; ++j)
    SMARTCOPY;
    //DUMPCOPY;
    return 0;
}
