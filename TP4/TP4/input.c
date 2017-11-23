#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

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
