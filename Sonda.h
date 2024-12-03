#ifndef SONDA_H
#define SONDA_H
#include "Compartimento.h"
#define MAXCAP 40

typedef struct 
{
    int id;
    float capacidade;
    LCompartimento CompartimentoR;
}Sonda;

void InicializaSonda(Sonda* sonda, int id);

#endif