#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node node;

struct _node
{
    char phrase[200];
    node *next;
};

node *newNode(string);
void destroyNode (node **a);

int main(void)
{
    node *a = newNode("Diogo");
    printf("a == NULL? %d\n", a == NULL);
    printf("Name: %s\n", a->phrase);
    destroyNode(&a);
    printf("a == NULL? %d\n", a == NULL);
}

node* newNode(char *p)
{
    node *b = (node*) calloc(1, sizeof(node));
    strcpy(b->phrase, p);
    b->next = NULL;

    return b;
}

void destroyNode (node **a)
{
    node *temp = *a;
    free(temp);
    *a = NULL;
}