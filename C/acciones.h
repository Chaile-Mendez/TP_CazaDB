#ifndef __ACCIONES_H__
#define __ACCIONES_H__
#include "caza.h"

/*
Precondiciones:
    FUENTE debe ser un archivo abierto en formato de lectura, con el formato ID;NOMBRE;EDAD;ESTADO
Postcondiciones:
    Lee una linea del archivo y almacena los datos en SUPER. Ademas, devuelve la cantidad de valores asignados exitosamente.
*/
int leer_linea(FILE *fuente, super_t *super);

/*
Precondiciones:
    DESTINO debe ser un archivo abierto en formato de escritura. Todos los valores de SUPER estan asignados.
Postcondiciones:
    Escribe en DESTINO una linea con los datos de SUPER con el siguiente formato ID;NOMBRE;EDAD;ESTADO
*/
void escribir_linea(FILE *destino, super_t super);

/*
Precondiciones:
    ESTADO es 'V' o 'M'

Postcondiciones:
    Si ESTADO es 'V' asigna "vivo" a columna, si es 'M' asigna "muerto"
*/
void estado_a_texto(char columna[MAX_ANCHO_COLUMNA], char estado);

/*
Precondiciones:
    El largo de COLUMNA debe ser menor a ANCHO MAXIMO

Postcondiciones:
    Completa COLUMNA con espacios ' ' hasta que su
    longitud sea igual a ANCHO MAXIMO
*/
void completar_ancho_columna(char columna[MAX_ANCHO_COLUMNA], size_t ancho_maximo);

/*
Precondiciones:
    FUENTE es un archivo abierto en formato de lectura, y DESTINO es un arhivo abierto en formato de ESCRITURA.
    DATOS tiene el ID, EDAD y ESTADO asignados correctamente.
    FUENTE debe tener el formato ID;NOMBRE;EDAD;ESTADO y los datos deben estar ordenados de manera descendente segun su ID

Postcondiciones:
    Devuelve FALSE si el ID dentro de DATOS no existe en el archivo FUENTE, en caso contrario, transcribe todo el
    archivo FUENTE a DESTINO modificando la linea con esa ID, cambiando su EDAD y ESTADO
    con los valores dentro de DATOS y devuelve TRUE, ademas se escribira en consola los datos ya modificados.
*/
bool transcribir_y_modificar(FILE *fuente, FILE *destino, parametros_t datos);

/*
Precondiciones:
    FUENTE es un archivo abierto en formato de lectura, y DESTINO es un arhivo abierto en formato de ESCRITURA.
    DATOS tiene el ID asignado correctamente.
    FUENTE debe tener el formato ID;NOMBRE;EDAD;ESTADO y los datos deben estar ordenados de manera descendente segun su ID

Postcondiciones:
    Devuelve FALSE si el ID dentro de DATOS no existe en el archivo FUENTE, en caso contrario transcribe todo el archivo
    FUENTE a DESTINO omitiendo la linea con el ID dentro de DATOS , manteniendo el orden de los datos,y devuelve TRUE, Ademas de escribir en consola
    los datos del heroe que ha sido contratado (omitido durante la transcripcion).
*/
bool transcribir_y_borrar(FILE *fuente, FILE *destino, parametros_t datos);

/*
Precondiciones:
    FUENTE es un archivo abierto en formato de lectura, y DESTINO es un arhivo abierto en formato de ESCRITURA.
    DATOS tiene el ID asignado correctamente.
    FUENTE debe tener el formato ID;NOMBRE;EDAD;ESTADO y los datos deben estar ordenados de manera descendente segun su ID
Postcondiciones:
    Devuelve FALSE si el ID dentro de DATOS no existe en el archivo FUENTE, en caso contrario transcribe todo el archivo
    FUENTE a DESTINO insertando una linea con la informacion DATOS respetando el orden de IDs y devuelve TRUE, Ademas de escribir en consola que se ha agregado exitosamente
*/
bool transcribir_e_insertar(FILE *fuente, FILE *destino, parametros_t datos);

/*
Precondiciones:
    FUENTE es un archivo abierto en formato de lectura, debe tener el formato ID;NOMBRE;EDAD;ESTADO y los datos deben estar ordenados de manera descendente segun su ID
Postcondiciones:
    Escribe en consola en forma de tabla los datos dentro FUENTE, mostrando el estado con su forma completa, es decir, la palabra no el caracter.
*/
void transcribir_lista_en_consola(FILE *fuente);

#endif /* __ACCIONES_H__ */