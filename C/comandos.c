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

        if (asignar_id(&(solicitud->heroe.id), argumentos, MODIFICAR_POSICION_ID) ||
            asignar_edad(&(solicitud->heroe.edad), argumentos, MODIFICAR_POSICION_EDAD) ||
            asignar_estado(&(solicitud->heroe.estado), argumentos, MODIFICAR_POSICION_ESTADO))
        {
            return false;
        }
        break;

    case CODIGO_LISTAR:

        strcpy(solicitud->archivo, *(&argumentos[LISTAR_POSICION_ARCHIVO]));
        break;

    case CODIGO_AYUDA:
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
    printf("Informacion del programa\n\n");

    printf("\nConsideraciones del archivo a utilizar\n");
    printf("El archivo con el que se trabaja utilizando este programa\n");
    printf("debe tener la extension .csv y su formato debe ser el siguiente:\n");
    printf("ID;NOMBRE;EDAD;ESTADO\n");
    printf("EJEMPLO:  32;Mr.Increible;44;V\n");

    printf("\nConsideraciones al ingresar datos\n");
    printf("El ID ingresado debe ser positivo\n");
    printf("El nombre ingresado debe tener maximo %i caracteres\n", MAX_NOMBRE);
    printf("El nombre debe ser ingreasdo entre comillas dobles en caso de tener espacios\n");
    printf("La edad ingresada debe estar entre %i y %i\n", EDAD_MINIMA, EDAD_MAXIMA);
    printf("El estado del personaje puede ser -%s- o -%s-\n", TEXTO_ESTADO_VIVO, TEXTO_ESTADO_MUERTO);
    printf("El nombre del archivo debe ser ingresado con su extension .csv");

    printf("\nLos comandos disponibles son:\n\n");

    printf("\n\n%s\n", COMANDO_AGREGAR_SUPER);
    printf("Formato: ./%s %s ID NOMBRE EDAD ESTADO ARCHIVO\n", NOMBRE_PROGRAMA, COMANDO_AGREGAR_SUPER);
    printf("\nDescripcion:\n");
    printf("Inserta una linea nueva con los datos del super ingresado.\n");
    printf("Solo si la ID del super ingresado no existe en la lista.\n");
    printf("En caso de que el archivo no exista, se creara\n");

    printf("\n\n%s\n", COMANDO_CONTACTAR_SUPER);
    printf("Formato: ./%s %s ARCHIVO\n", NOMBRE_PROGRAMA, COMANDO_CONTACTAR_SUPER);
    printf("\nDescripcion:\n");
    printf("Elimina al super de la lista que tenga el ID ingresado y\n");
    printf("se mostrara en consola los datos del super contactado.\n");
    printf("El super sera contactado independimenente de su estado\n");

    printf("\n\n%s\n", COMANDO_MODIFICAR_SUPER);
    printf("Formato: ./%s %s ID EDAD ESTADO ARCHIVO\n", NOMBRE_PROGRAMA, COMANDO_MODIFICAR_SUPER);
    printf("\nDescripcion:\n");
    printf("Modifica la edad y el estado del super de la lista que\n");
    printf("tenga el ID ingresado. Ademas se mostrara en consola los\n");
    printf("datos del super contactado.\n");

    printf("\n\n%s\n", COMANDO_LISTAR_SUPERS);
    printf("Formato: ./%s %s ID ARCHIVO\n", NOMBRE_PROGRAMA, COMANDO_LISTAR_SUPERS);
    printf("\nDescripcion:\n");
    printf("Muestra en consola un listado con todos los supers dentro\n");
    printf("del archivo. Los datos seran expresados en su forma completa\n");
    printf("y no solo como estan guardados dentro del .csv .\n");
}
