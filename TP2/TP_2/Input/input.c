#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

/**
* \brief Solicita un número al usuario y lo chequea
* \param input Se carga el numero ingresado (es una dirección de memoria).
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int salida = -1;
	int nro;

    printf("\n%s", message);
    scanf("%d", &nro);

    if (nro>hiLimit || nro<lowLimit)
    {
        printf("\n%s\n", eMessage);
        //system("pause");
    }
    else
    {
        *input = nro;
        salida = 0;
    }

    return salida;
}


/**
* \brief Solicita un número al usuario y lo chequea
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int salida = -1;
	float nro;

    printf("\n%s", message);
    scanf("%f", &nro);

    if (nro>hiLimit || nro<lowLimit)
    {
        printf("\n%s\n", eMessage);
        //system("pause");
    }
    else
    {
        *input = nro;
        salida = 0;
    }

    return salida;
}


/**
* \brief Solicita un caracter al usuario y lo chequea
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int salida = -1;
	char dato;

    printf("\n%s", message);
    dato = getche();
    dato = tolower(dato);

    if (dato!=hiLimit && dato!=lowLimit)
    {
        printf("\n%s\n", eMessage);
        //system("pause");
    }
    else
    {
        *input = dato;
        salida = 0;
    }

    return salida;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la chequea
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int salida = -1;
	char dato[2000];
    int length;

    printf("\n%s", message);
    fflush( stdin );
    gets(dato);
    length = strlen(dato);

    if (length>hiLimit || length<lowLimit)
    {
        printf("\n%s\n", eMessage);
        //system("pause");
    }
    else
    {
        //*input = dato;
        strcpy(input, dato);
        salida = 0;
    }

    return salida;
}
