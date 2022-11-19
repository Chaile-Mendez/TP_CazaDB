#include "constantes.h"
#include "comandos.h"

int main(int argc, char *argv[])
{

    parametros_t solicitud;

    asignar_datos_segun_comando(&solicitud, argv, argc);

    ejecutar_solicitud(solicitud);

    return 0;
}
 