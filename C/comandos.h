#ifndef __COMANDOS_H__
#define __COMANDOS_H__
#include "constantes.h"

int listar_super(parametros_t datos);

int contactar_super(parametros_t datos);

int modificar_super(parametros_t datos);

int agregar_super(parametros_t datos);

void mostrar_ayuda();

void asignar_datos_segun_comando(parametros_t *solicitud, char *argumentos[], int cantidad_argumentos);

void ejecutar_solicitud(parametros_t query);

#endif /* __COMANDOS_H__ */