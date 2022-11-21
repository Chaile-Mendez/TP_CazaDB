#include "constantes.h"
#include "comprobaciones.h"
#include "control.h"

int leer_linea(FILE *fuente, super_t *super)
{
    return fscanf(fuente, FORMATO_LECTURA, &super->id, super->nombre, &super->edad, &super->estado);
}

void escribir_linea(FILE *archivo, super_t super)
{
    fprintf(archivo, "%i;%s;%i;%c\n", super.id, super.nombre, super.edad, super.estado);
}

void modificar_linea(FILE *fuente, FILE *destino, super_t *super)
{
    int id = -1;
    char linea_basura[MAX_LONGITUD_LINEA];
    fscanf(fuente, "%i;%[^;];%[^\n]\n", &id, (super->nombre), linea_basura);
    escribir_linea(destino, *super);
}

void estado_a_texto(char columna[MAX_ANCHO_COLUMNA], char estado)
{
    if (estado == ESTADO_VIVO)
    {
        strcpy(columna, TEXTO_ESTADO_VIVO);
    }
    else
    {
        strcpy(columna, TEXTO_ESTADO_MUERTO);
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
    bool sin_modificar = true;
    super_t aux;

    while (leer_linea(fuente, &aux) == 4)
    {
        if (aux.id == datos.heroe.id && sin_modificar)
        {
            aux.edad = datos.heroe.edad;
            aux.estado = datos.heroe.estado;
            escribir_linea(destino, aux);
            printf("El heroe ha sido modificado a:\n");
            escribir_linea_en_consola(aux);
            sin_modificar = false;
        }
        else
        {
            escribir_linea(destino, aux);
        }
    }

    if (sin_modificar)
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
    bool sin_borrar = true;
    super_t aux;

    while (leer_linea(fuente, &aux) == 4)
    {
        if (aux.id == datos.heroe.id && sin_borrar)
        {
            printf("Se ha contratado exitosamente al siguiente heroe:\n");
            escribir_linea_en_consola(aux);
            sin_borrar = false;
        }
        else
        {
            escribir_linea(destino, aux);
        }
    }

    if (sin_borrar)
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
    bool sin_agregar = true;
    super_t aux;
    bool id_no_existe = true;

    while (leer_linea(fuente, &aux) == 4 && id_no_existe)
    {
        if (aux.id == datos.heroe.id)
        {
            id_no_existe = false;
        }

        if (aux.id > datos.heroe.id && sin_agregar)
        {

            escribir_linea(destino, datos.heroe);
            escribir_linea(destino, aux);
            sin_agregar = false;
        }
        else
        {
            escribir_linea(destino, aux);
        }
    }

    if (sin_agregar)
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