#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float x = 0;
    float y = 0;
    int xInt;
    int flagEntero;
    float resultado;

    while(seguir=='s')
    {
        system("cls");

        printf("1- Ingresar 1er operando (A=%.2f)\n", x);
        printf("2- Ingresar 2do operando (B=%.2f)\n", y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\n1- Ingresar 1er operando: ");
                scanf("%f", &x);
                break;
            case 2:
                system("cls");
                printf("\n2- Ingresar 2do operando: ");
                scanf("%f", &y);
                break;
            case 3:
                system("cls");
                resultado = sumarFloat(x,y);
                printf("\n%.2f + %.2f = %.2f\n\n", x, y, resultado);
                system("pause");
                break;
            case 4:
                system("cls");
                resultado = restarFloat(x, y);
                printf("\n%.2f - %.2f = %.2f\n\n", x, y, resultado);
                system("pause");
                break;
            case 5:
                system("cls");

                if (y != 0)
                {
                    resultado = dividirFloat(x, y);
                    printf("\n%.2f / %.2f = %.2f\n\n", x, y, resultado);
                }
                else
                {
                    printf("\nEl divisor debe ser distinto de cero.\n\n");
                }

                system("pause");
                break;
            case 6:
                system("cls");

                resultado = multiplicarFloat(x, y);
                printf("\n%.2f * %.2f = %.2f\n\n", x, y, resultado);

                system("pause");
                break;
            case 7:
                system("cls");

                flagEntero = chequearNroEntero(x);

                if (x>=1 && flagEntero==1)
                {
                    xInt = (int) x;
                    resultado = (float)factorial(xInt);
                    printf("\n%d! = %.0f\n\n", xInt, resultado);
                }
                else
                {
                    printf("\nNo se puede realizar la operación.\nEl numero ingresado (A) debe ser un entero positivo.\n\n");
                }


                system("pause");
                break;
            case 8:
                system("cls");

                // Suma
                resultado = sumarFloat(x,y);
                printf("\n%.2f + %.2f = %.2f\n", x, y, resultado);

                // Resta
                resultado = restarFloat(x, y);
                printf("\n%.2f - %.2f = %.2f\n", x, y, resultado);

                // Division
                if (y != 0)
                {
                    resultado = dividirFloat(x, y);
                    printf("\n%.2f / %.2f = %.2f\n", x, y, resultado);
                }
                else
                {
                    printf("\nNo se puede realizar la division.\nEl divisor debe ser distinto de cero.\n");
                }

                // Multiplicacion
                resultado = multiplicarFloat(x, y);
                printf("\n%.2f * %.2f = %.2f\n", x, y, resultado);

                // Factorial
                flagEntero = chequearNroEntero(x);

                if (x>=1 && flagEntero==1)
                {
                    xInt = (int) x;
                    resultado = (float)factorial(xInt);
                    printf("\n%d! = %.0f\n\n", xInt, resultado);
                }
                else
                {
                    printf("\nNo se puede calcular el factorial.\nEl numero ingresado (A) debe ser un entero positivo.\n\n");
                }

                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
