#include "constantes.h"
#include "control.h"

bool comprobar_cantidad_argumentos_ok(int codigo_comando, int cantidad_argumentos) // CAMBIAR NOMBRE DE MINIMO A CANTIDAD EXACTA
{
    int cantidad_argumentos_necesarios = -1;

    switch (codigo_comando)
    {
    case CODIGO_AGREGAR:

        cantidad_argumentos_necesarios = MINIMO_ARGUEMENTOS_AGREGAR;
        break;

    case CODIGO_ELIMINAR:

        cantidad_argumentos_necesarios = MINIMO_ARGUMENTOS_CONTACTAR;
        break;

    case CODIGO_MODIFICAR:

        cantidad_argumentos_necesarios = MINIMO_ARGUEMENTOS_MODIFICAR;
        break;

    case CODIGO_LISTAR:

        cantidad_argumentos_necesarios = MINIMO_ARGUMENTOS_LISTAR;
        break;

    case CODIGO_AYUDA:

        cantidad_argumentos_necesarios = MINIMO_ARGUEMENTOS_AYUDA;
        break;
    }

    if (cantidad_argumentos == cantidad_argumentos_necesarios)
    {
        return true;
    }
    else
    {
        printf("se necesitan %i arguementos para este comando\n", cantidad_argumentos_necesarios);
        return false;
    }
}

void escribir_linea_en_consola(super_t heroe)
{
    char columna_id[MAX_ANCHO_COLUMNA];
    char columna_nombre[MAX_ANCHO_COLUMNA];
    char columna_edad[MAX_ANCHO_COLUMNA];
    char columna_estado[MAX_ANCHO_COLUMNA];

    sprintf(columna_id, "%i", heroe.id);
    sprintf(columna_edad, "%i", heroe.edad);
    strcpy(columna_nombre, heroe.nombre);
    estado_a_texto(columna_estado, heroe.estado);

    completar_ancho_columna(columna_id, MAX_COLUMNA_ID);
    completar_ancho_columna(columna_nombre, MAX_COLUMNA_NOMBRE);
    completar_ancho_columna(columna_edad, MAX_COLUMNA_EDAD);
    completar_ancho_columna(columna_estado, MAX_COLUMNA_ESTADO);

    printf("||%s|%s|%s|%s||\n", columna_id, columna_nombre, columna_edad, columna_estado);
}

bool asignar_codigo_comando(char comando[MAX_LONGITUD_COMANDO], int *codigo_comando)
{
    if ((strcmp(comando, COMANDO_LISTAR_SUPERS)) == 0)
    {
        *codigo_comando = CODIGO_LISTAR;
    }
    else if (strcmp(comando, COMANDO_CONTACTAR_SUPER) == 0)
    {
        *codigo_comando = CODIGO_ELIMINAR;
    }
    else if (strcmp(comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        *codigo_comando = CODIGO_MODIFICAR;
    }
    else if (strcmp(comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        *codigo_comando = CODIGO_AGREGAR;
    }
    else if (strcmp(comando, COMANDO_AYUDA) == 0)
    {
        *codigo_comando = CODIGO_AYUDA;
    }
    else
    {
        printf("No ha ingresado ningun comando valido\n");
        printf("ingrese: ./%s %s \n", NOMBRE_PROGRAMA, COMANDO_AYUDA);
        printf("Para obtener ayuda respecto a como usar el programa\n");
        return false;
    }
    return true;
}

bool asignar_edad(int *edad, char *argumentos[], int posicion_edad) // Mover a comprobaciones
{
    *edad = atoi(argumentos[posicion_edad]);

    if (*edad < EDAD_MINIMA || *edad > EDAD_MAXIMA)
    {
        printf("[Solo se aceptan edades entre %i y %i]\n", EDAD_MINIMA, EDAD_MAXIMA);
        return true;
    }
    return false;
}

bool asignar_estado(char *estado, char *argumentos[], int posicion_caracter) // Mover a comprobaciones
{
    if (strcmp(argumentos[posicion_caracter], TEXTO_ESTADO_VIVO) == 0)
    {
        *estado = ESTADO_VIVO;
    }
    else if (strcmp(argumentos[posicion_caracter], TEXTO_ESTADO_MUERTO) == 0)
    {
        *estado = ESTADO_MUERTO;
    }
    else
    {
        printf("[Solo se aceptan los estados:  %s y %s]\n", TEXTO_ESTADO_MUERTO, TEXTO_ESTADO_VIVO);
        return true;
    }

    return false;
}

bool asignar_id(int *id, char *argumentos[], int posicion_caracter) // Mover a comprobaciones
{
    int valor_id = atoi(argumentos[posicion_caracter]);
    if (valor_id >= 0)
    {
        *id = valor_id;
        return false;
    }

    else
    {
        printf("[Solo se aceptan IDs mayores o iguales a 0]\n");
        return true;
    }
}

bool asignar_nombre(char nombre[MAX_NOMBRE], char *argumentos[], int posicion_caracter)
{
    size_t longitud = strlen(argumentos[posicion_caracter]);

    if (longitud <= MAX_NOMBRE)
    {
        strcpy(nombre, argumentos[posicion_caracter]);
        return false;
    }
    else
    {
        printf("[Solo se aceptan nombres con %i caracteres maximo]\n", MAX_NOMBRE);
        return true;
    }
}