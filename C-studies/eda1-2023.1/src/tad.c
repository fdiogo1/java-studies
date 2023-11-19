#include "tad.h"
#include <stdio.h>

struct registro
{
    Item info;
    node *prox;
    node *ant;
};

struct cabeca
{
    int num_itens;
    node *prox;
    node *ultimo;
};

head * criar_lista()
{
    head *creating = malloc(sizeof(head));
    creating->num_itens = 0;
    creating->prox = NULL;
    creating->ultimo = NULL;

    return creating;
}

void imprime(head *lista)
{
    node *aux = lista->prox;
    while (aux != NULL)
    {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
}

int vazia(head *p)
{
    return (p->prox==NULL);
}

node * criar_no(Item x)
{
    node *novo = malloc(sizeof(node));
    novo->ant = NULL;
    novo->info = x;
    novo->prox = NULL;
    
    return novo;
}

int tamanho(head *lista)
{
    return lista->num_itens;
}

void enfileira(head *lista, Item x)
{
    node *novo = criar_no(x);
    if(!vazia(lista)) lista->ultimo->prox = novo;
    else lista->prox = novo;

    lista->ultimo = novo;
    lista->num_itens++;
}

int desenfileira(head *lista)
{
    node *lixo = lista->prox;
    lista->prox = lista->prox->prox;

    if(lixo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = lixo->info; // salva a informação antes de ser deletada.
    free(lixo); // libera o espaço da memória.
    return x; // retorna a informação deletada.
}

void empilha(head *pilha, Item x)
{
    node *novo = criar_no(x);
    if(vazia(pilha)) pilha->ultimo = novo;
    
    novo->prox = pilha->prox;
    pilha->prox = novo;

    pilha->num_itens++;
}

int desempilha(head *pilha)
{
    node *topo = pilha->prox;
    pilha->prox = topo->prox;

    if(topo == pilha->ultimo) pilha->ultimo = NULL;
    pilha->num_itens--;

    Item x = topo->info;
    free(topo);

    return x;
}

int espia(head *pilha) 
{
    return pilha->prox->info;
} 

void imprimeReverso(head *lista)
{
    node *aux = lista->ultimo;
    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->ant;
    }
}