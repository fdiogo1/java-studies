#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 5, b = 10;

    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);


}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}