#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, row, column, spaces;
    do
    {
        height = get_int("Size: ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++)
    {
        for (spaces = 0; spaces < height - row - 1; spaces++)
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf ("#");
        }
        printf("\n");

    }

}