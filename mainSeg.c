#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIN 150
#define MAX_NOME 100

int main(){

    int i=0, num_vagas, num_pessoas=0, opcao;
    char linha [MAX_LIN], nome [MAX_NOME];
    long int rg;

    typedef struct Pessoa{
        char nome [MAX_NOME];
        long int rg;
    } Pessoa;

    Pessoa *listaPessoas;

    FILE *arq = fopen("/home/aluno/Downloads/joao/Lista-de-clientes/NomeRG1K.txt", "r");
    if (arq == NULL){
        printf("Erro abrindo o arquivo");
        return 0;
    }

    printf("Quantas pessoas serao registradas? ");
    scanf("%d", &num_vagas);

    listaPessoas = (Pessoa *) malloc(num_vagas * sizeof(Pessoa));

    if (listaPessoas == NULL){
        printf("Erro alocando memoria");
        fclose(arq);
        return 0;
    }

    rewind(arq);

    for (i=0; i<num_vagas && fgets(linha, MAX_LIN, arq); i++){

        if (sscanf (linha, "%[^,], %ld", nome, &rg) == 2 && nome[0] != '\0'){
            strcpy(listaPessoas[num_pessoas].nome, nome);
            listaPessoas[num_pessoas].rg = rg;

            num_pessoas++;
        }
    }

    fclose(arq);

    for (i=0; i<num_pessoas; i++) {
        printf("Pessoa %3d: %10s | RG: %ld\n", i+1, listaPessoas[i].nome, listaPessoas[i].rg);
    }

    int comparacao = 0, movimentacao = 0;
    double tempo = 0;

    printf("Escolha uma opcao pelo numero:\n"
    "1 - Inserir no inicio da lista\n"
    "2 - Inserir no fim da lista\n"
    "3 - Inserir na posicao N da lista\n"
    "4 - Retirar um no do inicio da lista\n"
    "5 - Retirar um no no fim da lista\n"
    "6 - Retirar um nó na posição N\n"
    "7 - Procurar um no com o campo RG\n"
    "8 - Mostrar a lista na tela\n"
    "9 - Salvar a lista em um arquivo\n"
    "10 - Ler a lista de um arquivo\n"
    "11 - Sair do sistema\n");
    scanf("%d", &opcao);

    if(opcao == 1){

        comparacao = 0;
        movimentacao = 0;

        comparacao ++;
        if (num_pessoas >= num_vagas) {

        printf("Lista cheia.\n");
        return 0;
        }

        printf("Nome: ");
        scanf("%s", nome);
        printf("Rg: ");
        scanf("%ld", &rg);

        clock_t inicioTempo = clock();

        for (i=num_pessoas; i>0; i--){
            movimentacao ++;
            listaPessoas[i] = listaPessoas[i-1];
        }

        strcpy(listaPessoas[0].nome, nome);
        listaPessoas[0].rg = rg;

        num_pessoas ++;

        clock_t fimTempo = clock();

        tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;

        printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, 0);

    }else if(opcao == 2){

        comparacao = 0;
        movimentacao = 0;


        comparacao ++;
        if (num_pessoas >= num_vagas) {

        printf("Lista cheia.\n");
        return 0;
        }

        printf("Nome: ");
        scanf("%s", nome);
        printf("Rg: ");
        scanf("%ld", &rg);

        clock_t inicioTempo = clock();

        strcpy(listaPessoas[num_pessoas].nome, nome);
        listaPessoas[num_pessoas].rg = rg;

        num_pessoas ++;

        clock_t fimTempo = clock();

        tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;


        printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, num_pessoas);

    }else if(opcao == 3){

        comparacao = 0;
        movimentacao = 0;


        comparacao ++;
        if (num_pessoas >= num_vagas) {

        printf("Lista cheia.\n");
        return 0;
        }

        int posicao;
        printf("posicao: ");
        scanf("%d", &posicao);
        printf("Nome: ");
        scanf("%s", nome);
        printf("Rg: ");
        scanf("%ld", &rg);

        clock_t inicioTempo = clock();

        for (i=num_pessoas; i>posicao; i++){
            movimentacao++;

            listaPessoas[i] = listaPessoas[i-1];
        }

        strcpy(listaPessoas[posicao].nome, nome);
        listaPessoas[posicao].rg = rg;

        num_pessoas++;

        clock_t fimTempo = clock();
        tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;


        printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, posicao);

    }else if(opcao == 4){
        clock_t inicioTempo = clock();

        comparacao = 0;
        movimentacao = 0;

        strcpy(nome, listaPessoas[0].nome);
        rg = listaPessoas[0].rg;

        for (i=0; i<num_pessoas-1; i++){
            movimentacao ++;

            listaPessoas[i] = listaPessoas[i+1];
        }

        num_pessoas --;

        clock_t fimTempo = clock();

        tempo = (double) (fimTempo - inicioTempo) / CLOCKS_PER_SEC;

        printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, 0);
    }else if (opcao == 5){
        clock_t inicioTempo = clock();

        comparacao = 0;
        movimentacao = 0;

        strcpy(nome, listaPessoas[num_pessoas-1].nome);
        rg = listaPessoas[num_pessoas-1].rg;

        num_pessoas --;

        clock_t fimTempo = clock();

        tempo = (double) (fimTempo - inicioTempo) / CLOCKS_PER_SEC;

        printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, num_pessoas);

    }else if (opcao == 6){
        clock_t inicioTempo = clock();

        comparacao = 0;
        movimentacao = 0;

        int posicao;
        printf("posicao: ");
        scanf("%d", &posicao);

        strcpy(nome, listaPessoas[posicao].nome);
        rg = listaPessoas[posicao].rg;

        for (i=posicao; i<num_pessoas-1; i++){
            movimentacao++;

            listaPessoas[i] = listaPessoas[i+1];
        }

        num_pessoas--;

        clock_t fimTempo = clock();

        tempo = (double) (fimTempo - inicioTempo) / CLOCKS_PER_SEC;

        printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, posicao);

    }else if(opcao == 7){
    // a fazer
    }

    free(listaPessoas);
    return 0;
}
