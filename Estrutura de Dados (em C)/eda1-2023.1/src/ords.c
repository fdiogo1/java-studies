#include "ords.h"
#include <stdlib.h>
// =========================== INTERFACE PRIVADA ======================== //

#define key(A) A 
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {int t = A; A = B; B = t;}
#define compexch(A, B) if(less(B, A)) {exch(A, B)} 

int partition(int *v, int l, int r)
{
    int tam = r-l+1;
    int c = v[r];
    int cpos;

    int *menores = malloc(sizeof(int)*tam);
    int *maiores = malloc(sizeof(int)*tam);

    int imenor = 0, imaior = 0;

    for(int i = l; i < r; i++)
    {
        if(less(v[i], c)) menores[imenor++] = v[i];
        else maiores[imaior++] = v[i];
    }

    int i = l;

    for(int j = 0; j < imenor; j++)
    {
        v[i++] = menores[j];
    }

    v[i] = c;
    cpos = i;
    i++;

    for(int j = 0; j < imaior; j++)
    {
        v[i++] = maiores[j];
    }

    free(maiores), free(menores);

    return cpos;
}

void merge(int *v, int l, int m, int r) // será utilizado no merge_sort
{
    // alocando espaço
    int tam = r-l+1;
    int *aux = malloc(sizeof(int)*tam);

    // auxiliares
    int k = 0;
    int i = l;
    int j = m+1;

    //ordenar em aux[k]
    while(k<tam) //condição de parada do aux
    {
        if(i>m) //ordenou todo o primeiro sub-vetor
            aux[k++] = v[j++];//consome o segundo sub-vetor -> ordene no aux

        else if (j>r) //ordenou todo o segundo sub-vetor
            aux[k++] = v[i++];//consome o primeiro sub-vetor -> ordene no aux

        else if (v[i] < v[j]) //testar sub-vetores
            aux[k++] = v[i++];//ordene no aux
        else
            aux[k++] = v[j++];//ordene no aux
    }
    k=0; //indice do aux
    for(i=l; i<=r; i++) //indice do v
        v[i] = aux[k++];//copiar o aux[k] para v[i]
        
    //liberar memória
    free(aux);
}

// ====================================================================== //


// =========================== INTERFACE PÚBLICA ======================== //

void selectionsort(int v[], int l, int r)
{
    int menor;
    for(int i = l; i <= r; i++)
    {
        menor = i;
        for(int j = i+1; j <= r; j++)
        {
            if(v[j] < v[menor]) menor = j;
        }
        if(v[i] != v[menor]) exch(v[i], v[menor]);
    }
}

void bubblesort(int v[], int l, int r)
{
    for(int i = l; i <= r; i++)
    {
        for(int j = l; j > i; j--)
        {
            if(less(v[j], v[j-1])) exch(v[j], v[j-1]);
        }
    }
}

void insertionsort(int v[], int l, int r)
{
    for(int i = l+1; i <= r; i++)
    {
        for(int j = i; j > l && v[j] < v[j-1]; j--)
        {
            if(v[j] < v[j-1]) exch(v[j], v[j-1]);
        }
    }

}

void insertionOTIMIZADO(int v[], int l, int r)
{
    for(int i = r; i > l; i--)
    {
        if(v[i] < v[i-1]) exch(v[i], v[i-1]); // garantir que o menor elemento já estará na posição 0;
    }

    for(int i = l+2; i <= r; i++)
    {
        int j = i;
        int tmp = v[j];

        while(tmp < v[j-1])
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

void insertionH(int v[], int l, int r, int h)
{
    for(int i = l+h; i <= r; i++)
    {
        int j = i;
        int tmp = v[j];

        while(j >= l+h && tmp < v[j-h])
        {
            v[j] = v[j-1];
            j-=h;
        }
        v[j] = tmp;
    }
}
void shellsort(int v[], int l, int r)
{
    int h = 1;
    while(h < (r-l+1)/3) h = 3*h+1;

    while(h>=1)
    {
        for(int i=l+h; i<=r; i++)
        {
            for(int j=i; j>=l+h && v[j]<v[j-h]; j-=h)
            {
                int a = v[j];
                v[j] = v[j-h];
                v[j-h] = a;
            }
        }
        h = h/3;
    }
}

void quicksort(int *v, int l, int r)
{   
    int j;
    if(l>=r) return;
    j = partition(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j, r);
}

void quickM3(int *v, int l, int r) // faz a escolha do pivot ser o elemento mediano
{
    if(r<=l) return;

    compexch(v[l], v[(l+r)/2]);
    compexch(v[l], v[r]);
    compexch(v[r], v[(l+r)/2]);

    int p = partition(v, l, r);
	quickM3(v, l, p-1);
	quickM3(v, p+1, r);
}

void merge_sort(int *v, int l, int r)
{
    if(l>=r) return;
    int m = (r+l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

void intro(int *v,  int l, int r, int maxdepth)
{ 
    if(r-l<=15){
        insertionsort(v, l, r);

    } else if(maxdepth == 0) {
        merge_sort(v, l, r);
        //heap_sort(v, l, r);

    } else {
        exch(v[(l+r)/2], v[r-1]);
        compexch(v[l], v[r-1]);
        compexch(v[l], v[r]);
        compexch(v[r-1], v[r]);

        int p = partition(v, l+1, r-1);
	    intro(v, l, p-1, maxdepth-1);
	    intro(v, p+1, r, maxdepth-1);
    }
}


// ====================================================================== //
