#include <stdio.h>
#include <stdlib.h>
#include "Compartimento.h"

void FLVazia(LCompartimento* rLista){
    rLista->pPrimeiro = (ApontadorRocha)malloc(sizeof(CCompartimento));
    rLista->pUltimo = rLista->pPrimeiro;
    rLista->pPrimeiro->pProx = NULL;
}

void InsereRocha(LCompartimento* rLista, Rocha* pRocha){
    rLista->pUltimo->pProx = (ApontadorRocha)malloc(sizeof(CCompartimento));
    rLista->pUltimo = rLista->pUltimo->pProx;
    rLista->pUltimo->ItemRocha = *pRocha;
    rLista->pUltimo->pProx = NULL;
}
