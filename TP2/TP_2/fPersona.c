#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fPersona.h"
#include "Input/input.h"
#include "Arreglos/arreglo.h"


EPersona ingresarPersona (int strTam)
{
    EPersona persona;
    int flag;

    do
    {
        flag = getString(&persona.nombre, "Ingrese Nombre: ", "Nombre invalido.", 1, strTam);
    }while(flag == -1);

    do
    {
        flag = getInt(&persona.edad, "Ingrese Edad: ", "Edad invalida.", 0, 100);
    }while(flag == -1);

    do
    {
        flag = getLongInt(&persona.dni, "Ingrese DNI: ", "DNI invalido.", 0, 1147483647);
    }while(flag == -1);

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

int buscarPorDni(EPersona lista[], int tam, long int dni_)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (lista[i].estado==1)
        {
            if (lista[i].dni == dni_)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

void quitarPersonaDeLista(EPersona lista[], int tam, long int dni)
{
    int indiceDni;
    indiceDni = buscarPorDni(lista, tam, dni);

    if (indiceDni >=0)
    {
        lista[indiceDni].estado = 0;
        printf("\nPersona borrada.");
    }
    else
    {
        printf("\nDni no encontrado.");
    }
}

void ordenarListaPorNombre(EPersona lista[], int tam)
{
    int i;
    int j;
    int comparacion;
    EPersona personaAux;

    for (i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            comparacion = strcmp(lista[i].nombre, lista[j].nombre);
            if (comparacion>0) // j es menor
            {
                personaAux = lista[i];
                lista[i] = lista[j];
                lista[j] = personaAux;
            }
        }
    }
}

void imprimirLista (EPersona lista[], int tam)
{
    int i;

    for (i=0; i<tam; i++)
    {
        if (lista[i].estado==1)
        {
            printf("\nNombre: %s  Edad: %d  DNI: %ld\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
}

void imprimirGraficoEdades (EPersona lista[], int tam)
{


    int i;
    int gruposEdades [3]={};
    int edad;
    int max;
    char asterisco1;
    char asterisco2;
    char asterisco3;
    for(i=0; i<tam; i++)
    {
        if (lista[i].estado == 1)
        {
            edad = lista[i].edad;
            if(edad<=18)
            {
                gruposEdades[0]++;
            }
            else if (edad>18 && edad<=35)
            {
                gruposEdades[1]++;
            }
            else if (edad>35)
            {
                gruposEdades[2]++;
            }
        }
    }

    max = maximo(gruposEdades, 3);

    for (i =max; i>0; i--)
    {
        asterisco1=' ';
        asterisco2=' ';
        asterisco3=' ';

        if (gruposEdades[0]>=i)
        {
            asterisco1='*';
        }
        if(gruposEdades[1]>=i)
        {
            asterisco2='*';
        }
        if(gruposEdades[2]>=i)
        {
            asterisco3='*';
        }
        printf("\n  %c     %c     %c\n",asterisco1,asterisco2, asterisco3);
    }
        printf("\n <18  19-35  >35\n\n");
}

