#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "Rocha.h"

typedef struct TCelulaRocha *ApontadorRocha;
typedef struct TCelulaRocha
{
    Rocha ItemRocha;
    struct TCelulaRocha *pProx; 
}CCompartimento;

typedef struct 
{
    ApontadorRocha pPrimeiro;
    ApontadorRocha pUltimo;
}LCompartimento;

void FLVaziaRocha(LCompartimento* rLista);
void InsereRocha(LCompartimento* rLista, Rocha* pRocha);
void LImprimeRocha(LCompartimento* rLista);

#endif