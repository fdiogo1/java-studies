#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node Node;

struct _node
{
    char phrase[25];
    Node *next;
};

Node *table[26];
int hash(char *phrase);
Node *load(char *);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./table <word>\n");
        exit(EXIT_FAILURE);
    }

    char phrase[25];
    strcpy(phrase, argv[1]);
    printf("'%s' hashes to %d\n", phrase, hash(phrase));
}

int hash(char *phrase)
{
    return (toupper(phrase[0]) - 'A');
}

Node *load(char *x)
{
    Node *new = (Node *) calloc(1, sizeof(Node));
    strcpy(new->phrase, x);
    new->next = NULL;
    return new;
}
