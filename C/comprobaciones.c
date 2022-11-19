#include "constantes.h"
#include "control.h"

int contar_argumentos_minimos(char comando[MAX_LONGITUD_COMANDO], int cantidad_argumentos) // CAMBIAR NOMBRE DE MINIMO A CANTIDAD EXACTA
{
    int cantidad_argumentos_necesarios = ERROR;

    if ((strcmp(comando, COMANDO_LISTAR_SUPERS)) == 0)
    {
        cantidad_argumentos_necesarios = MINIMO_ARGUMENTOS_LISTAR;
    }
    else if (strcmp(comando, COMANDO_CONTACTAR_SUPER) == 0)
    {
        cantidad_argumentos_necesarios = MINIMO_ARGUMENTOS_CONTACTAR;
    }
    else if (strcmp(comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        cantidad_argumentos_necesarios = MINIMO_ARGUEMENTOS_MODIFICAR;
    }
    else if (strcmp(comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        cantidad_argumentos_necesarios = MINIMO_ARGUEMENTOS_AGREGAR;
    }

    if (cantidad_argumentos == cantidad_argumentos_necesarios)
    {
        return OK;
    }

    printf("se necesitan %i arguementos para este comando\n", cantidad_argumentos_necesarios);
    return ERROR;
}

bool comprobar_edad_invalida(int edad)
{
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA)
    {
        printf("[Solo se aceptan edades entre %i y %i]\n", EDAD_MINIMA, EDAD_MAXIMA);
        return true;
    }
    return false;
}

bool comprobar_estado_invalido(char estado)
{
    if (estado == ESTADO_VIVO || estado == ESTADO_MUERTO)
    {
        return false;
    }
    else
    {
        printf("Los caracteres validos para el estado son %c y %c\n", ESTADO_VIVO, ESTADO_MUERTO);
        return true;
    }
}

bool comprobar_nombre_invalido(char nombre[MAX_NOMBRE])
{
    if (strlen(nombre) > MAX_NOMBRE)
    {
        printf("El nombre ingresado exede el limite maximo de %i caracteres\n", MAX_NOMBRE);
        return true;
    }
    else
    {
        return false;
    }
}

void escribir_linea_en_consola(parametros_t datos)
{
    char columna_id[MAX_ANCHO_COLUMNA];
    char columna_nombre[MAX_ANCHO_COLUMNA];
    char columna_edad[MAX_ANCHO_COLUMNA];
    char columna_estado[MAX_ANCHO_COLUMNA];

    sprintf(columna_id, "%i", datos.heroe.id);
    sprintf(columna_edad, "%i", datos.heroe.edad);
    strcpy(columna_nombre, datos.heroe.nombre);
    estado_a_texto(columna_estado, datos.heroe.estado);

    completar_ancho_columna(columna_id, MAX_COLUMNA_ID);
    completar_ancho_columna(columna_nombre, MAX_COLUMNA_NOMBRE);
    completar_ancho_columna(columna_edad, MAX_COLUMNA_EDAD);
    completar_ancho_columna(columna_estado, MAX_COLUMNA_ESTADO);

    printf("|%s|%s|%s|%s|\n", columna_id, columna_nombre, columna_edad, columna_estado);
}
