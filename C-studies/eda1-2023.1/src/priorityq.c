#include "priorityq.h"
#include <stdio.h>
#include <stdlib.h>

// ============================== INTERFACE PRIVADA ============================== //

#define key(A) A 
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

// =============================================================================== //

// ============================== INTERFACE PÚBLICA ============================== //

void show(int v[], int l, int r)
{
    for(int i = l; i <= r; i++)
    {
        printf("%i ", v[i]);
    }
    printf("");
}

int is_sorted(int v[], int l, int r)
{
    int p;
    for(p = r; p > l && v[p-1] <= v[p]; p--);

    return (p==0);
}

void PQinit(int maxN)
{
    pq = malloc(sizeof(Item)*(maxN+1));
    N = 0;
}

int PQempty()
{
    return N==0;
}

void fixUp(int k)
{
    while(k>1 && less(pq[k/2], pq[k]))
    {
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
}

void fixDown(int k, int N)
{
    int j;
    while(2*k <= N)
    {
        j = 2*k;
        // troque com o maior filho
        if(j<N && less(pq[j], pq[j+1])) j++;

        // se p[k] não precisar mais descer, pare
        if(!less(pq[k], pq[j])) break;

        // se não, afunde
        exch(pq[k], pq[j]);
        k = j;
    }
}

void PQinsert(Item v)
{
    pq[++N] = v;
    fixUp(N);
}

Item PQdelmax()
{
    // trocar o último com o topo
    exch(pq[1], pq[N]);

    // reposicionar o último
    fixDown(1, N-1); // N-1 pois está sendo retirado um elemento.

    // devolve o máximo:

    return pq[N--];
}

void PQsort(Item *v, int l, int r)
{
    PQinit(r-l+1);
    for(int k = l; k<=r; k++)
    {
        PQinsert(v[k]);
    }

    for(int k = r; k>=l; k--)
    {
        v[k] = PQdelmax();
    }
}

void heapsort(int *v, int l, int r)
{
    pq = v+l-1;
    N = r-l+1;
    for(int k = N/2; k >= 1; k--)
    {
        fixDown(k, N);
    }

    while(N>1)
    {
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}

// =============================================================================== //