#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");

    string t = calloc(sizeof(s) + 1, sizeof(char));

    for (int i = 0; i < sizeof(s); i++)
    {
        t[i] = toupper(s[i]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n\n", t);

    free(t); // free memory

}