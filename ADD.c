#include "comandos.h"
#include "comprobaciones.h"
#include "constantes.h"
#include "control.h"

int main(int argc, char *argv[])
{
    FILE *archivo = fopen("lista.cvs", "r");

    parametros_t datos;
    datos.cantidad_arguementos = argc;

    asignar_datos_segun_comando(&datos, argv, argc);

    /*
        strcpy(datos.comando, argv[1]);
        datos.heroe.id = atoi(argv[2]);
        strcpy(datos.heroe.nombre, argv[3]);
        datos.heroe.edad = atoi(argv[4]);
        datos.heroe.estado = atoi(argv[5]);
        strcpy(datos.archivo, argv[6]);
    */

    escribir_linea_en_consola(datos);

    fclose(archivo);
    return 0;
}
