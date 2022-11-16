#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const int BUSCADO_NO_EXISTE = -1;
/**/
#define MAX_LONGITUD_COMANDO 20
#define MAX_LONGITUD_ARGUMENTO 40
#define MAX_NOMBRE 30
#define MAX_NOMBRE_ARCHIVO 40
#define MAX_LINEAS 10000
#define MAX_ANCHO_COLUMNA 50
#define CANTIDAD_COLUMNAS 4
/**/
#define MAX_COLUMNA_ID 8
#define MAX_COLUMNA_EDAD 5
#define MAX_COLUMNA_NOMBRE MAX_NOMBRE + 5

static const int EDAD_MAXIMA = 100;

static const int MINIMO_ARGUMENTOS_LISTAR = 3;
static const int MINIMO_ARGUMENTOS_CONTACTAR = 4;
static const int MINIMO_ARGUEMENTOS_MODIFICAR = 6;
static const int MINIMO_ARGUEMENTOS_AGREGAR = 7;
static const int MINIMO_ARGUEMENTOS_AYUDA = 2;

static const char ESTADO_VIVO = 'V';
static const char ESTADO_MUERTO = 'M';

/*Indice de los datos en la linea de comandos*/
static const int POSICION_COMANDO = 1;

static const int LISTAR_POSICION_ARCHIVO = 2;

static const int CONTACTAR_POSICION_ID = 2;
static const int CONTACTAR_POSICION_ARCHIVO = 3;

static const int MODIFICAR_POSICION_ID = 2;
static const int MODIFICAR_POSICION_EDAD = 3;
static const int MODIFICAR_POSICION_ESTADO = 4;
static const int MODIFICAR_POSICION_ARCHIVO = 5;

static const int AGREGAR_POSICION_ID = 2;
static const int AGREGAR_POSICION_NOMBRE = 3;
static const int AGREGAR_POSICION_EDAD = 4;
static const int AGREGAR_POSICION_ESTADO = 5;
static const int AGREGAR_POSICION_ARCHIVO = 6;

/**/
static const int FINALIZAR_PROGRAMA = -1;
static const int MAX_ARGUMENTOS_PROGRAMA = 9;

/**/
static const char COMANDO_LISTAR_SUPERS[MAX_LONGITUD_COMANDO] = "listar";
static const char COMANDO_CONTACTAR_SUPER[MAX_LONGITUD_COMANDO] = "contactar";
static const char COMANDO_MODIFICAR_SUPER[MAX_LONGITUD_COMANDO] = "modificar";
static const char COMANDO_AGREGAR_SUPER[MAX_LONGITUD_COMANDO] = "agregar";
static const char COMANDO_AYUDA[MAX_LONGITUD_COMANDO] = "ayuda";

typedef struct datos_heroe
{
    int id;
    char nombre[MAX_NOMBRE];
    char estado;
    int edad;
} datos_heroe_t;

typedef struct parametros_comando
{
    char comando[MAX_LONGITUD_COMANDO];
    datos_heroe_t heroe;
    char archivo[MAX_NOMBRE_ARCHIVO];
    int cantidad_arguementos;
} parametros_comando_t;

#endif /* __CONSTANTES_H__ */