#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Digite o valor de X:\n>> ");
    int y = get_int("Digite o valor de Y:\n>> ");

    if (x > y) {
        printf("X é maior que Y\n");
    } else if (x < y) {
        printf("Y é maior que X\n");
    } else {
        printf("X e Y são iguais!\n");
    }
}