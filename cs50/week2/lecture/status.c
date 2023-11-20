#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    else
    {
        printf("hello, %s!\n", argv[1]);
        return 0;
    }
}