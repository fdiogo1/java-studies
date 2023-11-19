// =========================== INTERFACE PÚBLICA ======================== //

void selectionsort(int v[], int l, int r); // O(n^2)
void bubblesort(int v[], int l, int r); // O(n^2)
void insertionsort(int v[], int l, int r); // O(n^2)
void insertionOTIMIZADO(int v[], int l, int r); // O(n^2) -> evita trocas desnecessárias.
void insertionH(int v[], int l, int r, int h); // O(n^2); essa versão possui SALTOS. Será utilizado no ShellSort
void shellsort(int v[], int l, int r); // O(n^2), aproximadamente. Depende do salto (h).
void merge_sort(int *v, int l, int r);
void quicksort(int *v, int l, int r); // Melhor caso: O(nLogn) // Pior caso: O(N^2/2).
void quickM3(int *v, int l, int r); // Quick com mediana de 3.
void intro(int *v,  int l, int r, int maxdepth);

// ====================================================================== //

//

/*
    Notação Big-O -> serve para saber o quão rápido um algoritmo cresce. Não é utilizado para dizer qual algoritmo é MELHOR ou mais rápido,
e sim qual cresce mais rápido. Então, varia.
        * O(nLogn)
        * O(N^2) -> em alguns casos pode ser melhor que o O(nLogn)
*/