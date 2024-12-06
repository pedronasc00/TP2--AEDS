#include <stdio.h>
#include <stdlib.h>
#include "Rocha.h"

void InicializaRocha(Rocha* rch, int idRocha, int pesoI, int valorI){
    rch->idRocha = idRocha;
    rch->pesoI = pesoI;
    rch->valorI = valorI;
}