#include <stdio.h>
#include <stdlib.h>

// maximo
int maximo (int* arreglo, int cantElementos)
{
    int max;
    int i;

    for (i=0; i<cantElementos; i++)
    {
        if (i==0 || arreglo[i]>max)
        {
            max = arreglo[i];
        }
    }

    return max;
}

//minimo
int minimo (int* arreglo, int cantElementos)
{
    int min;
    int i;

    for (i=0; i<cantElementos; i++)
    {
        if (i==0 || arreglo[i]<min)
        {
            min = arreglo[i];
        }
    }

    return min;
}

// promedio
float media (int* arreglo, int cantElementos)
{
    float promedio;
    int i;
    int acumulador = 0;

    for(i=0; i<cantElementos; i++)
    {
        acumulador+=arreglo[i];
    }

    promedio=(float)acumulador/cantElementos;

    return promedio;
}

