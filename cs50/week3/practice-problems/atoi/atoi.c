#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(int argc, char **argv)
{
    // string input = NULL;

    // strcpy(argv[1], input);

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(argv[1]));
}

int convert(string input)
{
    if (strlen(input) < 1)
    {
        return 0;
    }
    int lastIndex = strlen(input) - 1;
    int lastChar = input[lastIndex] - '0';
    input[strlen(input) - 1] = '\0';
    return lastChar + 10 * convert(input);
}