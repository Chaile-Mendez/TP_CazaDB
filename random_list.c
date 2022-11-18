#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/*El formato es :  ID;Nombre;Edad;Estado  */

/*Constantes*/
#define MAX_ALFABETO 30
const char ALFABETO[MAX_ALFABETO] = "ABCDEFGHIJKLMNOPQRSUVWXYZ ";
const int TOPE_ALFABETO = 26;
const char ARCHIVO[MAX_ALFABETO] = "./lista.cvs";
const int FINALIZAR_PROGRAMA = -1;

/*Devuelve un numero aleatorio entre dos numeros*/
int obtener_numero_random(int minimo, int maximo)
{
    int amplitud = maximo - minimo + 1;
    int numero = rand() % amplitud + minimo; // la amplitud del rango es 20 y el valor mínimo es 10.
    return numero;
}

/* Asigna un string de caracteres aleatorios da una longitud */
void string_aleatorio(char string[], int longitud)
{
    int espacios = 0;
    int indice_aleatorio = -1;
    for (int i = 0; i < longitud; i++)
    {
        indice_aleatorio = obtener_numero_random(0, TOPE_ALFABETO - 1);
        string[i] = ALFABETO[indice_aleatorio];
    }
    string[longitud] = '\0';
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL)); // Semilla

    if (argc != 2)
    {
        printf("Ingresar numero de lineas");
        return -1;
    }

    int repeticiones = atoi(argv[1]);

    char nombre[50];
    int edad = -1;
    char estado = 'X';

    FILE *lista = fopen(ARCHIVO, "w");

    for (int i = 0; i < repeticiones; i++)
    {
        string_aleatorio(nombre, obtener_numero_random(4, 30));
        edad = obtener_numero_random(0, 100);

        if (obtener_numero_random(0, 1))
        {
            estado = 'V';
        }
        else
        {
            estado = 'M';
        }

        fprintf(lista, "%i;%s;%i;%c\n", i, nombre, edad, estado);
    }
    fclose(lista);
    return 0;
}
