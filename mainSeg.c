#include <stdio.h>
#define MAX_LIN 150
#define MAX_NOME 130
#define MAX_PESSOAS 150


int main(){

    int num_pessoas = 0, i=0;
    char linha [MAX_LIN];

    typedef struct Pessoa{
        char nome [MAX_NOME];
        long int rg;
    } Pessoa;

    Pessoa listaPessoas[MAX_PESSOAS];

    FILE *arq = fopen("NomeRG100.txt", "r");

    if (arq == NULL){
        printf("Erro abrindo o arquivo");
        return 0;
    }

    while(i<MAX_PESSOAS && fgets(linha, MAX_LIN, arq) != NULL){

        sscanf (linha, "%[^,], %ld", listaPessoas[i].nome, &listaPessoas[i].rg);
        i++;

    }

    fclose(arq);

    printf("\nTotal de pessoas carregadas: %d\n", i);
    if (i > 0) {
        printf("Pessoa 1: %s | RG: %ld\n", listaPessoas[0].nome, listaPessoas[0].rg);
        printf("Pessoa 2: %s | RG: %ld\n", listaPessoas[1].nome, listaPessoas[1].rg);
    }

    return 0;
}
