#include "constantes.h"
#include "comandos.h"

int main(int argc, char *argv[])
{

    printf("\n\nParametros:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("argv:%i: %s\n", i, argv[i]);
    }
    printf("\n\n");

    /**/

    parametros_comando_t solicitud;
    strcpy(solicitud.comando, argv[POSICION_COMANDO]);

    asignar_datos_segun_comando(&solicitud, argv, argc);

    ejecutar_solicitud(solicitud);

    printf("COMANDO: %s\n", solicitud.comando);
    printf("ID: %i\n", solicitud.heroe.id);
    printf("NOMBRE: %s\n", solicitud.heroe.nombre);
    printf("EDAD: %i\n", solicitud.heroe.edad);
    printf("ESTADO: %c\n", solicitud.heroe.estado);
    printf("ARCHIVO: %s\n", solicitud.archivo);

    return 0;
}
