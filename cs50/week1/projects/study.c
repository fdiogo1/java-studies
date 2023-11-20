#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string name, cidade, op;
    FILE *infos;
    do {
        name = get_string("Qual é o seu nome?\n>> ");
        cidade = get_string("Qual a sua cidade?\n>> ");

        infos = fopen("infos.txt", "at");
        if(infos != NULL) {
            fprintf(infos, "%s\n", name);
            fprintf(infos, "%s\n", cidade);
            printf("Informações registradas com sucesso.\n");
        } else {
            printf("Ops, arquivo não encontrado.\n");
            printf("As informações não puderam ser salvas.\n");
        }
        fclose(infos);
        op = get_string("Deseja sair?\n>> ");
    } while (strcmp(op, "SAIR") != 0);
    printf("Miniprograma encerrado. Até breve!\n");
}