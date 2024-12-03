#ifndef LISTASONDA_H
#define LISTASONDA_H
#define MAXTAM 3
#include "Sonda.h"

typedef struct CelulaSonda *ApontadorSonda;
typedef struct CelulaSonda
{
    Sonda sondas;
    struct CelulaSonda *pProx;
}CSonda;

typedef struct 
{
    ApontadorSonda pPrimeiro;
    ApontadorSonda pUltimo;
}LSonda;

void FLVaziaSonda(LSonda* sLista);
void InsereSondas(LSonda* sLista, Sonda sondas[]);
void LImprime(LSonda* sLista);
int Peso_Sonda(LSonda* sonda);
int Valor_Sonda(LSonda* sonda);

#endif