#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size1, size2; //tamanhos
    int years = 0, born, die;
    // TODO: Prompt for start size
    do
    {
        size1 = get_int("Start size: ");
    }
    while (size1 < 9);
    // TODO: Prompt for end size
    do
    {
        size2 = get_int("End size: ");
    }
    while (size2 < size1);
    // TODO: Calculate number of years until we reach threshold
    while (size1 < size2)
    {
        size1 += (size1 / 3) - (size1 / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
