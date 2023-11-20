#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int min = get_int("Enter the minimum: ");
    int max = get_int("Enter the maximum: ");
    int j;
    int result;

    for (int i = min; i <= max; i++)
    {
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j != 0)
            {
                printf("%i\n", i);
                break;
            }
        }
    }
}