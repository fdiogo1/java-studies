#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void draw(int n);

int main(int argc, char **argv)
{
    int height = atoi(argv[1]);
    draw(height);
}

void draw(int n)
{
    if (n <= 0) return;
    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    puts("");
}