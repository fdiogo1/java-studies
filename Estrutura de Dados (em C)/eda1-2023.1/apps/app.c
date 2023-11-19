#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

#define key(A) 
#define less(A, B) if(key(A) < key(B))
#define exch(A, B) {int t = A; A = B; B = t;}
#define compexch(A, B) if(less(A, B)) exch(A, B)

int main(void)
{
    head *pilha = criar_lista();

    char teste[50];

    printf("Digite a string a ser invertida: ");
    scanf("%s", teste);

    int tam = strlen(teste);

    for(int i = 0; i < tam; i++)
    {
        empilha(pilha, teste[i]);
    }

    while(!vazia(pilha))
    {
        printf("%c", desempilha(pilha));
    }
    printf("\n");
    system("pause");

}