#include <stdio.h>
#include <stdlib.h>
#include "Rocha.h"

void InicializaRocha(Rocha *rch, int pesoI, int valorI) {
    rch->pesoI = pesoI;
    rch->valorI = valorI;
}

int comparar_rochas(const void *a, const void *b) {
    Rocha *rochaA = (Rocha *)a;
    Rocha *rochaB = (Rocha *)b;
    double razaoA = (double)rochaA->valorI / rochaA->pesoI;
    double razaoB = (double)rochaB->valorI / rochaB->pesoI;
    if (razaoA < razaoB) return 1;
    if (razaoA > razaoB) return -1;
    return 0;
}