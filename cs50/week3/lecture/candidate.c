#include <cs50.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct person candidate;
struct person
{
    string name;
    int age;
};

size_t factorial(int x);

int main(void)
{
    puts("Training the Week-3");
    candidate diogo;
    diogo.name = get_string("Name: "); // if it was dinamically allocated (heap), it should be diogo->name;
    diogo.age = get_int("Age: ");

    printf("The name is '%s'\n", diogo.name);
    printf("The age is '%d'\n", diogo.age);

    printf("Now, let's try the RECURSION.\n");
    int x = get_int("Factorial of: ");

    printf("The factorial of '%d' is: %lu\n", x, factorial(x));
}

size_t factorial(int x) // recursive function
{
    if (x <= 0) return 1;
    int n = x * factorial(x - 1); // it calls itself inside the function
    return n;
}