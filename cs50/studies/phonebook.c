#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("What's your age? ");
    string number = get_string("What's your phone number? ");

    printf("The name is %s. The age is %i. The phonenumber is %s.\n", name, age, number);
}