#include "caza.h"
#include "comprobaciones.h"
#include "acciones.h"

int leer_linea(FILE *fuente, super_t *super)
{
    return fscanf(fuente, FORMATO_LECTURA, &super->id, super->nombre, &super->edad, &super->estado);
}

void escribir_linea(FILE *destino, super_t super)
{
    fprintf(destino, "%i;%s;%i;%c\n", super.id, super.nombre, super.edad, super.estado);
}

void estado_a_texto(char columna[MAX_ANCHO_COLUMNA], char estado)
{
    if (estado == CARACTER_ESTADO_OK)
    {
        strcpy(columna, PALABRA_ESTADO_OK);
    }
    else
    {
        strcpy(columna, PALABRA_ESTADO_NO_OK);
    }
}

void completar_ancho_columna(char columna[MAX_ANCHO_COLUMNA], size_t ancho_maximo)
{
    for (size_t i = strlen(columna); i < ancho_maximo; i++)
    {
        strcat(columna, " ");
    }
}

bool transcribir_y_modificar(FILE *fuente, FILE *destino, parametros_t datos)
{
    bool sin_modificaciones_realizadas = true;
    super_t heroe_auxiliar;

    while (leer_linea(fuente, &heroe_auxiliar) == CANTIDAD_COLUMNAS)
    {
        if (heroe_auxiliar.id == datos.heroe.id && sin_modificaciones_realizadas)
        {
            heroe_auxiliar.edad = datos.heroe.edad;
            heroe_auxiliar.estado = datos.heroe.estado;
            escribir_linea(destino, heroe_auxiliar);
            printf("El heroe ha sido modificado a:\n");
            escribir_super_en_consola(heroe_auxiliar);
            sin_modificaciones_realizadas = false;
        }
        else
        {
            escribir_linea(destino, heroe_auxiliar);
        }
    }

    if (sin_modificaciones_realizadas)
    {
        printf("El heroe de ID: %i no existe dentro de [ %s ]\n", datos.heroe.id, datos.archivo);
        return false;
    }
    else
    {
        return true;
    }
}

bool transcribir_y_borrar(FILE *fuente, FILE *destino, parametros_t datos)
{
    bool sin_borrado_realizado = true;
    super_t heroe_auxiliar;

    while (leer_linea(fuente, &heroe_auxiliar) == CANTIDAD_COLUMNAS)
    {
        if (heroe_auxiliar.id == datos.heroe.id && sin_borrado_realizado)
        {
            printf("Se ha contratado exitosamente al siguiente heroe:\n");
            escribir_super_en_consola(heroe_auxiliar);
            sin_borrado_realizado = false;
        }
        else
        {
            escribir_linea(destino, heroe_auxiliar);
        }
    }

    if (sin_borrado_realizado)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool transcribir_e_insertar(FILE *fuente, FILE *destino, parametros_t datos)
{
    bool sin_aniadido_realizado = true;
    super_t heroe_auxiliar;
    bool id_no_existe = true;

    while (leer_linea(fuente, &heroe_auxiliar) == CANTIDAD_COLUMNAS && id_no_existe)
    {
        if (heroe_auxiliar.id == datos.heroe.id)
        {
            id_no_existe = false;
        }

        if (heroe_auxiliar.id > datos.heroe.id && sin_aniadido_realizado)
        {

            escribir_linea(destino, datos.heroe);
            escribir_linea(destino, heroe_auxiliar);
            sin_aniadido_realizado = false;
        }
        else
        {
            escribir_linea(destino, heroe_auxiliar);
        }
    }

    if (sin_aniadido_realizado)
    {
        escribir_linea(destino, datos.heroe);
    }
    if (!id_no_existe)
    {
        return false;
    }
    printf("El heroe ha sido agregado exitosamente\n");
    return true;
}

void transcribir_lista_en_consola(FILE *fuente)
{
    super_t heroe_auxiliar;

    leer_linea(fuente, &heroe_auxiliar);
    while (!feof(fuente))
    {
        escribir_super_en_consola(heroe_auxiliar);
        leer_linea(fuente, &heroe_auxiliar);
    }
}