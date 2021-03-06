#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NKEYS (sizeof keytab / sizeof (struct key))
#define MAXWORD 100
#define BUFSIZE 100

struct key {
    char *word;
    unsigned int count;
};

struct key1 {
    long double word;
    unsigned int count;
};

struct key keytab[] = {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0
};

int getword(char *, int);

struct key *binsearch(char *, struct key *, int);

static char buf[BUFSIZE]; /*buffer for un-read character*/
static int bufp; /*next free position in buffer*/

int main(void) {
    char word[MAXWORD];
    struct key *pk;
    while (getword(word, MAXWORD) != EOF) {
        if ((pk = binsearch(word, &keytab[0], NKEYS)) != NULL)
            ++pk->count;
    }
    for (pk = keytab; pk < keytab + NKEYS; ++pk)
//    while (pk++ < keytab + NKEYS)
        if (pk->count > 0)
            printf("%4d %s\n", pk->count, pk->word);

    /*printf("%d\n", sizeof (struct key1));
    printf("%d\n", sizeof (double));
    printf("%d\n", sizeof (double));
    printf("%d\n", sizeof (double));*/
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n) {
    struct key *low, *high, *mid;
    int cond;
    low = tab;
    high = tab + n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()));
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void) {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp > BUFSIZE)
        printf("%s\n", "[ungetch]Error:too many characters!");
    else
        buf[bufp++] = c;
}
