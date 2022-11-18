#include "constantes.h"

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
    else if (strcmp(comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        return MINIMO_ARGUEMENTOS_MODIFICAR;
    }
    else if (strcmp(comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        return MINIMO_ARGUEMENTOS_AGREGAR;
    }
    else
    {
        return 2;
    }
}

bool comprobar_edad_valida(int edad)
{
    if (edad < 0 || edad > EDAD_MAXIMA)
    {
        printf("[Solo se aceptan edades entre 0 y %i]\n", EDAD_MAXIMA);
        return false;
    }
    return true;
}

bool comprobar_estado_valido(char estado)
{
    if (estado == ESTADO_VIVO || estado == ESTADO_MUERTO)
    {
        return true;
    }
    else
    {
        printf("Los caracteres validos para el estado son %c y %c", ESTADO_VIVO, ESTADO_MUERTO);
        return false;
    }
}

bool comprobar_nombre_valido(char nombre[MAX_NOMBRE])
{
    if (strlen(nombre) > MAX_NOMBRE)
    {
        printf("El nombre ingresado exede el limite maximo de %i caracteres\n", MAX_NOMBRE);
        return false;
    }
    else
    {
        return true;
    }
}

void escribir_linea_en_consola(parametros_comando_t datos)
{
    char columna_id[MAX_ANCHO_COLUMNA] = " ";
    char columna_nombre[MAX_ANCHO_COLUMNA] = " ";
    char columna_edad[MAX_ANCHO_COLUMNA] = " ";

    sprintf(columna_id, "%i", datos.heroe.id);
    sprintf(columna_edad, "%i", datos.heroe.edad);
    strcpy(columna_nombre, datos.heroe.nombre);

    int longitud_id = (int)(strlen(columna_id));
    int longtiud_edad = (int)(strlen(columna_edad));
    int lontitud_nombre = (int)(strlen(columna_nombre));

    for (int i = longitud_id; i < MAX_COLUMNA_ID; i++)
    {
        strcat(columna_id, " ");
    }

    for (int i = longtiud_edad; i < MAX_COLUMNA_EDAD; i++)
    {
        strcat(columna_edad, " ");
    }

    for (int i = lontitud_nombre; i < MAX_COLUMNA_NOMBRE; i++)
    {
        strcat(columna_nombre, " ");
    }

    printf("|%s|%s|%s| %c |\n", columna_id, columna_nombre, columna_edad, datos.heroe.estado);
}
