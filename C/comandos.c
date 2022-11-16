#include "constantes.h"
#include "comandos.h"
#include "comprobaciones.h"

void listar_super(parametros_comando_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo de lectura");
    }
    else
    {

        while (!feof(heroes)) // !feof(heroes)
        {
            if (CANTIDAD_COLUMNAS == fscanf(heroes, "%i;%[^;];%i;%c\n", &(datos.heroe.id), &(*datos.heroe.nombre), &(datos.heroe.edad), &(datos.heroe.estado)))
            {
                escribir_linea(datos);
            }
        }
    }
    fclose(heroes);
}

void contactar_super(parametros_comando_t datos)
{
    printf("contacta un super\n");
    printf("ID: %i\n", datos.heroe.id);
    printf("ARCHIVO: %s\n", datos.archivo);
}

void modificar_super(parametros_comando_t datos)
{
    bool si_cumple_condiciones = comprobar_edad(datos.heroe.edad) && comprobar_estado(datos.heroe.estado);
    if (si_cumple_condiciones)
    {
        printf("Modifica un super\n");
        printf("ID: %i\n", datos.heroe.id);
        printf("EDAD: %i\n", datos.heroe.edad);
        printf("ESTADO: %c\n", datos.heroe.estado);
        printf("ARCHIVO: %s\n", datos.archivo);
    }
}

void agregar_super(parametros_comando_t datos)
{
    bool si_cumple_condiciones = comprobar_edad(datos.heroe.edad) && comprobar_estado(datos.heroe.estado) && comprobar_nombre(datos.heroe.nombre);

    if (si_cumple_condiciones)
    {
        printf("agrega un super heroe\n");
        printf("ID: %i\n", datos.heroe.id);
        printf("NOMBRE: %s\n", datos.heroe.nombre);
        printf("ESTADO: %c\n", datos.heroe.estado);
        printf("EDAD: %i\n", datos.heroe.edad);
        printf("ARCHIVO: %s\n", datos.archivo);
    }
}

void mostrar_ayuda()
{
    printf("mostrar informacion del programa\n");
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
        else if (strcmp(solicitud->comando, COMANDO_CONTACTAR_SUPER) == 0)
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

void ejecutar_solicitud(parametros_comando_t query)
{

    if ((strcmp(query.comando, COMANDO_LISTAR_SUPERS)) == 0)
    {
        listar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_CONTACTAR_SUPER) == 0)
    {
        contactar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        modificar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        agregar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_AYUDA) == 0)
    {
        mostrar_ayuda();
    }
}