#include "constantes.h"
#include "comandos.h"
#include <stdio.h>

void ejecutar_comando(char comando[MAX_LONGITUD_COMANDO])
{
    if (!strcmp(comando, COMANDO_LISTAR_SUPERS))
    {
        listar_super();
    }
    else if (!strcmp(comando, COMANDO_MODIFICAR_SUPER))
    {
        modificar_super();
    }
    else if (!strcmp(comando, COMANDO_AGREGAR_SUPER))
    {
        agregar_super();
    }
    else if (!strcmp(comando, COMANDO_CONTACTAR_SUPER))
    {
        contactar_super();
    }
    else if (!strcmp(comando, COMANDO_AYUDA))
    {
        mostrar_ayuda();
    }

    printf("\nse ejecuta %s\n", comando);
}

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

void asignar_datos_segun_comando(parametros_comando_t *comando, char argumentos[])
{
    if ((strcmp(comando->comando, COMANDO_LISTAR_SUPERS))==0)
    {
        printf("comando listar\n\n");
        if (comando->cantidad_arguementos == CANTIDAD_ARGUEMENTOS_LISTAR)
        {
            strcpy(comando->archivo, &argumentos[LISTAR_POSICION_ARCHIVO]);
        }
        else
        {
            printf("se necesitan %i arguementos para este comando", CANTIDAD_ARGUEMENTOS_LISTAR);
        }
    }
    else if (!strcmp(comando->comando, COMANDO_CONTACTAR_SUPER))
    {
        if (comando->cantidad_arguementos == CANTIDAD_ARGUEMENTOS_CONTACTAR)
        {
            strcpy(comando->archivo, &argumentos[CONTACTAR_POSICION_ARCHIVO]);
            comando->id = argumentos[CONTACTAR_POSICION_ID];
        }
        else
        {
            printf("se necesitan %i arguementos para este comando", CANTIDAD_ARGUEMENTOS_CONTACTAR);
        }
    }
    else if (!strcmp(comando->comando, COMANDO_MODIFICAR_SUPER))
    {
        if (comando->cantidad_arguementos == CANTIDAD_ARGUEMENTOS_MODIFICAR)
        {
            strcpy(comando->archivo, &argumentos[MODIFICAR_POSICION_ARCHIVO]);
            comando->id = argumentos[MODIFICAR_POSICION_ID];
            comando->edad = argumentos[MODIFICAR_POSICION_EDAD];
            comando->estado = argumentos[MODIFICAR_POSICION_ESTADO];
        }
        else
        {
            printf("se necesitan %i arguementos para este comando", CANTIDAD_ARGUEMENTOS_MODIFICAR);
        }
    }
    else if (!strcmp(comando->comando, COMANDO_AGREGAR_SUPER))
    {
        if (comando->cantidad_arguementos == CANTIDAD_ARGUEMENTOS_AGREGAR)
        {
            strcpy(comando->archivo, &argumentos[AGREGAR_POSICION_ARCHIVO]);
            strcpy(comando->nombre, &argumentos[AGREGAR_POSICION_NOMBRE]);
            comando->id = argumentos[AGREGAR_POSICION_ID];
            comando->edad = argumentos[AGREGAR_POSICION_EDAD];
            comando->estado = argumentos[AGREGAR_POSICION_ESTADO];
        }
        else
        {
            printf("se necesitan %i arguementos para este comando", CANTIDAD_ARGUEMENTOS_AGREGAR);
        }
    }
    else if (!strcmp(comando->comando, COMANDO_AYUDA))
    {
        mostrar_ayuda();
    }
}