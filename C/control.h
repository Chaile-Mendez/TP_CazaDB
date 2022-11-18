#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "constantes.h"

void listar_ids(int lista_ids[MAX_LINEAS], int *tope_ids, char nombre_archivo[MAX_NOMBRE_ARCHIVO]);

int busqueda_binaria(int buscado, int vector[], int tope);

int busqueda_binaria_rec(int buscado, int vector[], int minimo, int maximo);

void reescribir_hasta(FILE *fuente, FILE *destino, int posicion);

void reescribir_hasta_final(FILE *fuente, FILE *destino);

void modificar_linea(parametros_comando_t datos, FILE *auxiliar, FILE *original);

void saltear_linea(FILE *fuente);

int obtener_posicion(int id, char archivo[MAX_NOMBRE_ARCHIVO]);

int leer_linea(FILE *fuente, datos_heroe_t *super);

int buscar_maximo_menor(int buscado, char archivo[MAX_NOMBRE_ARCHIVO]);

void escribir_linea(FILE *archivo, datos_heroe_t super);

#endif /* __CONTROL_H__ */