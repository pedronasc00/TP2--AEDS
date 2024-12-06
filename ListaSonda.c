#include <stdio.h>
#include <stdlib.h>
#include "ListaSonda.h"
#define NUM_SONDAS 3

void FLVaziaSonda(LSonda* sLista){
    sLista->pPrimeiro = (ApontadorSonda)malloc(sizeof(CSonda));
    sLista->pUltimo = sLista->pPrimeiro;
    sLista->pUltimo->pProx = NULL;
}

void InsereSondas(LSonda* sLista){
    for (int i = 0; i < NUM_SONDAS; i++) {
        Sonda* sondasI = (Sonda*)malloc(sizeof(Sonda));
        InicializaSonda(sondasI, i + 1);
        FLVaziaRocha(&sondasI->CompartimentoR); // Inicializa compartimento da sonda original
        
        sLista->pUltimo->pProx = (ApontadorSonda)malloc(sizeof(CSonda));
        sLista->pUltimo = sLista->pUltimo->pProx;
        sLista->pUltimo->sondas = sondasI;
        sLista->pUltimo->pProx = NULL;   
    }
}

void LImprimeSonda(LSonda* sLista) {
    ApontadorSonda pAux;
    pAux = sLista->pPrimeiro->pProx;

    printf("\nSONDAS\n");
    printf("---------------------------------\n\n");
    while (pAux != NULL) {
        printf("ID SONDA: %d\n", pAux->sondas->idSonda);
        printf("Peso Total: %d\n", pAux->sondas->pesoAtual);
        printf("Capacidade: %d\n\n", pAux->sondas->capacidade);

        pAux = pAux->pProx;
    }
    printf("---------------------------------\n");
}

int Peso_Sondas(LSonda* sLista) {
    
    int pesoSonda = 0;

    if (sLista == NULL || sLista->pPrimeiro->pProx->sondas->CompartimentoR.pPrimeiro->pProx == NULL) {
        return 0;
    }
    ApontadorRocha pAux;
    pAux = sLista->pPrimeiro->pProx->sondas->CompartimentoR.pPrimeiro->pProx;
    
    while (pAux != NULL) {
        pesoSonda += pAux->ItemRocha.pesoI;
        pAux = pAux->pProx;
    }

    return pesoSonda;
}

int Valor_Sondas(LSonda* sLista) {
    
    int valorSonda = 0;

    if (sLista == NULL || sLista->pPrimeiro->pProx->sondas->CompartimentoR.pPrimeiro->pProx == NULL) {
        return 0;
    }
    ApontadorRocha pAux;
    pAux = sLista->pPrimeiro->pProx->sondas->CompartimentoR.pPrimeiro->pProx;
    
    while (pAux != NULL) {
        valorSonda += pAux->ItemRocha.valorI;
        pAux = pAux->pProx;
    }

    return valorSonda;
}

void liberarSondas(LSonda* sLista) {
    ApontadorSonda pAux = sLista->pPrimeiro;
    while (pAux != NULL) {
        ApontadorSonda temp = pAux;
        pAux = pAux->pProx;

        if (temp->sondas != NULL) {  // Libera a memória da Sonda
            free(temp->sondas);
        }
        free(temp); // Libera a memória do nó da lista
    }
    sLista->pPrimeiro = NULL;
    sLista->pUltimo = NULL;
}
