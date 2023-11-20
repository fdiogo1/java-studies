#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) // with command-line argument -> argc, argv
{
    // a string ends with '\0' -> null character
    if(argc > 1)
    {
        if(strcmp(argv[1], "upper") == 0)
        {
            printf("argv[1] is %s\n", argv[2]);

            for(int i = 0, size = strlen(argv[2]); i < size; i++)
            {
                printf("%c", toupper(argv[2][i]));
            }
            puts("");
        }
        else if(strcmp(argv[1], "lower") == 0)
        {
            printf("argv[1] is %s\n", argv[2]);

            for(int i = 0, size = strlen(argv[2]); i < size; i++)
            {
                printf("%c", tolower(argv[2][i]));
            }
            puts("");
        }
        else puts("Not recognized.");
    }
    else puts("ERROR: ./notes <name>");
}