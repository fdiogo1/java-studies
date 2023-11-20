#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Insira o tamanho desejado:\n>> ");

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}