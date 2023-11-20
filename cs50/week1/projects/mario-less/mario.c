#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //variaveis
    int height, row, column, spaces;
    //loop pra não aceitar números indevidos
    do
    {
        height = get_int("Size: ");
    }
    while (height < 1 || height > 8);

    //inicio
    for (row = 0; row < height; row++)
    {
        for (spaces = 0; spaces < height - row - 1; spaces++)
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");

    }

}