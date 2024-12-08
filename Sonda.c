#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

void InicializaSonda(Sonda *sonda, int idSonda)
{
    sonda->idSonda = idSonda;
    sonda->capacidade = MAXCAP;
    sonda->pesoAtual = 0;
    sonda->valorAtual = 0;
}

int PesoSonda(LCompartimento *CompartimentoSonda)
{

    int pesoSonda = 0;

    ApontadorRocha pAux = CompartimentoSonda->pPrimeiro->pProx;

    while (pAux != NULL)
    {
        pesoSonda += pAux->ItemRocha.pesoI;
        pAux = pAux->pProx;
    }
    return pesoSonda;
}

int ValorSonda(LCompartimento *CompartimentoSonda)
{

    int valorSonda = 0;

    ApontadorRocha pAux = CompartimentoSonda->pPrimeiro->pProx;

    while (pAux != NULL)
    {
        valorSonda += pAux->ItemRocha.valorI;
        pAux = pAux->pProx;
    }

    return valorSonda;
}