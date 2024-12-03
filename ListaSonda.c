#include <stdio.h>
#include <stdlib.h>
#include "ListaSonda.h"
#define NUM_SONDAS 3

void FLVaziaSonda(LSonda* sLista){
    sLista->pPrimeiro = (ApontadorSonda)malloc(sizeof(CSonda));
    sLista->pUltimo = sLista->pPrimeiro;
    sLista->pUltimo->pProx = NULL;
}

void InsereSondas(LSonda* sLista, Sonda* sondas[]){
    sondas[NUM_SONDAS];

    for (int i = 0; i < NUM_SONDAS; i++)
    {
        InicializaSonda(&sondas[i], i + 1);
        sLista->pUltimo->pProx = (ApontadorSonda)malloc(sizeof(CSonda));
        sLista->pUltimo = sLista->pUltimo->pProx;
        sLista->pUltimo->sondas = *sondas[i];
        sLista->pUltimo->pProx = NULL;   
    }

}