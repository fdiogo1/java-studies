// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

#define swap(A, B)                                                                                                                 \
    {                                                                                                                              \
        int t = A;                                                                                                                 \
        A = B;                                                                                                                     \
        B = t;                                                                                                                     \
    }

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n) // sort the array and return de max value
{
    int menor;
    for (int i = 0; i < n; i++)
    {
        menor = i;
        for (int j = i; j < n; j++)
        {
            if (array[j] < array[menor]) menor = j;
        }
        if (array[i] != array[menor])
        {
            swap(array[i], array[menor]);
        }
    }
    return array[n - 1];
}
