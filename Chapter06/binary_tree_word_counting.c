#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode {
    char *word;
    unsigned count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);

struct tnode *talloc();

struct tnode *addtree(struct tnode *, char *);

char *my_strdup(char *);

void treeprint(struct tnode *);

int c, getch(void);

void ungetch(int);

static char buf[BUFSIZE]; /*buffer for un-read character*/
static int bufp; /*next free position in buffer*/

int main(int argc, char const *argv[])
{
    printf("%d\n", strcmp("otuog", "auto"));
    char word[MAXWORD];
    struct tnode *root;
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc()
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
struct tnode *addtree(struct tnode *root, char *w)
{
    int cond;
    if (root == NULL) {
        root = talloc();
        root->word = my_strdup(w);
        root->count++;
        root->left = root->right = NULL;
    } else if ((cond = strcmp(w, root->word)) == 0) {
        root->count++;
    } else if (cond > 0) {
        root->right = addtree(root->right, w);
    } else {
        root->left = addtree(root->left, w);
    }
    return root;
}

char *my_strdup(char *s)
{
    char *p;
/* make a duplicate of s */
    p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}


void treeprint(struct tnode *root)
{
    if (root != NULL) {
        treeprint(root->left);
        printf("%4d %s\n", root->count, root->word);
        treeprint(root->right);
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
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

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > BUFSIZE)
        printf("%s\n", "[ungetch]Error:too many characters!");
    else
        buf[bufp++] = c;
}
