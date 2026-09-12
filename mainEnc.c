#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100
#define MAX_LIN 150

int main(){

    int qnt_pessoas = 0;
    char linha [MAX_LIN];

    typedef struct Pessoa{

        char nome[MAX_NOME];
        long int rg;
        struct Pessoa *proximo;

    }Pessoa;

    Pessoa *primeiro;
    Pessoa *ultimo;

    FILE *arq = fopen("NomeRG100.txt", "r");

    if (arq == NULL){
        printf("Falha ao abrir o arquivo.");
        return 0;
    }


    return 0;
}
