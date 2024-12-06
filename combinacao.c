#include <stdio.h>
#include <stdlib.h>
# include "combinacao.h"

void combinar(int N, int K, int indice, int *combinacao_atual, int *tamanho_rochas_selecionadas, LCompartimento *rochas_selecionadas, LCompartimento *rLista) {
    if (K == 0) {
      printf("Veroficação de combinar\n");
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
    printf("Gerando combinações com N = %d, k = %d\n", N, K);
    if (K < 0 || K > N) {
        return; // Combinação inválida
    }

    int combinacao_atual[K];
    *tamanho_rochas_selecionadas = K;

    printf("AAAAA\n");
    combinar(N, K, -1, combinacao_atual, tamanho_rochas_selecionadas, rochas_selecionadas, rLista);
    
}

void ImprimeSolucao(Sonda* sonda) {
    printf("Sonda %d: Peso %d, Valor %d, Solução [", sonda->idSonda, 
    sonda->pesoAtual, ValorSonda(&sonda->CompartimentoR));

    ApontadorRocha rAux = sonda->CompartimentoR.pPrimeiro->pProx;
    while (rAux != NULL) {
        printf("%d", rAux->ItemRocha.idRocha);
        if (rAux->pProx != NULL) {
            printf(", ");
        }
        rAux = rAux->pProx;
    }
    printf("]\n");
}

void problemaMochila(LSonda* sLista, LCompartimento* rLista, int N) {
    
    ApontadorSonda sAux = sLista->pPrimeiro->pProx;
    printf("N = %d\n", N);
    
    while (sAux != NULL) {
        Sonda *sondaAtual = sAux->sondas;
        int melhorValor = -1;
        LCompartimento melhorCombinacao;
        FLVaziaRocha(&melhorCombinacao);

        printf("Processando sonda %d\n", sondaAtual->idSonda);
        for (int K = 1; K <= N; K++) {
            
            LCompartimento rochas_select;
            FLVaziaRocha(&rochas_select);
            int tamanho_rochasS = 0;

            ApontadorRocha temp = rLista->pPrimeiro->pProx;
            for (int i = 0; i < 3 && temp != NULL; i++) { // Imprime os 3 primeiros elementos, por exemplo
                printf("Rocha %d: peso=%d, valor=%d\n", i, temp->ItemRocha.pesoI, temp->ItemRocha.valorI);
                temp = temp->pProx;
            }
            
            gerar_combinacoes(N, K, rLista, &tamanho_rochasS, &rochas_select);

            printf("Gerando combinações de tamanho %d\n", K);
            int peso_total = 0;
            int valor_total = 0;

            int contador = 0;
            ApontadorRocha rAux = rochas_select.pPrimeiro->pProx;
            while (rAux != NULL) {
                printf("    Dentro do while (rAux != NULL), iteração %d, peso=%d, valor=%d, rAux=%p, rAux->pProx=%p\n", contador, rAux->ItemRocha.pesoI, rAux->ItemRocha.valorI, rAux, rAux->pProx);
                peso_total += rAux->ItemRocha.pesoI;
                valor_total += rAux->ItemRocha.valorI;
                rAux = rAux->pProx;
                contador++;
            }
            printf("Fim do while, contador=%d\n", contador);

            if (peso_total <= sondaAtual->capacidade && valor_total > melhorValor) {
                melhorValor = valor_total;
                LiberarRochas(&melhorCombinacao);
                CopiaCompartimento(&rochas_select, &melhorCombinacao);
            }
            
            printf("rochas_selecionadas.pPrimeiro->pProx == NULL ?  %s\n", rochas_select.pPrimeiro->pProx == NULL ? "True" : "False");
            LiberarRochas(&rochas_select);
        }
        printf("sAux->pProx == NULL ?  %s\n", sAux->pProx == NULL ? "True" : "False");

        ApontadorRocha melhorCombAux = melhorCombinacao.pPrimeiro->pProx;
        while (melhorCombAux != NULL) {
            InsereRocha(&sondaAtual->CompartimentoR, &melhorCombAux->ItemRocha);
            melhorCombAux = melhorCombAux->pProx;
        }

        RemoveRochasIguais(&melhorCombinacao, rLista);

        sondaAtual->pesoAtual = PesoSonda(&(sondaAtual->CompartimentoR));
        sondaAtual->valorAtual = ValorSonda(&(sondaAtual->CompartimentoR));
        ImprimeSolucao(sondaAtual);

        LiberarRochas(&melhorCombinacao);
        sAux = sAux->pProx;
    }
}