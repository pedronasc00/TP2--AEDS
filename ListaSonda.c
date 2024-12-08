#include <stdio.h>
#include <stdlib.h>
#include "ListaSonda.h"
#include <string.h>
#define NUM_SONDAS 3
#define MAXCAP 40

void FLVaziaSonda(LSonda *sLista)
{
    sLista->pPrimeiro = (ApontadorSonda)malloc(sizeof(CSonda));
    sLista->pUltimo = sLista->pPrimeiro;
    sLista->pUltimo->pProx = NULL;
}

void LInsereSondas(LSonda *sLista, Sonda *pSonda)
{
    sLista->pUltimo->pProx = (ApontadorSonda)malloc(sizeof(CSonda));
    sLista->pUltimo = sLista->pUltimo->pProx;
    sLista->pUltimo->ItemSonda = *pSonda;
    sLista->pUltimo->pProx = NULL;
}

void LImprimeSonda(LSonda *sLista)
{
    ApontadorSonda pAux;
    pAux = sLista->pPrimeiro->pProx;

    printf("\nSONDAS\n");
    printf("---------------------------------\n\n");
    while (pAux != NULL)
    {
        printf("ID SONDA: %d\n", pAux->ItemSonda.idSonda);
        printf("Capacidade: %d\n\n", pAux->ItemSonda.capacidade);

        pAux = pAux->pProx;
    }
    printf("---------------------------------\n");
}

int knapsack(Rocha rochas[], int n, int capacity, int *selecionados, int *usados)
{
    // Alocação dinâmica para dp e keep
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    int **keep = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
        keep[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }

    // Inicializar dp e keep com 0
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= capacity; w++)
            dp[i][w] = keep[i][w] = 0;

    // Preenchendo dp e keep
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (rochas[i - 1].pesoI <= w && !usados[i - 1])
            {
                int incluir = rochas[i - 1].valorI + dp[i - 1][w - rochas[i - 1].pesoI];
                int excluir = dp[i - 1][w];
                if (incluir > excluir)
                {
                    dp[i][w] = incluir;
                    keep[i][w] = 1;
                }
                else
                {
                    dp[i][w] = excluir;
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Reconstruir solução
    int w = capacity;
    int totalValor = dp[n][capacity];
    int idx = 0;
    int pesoAcumulado = 0;

    for (int i = n; i > 0; i--)
    {
        if (keep[i][w])
        {
            if (pesoAcumulado + rochas[i - 1].pesoI > MAXCAP)
                continue;

            selecionados[idx++] = i - 1;
            usados[i - 1] = 1;
            w -= rochas[i - 1].pesoI;
            pesoAcumulado += rochas[i - 1].pesoI;
        }
    }
    selecionados[idx] = -1;

    // Liberar memória das matrizes dp e keep
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
        free(keep[i]);
    }
    free(dp);
    free(keep);

    return totalValor;
}
void ordenarArray(int array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void resolverSondas(LSonda *ListaS, int n_sondas, Rocha rochas[], int n)
{
    int *usados = (int*)malloc(n * sizeof(int));  // Alocação dinâmica
    if (usados == NULL) {
        fprintf(stderr, "Falha na alocação de memória para o vetor usados.\n");
        return ;
    }
     // Inicializa todos os valores de usados como 0
    memset(usados, 0, n * sizeof(int));
    int *selecionados = (int*)malloc(n * sizeof(int));  // Alocação dinâmica
    if (selecionados == NULL) {
        fprintf(stderr, "Falha na alocação de memória para o vetor selecionados.\n");
        free(usados);
        return ;
    }

    ApontadorSonda atual = ListaS->pPrimeiro->pProx;  // Ponteiro para o primeiro elemento da lista encadeada

    for (int i = 0; i < n_sondas && atual != NULL; i++) {

        int valorTotal = knapsack(rochas, n, atual->ItemSonda.capacidade, selecionados, usados);

        int tamanho = 0;
        while (selecionados[tamanho] != -1) {
            tamanho++;
        }

        ordenarArray(selecionados, tamanho);

        int pesoTotal = 0;
        printf("Sonda %d: Peso ", atual->ItemSonda.idSonda);  // Usando 'atual->sonda.id' para acessar o id da sonda corrente
        for (int j = 0; j < tamanho; j++) {
            int idx = selecionados[j];
            pesoTotal += rochas[idx].pesoI;
        }
        printf("%d, Valor %d, Solucao [", pesoTotal, valorTotal);
        for (int j = 0; j < tamanho; j++) {
            printf("%d", selecionados[j]);
            if (j < tamanho - 1)
                printf(", ");
        }
        printf("]\n");

        atual = atual->pProx;  // Avança para a próxima sonda na lista encadeada
    }
    free(usados);
    free(selecionados);
}