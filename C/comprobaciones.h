#ifndef __COMPROBACIONES_H__
#define __COMPROBACIONES_H__

#include "constantes.h"

bool comprobar_cantidad_argumentos_ok(int codigo_comando, int cantidad_argumentos);

void escribir_linea_en_consola(super_t heroe);

bool asignar_codigo_comando(char comando[MAX_LONGITUD_COMANDO], int *codigo_comando);

bool asignar_edad(int *edad, char *argumentos[], int posicion_edad);

bool asignar_estado(char *estado, char *argumentos[], int posicion_caracter);

bool asignar_id(int *id, char *argumentos[], int posicion_caracter);

bool asignar_nombre(char nombre[MAX_NOMBRE], char *argumentos[], int posicion_caracter);

#endif /* __COMPROBACIONES_H__ */