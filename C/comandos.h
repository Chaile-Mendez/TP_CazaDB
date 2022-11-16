#ifndef __COMANDOS_H__
#define __COMANDOS_H__

void log_c(char character);
void log_i(int integer);
void log_s(char string[]);

void listar_super(parametros_comando_t datos);

void contactar_super(parametros_comando_t datos);

void modificar_super(parametros_comando_t datos);

void agregar_super(parametros_comando_t datos);

void mostrar_ayuda();

void asignar_datos_segun_comando(parametros_comando_t *solicitud, char *argumentos[], int cantidad_argumentos);

void ejecutar_solicitud(parametros_comando_t query);

#endif /* __COMANDOS_H__ */