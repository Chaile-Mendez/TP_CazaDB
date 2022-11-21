#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const int ERROR = -1;
static const int OK = 1;

static const int FINALIZAR_PROGRAMA = -1;
static const int BUSCADO_NO_EXISTE = -1;
/**/
#define MAX_LONGITUD_COMANDO 20
#define MAX_LONGITUD_ARGUMENTO 40
#define MAX_NOMBRE 50
#define MAX_NOMBRE_ARCHIVO 40
#define MAX_LINEAS 100000
#define MAX_ANCHO_COLUMNA 50
#define CANTIDAD_COLUMNAS 4
/**/
#define MAX_COLUMNA_ID 8
#define MAX_COLUMNA_EDAD 5
#define MAX_COLUMNA_NOMBRE MAX_NOMBRE + MAX_COLUMNA_ESTADO
#define MAX_COLUMNA_ESTADO 10

#define MAX_LONGITUD_LINEA MAX_COLUMNA_ID + MAX_COLUMNA_NOMBRE + MAX_COLUMNA_ESTADO

static const int EDAD_MAXIMA = 100;
static const int EDAD_MINIMA = 0;
static const int MINIMO_ARGUMENTOS_LISTAR = 3;
static const int MINIMO_ARGUMENTOS_CONTACTAR = 4;
static const int MINIMO_ARGUEMENTOS_MODIFICAR = 6;
static const int MINIMO_ARGUEMENTOS_AGREGAR = 7;
static const int MINIMO_ARGUEMENTOS_AYUDA = 2;

static const char ESTADO_VIVO = 'V';
static const char TEXTO_ESTADO_VIVO[MAX_COLUMNA_ESTADO] = "vivo";
static const char TEXTO_ESTADO_MUERTO[MAX_COLUMNA_ESTADO] = "muerto";
static const char ESTADO_MUERTO = 'M';
#define NOMBRE_PROGRAMA "caza"

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
static const int MAX_ARGUMENTOS_PROGRAMA = 9;

#define FORMATO_LECTURA "%i;%[^;];%i;%c\n"

static const char NOMBRE_ARCHIVO_AUXILIAR[MAX_NOMBRE_ARCHIVO] = "auxiliar.cvs";
/**/
static const char COMANDO_LISTAR_SUPERS[MAX_LONGITUD_COMANDO] = "listar";
static const char COMANDO_CONTACTAR_SUPER[MAX_LONGITUD_COMANDO] = "contactar";
static const char COMANDO_MODIFICAR_SUPER[MAX_LONGITUD_COMANDO] = "modificar";
static const char COMANDO_AGREGAR_SUPER[MAX_LONGITUD_COMANDO] = "agregar";
static const char COMANDO_AYUDA[MAX_LONGITUD_COMANDO] = "ayuda";

typedef struct super
{
    int id;
    char nombre[MAX_NOMBRE];
    char estado;
    int edad;
} super_t;

typedef struct parametros
{
    int codigo_comando;
    super_t heroe;
    char archivo[MAX_NOMBRE_ARCHIVO];
} parametros_t;

#define CODIGO_AYUDA 1
#define CODIGO_AGREGAR 2
#define CODIGO_ELIMINAR 3
#define CODIGO_MODIFICAR 4
#define CODIGO_LISTAR 5

#endif /* __CONSTANTES_H__ */