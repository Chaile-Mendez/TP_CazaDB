#ifndef __COMPROBACIONES_H__
#define __COMPROBACIONES_H__

#include "constantes.h"

int contar_argumentos_minimos(char comando[MAX_LONGITUD_COMANDO]);

bool comprobar_edad(int edad);

bool comprobar_estado(char estado);

bool comprobar_nombre(char nombre[MAX_NOMBRE]);

void escribir_linea(parametros_comando_t datos);

void leer_linea(FILE *archivo, parametros_comando_t *datos);

#endif /* __COMPROBACIONES_H__ */