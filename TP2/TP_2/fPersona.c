#include <stdio.h>
#include <stdlib.h>
#include "fPersona.h"
#include "Input/input.h"

int agregarPersonaALista (EPersona persona, int indice)
{

}

EPersona ingresarPersona (int tam)
{
    EPersona persona;
    int flag;

    do
    {
        flag = getString(persona.nombre, "Ingrese Nombre: ", "Nombre invalido.", 1, tam);
    }while(flag == -1);

    do
    {
        flag = getInt(persona.edad, "Ingrese Edad: ", "Edad invalida.", 0, 100);
    }while(flag == -1);

    persona.dni=23;
    persona.estado=1;
    return persona;
}

int obtenerEspacioLibre(EPersona lista[], int tam)
{
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
