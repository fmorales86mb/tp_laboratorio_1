#include <stdio.h>
#include <stdlib.h>

/**
* \brief Realiza la suma de dos variables float.
* \param nro1 primer valor float.
* \param nro2 segundo valor float.
* \return Devuelve, en un tipo de dato float, el valor de la suma.
*
*/
float sumarFloat (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 + nro2;

    return resultado;
}

/**
* \brief Realiza la resta de dos variables float.
* \param nro1 primer valor float.
* \param nro2 segundo valor float.
* \return Devuelve, en un tipo de dato float, el valor de la resta.
*
*/
float restarFloat (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 - nro2;

    return resultado;
}

/**
* \brief Realiza la multiplicación de dos variables float.
* \param nro1 primer valor float.
* \param nro2 segundo valor float.
* \return Devuelve, en un tipo de dato float, el valor de la multiplicación.
*
*/
float multiplicarFloat (float nro1, float nro2)
{
    float resultado;

    resultado = nro1 * nro2;

    return resultado;
}

/**
* \brief Realiza la división de dos variables float.
* \param nro1 primer valor float.
* \param nro2 segundo valor float, no debe ser igual a cero.
* \return Devuelve, en un tipo de dato float, el valor de la división.
*
*/
float dividirFloat (float nro1, float nro2)
{
    float resultado;

    if (nro2 != 0)
    {
        resultado = nro1 / nro2;
    }

    return resultado;
}

/**
* \brief Realiza el factorial de una variable int.
* \param nro entero positivo.
* \return Devuelve, en un tipo de dato int, el valor del factorial.
*
*/
int factorial (int nro)
{
    int factorial=1;

    for (int i = 1; i<nro; i++)
    {
        factorial = factorial*(i+1);
    }
    return factorial;
}

/**
* \brief Chequea que el nro ingresado sea entero.
* \param nro variable float a ser chequeada.
* \return Devuelve 1 si es entero, 0 si no lo es.
*
*/
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
