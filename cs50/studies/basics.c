#include <cs50.h>
#include <stdio.h>

int main(void)
{
/*
    int i = 0;
    while (i < 10)
    {
        printf("Number %i\n", i);
        i++;
    }

    printf("\n\n");
    printf("But, we can use a different way to do the same thing, with the for...\n");

    for (int j = 0; j < 10; j++)
    {
        printf("Another way... %i\n", j);
    }

    printf("Or, even the DO WHILE loop...\n");

    int k = 0;

    do
    {
        printf("With DO WHILE: %i\n", k);
        k++;
    }
    while (k < 10);
*/
    int n;
    do
    {
        n = get_int("Prompt a number: ");
    }
    while (n > 0);

    /*
    [*] OPERATORS
            + - / *.  % give us the rest of a division. For example: int j = 13%4 = the rest of the division 13/4, in this case, 1.

            x = x + 1 = x++; OR x = x - 1 == x--;
            x = x + 2 = x += 2;

    [*] BOOLEAN EXPRESSIONS
            -> Used to compare values.

            0 = false    |   we can use whatever
            other = true | we want

            [*] LOGICAL OPERATORS

            && AND (all the sentences have to be true)
            || OR  (at least on is true)
            ! NOT

    [*] RELATIONAL OPERATORS

            x < y = less than
            x <= y = less than or equal to
            x > y = greater than
            x >= greater than or equal to

            x == y | x is equal to | it's a common mistake to use the =, but the correct is ==
            x != y | x isn't equal to


    [*] CONDITIONALS

        if (boolean-expression) -> if the expression is true, everything below will be executed.
        {
            //actions
        }
        else
        {
            //in case of the "if" conditions aren't true, these lines will be executed.
        }

        ANOTHER WAY: it's possible to use more than one.

            if ()
            {
                first branch
            }
            else if ()
            {
                second branch
            }
            else if ()
            {
                third branch
            }
            else
            {
                fourth branch - in case of those three before aren't true
            }


            int y;                 |
            if (condition)         |
            {                      |                    THE SAME THING:
                y = 5;             |
            }                      |              int x = (condition) ? 5 : 6; // "?" - if the condition is true, make x be 5. ":" if it's not, make x be 6.
            else                   |
            {                      |        simulates an if else, but really small.
                x = 6;             |
            }                      |



        THE SWITCH-CASE:

            int x = get_int();
            switch (x)
            {
                case 1:
                    printf("One!\n");
                    break;
                case 2:
                    printf("Two!\n");
                    break;
                default:
                    printf("Sorry!\n");
            }

    [*] LOOPS

        repeat lines of code repeatedly

            while (true) // infinite loop
            {

            }

            while (boolean-expr) // if the condition is TRUE, all lines of code will be executed, until the condition evaluates to FALSE
            {
                // here there must be the update of the condition put up there, like "i++", or something like that.
            }

            do
            {
                // differently of the WHILE, it's guaranteed to run at least one time. It'll execute and check the sentence;
            }
            while (boolean-expr);

            for (int i = 0; i < 10; i++)
            {
                // all the lines are executed for each value of "i", and at the final, the variable is updated (i++);
            }

    [*] LINUX COMMAND LINE

        > ls = list all the files and folders in the currently directory

        > cd <directory> - used to access a directory. // only "cd" - returns to the workspace directory, the tree
            short name for the current directory is "."
            to return to the parent directory of the current directory is ".."
            > pwd = to figure out where I am, in what directory, the current directory

        > mkdir <name> = creates a new directory inside the current directory

        > cp <source> <destination-name> = source is the name of the file I want to copy
            > to copy entire directorys, we use: cp -r <source> <destination>

        > rm <file>
            > there will'be a confirmation with Y/N
            > rm -f <file) = will skip the confirmation
            > rm -r <directory> = delete a directory, with Y/N confirmation
            > rm -rf <directory> = delete a directory without the confirmation

        > mv <source> <destination> = <source> is the file, and the destination is the new name desired.
    */
}