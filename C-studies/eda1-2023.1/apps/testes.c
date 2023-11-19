#include <stdio.h>
#include "ords.h"

int main(void)
{
    int idades[15] = {14, 12, 19, 1, 7, 8, 3, 9, 0, 5, 6, 2, 4, 15, 11};
    
    printf("Hey.\nAplicativo destinado para testes! \n\n");
    printf("Vetor desordenado: ");
    for(int i = 0; i <= 14; i++)
    {
        printf("%i ", idades[i]);
    }

    quickM3(idades, 0, 14);
    printf("\nVetor ordenado: ");
    for(int i = 0; i <= 14; i++)
    {
        printf("%i ", idades[i]);
    }
}