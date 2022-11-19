#ifndef __COMPROBACIONES_H__
#define __COMPROBACIONES_H__

#include "constantes.h"

int contar_argumentos_minimos(char comando[MAX_LONGITUD_COMANDO], int cantidad_argumentos);

bool comprobar_edad_invalida(int edad);

bool comprobar_estado_invalido(char estado);

bool comprobar_nombre_invalido(char nombre[MAX_NOMBRE]);

void escribir_linea_en_consola(parametros_t datos);



#endif /* __COMPROBACIONES_H__ */