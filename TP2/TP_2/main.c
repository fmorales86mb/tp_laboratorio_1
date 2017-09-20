#include <stdio.h>
#include <stdlib.h>
#include "fPersona.h"
#define TAM 50


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona listaPersonas[20];
    int contador=0;

    while(seguir=='s')
    {
        system("cls");
        printf("\n     ---MENU---\n\n");

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(listaPersonas[contador], 50);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
