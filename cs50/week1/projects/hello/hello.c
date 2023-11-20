#include <stdio.h> //biblioteca principal
#include <cs50.h> //biblioteca dos "gets"

int main(void)
{
    //Prompt para pegar o nome
    string name = get_string("What's your name? ");
    //Dando as boas vindas
    printf("hello, %s\n", name);
}