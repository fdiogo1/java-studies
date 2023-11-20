#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[8];

    // Create array to store plate numbers
    char *plates = (char*) calloc(7, sizeof(char));

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    if (infile == NULL)
    {
        puts("No such file found.");
        fclose(infile);
        return 1;
    }

    for (int i = 0; i < 8; i++)
    {
        fscanf(infile, " %[^\n]s", plates);
        printf("%s\n", plates);
    }

    free(plates);
    plates = NULL;
    fclose(infile);
}
