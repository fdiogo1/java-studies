#include <cs50.h>
#include <stdio.h>

/*
    Pointers = variable that contains the address of some value
    %p = flag to print a address

        */

int main(void)
{
    int n = 54;
    int *p = &n;
    int **j = &p; // *j = &n; **j = 54;

    printf("&n = %p, n = %d\n", &n, n);
    printf("&p = %p, p = %p, *p = %d\n\n", &p, p, *p);
    printf("&j = %p, j = %p, *j = %p, **j = %d\n", &j, j, *j, **j);

}