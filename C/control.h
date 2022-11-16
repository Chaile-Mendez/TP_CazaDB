#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "constantes.h"


void listar_ids(int lista_ids[MAX_LINEAS], int *tope_ids, FILE *archivo);

int busqueda_binaria(int buscado, int vector[], int tope);

int busqueda_binaria_rec(int buscado, int vector[], int minimo, int maximo);

#endif /* __CONTROL_H__ */