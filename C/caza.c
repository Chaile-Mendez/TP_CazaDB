#include <stdio.h>
#include <string.h>
#include "constantes.h"
#include "comandos.h"

int main(int argc, char *argv[])
{

   if (argc > MAX_ARGUMENTOS_PROGRAMA || argc < 2)
    {
        printf("\nEscriba './caza ayuda' para obtener informacion de los comandos disponibles y como usarlos\n");
        return FINALIZAR_PROGRAMA;
    }

    printf(" %s dsad", argv[LISTAR_POSICION_ARCHIVO]);
    printf("asdasdasdas");

    printf(" %s dsad", argv[2]);


    parametros_comando_t solicitud;
    strcpy(solicitud.comando, argv[POSICION_COMANDO]);
    solicitud.cantidad_arguementos = argc;

    asignar_datos_segun_comando(&solicitud, &argv);

    printf("COMANDO: %s\n", solicitud.comando);
    printf("ID: %i\n", solicitud.id);
    printf("NOMBRE: %s\n", solicitud.nombre);
    printf("EDAD: %i\n", solicitud.edad);
    printf("ESTADO: %c\n", solicitud.estado);
    printf("ARCHIVO: %s\n", solicitud.archivo);

    return 0;
}
