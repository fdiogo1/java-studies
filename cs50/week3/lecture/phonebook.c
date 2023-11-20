#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // string names[] = {"Diogo", "Dario", "Geralda"};
    // string numbers[] = {"1111111111", "2222222222", "333333333"};

    // string n = get_string("Prompt the name: ");

    // for (int i = 0; i < 3; i++)
    // {
    //     if (strcmp(names[i], n) == 0)
    //     {
    //         printf("Found %s\n", numbers[i]);
    //         return 0;
    //     }
    // }
    // printf("Not found.\n");
    // return 1;

    string list[3][3] = { {"Diogo", "Dario", "Geralda"},
                          {"11111", "22222", "3333333"},
                          {"SON--", "FATHER", "MOTHER"}  };

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(list[0][i], name) == 0)
        {
            printf("FOUND! %s\n", list[1][i]);
            printf("%s\n", list[2][i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}