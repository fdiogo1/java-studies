#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int rotate(char c, int key);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        puts("Usage: ./caesar key");
    }
    else
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");
        for (int i = 0, size = strlen(plaintext); i < size; i++)
        {
            printf("%c", rotate(plaintext[i], key));
        }
    }
}

int rotate(char c, int key)
{
    int newKey, k = 0;
    if(isupper(c))
    {
        if(c+key > 90)
        {
            newKey = key - (90-c);
            k = 'A' + newKey;
            return k;
        }
        else
        {
            return c+key;
        }
    }
    else if (islower(c))
    {
        if(c+key > 122)
        {
            newKey = key - (122-c);
            k = 'a' + newKey;
            return k;
        }
        else return c+key;
    }
}