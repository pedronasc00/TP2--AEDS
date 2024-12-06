#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combinacao.h"

int main() {
    LSonda ListaSondas;
    LCompartimento ListaDistribuidora;
    Sonda sondas[3];
    int valorI, pesoI;
    
    printf("Nome do arquivo de entrada: ");
    
    char nomearq[33];
    FILE *arq;
    scanf("%32s", nomearq);
    arq = fopen(nomearq, "r");

    int N;

    fscanf(arq, "%d", &N);

    FLVaziaSonda(&ListaSondas);
    FLVaziaRocha(&ListaDistribuidora);

    InsereSondas(&ListaSondas);

    for(int i = 0; i < N; i++){
        Rocha rochaI;
        fscanf(arq, "%d %d", &pesoI, &valorI);
        InicializaRocha(&rochaI, i++, pesoI, valorI);
        InsereRocha(&ListaDistribuidora, &rochaI);
    }

    problemaMochila(&ListaSondas, &ListaDistribuidora, N);
    
}