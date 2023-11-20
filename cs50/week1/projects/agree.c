#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user to agree
    char toupper= get_char("Você concorda?\n>> ");

    //conferir
    if (c == 'S' || c == 's') {
        printf("Você concorda.\n");
    } else if (c == 'N' || c == 'n') {
        printf("Você não concorda\n");
    } else {
        printf("Opção não compreendida.\n");
    }
}