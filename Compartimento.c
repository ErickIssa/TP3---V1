#include "Compartimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inicializarListaComp(ListaRochas* lista) {
    lista->tamanho = 0;
}

void insere_Rocha(ListaRochas* lista, RochaIndv novaRocha) {
    if (lista->tamanho >= MAX) {
        printf("Tamanho Max da lista\n");
        return;
    }
    lista->vetor[lista->tamanho] = novaRocha;
    lista->tamanho++;
    return;
}

void remove_Rocha(ListaRochas* lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Sem rocha\n");
        return;
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->vetor[i] = lista->vetor[i + 1];
    }
    lista->tamanho--;
    return;
}

void ImprimeCompartimento(ListaRochas* lista) {
    if (lista->tamanho == 0) {
        printf("Vazia\n");
        return;
    }
    printf("Lista de Rochas:\n");
    for (int i = 0; i < lista->tamanho; i++) {
       printf("%s %.1f\n", lista->vetor[i].categoria, lista->vetor[i].peso);
    }
}

void troca_rochas(RochaIndv *a, RochaIndv *b){
    RochaIndv temp = *a;
    *a = *b;
    *b = temp;
}

void algoritmo_selection(RochaIndv *rochas, int n, int *comparacoes, int *trocas){
    for(int i = 0; i < n - 1; i++){
        int menorIndice = i; // perguntar se precisa por as comparaçoes
        for(int j = i + 1; j < n;j++){
            (*comparacoes)++;
            if(rochas[j].peso < rochas[menorIndice].peso){
                menorIndice = j;
            }
        }
        if(menorIndice != i){
            troca_rochas(&rochas[i], &rochas[menorIndice]);
            (*trocas)++; 
        }
    }
}
