#include "fun.h"

int obtenerEspacioLibre(EPersona lista[], int tam){
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarPorDni(EPersona lista[], int tam, int dni)
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (lista[i].dni == dni)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
