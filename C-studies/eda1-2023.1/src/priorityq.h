/*
    Fila de prioridades = é um TAD com chaves ordenadas, acessadas por um conjunto de operações.
        * Permite formar uma interface para uso de programas clientes;
        * Existem operações que envolvem um grande volume de informações que precisam de alguma ordenação.
            -> não necessariamente precisa estar totalmente ordenado.
            -> o importante é saber qual tem a MAIOR prioridade.
        * A cada novo dado inserido = atualiza-se a fila.
*/


// ======================== INTERFACE PÚBLICA =========================== //

typedef int Item;

static Item *pq;
static int N;

void show(int v[], int l, int r);
int is_sorted(int v[], int l, int r);
void PQinit(int maxN);
int PQempty();
void fixUp(int k);
void fixDown(int k, int N);
void PQinsert(Item v);
Item PQdelmax();
void PQsort(Item *v, int l, int r);
void heapsort(int *v, int l, int r);

// ===================================================================== //

/*
Implementações:
    $ Vetores e listas encadeadas:
        em listas encadeadas: 3 ponteiros -> p/ os filhos e pai
        úteis p/ filas pequenas
        em vetor não ordenado:
            -> processo corresponde a executar um selectionsort
            -> selecionar o de maior prioridade e colocar no início
        em vetor ordenado:
            -> processo corresponde a executar um insertionsort
            -> a cada novo item, posicionar comparando com os seus antecessores

    $ Heap Binária (heap)
        * estrutura de dados eficiente p/ as operações básicas da fila de prioridades
        * organizar as chaves como em uma ÁRVORE BINÁRIA COMPLETA
            -> todos os níveis (exceto o último) estão cheios
            -> os nós do último nível estão o mais a esquerda possível
            -> cada nó: possui filhos com valores menores ou iguais ao seu
            -> RAIZ: maior chave da heap
            -> não ordena por completo, só garante que:
                + quanto mais próximo à raiz, maior a prioridade
            -> operações para manter a heap ordenada: exige a navegação p/ cima e p/ baixo
        * Detalhes de implementação: heap de tamanho N em um vetor pq[]
            -> vantagem: acesso pelo indíce
            -> pq[N+1]: não se utiliza a posição [0]
            -> é a partir da [1]
        * Operações:
            -> Prioridade aumentada ou chave inserida:
                - inserção nas folhas da heap
                - restauração: subindo na heap (fix up)
                - bottom-up: sobe um nó com uma chave maior que seu pai (recursivamente sobe o nó até um pai maior ou a raiz)

        * Heap com vetores:
            - a partir do indíce 1;
            - pai de um nó: k/2
            - filhos de um nó: 2k e 2k+1

        -> INSERIR NA HEAP: insere nas folhas (fim do vetor), e vai corrigindo com fixUp -> garantir que não tem um nó filho maior que seu pai
                - incrementa o tamanho da heap
                - complexidade: O(logN) -> logarítmica

        -> REMOÇÃO DO MÁXIMO: remover a maior chave (topo); 
                - troca a raiz ([1]) com o último [N];
                - afunda a nova raiz, p/ corrigir e restaurar a ordenação da heap -> fixDown -> garantir que o nó pai não é menor que seu filho

        
        MÉTODO HEAPSORT
            -> Construir e destruir a heap da fila de prioridades
            -> Usa as filas de prioridades para ordenar elementos
                * fase 1: construção da heap (fila prioridades)
                    + reorganiza o vetor em uma heap-ordenada
                        - topo é o de maior prioridade
                        - quanto mais próximo ao topo, maior a prioridade
                        - não há garantia de ordenação de todos os itens
                * fase 2: ordenação por remoção

            (Solução 1):
                usa a interface da TAD fila de prioridades
                cria uma fila de prioridades
                    Utiliza espaço extra (não é in-place)
                fase 1: construção da heap
                    + construção por inserção
                        - varredura da esquerda para direita
                        - fixUp para reposicionar na heap
                        - Custo proporcional a 2NlogN
                fase 2: ordenação (decrescente)
                    + ordenação por remoção (maior prioridade)
                        - reorganização da fila de prioridades
                    + cada item removido volta para o vetor original

            (Solução 2 - otimização):
                usa-se diretamente as funções exclusivas da TAD fila de prioridades: fixUp, fixDown
                não há necessidade de espaços extras
                    vetor original é utilizado para construir a heap
                fase 1: construção da heap
                    varredura da direita para esquerda
                    fixDown para preservar a heap-ordenada
                    cada fixDown constrói uma sub-heap
                        cada posição no vetor é uma raiz de uma sub-heap
                    percurso:
                        inicializa da metade do vetor
                            N/2: pai dos nós das folhas
                            pular sub-heaps de tamanho 1
                        termina na posição 1
                    resultado (contra intuitivo):
                        primeiro elemento sendo o maior elemento do vetor
                        outros maiores elementos, próximos ao início
                    custo proporcional a 2N
                fase 2: ordenação (decrescente)
                        remover o máximo repetidamente
                            troca-se o último elemento pela raiz
                            diminui-se o tamanho da fila
                            fixDown da raiz

                -> a segunda fase é a mais custosa
                    reorganizar a heap a cada remoção
                -> complexidade: 2NlogN + 2N comparações
                    - 2N na construção da heap
                    - 2NlogN no conserto da heap (2ª fase)
                -> é in-place, não é estável
                complexidade: O(nlogn)


                    
                        


*/