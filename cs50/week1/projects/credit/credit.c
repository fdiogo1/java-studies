#include <cs50.h>
#include <stdio.h>

int verifycard();

int main(void)
{
    long card;

    do
    {
        card = get_long("Enter the card number: ");
    }
    while (card < 0); // não aceita num negativo.

    // pegando mais digitos
    int c1, c2, c3, c4, c5, c6, c7, c8;
    // algoritmo para verificar
    c1 = ((card % 100) / 10) * 2;
    c2 = ((card % 10000) / 1000) * 2;
    c3 = ((card % 1000000) / 100000) * 2;
    c4 = ((card % 100000000) / 10000000) * 2;
    c5 = ((card % 10000000000) / 1000000000) * 2;
    c6 = ((card % 1000000000000) / 100000000000) * 2;
    c7 = ((card % 100000000000000) / 10000000000000) * 2;
    c8 = ((card % 10000000000000000) / 1000000000000000) * 2;


    c1 = (c1 % 100 / 10) + (c1 % 10);
    c2 = (c2 % 100 / 10) + (c2 % 10);
    c3 = (c3 % 100 / 10) + (c3 % 10);
    c4 = (c4 % 100 / 10) + (c4 % 10);
    c5 = (c5 % 100 / 10) + (c5 % 10);
    c6 = (c6 % 100 / 10) + (c6 % 10);
    c7 = (c7 % 100 / 10) + (c7 % 10);
    c8 = (c8 % 100 / 10) + (c8 % 10);

    int soma1 = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8;

    int c9, c10, c11, c12, c13, c14, c15, c16;

    c9 = (card % 10);
    c10 = ((card % 1000) / 100);
    c11 = ((card % 100000) / 10000);
    c12 = ((card % 10000000) / 10000000);
    c13 = ((card % 1000000000) / 1000000000);
    c14 = ((card % 100000000000) / 100000000000);
    c15 = ((card % 10000000000000) / 1000000000000);
    c16 = ((card % 1000000000000000) / 100000000000000);

    int soma2 = c9 + c10 + c11 + c12 + c13 + c14 + c15 + c16;
    int soma3 = soma1 + soma2;

    int lenght = 0;
    long visa = card; // VISA
    long amex = card; // AMEX
    long master = card; // MASTERCARD

    if ((soma3 % 10) != 0)
    {
        printf("INVALID\n"); // INVALIDO
    }

    while (card > 0)
    {
        card = card / 10;
        lenght++;
    }

    // identificando se é visa.
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (lenght == 13 || lenght == 16))
    {
        printf("VISA\n");
    }

    // identificando se é AMEX

    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (lenght == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
    }

    while (master >= 100000000000000)
    {
        master /= 100000000000000;
    }
    if (lenght == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55))
    {
        printf("MASTERCARD\n");
    }
}
