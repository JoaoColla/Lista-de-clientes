#include <stdio.h>
#include <stdlib.h>

#define MAX_LIN 150
#define MAX_NOME 100

int main(){

    int i=0, k;
    char linha [MAX_LIN];

    typedef struct Pessoa{
        char nome [MAX_NOME];
        long int rg;
    } Pessoa;

    Pessoa *listaPessoas;

    FILE *arq = fopen("NomeRG100.txt", "r");

    if (arq == NULL){
        printf("Erro abrindo o arquivo");
        return 0;
    }

    while(fgets(linha, MAX_LIN, arq) != NULL){
        i++;
    }

    listaPessoas = (Pessoa *) malloc(i * sizeof(Pessoa));

    if (listaPessoas == NULL){
        printf("Erro alocando memoria");
        fclose(arq);
        return 0;
    }
    
    rewind(arq);

    for (k=0; k<i; k++){
        fgets(linha, MAX_LIN, arq);
        sscanf (linha, "%[^,], %ld", listaPessoas[k].nome, &listaPessoas[k].rg);
    }

    fclose(arq);

    printf("\nTotal de pessoas carregadas: %d\n", i);
    for (k=0; k<i; k++) {
        printf("Pessoa %3d: %10s | RG: %ld\n", k, listaPessoas[k].nome, listaPessoas[k].rg);
    }

    free(listaPessoas);
    return 0;
}
