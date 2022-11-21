#include "constantes.h"
#include "comandos.h"
#include "comprobaciones.h"
#include "control.h"

bool ejecutar_solicitud(parametros_t query)
{
    switch (query.codigo_comando)
    {
    case CODIGO_AGREGAR:

        if (!(agregar_super(query)))
        {
            return false;
        }
        break;

    case CODIGO_ELIMINAR:

        contactar_super(query);
        if (!(contactar_super(query)))
        {
            return false;
        }
        break;

    case CODIGO_MODIFICAR:

        if (!(modificar_super(query)))
        {
            return false;
        }
        break;

    case CODIGO_LISTAR:

        if (!(listar_supers(query)))
        {
            return false;
        }
        break;

    case CODIGO_AYUDA:

        mostrar_ayuda();
        break;
    }
    return true;
}

bool asignar_datos_segun_comando(parametros_t *solicitud, char *argumentos[], int cantidad_argumentos)
{

    if (!(comprobar_cantidad_argumentos_ok(solicitud->codigo_comando, cantidad_argumentos)))
    {
        return false;
    }

    switch (solicitud->codigo_comando)
    {
    case CODIGO_AGREGAR:

        strcpy(solicitud->archivo, *(&argumentos[AGREGAR_POSICION_ARCHIVO]));

        if (asignar_id(&(solicitud->heroe.id), argumentos, AGREGAR_POSICION_ID) ||
            asignar_nombre(solicitud->heroe.nombre, argumentos, AGREGAR_POSICION_NOMBRE) ||
            asignar_edad(&(solicitud->heroe.edad), argumentos, AGREGAR_POSICION_EDAD) ||
            asignar_estado(&(solicitud->heroe.estado), argumentos, AGREGAR_POSICION_ESTADO))
        {
            return false;
        }
        break;

    case CODIGO_ELIMINAR:

        strcpy(solicitud->archivo, *(&argumentos[CONTACTAR_POSICION_ARCHIVO]));

        if (asignar_id(&(solicitud->heroe.id), argumentos, CONTACTAR_POSICION_ID))
        {
            return false;
        }
        break;

    case CODIGO_MODIFICAR:

        strcpy(solicitud->archivo, *(&argumentos[MODIFICAR_POSICION_ARCHIVO]));

        if (asignar_id(&(solicitud->heroe.id), argumentos, AGREGAR_POSICION_ID) ||
            asignar_edad(&(solicitud->heroe.edad), argumentos, AGREGAR_POSICION_EDAD) ||
            asignar_estado(&(solicitud->heroe.estado), argumentos, AGREGAR_POSICION_ESTADO))
        {
            return false;
        }
        break;

    case CODIGO_LISTAR:

        strcpy(solicitud->archivo, *(&argumentos[LISTAR_POSICION_ARCHIVO]));
        break;

    case CODIGO_AYUDA:

        mostrar_ayuda();
        break;
    }

    return true;
}

bool listar_supers(parametros_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo de lectura");
        return false;
    }
    else
    {
        while (!feof(heroes))
        {
            if (CANTIDAD_COLUMNAS == leer_linea(heroes, &datos.heroe))
            {
                escribir_linea_en_consola(datos.heroe);
            }
        }
    }
    fclose(heroes);
    return true;
}

bool contactar_super(parametros_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo");
        return false;
    }

    FILE *archivo_auxiliar = fopen(NOMBRE_ARCHIVO_AUXILIAR, "w");
    if (archivo_auxiliar == NULL)
    {
        fclose(heroes);
        perror("Error al crear y abrir el archivo");
        return false;
    }

    bool resultado = transcribir_y_borrar(heroes, archivo_auxiliar, datos);

    fclose(heroes);
    fclose(archivo_auxiliar);

    if (resultado)
    {
        remove(datos.archivo);
        rename(NOMBRE_ARCHIVO_AUXILIAR, datos.archivo);
    }
    else
    {
        remove(NOMBRE_ARCHIVO_AUXILIAR);
        printf("El heroe de ID: %i no existe dentro de [ %s ]\n", datos.heroe.id, datos.archivo);
    }
    return true;
}

bool modificar_super(parametros_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        perror("Error al abrir el archivo");
        return false;
    }
    FILE *archivo_auxiliar = fopen(NOMBRE_ARCHIVO_AUXILIAR, "w");
    if (archivo_auxiliar == NULL)
    {
        fclose(heroes);
        perror("Error al abrir el archivo");
        return false;
    }

    bool resultado = transcribir_y_modificar(heroes, archivo_auxiliar, datos);

    fclose(heroes);
    fclose(archivo_auxiliar);

    if (resultado)
    {
        remove(datos.archivo);
        rename(NOMBRE_ARCHIVO_AUXILIAR, datos.archivo);
    }
    else
    {
        remove(NOMBRE_ARCHIVO_AUXILIAR);
        return false;
    }

    return true;
}

bool agregar_super(parametros_t datos)
{
    FILE *heroes = fopen(datos.archivo, "r");
    if (heroes == NULL)
    {
        heroes = fopen(datos.archivo, "a");
        if (heroes == NULL)
        {
            perror("El archivo no existe y no se pudo crear\n");
            return false;
        }
        fclose(heroes);
        FILE *heroes = fopen(datos.archivo, "r");
        if (heroes == NULL)
        {
            perror("Error al abrir el archivo\n");
            return false;
        }
    }

    FILE *archivo_auxiliar = fopen(NOMBRE_ARCHIVO_AUXILIAR, "w");

    if (archivo_auxiliar == NULL)
    {
        fclose(heroes);
        perror("Error al abrir el archivo\n");
        return false;
    }

    bool resultado = transcribir_e_insertar(heroes, archivo_auxiliar, datos);

    fclose(heroes);
    fclose(archivo_auxiliar);

    if (resultado)
    {
        remove(datos.archivo);
        rename(NOMBRE_ARCHIVO_AUXILIAR, datos.archivo);
    }
    else
    {
        remove(NOMBRE_ARCHIVO_AUXILIAR);
        printf("Ya existe el ID: %i dentro del archivo [ %s ]\n", datos.heroe.id, datos.archivo);
        return false;
    }
    return true;
}

void mostrar_ayuda()
{
    printf("mostrar informacion del programa\n");
}
