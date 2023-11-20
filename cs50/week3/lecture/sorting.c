#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(A, B) {int t = A; A = B; B = t;}

/*

    SORTING ALGORITHMS
        -> SelectionSort

*/


void selectionsort(int *v, int left, int right); // O(n^2), Ω(n^2) == θ(n^2)
void bubblesort(int *v, int l, int r); // O(n^2), Ω(1) -> asymptotically -> as N approaches infinity, gets really large
void merge_sort(int *v, int l, int r); // O(NlogN), Ω(NlogN) == θ(NlogN)
void merge(int *v, int l, int m, int r);

int main(void)
{
    int P[] = {7, 2, 27, 4, 1, 6, 0, 3};
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", P[i]);
    }
    puts("");

    bubblesort(P, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", P[i]);
    }
    puts("");
}

void selectionsort(int *v, int left, int right)
{
    int less;
    for (int i = left; i <= right; i++)
    {
        less = i;
        for (int j = i+1; j <= right; j++)
        {
            if (v[j] < v[less]) less = j;
        }
        if (v[i] != v[less]) swap(v[i], v[less]);
    }
}

void bubblesort(int *v, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        for (int j = r; j > i; j--)
        {
            if (v[j] < v[j-1]) swap(v[j], v[j-1]);
        }
    }
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r) return;
    int m = (r+l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

void merge(int *v, int l, int m, int r)
{
    printf("hello, world.\n");
}