#include "constantes.h"
#include "comandos.h"
#include <stdio.h>

/**/
void log_c(char character)
{
    printf("%c\n", character);
}
void log_i(int integer)
{
    printf("%i\n", integer);
}
void log_s(char string[])
{
    printf("%s\n", string);
}
/**/



void listar_super()
{
    printf("lista los supers");
}
void contactar_super()
{
    printf("contacta un super");
}
void modificar_super()
{
    printf("Modifica un super");
}
void agregar_super()
{
    printf("agrega un super heroe");
}
void mostrar_ayuda()
{
    printf("mostrar informacion del programa");
}

int contar_argumentos_minimos(char comando[MAX_LONGITUD_COMANDO])
{

    if ((strcmp(comando, COMANDO_LISTAR_SUPERS)) == 0)
    {
        return MINIMO_ARGUMENTOS_LISTAR;
    }
    else if (strcmp(comando, COMANDO_CONTACTAR_SUPER) == 0)
    {
        return MINIMO_ARGUMENTOS_CONTACTAR;
    }
    else if (!strcmp(comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        return MINIMO_ARGUEMENTOS_MODIFICAR;
    }
    else if (!strcmp(comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        return MINIMO_ARGUEMENTOS_AGREGAR;
    }
    else
    {
        return 2;
    }
}

void asignar_datos_segun_comando(parametros_comando_t *solicitud, char *argumentos[], int cantidad_argumentos)
{
    strcpy(solicitud->comando, *(&argumentos[POSICION_COMANDO]));
    solicitud->cantidad_arguementos = cantidad_argumentos;

    int minimo_argumentos = contar_argumentos_minimos(solicitud->comando);
    if (cantidad_argumentos < minimo_argumentos)
    {
        printf("se necesitan almenos %i arguementos para este comando", minimo_argumentos);
    }
    else
    {
        if ((strcmp(solicitud->comando, COMANDO_LISTAR_SUPERS)) == 0)
        {

            strcpy(solicitud->archivo, *(&argumentos[LISTAR_POSICION_ARCHIVO]));
        }
        else if (!strcmp(solicitud->comando, COMANDO_CONTACTAR_SUPER))
        {

            strcpy(solicitud->archivo, *(&argumentos[CONTACTAR_POSICION_ARCHIVO]));
            solicitud->heroe.id = atoi(argumentos[CONTACTAR_POSICION_ID]);
        }
        else if (strcmp(solicitud->comando, COMANDO_MODIFICAR_SUPER) == 0)
        {

            strcpy(solicitud->archivo, *(&argumentos[MODIFICAR_POSICION_ARCHIVO]));
            solicitud->heroe.id = atoi(argumentos[MODIFICAR_POSICION_ID]);
            solicitud->heroe.edad = atoi(argumentos[MODIFICAR_POSICION_EDAD]);
            solicitud->heroe.estado = argumentos[MODIFICAR_POSICION_ESTADO][0];
        }
        else if (strcmp(solicitud->comando, COMANDO_AGREGAR_SUPER) == 0)
        {

            strcpy(solicitud->archivo, *(&argumentos[AGREGAR_POSICION_ARCHIVO]));
            strcpy(solicitud->heroe.nombre, *(&argumentos[AGREGAR_POSICION_NOMBRE]));
            solicitud->heroe.id = atoi(argumentos[AGREGAR_POSICION_ID]);
            solicitud->heroe.edad = atoi(argumentos[AGREGAR_POSICION_EDAD]);
            solicitud->heroe.estado = argumentos[AGREGAR_POSICION_ESTADO][0];
        }
        else if (strcmp(solicitud->comando, COMANDO_AYUDA) == 0)
        {
            mostrar_ayuda();
        }
    }
}