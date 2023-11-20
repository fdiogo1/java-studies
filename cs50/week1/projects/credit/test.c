#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char card[2], carac[2];
    int result;

    scanf("%s", card);
    scanf("%s", carac);

    result = card[1] + carac[1];

    printf("%i", result);
}