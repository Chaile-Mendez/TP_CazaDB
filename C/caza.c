#include "constantes.h"
#include "comandos.h"

int main(int argc, char *argv[])
{

    parametros_t solicitud;

    if (ERROR == asignar_datos_segun_comando(&solicitud, argv, argc))
    {
        return ERROR;
    }

    ejecutar_solicitud(solicitud);

    return 0;
}
