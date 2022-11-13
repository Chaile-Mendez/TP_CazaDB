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

bool comprobar_edad(datos_heroe_t datos)
{
    if (datos.edad < 0 || datos.edad > EDAD_MAXIMA)
    {
        printf("[Solo se aceptan edades entre 0 y %i]\n", datos.edad);
        return false;
    }
    return true;
}

bool comprobar_estado(datos_heroe_t datos)
{
    if (datos.estado == ESTADO_VIVO || datos.estado == ESTADO_MUERTO)
    {
        return true;
    }
    else
    {
        printf("Los caracteres validos para el estado son %c y %c", ESTADO_VIVO, ESTADO_MUERTO);
        return false;
    }
}