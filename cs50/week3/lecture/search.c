#include <cs50.h>
#include <stdio.h>
#include <string.h>


/*
    Linear Search -> O(n) / Ω(1) -> search step-by-step, repeat starting from the first element (beginning)
    Binary Search -> O(logN) / Ω(1) -> it's required that the vector be sorted. it starts from the middle, and compares if it's the element, or if it's smaller or bigger.
*/

int main(void)
{
    // LINEAR SEARCH with NUMBERS
    // int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // int n = get_int("Number: ");

    // for (int i = 0; i < 7; i++)
    // {
    //     if (numbers[i] == n)
    //     {
    //         printf("Found\n");
    //         return 0;
    //     }
    // }
    // printf("Not found.\n");
    // return 1;


    // LINEAR SEARCH with STRINGS
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}