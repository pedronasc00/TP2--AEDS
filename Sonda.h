#ifndef SONDA_H
#define SONDA_H
#include "Compartimento.h"
#define MAXCAP 40

typedef struct
{
    int idSonda;
    int capacidade;
    int pesoAtual;
    int valorAtual;
    LCompartimento CompartimentoR;
} Sonda;

void InicializaSonda(Sonda *sonda, int idSonda);
int PesoSonda(LCompartimento *CompartimentoSonda);
int ValorSonda(LCompartimento *CompartimentoSonda);

#endif