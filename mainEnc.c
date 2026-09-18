#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


#define MAX_NOME 100
#define MAX_LIN 150

int main(){

    int qnt_pessoas = 0, i;
    char linha [MAX_LIN];

    char nome[MAX_NOME];
    long int rg;

    typedef struct Pessoa{

        char nome[MAX_NOME];
        long int rg;
        struct Pessoa *proximo;

    }Pessoa;

    Pessoa *inicio = NULL;
    Pessoa *ultimo=NULL;
    Pessoa *atual= NULL;
    Pessoa *anterior=NULL;

    FILE *arq = fopen("/home/aluno/Downloads/joao/Lista-de-clientes/NomeRG1k.txt", "r");


    if (arq == NULL){
        printf("Falha ao abrir o arquivo.");
        return 1;
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

    i = 1;
    Pessoa *p = inicio;
    while(p != NULL){
        printf("%d - Nome: %15s|RG: %15ld\n", i, p->nome, p->rg);
        p = p->proximo;
        i++;
    }

    int comparacao = 0, movimentacao = 0, opcao, posicao;
    double tempo = 0;
    Pessoa *aux = NULL;

    printf("Escolha uma opcao pelo numero:\n"
    "1 - Inserir no inicio da lista\n"
    "2 - Inserir no fim da lista\n"
    "3 - Inserir na posicao N da lista\n"
    "4 - Retirar um no do inicio da lista\n"
    "5 - Retirar um no no fim da lista\n"
    "6 - Retirar um no na posição N\n"
    "7 - Procurar um no com o campo RG\n"
    "8 - Mostrar a lista na tela\n"
    "9 - Salvar a lista em um arquivo\n"
    "10 - Ler a lista de um arquivo\n"
    "11 - Sair do sistema\n");
    scanf("%d", &opcao);

    while(opcao != 11){
        if (opcao == 1){
            comparacao=0;
            movimentacao=0;

            printf("Nome: ");
            scanf("%s", nome);
            printf("Rg: ");
            scanf("%ld", &rg);

            clock_t inicioTempo = clock();

            movimentacao++;
            aux = (Pessoa *)malloc(sizeof(Pessoa));

            strcpy(aux->nome, nome);
            aux->rg = rg;

            movimentacao++;
            aux->proximo = inicio;
            inicio = aux;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;

            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, 0);

            qnt_pessoas++;

        }else if(opcao == 2){
            comparacao = 0;
            movimentacao =0;

            printf("Nome: ");
            scanf("%s", nome);
            printf("Rg: ");
            scanf("%ld", &rg);

            clock_t inicioTempo = clock();

            movimentacao++;
            aux = (Pessoa *)malloc(sizeof(Pessoa));

            strcpy(aux->nome, nome);
            aux->rg = rg;
            aux->proximo = NULL;

            movimentacao++;
            ultimo->proximo = aux;
            ultimo = aux;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;

            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, 0);

            qnt_pessoas++;

        }else if (opcao == 3){
            comparacao = 0;
            movimentacao =0;

            printf("Posicao: ");
            scanf("%d", &posicao);

            comparacao++;
            if (posicao<0 || posicao>qnt_pessoas){
                printf("Posicao invalida.");
                opcao =0;
                continue;
            }

            printf("Nome: ");
            scanf("%s", nome);
            printf("Rg: ");
            scanf("%ld", &rg);

            clock_t inicioTempo = clock();

            movimentacao++;
            aux = (Pessoa *)malloc(sizeof(Pessoa));

            strcpy(aux->nome, nome);
            aux->rg = rg;

            anterior = inicio;
            for(i=0; i<posicao; i++, comparacao++){
                movimentacao++;
                anterior = anterior->proximo;
            }
            movimentacao+=2;
            aux->proximo = anterior->proximo;
            anterior->proximo = aux;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;

            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, i);

            qnt_pessoas++;
        }else if (opcao == 4){
            comparacao = 0;
            movimentacao =0;
            clock_t inicioTempo = clock();

            strcpy(nome, inicio->nome);
            rg = inicio->rg;

            movimentacao++;
            inicio=inicio->proximo;

            movimentacao++;
            free(inicio);

            qnt_pessoas--;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;
            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, 0);

        }else if(opcao == 5){
            comparacao = 0;
            movimentacao =0;
            clock_t inicioTempo = clock();

            aux = inicio;
            while(aux->proximo != ultimo){
                comparacao++;

                movimentacao++;
                aux = aux->proximo;
            }

            strcpy(nome, ultimo->nome);
            rg->ultimo->rg;

            movimentacao+=2;
            aux->proximo = NULL;
            free(ultimo);
            ultimo = aux;

            qnt_pessoas--;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;
            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, qnt_pessoas);

        }else if(opcao == 6){
            comparacao = 0;
            movimentacao =0;

        
            printf("Posicao: ");
            scanf("%d", &posicao);

            clock_t inicioTempo = clock();

            comparacao++;
            if (posicao<0 || posicao>=qnt_pessoas){
                printf("Posicao invalida.");
                opcao =0;
                continue;
            }

            anterior = inicio;
            for (i=0; i<posicao-1; i++, comparacao++){
                movimentacao++;
                anterior = anterior->proximo;
            }

            movimentacao+=3;
            aux = anterior->proximo;
            anterior->proximo = aux->proximo;

            strcpy(nome, aux->nome);
            rg = aux->rg;

            free(aux);
            qnt_pessoas--;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;
            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, posicao);
        }else if(opcao == 7){
            comparacao = 0;
            movimentacao =0;

            printf("Digite o rg para a busca: ");
            scanf("%ld", rg);

            clock_t inicioTempo = clock();

            aux = inicio;
            posicao=0;
            while(anterior->rg != rg){
                aux++;

                movimentacao++;
                aux = aux->proximo;

                posicao++;
            }

            strcpy(nome, aux->nome);
            rg = aux->rg;

            clock_t fimTempo = clock();
            tempo = (double)(fimTempo-inicioTempo) / CLOCKS_PER_SEC;
            printf("Nome: %s  |Rg: %ld  |C: %d  |M  %d  |Tempo: %.12f |Posicao: %d\n", nome, rg, comparacao, movimentacao, tempo, posicao);
        }else if(opcao == 8){
            i =0;
            aux = inicio;
            while(aux != NULL){
                printf("%d - Nome: %15s|RG: %15ld\n", i, aux->nome, aux->rg);
                aux = aux->proximo;
                i++;
            }
        }else if(opcao == 9){

            FILE *arq_saida = fopen("lista_saida.txt", "w");
    
            comparacao++;
            if (arq_saida == NULL){
                printf("Erro abindo o arquivo.");
                return 1;
            }

            aux = inicio;
            while(aux->proximo != NULL){
                fprintf()
            }

        }
        
    }

    return 0;
}
