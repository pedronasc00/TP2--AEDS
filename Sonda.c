#include <stdio.h>
#include <stdlib.h>
#include "Sonda.h"

void InicializaSonda(Sonda* sonda, int id){
    sonda->id = id;
    sonda->capacidade = MAXCAP;
}