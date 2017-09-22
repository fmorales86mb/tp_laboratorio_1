#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fPersona.h"
#include "Input/input.h"


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
        flag = getInt(&persona.dni, "Ingrese DNI: ", "DNI invalido.", 0, 10000);
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

int buscarPorDni(EPersona lista[], int tam, int dni)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (lista[i].estado==1)
        {
            if (lista[i].dni == dni)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

void quitarPersonaDeLista(EPersona lista[], int tam, int dni)
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
            printf("\nNombre: %s  Edad: %d  DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
}

void imprimirGraficoEdades (EPersona lista[], int tam)
{


    int i;
    int men18 = 0; // No incluye 18
    int ent19_35 = 0; // incluye 19 y 35
    int may35 = 0; // no incluye 35
    int edad;
    char asterisco1;
    char asterisco2;
    char asterisco3;
    for(i=0; i<tam; i++)
    {
        if (lista[i].estado == 1)
        {
            edad = lista[i].edad;
            if(edad<18)
            {
                men18++;
            }
            else if (edad>18 && edad<=35)
            {
                ent19_35++;
            }
            else if (edad>35)
            {
                may35++;
            }
        }
    }

    for (i =tam; i>0; i--)
    {
        asterisco1=' ';
        asterisco2=' ';
        asterisco3=' ';

        if (men18>=i)
        {
            asterisco1='*';
        }
        if(ent19_35>=i)
        {
            asterisco2='*';
        }
        if(may35>=i)
        {
            asterisco3='*';
        }
        printf("\n %c\t%c\n%c\n",asterisco1,asterisco2, asterisco3);
    }
}

