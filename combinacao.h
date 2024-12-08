#ifndef COMBINACAO_H
#define COMBINACAO_H
#include "ListaSonda.h"

void combinar(int n, int k, int indice, int *combinacao_atual, int *tamanho_rochas_selecionadas, LCompartimento *rochas_selecionadas, LCompartimento *rLista);
void gerar_combinacoes(int n, int k, LCompartimento *rLista, int *tamanho_rochas_selecionadas, LCompartimento *rochas_selecionadas);
void problemaMochila(LSonda *sLista, LCompartimento *rLista, int N);
void ImprimeSolucao(Sonda *sonda);
#endif