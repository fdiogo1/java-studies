#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("i is %i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Prompt a negative integer: ");
    }
    while (n > 0);
    return n;
}