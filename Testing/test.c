#include <stdio.h>

void leer_linea(FILE *archivo, int cantidad)
{
    int i = 0;
    char linea[50];
    while (i < cantidad)
    {
        fscanf(archivo, "%[^\n]\n", linea);
        i++;
    }
}
void leer_escribir(FILE *archivo, FILE *destino)
{
    char linea[50];
    while (!feof(archivo))
    {
        fscanf(archivo, "%[^\n]\n", linea);
        fprintf(destino, "%s\n", linea);
    }
}

int main(int argc, char *argv[])
{
    FILE *archivo_lectura = fopen("testing_original.csv", "r");
    if (archivo_lectura == NULL)
    {
        printf("error lec");
        return -1;
    }

    FILE *archivo_destino = fopen("testing.csv", "w");
    if (archivo_destino == NULL)
    {

        return -1;
        printf("error wrt");
    }

    leer_linea(archivo_lectura, 3);
    leer_escribir(archivo_lectura, archivo_destino);

    fclose(archivo_destino);
    fclose(archivo_lectura);
    return 0;
}
