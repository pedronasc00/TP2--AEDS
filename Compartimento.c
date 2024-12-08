#include <stdio.h>
#include <stdlib.h>
#include "Compartimento.h"

void FLVaziaRocha(LCompartimento *rLista)
{
    rLista->pPrimeiro = (ApontadorRocha)malloc(sizeof(CCompartimento));
    rLista->pPrimeiro->pProx = NULL;
    rLista->pUltimo = rLista->pPrimeiro;
}

void InsereRocha(LCompartimento *rLista, Rocha *pRocha)
{
    ApontadorRocha novoNo = (ApontadorRocha)malloc(sizeof(CCompartimento));
    if (novoNo == NULL)
    {
        perror("Erro de alocação de memória");
        exit(EXIT_FAILURE); // Ou trate o erro de outra forma
    }
    novoNo->ItemRocha = *pRocha;
    novoNo->pProx = NULL;

    if (rLista->pPrimeiro->pProx == NULL)
    { // Primeiro elemento depois do nó cabeça
        rLista->pPrimeiro->pProx = novoNo;
        rLista->pUltimo = novoNo; // Atualiza pUltimo
    }
    else
    {
        rLista->pUltimo->pProx = novoNo;
        rLista->pUltimo = novoNo; // Atualiza pUltimo
    }
}

void LImprimeRocha(LCompartimento *rLista)
{
    int cont = 1;
    ApontadorRocha pAux = NULL;
    pAux = rLista->pPrimeiro->pProx;

    printf("\nROCHAS\n");
    printf("----------------------------------\n\n");
    while (pAux != NULL)
    {
        printf("ID: %d\n", cont++);
        printf("Peso: %d\n", pAux->ItemRocha.pesoI);
        printf("Valor: %d\n\n", pAux->ItemRocha.valorI);

        pAux = pAux->pProx;
    }
    printf("----------------------------------\n");
}

void LiberarRochas(LCompartimento *rLista)
{
    ApontadorRocha rAux = rLista->pPrimeiro;
    while (rAux != NULL)
    {
        ApontadorRocha temp = rAux;
        temp = temp->pProx;

        free(temp);
    }
    rLista->pPrimeiro = NULL;
    rLista->pUltimo = NULL;
}

void CopiaCompartimento(LCompartimento *origem, LCompartimento *destino)
{
    FLVaziaRocha(destino);                         // Inicializa o compartimento de destino
    ApontadorRocha aux = origem->pPrimeiro->pProx; // Pula o nó cabeça
    while (aux != NULL)
    {
        Rocha *novaRocha = (Rocha *)malloc(sizeof(Rocha));
        if (novaRocha == NULL)
        {
            // Trate o erro de alocação (por exemplo, imprima uma mensagem e saia)
            perror("Erro ao alocar memória para Rocha em CopiaCompartimento");
            exit(EXIT_FAILURE);
        }
        *novaRocha = aux->ItemRocha;     // Copia os valores da rocha
        InsereRocha(destino, novaRocha); // Insere a nova rocha no destino
        free(novaRocha);                 // Libera rocha temporaria
        aux = aux->pProx;
    }
}

void RemoveRochasIguais(LCompartimento *rochasRem, LCompartimento *listaDistribuidora)
{
    ApontadorRocha auxRemover = rochasRem->pPrimeiro->pProx;
    while (auxRemover != NULL)
    {
        ApontadorRocha auxLista = listaDistribuidora->pPrimeiro;
        ApontadorRocha anterior = NULL;

        while (auxLista != NULL)
        {
            if (auxLista->pProx != NULL && auxLista->pProx->ItemRocha.pesoI == auxRemover->ItemRocha.pesoI && auxLista->pProx->ItemRocha.valorI == auxRemover->ItemRocha.valorI)
            {
                ApontadorRocha temp = auxLista->pProx;
                auxLista->pProx = temp->pProx;
                if (temp == listaDistribuidora->pUltimo)
                {
                    listaDistribuidora->pUltimo = auxLista;
                }

                free(temp);

                break; // Sai do loop interno após remover a rocha
            }

            anterior = auxLista;
            auxLista = auxLista->pProx;
        }
        auxRemover = auxRemover->pProx;
    }
}