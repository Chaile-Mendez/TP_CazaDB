#ifndef __COMANDOS_H__
#define __COMANDOS_H__

void log_c(char character);
void log_i(int integer);
void log_s(char string[]);

void ejecutar_comando(char comando[MAX_LONGITUD_COMANDO]);

void listar_super();

void contactar_super();

void modificar_super();

void agregar_super();

void mostrar_ayuda();

void asignar_datos_segun_comando(parametros_comando_t *solicitud, char *argumentos[], int cantidad_argumentos);

#endif /* __COMANDOS_H__ */