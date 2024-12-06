#ifndef LISTASONDA_H
#define LISTASONDA_H
#define MAXTAM 3
#include "Sonda.h"

typedef struct CelulaSonda *ApontadorSonda;
typedef struct CelulaSonda
{
    Sonda *sondas;
    struct CelulaSonda *pProx;
}CSonda;

typedef struct 
{
    ApontadorSonda pPrimeiro;
    ApontadorSonda pUltimo;
}LSonda;

void FLVaziaSonda(LSonda* sLista);
void InsereSondas(LSonda* sLista);
void LImprimeSonda(LSonda* sLista);
void liberarSondas(LSonda* sLista);

#endif