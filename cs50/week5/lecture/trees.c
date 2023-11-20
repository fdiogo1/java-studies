#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node node;

struct _node
{
    int number;
    node *left;
    node *right;
};

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else return true;

}