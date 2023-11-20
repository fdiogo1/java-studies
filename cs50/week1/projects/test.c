#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string name;

    name = get_string("Testando:\n>> ");
    printf("Nome digitado: \n");
    for (int i = 0; i < strlen(name); i++) {
        printf("%c", toupper(name[i]));
    }
    printf("\n");
}