#include "constantes.h"
#include "control.h"

void listar_ids(int lista_ids[MAX_LINEAS], int *tope_ids, char nombre_archivo[MAX_NOMBRE_ARCHIVO])
{
    FILE *archivo = fopen(nombre_archivo, "r");

    while (!feof(archivo))
    {
        int id = -1;
        char texto[MAX_LONGITUD_LINEA];
        if (1 < fscanf(archivo, "%i;%[^\n]", &id, texto))
        {
            lista_ids[*tope_ids] = id;
            ++(*tope_ids);
        }
    }
    fclose(archivo);
}

int busqueda_binaria_rec(int buscado, int vector[], int minimo, int maximo)
{
    if (minimo > maximo)
    {
        return BUSCADO_NO_EXISTE;
    }
    else
    {
        int punto_medio = (minimo + maximo) / 2;
        if (buscado == vector[punto_medio])
        {
            return punto_medio;
        }
        else if (buscado > vector[punto_medio])
        {
            return busqueda_binaria_rec(buscado, vector, punto_medio + 1, maximo);
        }
        else
        {
            return busqueda_binaria_rec(buscado, vector, minimo, punto_medio - 1);
        }
    }
}

int busqueda_binaria(int buscado, int vector[], int tope)
{
    return busqueda_binaria_rec(buscado, vector, 0, tope - 1);
}

void reescribir_hasta(FILE *fuente, FILE *destino, int posicion)
{
    char linea[MAX_LONGITUD_LINEA];
    int i = 0;

    while (i < posicion && (1 == fscanf(fuente, "%[^\n]\n", linea)))
    {

        fprintf(destino, "%s\n", linea);
        i++;
    }
}

void reescribir_hasta_final(FILE *fuente, FILE *destino)
{
    char linea[MAX_LONGITUD_LINEA];
    while (1 == fscanf(fuente, "%[^\n]\n", linea))
    {
        // fscanf(fuente, "%[^\n]\n", linea);
        fprintf(destino, "%s\n", linea);
    }
}

void saltear_linea(FILE *fuente)
{
    char linea[MAX_LONGITUD_LINEA];
    fscanf(fuente, "%[^\n]\n", linea);
}

int obtener_posicion(int id, char archivo[MAX_NOMBRE_ARCHIVO])
{
    int ids_archivo[MAX_LINEAS];
    int tope_ids = 0;

    listar_ids(ids_archivo, &tope_ids, archivo);
    int posicion = busqueda_binaria(id, ids_archivo, tope_ids);
    return posicion;
}

int leer_linea(FILE *fuente, super_t *super)
{
    return fscanf(fuente, FORMATO_LECTURA, &super->id, super->nombre, &super->edad, &super->estado);
}

void transformar_heroe_a_string(char linea[MAX_LONGITUD_LINEA], super_t super)
{
    sprintf(linea, "%i;%s;%i;%c", super.id, super.nombre, super.edad, super.estado);
}

int buscar_maximo_menor(int buscado, char archivo[MAX_NOMBRE_ARCHIVO])
{
    int lista_ids[MAX_LINEAS];
    int tope = 0;

    listar_ids(lista_ids, &tope, archivo);

    int i = 0;
    int este_numero = -1;
    while ((i < tope) && (este_numero < buscado))
    {
        este_numero = lista_ids[i];
        i++;
    }
    return este_numero;
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

int datos_de_heroe_segun_id(parametros_t *datos, int id)
{
    FILE *archivo = fopen(datos->archivo, "r");
    if (archivo == NULL)
    {
        perror("No se puede leer archivo");
        return ERROR;
    }

    super_t super_leido;

    bool buscando = true;

    while (buscando)
    {
        leer_linea(archivo, &super_leido);

        if (datos->heroe.id == super_leido.id)
        {
            buscando = false;
        }
    }

    datos->heroe = super_leido;
    fclose(archivo);
    return OK;
}

void transcribir_hasta_id_mayor(FILE *fuente, FILE *destino, super_t super)
{
    bool buscando = true;
    super_t super_leido;

    while (buscando)
    {
        leer_linea(fuente, &super_leido);

        if (super_leido.id < super.id && !feof(fuente))
        {
            escribir_linea(destino, super_leido);
        }
        else
        {
            buscando = false;
        }
    }
    if (feof(fuente) && super_leido.id < super.id)
    {
        escribir_linea(destino, super_leido);
        escribir_linea(destino, super);
    }
    else
    {
        escribir_linea(destino, super);
        escribir_linea(destino, super_leido);
    }
}