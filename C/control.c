#include "constantes.h"

void listar_ids(int lista_ids[MAX_LINEAS], int *tope_ids, FILE *archivo)
{
    while (!feof(archivo))
    {
        int id = -1;
        char txt[1000] = " ";
        if (1 < fscanf(archivo, "%i;%[^\n]", &id, txt))
        {
            lista_ids[*tope_ids] = id;
            ++(*tope_ids);
        }
    }
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