#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "Rocha.h"
#define MAX 100000

typedef struct {
    RochaIndv vetor[MAX];
    int tamanho;
} ListaRochas;

void inicializarListaComp(ListaRochas* lista);
void insere_Rocha(ListaRochas* lista, RochaIndv novaRocha);
void remove_Rocha(ListaRochas* lista, int indice);
void ImprimeCompartimento(ListaRochas* lista);
void troca_rochas(RochaIndv *a, RochaIndv *b);
void algoritmo_selection(RochaIndv *rochas, int n, int *comparacoes, int *trocas);
void Particao(int Esq, int Dir, int *i, int *j, ListaRochas *vetor);
void Ordena(int Esq, int Dir, ListaRochas *vetor);
void algoritmo_quickSort(ListaRochas *vetor);

#endif