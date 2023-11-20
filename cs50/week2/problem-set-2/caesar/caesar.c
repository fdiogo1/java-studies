#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int rotate(char c, int key);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int check = 0;
        for (int i = 0, size = strlen(argv[1]); i < size; i++)
        {
            if(!isdigit(argv[1][i]))
                check = 1;
        }

        if (check == 0)
        {
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext:  ");
            printf("ciphertext: ");
            for (int i = 0, size = strlen(plaintext); i < size; i++)
            {
                printf("%c", rotate(plaintext[i], key));
            }
            puts("");
        }
        else
        {
            puts("Usage: ./caesar key");
            return 1;
        }
    }
    else
    {
        puts("Usage: ./caesar key");
        return 1;
    }
}

int rotate(char c, int key)
{
    int newKey, k = 0;
    if(isupper(c) && isalpha(c) && !ispunct(c) && !isblank(c))
    {
        if(c+key > 90)
        {
            newKey = key - (90-c);
            k = 64 + newKey;
            return k;
        }
        else
        {
            return c+key;
        }
    }
    else if (islower(c) && isalpha(c) && !ispunct(c) && !isblank(c))
    {
        if(c + key > 122)
        {
            newKey = key - (122 - c);
            k = 96 + newKey;
            return k;
        }
        else return c + key;
    }
    else return c;
}