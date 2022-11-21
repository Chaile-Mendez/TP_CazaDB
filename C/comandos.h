#ifndef __COMANDOS_H__
#define __COMANDOS_H__
#include "constantes.h"

bool listar_supers(parametros_t datos);

bool contactar_super(parametros_t datos);

bool modificar_super(parametros_t datos);

bool agregar_super(parametros_t datos);

void mostrar_ayuda();

bool asignar_datos_segun_comando(parametros_t *solicitud, char *argumentos[], int cantidad_argumentos);

bool ejecutar_solicitud(parametros_t query);

#endif /* __COMANDOS_H__ */