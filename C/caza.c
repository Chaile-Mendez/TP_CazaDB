#include "caza.h"
#include "comprobaciones.h"
#include "comandos.h"

/*
Precondiciones:
    
Postcondiciones:

*/
int main(int argc, char *argv[])
{
    parametros_t datos;

    if (!(asignar_codigo_comando(argv[POSICION_COMANDO], &datos.codigo_comando)) ||
        !(asignar_datos_segun_comando(&datos, argv, argc)) ||
        !(ejecutar_comando(datos)))
    {
        return ERROR;
    }

    return 0;
}
