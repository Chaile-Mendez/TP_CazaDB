#ifndef __COMANDOS_H__
#define __COMANDOS_H__
#include "caza.h"

/*
Precondiciones:
    Los valores en DATOS estan asignados correctamente.

Postcondiciones:
    Dependiendo del CODIGO COMANDO dentro DATOS ejecuta su respectiva accion.
    Si ocurre algun error abriendo o creando archivos devuelve FALSE, en caso contrario devuelve TRUE.
    La accion a ejectuar segun su CODIGO COMANDO SON:
        1) AYUDA:
            Muestra informacion en pantalla del uso del programa.
        2) AGREGAR
            Inserta un heroe en el archivo especificado.
        3) ELIMINAR
            Elimina un heroe dentro del archivo especificado.
        4) MODIFICAR
            Modifica el estado y edad de un heroe del archivo especificado.
        5) LISTAR
            Muestra en forma de tabla todos los heroes del archivo especificado.
*/
bool ejecutar_comando(parametros_t datos);

/*
Postcondiciones:
    Si la CANTIDAD DE ARGUMENTOS es incorrecta devuelve FALSE.
    Si los ARGUMENTOS ingresados son invalidos, devuelve FALSE.
    Si los DATOS ingresados son validos para el CODIGO COMANDO devuelve TRUE.
*/
bool asignar_datos_segun_comando(parametros_t *datos, char *argumentos[], int cantidad_argumentos);

/*
Precondiciones:
    NOMBRE ARCHIVO esta asignada correctamente.

Postcondiciones:
    Muestra en consola en forma de tabla a todos los superheroes del NOMBRE ARCHIVO y devuelve TRUE.
    En caso de que ocurra un error en la apertura del archivo devuelve FALSE
*/
bool listar_supers(parametros_t datos);

/*
Precondiciones:

Postcondiciones:

*/
bool contactar_super(parametros_t datos);

/*
Precondiciones:

Postcondiciones:

*/
bool modificar_super(parametros_t datos);

/*
Precondiciones:

Postcondiciones:

*/
bool agregar_super(parametros_t datos);

/*
Precondiciones:

Postcondiciones:

*/
void mostrar_ayuda();

#endif /* __COMANDOS_H__ */