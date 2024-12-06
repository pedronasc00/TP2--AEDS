#include <stdio.h>
#include <stdlib.h>
# include "combinacao.h"

void combinar(int N, int K, int indice, int *combinacao_atual, int *tamanho_rochas_selecionadas, LCompartimento *rochas_selecionadas, LCompartimento *rLista) {
    if (K == 0) {
      for(int i = 0; i < *tamanho_rochas_selecionadas; i++){
        ApontadorRocha aux = rLista->pPrimeiro->pProx;
        for(int j = 0; j < combinacao_atual[i] - 1; j++){
            aux = aux->pProx;
        }
        InsereRocha(rochas_selecionadas, &aux->ItemRocha);
      }

      *tamanho_rochas_selecionadas = 0;
        return;
    }

    if (N < K) {
        return;
    }


    combinacao_atual[K - 1] = indice + 1;
    combinar(N - 1, K - 1, indice + 1, combinacao_atual, tamanho_rochas_selecionadas, rochas_selecionadas, rLista);
    
    if(N > K){
        combinar(N - 1, K, indice + 1, combinacao_atual, tamanho_rochas_selecionadas, rochas_selecionadas, rLista);
    }
}

void gerar_combinacoes(int N, int K, LCompartimento *rLista, int *tamanho_rochas_selecionadas, LCompartimento *rochas_selecionadas) {
    if (K < 0 || K > N) {
        return; // Combinação inválida
    }

    int combinacao_atual[K];
    *tamanho_rochas_selecionadas = K;

    combinar(N, K, -1, combinacao_atual, tamanho_rochas_selecionadas, rochas_selecionadas, rLista);
    
}

void problemaMochila(LSonda* sLista, LCompartimento* rLista, int N) {
    ApontadorSonda sAux = sLista->pPrimeiro->pProx;
    while (sAux != NULL) {
        Sonda *sondaAtual = sAux->sondas;
        int melhorValor = -1;
        LCompartimento melhorCombinacao;
        FLVaziaRocha(&melhorCombinacao);

        for (int K = 1; K <= N; K++) {
            LCompartimento rochas_select;
            FLVaziaRocha(&rochas_select);
            int tamanho_rochasS = 0;

            gerar_combinacoes(N, K, rLista, &tamanho_rochasS, &rochas_select);

            int peso_total = 0;
            int valor_total = 0;

            ApontadorRocha rAux = rochas_select.pPrimeiro->pProx;
            while (rAux != NULL) {
                peso_total += rAux->ItemRocha.pesoI;
                valor_total += rAux->ItemRocha.valorI;
                rAux = rAux->pProx;
            }

            if (peso_total <= sondaAtual->capacidade && valor_total > melhorValor) {
                melhorValor = valor_total;
                LiberarRochas(&melhorCombinacao);
                CopiaCompartimento(&rochas_select, &melhorCombinacao);
            }
            
            LiberarRochas(&rochas_select);
        }

        ApontadorRocha melhorCombAux = melhorCombinacao.pPrimeiro->pProx;
        while (melhorCombAux != NULL) {
            InsereRocha(&sondaAtual->CompartimentoR, &melhorCombAux->ItemRocha);
            melhorCombAux = melhorCombAux->pProx;
        }

        RemoveRochasIguais(&melhorCombinacao, rLista);

        LiberarRochas(&melhorCombinacao);
        sAux = sAux->pProx;
    }
}