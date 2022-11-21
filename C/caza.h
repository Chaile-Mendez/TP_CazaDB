#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const int ERROR = -1;

#define MAX_LONGITUD_COMANDO 20
#define MAX_NOMBRE 50
#define MAX_NOMBRE_ARCHIVO 40
#define MAX_ANCHO_COLUMNA ANCHO_COLUMNA_NOMBRE
#define CANTIDAD_COLUMNAS 4

#define ANCHO_COLUMNA_ID 8
#define ANCHO_COLUMNA_NOMBRE MAX_NOMBRE + 5
#define ANCHO_COLUMNA_EDAD 8
#define ANCHO_COLUMNA_ESTADO 10

#define MAX_LONGITUD_LINEA ANCHO_COLUMNA_ID + ANCHO_COLUMNA_NOMBRE + ANCHO_COLUMNA_EDAD + ANCHO_COLUMNA_ESTADO + 6

static const int EDAD_MAXIMA = 100;
static const int EDAD_MINIMA = 0;

#define CODIGO_AYUDA 1
#define CODIGO_AGREGAR 2
#define CODIGO_ELIMINAR 3
#define CODIGO_MODIFICAR 4
#define CODIGO_LISTAR 5

static const int CANTIDAD_ARGUMENTOS_LISTAR = 3;
static const int CANTIDAD_ARGUMENTOS_CONTACTAR = 4;
static const int CANTIDAD_ARGUMENTOS_MODIFICAR = 6;
static const int CANTIDAD_ARGUMENTOS_AGREGAR = 7;
static const int CANTIDAD_ARGUMENTOS_AYUDA = 2;

static const char CARACTER_ESTADO_OK = 'V';
static const char CARACTER_ESTADO_NO_OK = 'M';
static const char PALABRA_ESTADO_OK[ANCHO_COLUMNA_ESTADO] = "vivo";
static const char PALABRA_ESTADO_NO_OK[ANCHO_COLUMNA_ESTADO] = "muerto";

static const int POSICION_COMANDO = 1;

static const int LISTAR_POSICION_ARCHIVO = 2;

static const int POSICION_ID_EN_CONTACTAR = 2;
static const int POSICION_ARCHIVO_EN_CONTACTAR = 3;

static const int POSICION_ID_EN_MODIFICAR = 2;
static const int POSICION_EDAD_EN_MODIFICAR = 3;
static const int POSICION_ESTADO_EN_MODIFICAR = 4;
static const int POSICION_ARCHIVO_EN_MODIFICAR = 5;

static const int POSICION_ID_EN_AGREGAR = 2;
static const int POSICION_NOMBRE_EN_AGREGAR = 3;
static const int POSICION_EDAD_EN_AGREGAR = 4;
static const int POSICION_ESTADO_EN_AGREGAR = 5;
static const int POSICION_ARCHIVO_EN_AGREGAR = 6;

#define FORMATO_LECTURA "%i;%[^;];%i;%c\n"

#define NOMBRE_PROGRAMA "caza"
static const char COMANDO_LISTAR_SUPERS[MAX_LONGITUD_COMANDO] = "listar";
static const char COMANDO_CONTACTAR_SUPER[MAX_LONGITUD_COMANDO] = "contactar";
static const char COMANDO_MODIFICAR_SUPER[MAX_LONGITUD_COMANDO] = "modificar";
static const char COMANDO_AGREGAR_SUPER[MAX_LONGITUD_COMANDO] = "agregar";
static const char COMANDO_AYUDA[MAX_LONGITUD_COMANDO] = "ayuda";
static const char NOMBRE_ARCHIVO_AUXILIAR[MAX_NOMBRE_ARCHIVO] = "auxiliar.cvs";

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

#endif /* __CONSTANTES_H__ */