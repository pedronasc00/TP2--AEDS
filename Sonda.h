#ifndef SONDA_H
#define SONDA_H
#include "Compartimento.h"
#define MAXCAP 40

typedef struct 
{
    int id;
    int capacidade;
    int pesoAtual;
    LCompartimento CompartimentoR;
}Sonda;

void InicializaSonda(Sonda* sonda, int id);

#endif