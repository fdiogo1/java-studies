#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string buffer[2];
    FILE *input = fopen("hi.txt", "r");
    fread(buffer, 1, 3, input); // input -> location where we area reading for; 1 -> size of what we want to read (char = 1); 3 -> amount of;
    //                            buffer -> variable where will be saved

    fclose(input);
    printf("%s",)

}