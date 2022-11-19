#include "constantes.h"
#include "comandos.h"
#include "comprobaciones.h"
#include "control.h"

void ejecutar_solicitud(parametros_t query)
{
    if ((strcmp(query.comando, COMANDO_LISTAR_SUPERS)) == 0)
    {
        listar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_CONTACTAR_SUPER) == 0)
    {
        contactar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        modificar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        agregar_super(query);
    }
    else if (strcmp(query.comando, COMANDO_AYUDA) == 0)
    {
        mostrar_ayuda();
    }
}

int listar_super(parametros_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo de lectura");
        return ERROR;
    }
    else
    {

        while (!feof(heroes))
        {
            if (CANTIDAD_COLUMNAS == leer_linea(heroes, &datos.heroe))
            {
                escribir_linea_en_consola(datos);
            }
        }
    }
    fclose(heroes);
    return OK;
}

int contactar_super(parametros_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo");
        return ERROR;
    }

    FILE *archivo_auxiliar = fopen(NOMBRE_ARCHIVO_AUXILIAR, "w");
    if (archivo_auxiliar == NULL)
    {
        fclose(heroes);
        perror("Error al crear y abrir el archivo");
        return ERROR;
    }

    int posicion_linea = obtener_posicion(datos.heroe.id, datos.archivo);

    if (posicion_linea != BUSCADO_NO_EXISTE)
    {
        printf("Se ha contratado exitosamente al siguiente heroe:\n");

        mostrar_heroe_id(&datos);

        reescribir_hasta(heroes, archivo_auxiliar, posicion_linea);
        saltear_linea(heroes);
        reescribir_hasta_final(heroes, archivo_auxiliar);

        fclose(heroes);
        fclose(archivo_auxiliar);
        remove(datos.archivo);
        rename(NOMBRE_ARCHIVO_AUXILIAR, datos.archivo);
    }
    else
    {
        printf("El heroe de ID: %i no existe dentro de [ %s ]\n", datos.heroe.id, datos.archivo);
        fclose(heroes);
        fclose(archivo_auxiliar);
        remove(NOMBRE_ARCHIVO_AUXILIAR);
    }

    return OK;
}

int modificar_super(parametros_t datos)
{

    // Error actual, si la lista esta vacia, lee 2 lineas y una no existe
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo");
        return ERROR;
    }
    FILE *archivo_auxiliar = fopen(NOMBRE_ARCHIVO_AUXILIAR, "w");
    if (archivo_auxiliar == NULL)
    {
        fclose(heroes);
        perror("Error al abrir el archivo");
        return ERROR;
    }

    int posicion_linea = obtener_posicion(datos.heroe.id, datos.archivo);

    if (posicion_linea != BUSCADO_NO_EXISTE)
    {
        reescribir_hasta(heroes, archivo_auxiliar, posicion_linea);
        modificar_linea(heroes, archivo_auxiliar, &datos.heroe);
        reescribir_hasta_final(heroes, archivo_auxiliar);

        fclose(heroes);
        fclose(archivo_auxiliar);
        remove(datos.archivo);
        rename(NOMBRE_ARCHIVO_AUXILIAR, datos.archivo);
        printf("El heroe ha sido modificado a:\n");
        mostrar_heroe_id(&datos);
    }
    else
    {
        printf("El heroe de ID: %i no existe dentro de [ %s ]\n", datos.heroe.id, datos.archivo);
        fclose(heroes);
        fclose(archivo_auxiliar);
        remove(NOMBRE_ARCHIVO_AUXILIAR);
        return ERROR;
    }

    return OK;
}

int agregar_super(parametros_t datos)
{

    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        heroes = fopen(datos.archivo, "a");
        if (heroes == NULL)
        {
            perror("El archivo no existe y no se pudo crear\n");
            return ERROR;
        }
        fclose(heroes);
        FILE *heroes = fopen(datos.archivo, "r");
        if (heroes == NULL)
        {
            perror("Error al abrir el archivo\n");
            return ERROR;
        }
    }

    FILE *archivo_auxiliar = fopen(NOMBRE_ARCHIVO_AUXILIAR, "w");
    if (archivo_auxiliar == NULL)
    {
        fclose(heroes);
        perror("Error al abrir el archivo\n");
        return ERROR;
    }

    int existe_id = obtener_posicion(datos.heroe.id, datos.archivo);

    if (existe_id == BUSCADO_NO_EXISTE)
    {

        transcribir_e_insertar(heroes, archivo_auxiliar, datos);

        fclose(heroes);
        fclose(archivo_auxiliar);
        remove(datos.archivo);
        rename(NOMBRE_ARCHIVO_AUXILIAR, datos.archivo);
        printf("El heroe ha sido agregado exitosamente\n");
    }
    else
    {
        fclose(heroes);
        fclose(archivo_auxiliar);
        remove(NOMBRE_ARCHIVO_AUXILIAR);
        printf("Ya existe el ID: %i dentro del archivo [ %s ]\n", datos.heroe.id, datos.archivo);
        return ERROR;
    }

    return OK;
}

void mostrar_ayuda()
{
    printf("mostrar informacion del programa\n");
}

int asignar_datos_segun_comando(parametros_t *solicitud, char *argumentos[], int cantidad_argumentos)
{
    strcpy(solicitud->comando, *(&argumentos[POSICION_COMANDO]));
    solicitud->cantidad_arguementos = cantidad_argumentos;

    if (ERROR == contar_argumentos_minimos(solicitud->comando, cantidad_argumentos))
    {
        return ERROR;
    }

        if ((strcmp(solicitud->comando, COMANDO_LISTAR_SUPERS)) == 0)
    {
        strcpy(solicitud->archivo, *(&argumentos[LISTAR_POSICION_ARCHIVO]));
    }
    else if (strcmp(solicitud->comando, COMANDO_CONTACTAR_SUPER) == 0)
    {
        strcpy(solicitud->archivo, *(&argumentos[CONTACTAR_POSICION_ARCHIVO]));
        solicitud->heroe.id = atoi(argumentos[CONTACTAR_POSICION_ID]);
    }
    else if (strcmp(solicitud->comando, COMANDO_MODIFICAR_SUPER) == 0)
    {
        strcpy(solicitud->archivo, *(&argumentos[MODIFICAR_POSICION_ARCHIVO]));

        if (asignar_edad(&(solicitud->heroe.edad), argumentos, MODIFICAR_POSICION_EDAD) ||
            asignar_estado(&(solicitud->heroe.estado), argumentos, MODIFICAR_POSICION_ESTADO))
        {
            return ERROR;
        }
        solicitud->heroe.id = atoi(argumentos[MODIFICAR_POSICION_ID]);
    }
    else if (strcmp(solicitud->comando, COMANDO_AGREGAR_SUPER) == 0)
    {
        strcpy(solicitud->archivo, *(&argumentos[AGREGAR_POSICION_ARCHIVO]));
        strcpy(solicitud->heroe.nombre, *(&argumentos[AGREGAR_POSICION_NOMBRE]));
        solicitud->heroe.id = atoi(argumentos[AGREGAR_POSICION_ID]);

        if (asignar_edad(&(solicitud->heroe.edad), argumentos, AGREGAR_POSICION_EDAD) ||
            asignar_estado(&(solicitud->heroe.estado), argumentos, AGREGAR_POSICION_ESTADO))
        {
            return ERROR;
        }
    }
    else if (strcmp(solicitud->comando, COMANDO_AYUDA) == 0)
    {
        mostrar_ayuda();
    }

    return OK;
}
