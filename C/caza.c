#include "constantes.h"
#include "comprobaciones.h"
#include "comandos.h"

int main(int argc, char *argv[])
{

    parametros_t solicitud;

    if (!(asignar_codigo_comando(argv[POSICION_COMANDO], &solicitud.codigo_comando)))
    {
        return ERROR;
    }

    if (!(asignar_datos_segun_comando(&solicitud, argv, argc)))
    {
        return ERROR;
    }

    if (!(ejecutar_solicitud(solicitud)))
    {
        return ERROR;
    }

    return 0;
}
