#ifndef LISTASONDA_H
#define LISTASONDA_H
#define MAXTAM 3
#include "Sonda.h"

typedef struct CelulaSonda *ApontadorSonda;
typedef struct CelulaSonda
{
    Sonda ItemSonda;
    struct CelulaSonda *pProx;
} CSonda;

typedef struct
{
    ApontadorSonda pPrimeiro;
    ApontadorSonda pUltimo;
} LSonda;

void FLVaziaSonda(LSonda *sLista);
void LImprimeSonda(LSonda *sLista);
void LInsereSondas(LSonda *sLista, Sonda* pSonda);
int knapsack(Rocha rochas[], int n, int capacity, int *selecionados, int *usados);
void ordenarArray(int array[], int tamanho);
void resolverSondas(LSonda *ListaS, int n_sondas, Rocha rochas[], int n);

#endif