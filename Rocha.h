#ifndef ROCHA_H
#define ROCHA_H

#include "ListaMineral.h"

typedef struct
{
    TListaMineral *lista_mineral;
    char categoria[50];
    float peso;
    float lat_rocha, long_rocha;
} RochaIndv;

RochaIndv preenche_rocha(RochaIndv* rocha, float lat_rocha, float long_rocha, float peso, TListaMineral* lista_mineral);
double get_peso(RochaIndv *rocha);
int get_data(RochaIndv *rocha);
char *get_localizacao(RochaIndv *rocha);

void set_identificador(RochaIndv *rocha, int identificador);
void set_listaminerais(RochaIndv *rocha, TListaMineral *lista_mineral);
void set_categoria(RochaIndv *rocha, char *categoria);
void set_peso(RochaIndv *rocha, float peso);
void set_latRocha(RochaIndv *rocha, float lat_rocha);
void set_longRocha(RochaIndv *rocha, float long_rocha);
void set_data(RochaIndv *rocha, int data);

char* classificar(TListaMineral *pListaC);

#endif // ROCHA_H