// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        puts("Usage: ./no-vowels word");
    }
    else
    {
        for (int i = 0, size = strlen(argv[1]); i < size; i++)
        {
            if (argv[1][i] == 'a') printf("4");
            else if (argv[1][i] == 'e') printf("3");
            else if (argv[1][i] == 'i') printf("1");
            else if (argv[1][i] == 'o') printf("0");
            else printf("%c", argv[1][i]);
        }
        puts("");
    }
}
