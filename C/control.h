#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "constantes.h"

int leer_linea(FILE *fuente, super_t *super);

void escribir_linea(FILE *archivo, super_t super);

void modificar_linea(FILE *fuente, FILE *destino, super_t *super);

void estado_a_texto(char columna[MAX_ANCHO_COLUMNA], char estado);

void completar_ancho_columna(char columna[MAX_ANCHO_COLUMNA], size_t ancho_maximo);

bool transcribir_y_modificar(FILE *fuente, FILE *destino, parametros_t datos);

bool transcribir_y_borrar(FILE *fuente, FILE *destino, parametros_t datos);

bool transcribir_e_insertar(FILE *fuente, FILE *destino, parametros_t datos);

#endif /* __CONTROL_H__ */