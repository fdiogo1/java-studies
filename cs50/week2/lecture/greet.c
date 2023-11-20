#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc > 1) printf("hello, %s!\n", argv[1]);
    else
    {
        puts("ERROR -> ./greet <your name>\n");
        exit(-1);
    }
}
