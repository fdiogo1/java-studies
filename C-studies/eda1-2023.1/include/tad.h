#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct cabeca head;
typedef struct registro node;

head * criar_lista();
node * criar_no(Item x);
int vazia(head *p);
int tamanho(head *lista);
void enfileira(head *lista, Item x);
int desenfileira(head *lista);
void imprime(head *lista);
void imprimeReverso(head *lista);
void empilha(head *pilha, Item x);
int desempilha(head *pilha);
int espia(head *pilha);   

/*
Tipos Abstratos de Dados
    * Define um tipo de estrutura
    * É um tipo de dado que é acessada por uma interface
        - Programas clientes (que usam os dados) não acessam diretamente os valores
        - Acessam via operações fornecidas pela interace
        - Esconder internamente as estruturas de dados e a lógica nos procedimentos
        - Ocultamento de informação (caixa preta)
    * Tipos: pilhas, filas, árvores


    FILAS (First In - First Out - FIFO)
        * Primeiro a entrar, é o primeiro a sair
        * Inserção no fim, remoção do começo
        * Operações:
            - vazia
            - tamanho
            - primeiro -> busca_inicio;
            - ultimo -> busca_fim;
            - enfileira -> insere_fim;
            - desenfileira -> remove_inicio;

    PILHAS (last in - first out -> LIFO)
        * insere no topo, retira do topo;
        * operações:
            - criar;
            - vazia;
            - empilhar (insere_fim);
            - desempilhar (remove_fim);
            - espiar (return lista->prox->info);
        * aplicações:
            - balanceamento de símbolos ([{}]): verificação de sintaxe (compliadores);
            - inversão de strings;
            - operação desfazer/refazer;
            - recursão
            - busca em profundidade;
            - backtracking: poder voltar a um ponto para refazer uma decisão;
            - conversão de expressões;
            - gerenciamento de memória;

    Árvores binárias        
*/