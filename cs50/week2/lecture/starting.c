#include <cs50.h>  // PREPROCESSING
#include <stdio.h> // PREPROCESSING

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s!\n", name);
}

/*
    [*] ways to compile -
        make starting
        clang starting (it will generate a file called "a.out")
        clang -o starting starting.c (it will generate a file called starting)
        clang -o starting starting.c -lcs50 // to use in things here in the course CS50.
        gcc starting.c -o starting -lcs50 // another way to compile

    [*] phases of the compiling process
        1- PREPROCESS: the includes; the libraries; the hashs at the top
        2- COMPILING: literally compiles the code
        3- ASSEMBLING: where the code is converted to machine code. to 0s and 1s
        4- LINKING: link the libraries, and links all together

    [*] debugging - ideas to identify a mistake in the code
        1- debug50 ./<executable>
        2- use the printf's to look better

    [*] data types
        1- bool [1 byte]
        2- int [4 bytes]
        3- long [8 bytes]
        4- float [4 bytes]
        5- double [8 bytes]
        6- char [1 byte]
        7- string [? bytes]
    [*] command-line argument

        int main(int argc, char *argv[])
            argc = argument count;
            argv = the arguments after ./ -> the argv[0] will always be the name of the executable, like ./hi


*/