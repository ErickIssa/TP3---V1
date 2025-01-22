#include "Compartimento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t inicio = clock();

    int qntdOperacoes; 
    int comparacoes = 0;
    int trocas = 0;
    ListaRochas compartimentoL;
    inicializarListaComp(&compartimentoL);


    FILE *arq = NULL;
        arq = fopen("teste", "r");
        if (arq == NULL)
        {
            printf("falha na leitura\n");
            exit(0);
        }
    fscanf(arq, "%d", &qntdOperacoes);

    for(int i = 0;i < qntdOperacoes;i++)
    {
    RochaIndv novarocha;
    float lat, long_i, peso;
    char minerais[100];
    TMineral x;
    TListaMineral listaM;
    
    fscanf(arq, "%f %f %f", &lat, &long_i, &peso);
    
    
    FLVaziaM(&listaM);
    fgets(minerais, 100, arq);
    
    if(minerais[strlen(minerais)-1] == '\n'){
        minerais[strlen(minerais)-1] = '\0';
    }
    else{
        minerais[strlen(minerais)] = '\0';
    }
    // Quebra os minerais em partes e adiciona à lista
    const char delim[] = " ";
    char *parte = strtok(minerais, delim);
    

    while (parte != NULL)
    {
        strcpy(x.nomeM, parte);
        LInsereM(&listaM, x);
        parte = strtok(NULL, delim);
    }
    novarocha = preenche_rocha(&novarocha, lat, long_i, peso, &listaM);
    insere_Rocha(&compartimentoL, novarocha);
    }


    int caso;
    printf("---Digite o (1) para SelectionSort, Digite (2) para QuickSort--\n");
    scanf("%d", &caso);
    switch (caso)
    {
    case 1:{
        //algoritmo_quickSort(&compartimentoL);
        algoritmo_selection(&compartimentoL, qntdOperacoes, &comparacoes, &trocas);
        ImprimeCompartimento(&compartimentoL);
        printf("comparações: %d  trocas: %d\n", comparacoes, trocas);
        fclose(arq);

        clock_t fim = clock();
        double tempo_decorrido = (double)(fim - inicio) / 1000000;
        printf("Tempo gasto: %f segundos\n", tempo_decorrido);
        printf("\n"); 

        break;
    }
    case 2:
    {
        algoritmo_quickSort(&compartimentoL);
        fclose(arq);

        clock_t fim = clock();
        double tempo_decorrido = (double)(fim - inicio) / 1000000;
        printf("Tempo gasto: %f segundos\n", tempo_decorrido);
        printf("\n"); 

        break;
    }
    }
  

    return 0;
}