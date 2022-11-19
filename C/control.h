#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "constantes.h"

void listar_ids(int lista_ids[MAX_LINEAS], int *tope_ids, char nombre_archivo[MAX_NOMBRE_ARCHIVO]);

int busqueda_binaria(int buscado, int vector[], int tope);

int busqueda_binaria_rec(int buscado, int vector[], int minimo, int maximo);

void reescribir_hasta(FILE *fuente, FILE *destino, int posicion);

void reescribir_hasta_final(FILE *fuente, FILE *destino);

void modificar_linea(FILE *fuente, FILE *destino, super_t *super);

void saltear_linea(FILE *fuente);

int obtener_posicion(int id, char archivo[MAX_NOMBRE_ARCHIVO]);

int leer_linea(FILE *fuente, super_t *super);

int buscar_maximo_menor(int buscado, char archivo[MAX_NOMBRE_ARCHIVO]);

void escribir_linea(FILE *archivo, super_t super);

int datos_de_heroe_segun_id(parametros_t *datos, int id);

void transcribir_hasta_id_mayor(FILE *fuente, FILE *destino, super_t super);

int mostrar_heroe_id(parametros_t *datos);

int buscar_id_menor_maxima(parametros_t datos);

void transcribir_e_insertar(FILE *fuente, FILE *destino, parametros_t datos);

bool asignar_estado(char *estado, char *argumentos[], int posicion_caracter);

bool asignar_edad(int *edad, char *argumentos[], int posicion_edad);

void estado_a_texto(char string[MAX_ANCHO_COLUMNA], char estado);

void completar_ancho_columna(char columna[MAX_ANCHO_COLUMNA], size_t ancho_maximo);

#endif /* __CONTROL_H__ */