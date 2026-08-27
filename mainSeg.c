#include <stdio.h>
#define MAX_LIN 150
#define MAX_NOME 100
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
    for (int k=0; k<=i; k++) {
        printf("Pessoa %3d: %10s | RG: %ld\n", k, listaPessoas[k].nome, listaPessoas[k].rg);
    }

    return 0;
}
