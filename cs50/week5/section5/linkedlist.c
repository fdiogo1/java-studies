#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list List;
typedef struct _node Node;

struct _list
{
    int size;
    Node *begin;
    Node *end;
};

struct _node
{
    char name[25];
    Node *next;
};

List *createList();
Node *createNode(char *);
void insertBegin(List *, char *);
void insertEnd(List *, char *);
bool isEmpty(const List *);
void visualize(const List *);
void unload(List **);

int main(void)
{
    List *myList = createList();
    addBegin(myList, "Diogo");
    addEnd(myList, "Raissa");
    addEnd(myList, "Tata");
    visualize(myList);
    unload(&myList);
}

List *createList()
{
    List *a = (List *) calloc(1, sizeof(List));
    a->size = 0;
    a->begin = NULL;
    a->end = NULL;
    return a;
}

Node *createNode(char *x)
{
    Node *n = (Node *) calloc(1, sizeof(Node));
    strcpy(n->name, x);
    n->next = NULL;
    return n;
}

bool isEmpty(const List *L)
{
    return L->begin == NULL;
}

void insertBegin(List *L, char *x)
{
    Node *new = createNode(x);
    if (isEmpty(L))
    {
        L->begin = L->end = new;
    }
    else
    {
        new->next = L->begin;
        L->begin = new;
    }

    L->size++;
}

void insertEnd(List *L, char *x)
{
    if (isEmpty(L))
        insertBegin(L, x);
    else
    {
        Node *new = createNode(x);
        L->end->next = new;
        L->end = new;
        L->size++;
    }
}

void visualize(const List *L)
{
    if (!isEmpty(L))
    {
        Node *p = L->begin;
        int controller = 1;
        while (p != NULL)
        {
            printf("Name [%d] = %s\n", controller, p->name);
            controller++;
            p = p->next;
        }
    }
    else
    {
        fprintf(stderr, "ERROR at 'printList': empty list\n");
        exit(EXIT_FAILURE);
    }
}

void unload(List **L_ref)
{
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux;

    while (p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }

    free(L);
    *L_ref = NULL;
}
