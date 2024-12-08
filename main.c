#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSonda.h"
#include <time.h>

int main() {
    LSonda ListaSondas;
    Sonda sondas;
    int pesoI, valorI;
    int QtdSonda = 3;

    printf("Nome do arquivo de entrada: ");

    char nomearq[33];
    FILE *arq;
    scanf("%32s", nomearq);
    arq = fopen(nomearq, "r");

    int N;

    fscanf(arq, "%d", &N);
   
    FLVaziaSonda(&ListaSondas);

    for (int i = 0; i < QtdSonda; i++) {
      
        InicializaSonda(&sondas, (i + 1));
        LInsereSondas(&ListaSondas, &sondas);
    }

    Rocha *rochas = (Rocha *)malloc(N * sizeof(Rocha));
    for (int i = 0; i < N; i++) {
        if (fscanf(arq, "%d %d", &rochas[i].pesoI, &rochas[i].valorI) != 2)
        {
            fprintf(stderr, "Erro ao ler os dados do arquivo.\n");
            free(rochas);
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    
    resolverSondas(&ListaSondas, QtdSonda, rochas, N);
}
//  ApontadorRocha temp = rLista->pPrimeiro->pProx; ==> vai ter que criar esse ponteiro pra acessar as rochas
//"Rocha %d: peso=%d, valor=%d\n", i, temp->ItemRocha.pesoI, temp->ItemRocha.valorI) ====> Aqui que estao os valores da rocha