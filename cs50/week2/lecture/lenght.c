#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What's your name? ");

    int n = strlen(name);

    printf("n is %ld\n", strlen(name));
}