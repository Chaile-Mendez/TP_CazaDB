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

bool comprobar_edad(int edad)
{
    if (edad < 0 || edad > EDAD_MAXIMA)
    {
        printf("[Solo se aceptan edades entre 0 y %i]\n", EDAD_MAXIMA);
        return false;
    }
    return true;
}

bool comprobar_estado(char estado)
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

bool comprobar_nombre(char nombre[MAX_NOMBRE])
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
void escribir_linea(char linea[MAX_LINEA], parametros_comando_t datos)
{
    char columna_id[MAX_ANCHO_COLUMNA];
    char columna_nombre[MAX_ANCHO_COLUMNA] = "NOMBRE";
    char columna_edad[MAX_ANCHO_COLUMNA] = "000";
    char columna_estado[MAX_ANCHO_COLUMNA] = "X";

    sprintf(columna_id, " %i", datos.heroe.id);
    int longitud_id = (int)(strlen(columna_id));

    for (int i = longitud_id; i < MAX_COLUMNA_ID; i++)
    {
        strcat(columna_id, " ");
    }

    printf("|%s| %s %s %s", columna_id, columna_nombre, columna_edad, columna_estado);
}

void leer_linea(FILE *archivo, parametros_comando_t *datos)
{

}