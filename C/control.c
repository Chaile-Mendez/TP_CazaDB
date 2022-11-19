#include "constantes.h"
#include "comprobaciones.h"
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

int posicion_id(char nombre_archivo[MAX_NOMBRE_ARCHIVO], int id)
{
    FILE *archivo = fopen(nombre_archivo, "r");

    super_t aux;
    int posicion = -1;
    int i = 0;

    leer_linea(archivo, &aux);
    while (!feof(archivo))
    {
        if (aux.id == id)
        {
            posicion = i;
        }

        leer_linea(archivo, &aux);
        i++;
    }
    fclose(archivo);
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

int mostrar_heroe_id(parametros_t *datos)
{
    datos_de_heroe_segun_id(datos, datos->heroe.id);
    escribir_linea_en_consola(*datos);
    return OK;
}

int buscar_id_menor_maxima(parametros_t datos)
{
    int id = 0;

    int ids_archivo[MAX_LINEAS];
    int tope_ids = 0;

    listar_ids(ids_archivo, &tope_ids, datos.archivo);
    int i = 0;
    bool buscando = true;
    while (i < tope_ids && buscando)
    {
        if (ids_archivo[i] < datos.heroe.id)
        {
            id = ids_archivo[i];
        }
        else
        {
            buscando = false;
        }
        i++;
    }

    return id;
}

void transcribir_e_insertar(FILE *fuente, FILE *destino, parametros_t datos)
{
    bool sin_agregar = true;
    super_t aux;

    while (leer_linea(fuente, &aux) == 4)
    {
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
}

bool asignar_edad(int *edad, char *argumentos[], int posicion_edad)
{
    *edad = atoi(argumentos[posicion_edad]);

    if (*edad < EDAD_MINIMA || *edad > EDAD_MAXIMA)
    {
        printf("[Solo se aceptan edades entre %i y %i]\n", EDAD_MINIMA, EDAD_MAXIMA);
        return true;
    }
    return false;
}

bool asignar_estado(char *estado, char *argumentos[], int posicion_caracter)
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

void transcribir_y_modificar(FILE *fuente, FILE *destino, parametros_t datos)
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
        }
        else
        {
            escribir_linea(destino, aux);
        }
    }
}