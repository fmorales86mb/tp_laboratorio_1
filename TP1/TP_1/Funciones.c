#include <stdio.h>
#include <stdlib.h>

// Sumar

float sumarFloat (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 + nro2;

    return resultado;
}

// Restar

float restarFloat (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 - nro2;

    return resultado;
}

// Multiplicar

float multiplicarFloat (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 * nro2;

    return resultado;
}

// Dividir

float dividirFloat (float nro1, float nro2)
{
    float resultado;

    if (nro2 != 0)
    {
        resultado = nro1 / nro2;
    }

    return resultado;
}

// El nro ingresado debe ser un entero positivo.
int factorial (int nro)
{
    int factorial=1;

    for (int i = 1; i<nro; i++)
    {
        factorial = factorial*(i+1);
    }
    return factorial;
}

// Chequea que el nro ingresado sea entero o no. Devuelve 1 si es entero, 0 si no lo es.
int chequearNroEntero (float nro)
{
    int flag;
    int parteEntera;

    parteEntera=(int) nro;

    if (parteEntera - nro == 0)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}
