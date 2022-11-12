#ifndef __COMANDOS_H__
#define __COMANDOS_H__

void ejecutar_comando(char comando[MAX_LONGITUD_COMANDO]);

void listar_super();

void contactar_super();

void modificar_super();

void agregar_super();

void mostrar_ayuda();

void asignar_datos_segun_comando(parametros_comando_t *comando, char argumentos[]);

#endif /* __COMANDOS_H__ */