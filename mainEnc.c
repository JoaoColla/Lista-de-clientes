#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_LIN 150

int main(){

    int qnt_pessoas = 0;
    char linha [MAX_LIN];

    char nome[MAX_NOME];
    long int rg;

    typedef struct Pessoa{

        char nome[MAX_NOME];
        long int rg;
        struct Pessoa *proximo;

    }Pessoa;

    Pessoa *inicio = NULL;
    Pessoa *atual= NULL;
    Pessoa *anterior=NULL;
    Pessoa *ultimo=NULL;

    FILE *arq = fopen("/home/aluno/Downloads/joao/Lista-de-clientes/NomeRG1k.txt", "r");


    if (arq == NULL){
        printf("Falha ao abrir o arquivo.");
        return 0;
    }

    while(fgets(linha, MAX_LIN, arq) != NULL){

        sscanf (linha, "%[^,], %ld", nome, &rg);

        atual = (Pessoa *) malloc(sizeof(Pessoa));
        strcpy(atual->nome, nome);
        atual->rg = rg;
        atual->proximo = NULL;

        if (qnt_pessoas==0){
            inicio = atual;
        }else{
            anterior->proximo = atual;
        }

        anterior = atual;
        ultimo = atual;
        qnt_pessoas ++;
    }

    Pessoa *p = inicio;
    int i=1;
    while(p != NULL){
        printf("%d - Nome: %15s|RG: %15ld\n", i, p->nome, p->rg);
        p = p->proximo;
        i++;
    }

    return 0;
}
