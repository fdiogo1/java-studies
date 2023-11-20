#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;

struct _node
{
    int number;
    node *next;
};

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]); // ascii to integer
        node *n = calloc(1, sizeof(node)); // allocating

        if (n == NULL)
        {
            return 1; // if the memory isn't enough
        }

        n->number = number;
        n->next = list;

        list = n;
    }

    node *ptr = list;


    while (ptr != NULL) // printing and deallocating
    {
        node *aux = ptr;
        printf("%d\n", ptr->number);
        ptr = ptr->next;
        free(aux);
    }

    list = NULL;

}