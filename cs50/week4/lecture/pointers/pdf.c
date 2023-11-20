#include <cs50.h>
#include <stdint.h> // uint8_t
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        puts("Improper usage.");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r"); // r = read mode

    // Check if the file exists
    if (file == NULL)
    {

        puts("No such file found");
        fclose(file);
        return 1;
    }

    uint8_t buffer[4]; // unsigned int, 8 bits (a single byte);
    fread(buffer, 1, 4, file);

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", buffer[i]);
    }

    fclose(file);
}