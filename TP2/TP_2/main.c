#include <stdio.h>
#include <stdlib.h>
#include "fPersona.h"
#include "Input/input.h"
#include "biblioStr/validacionStr.h"

#define TAM 50
#define TAMLIST 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona listaPersonas[TAMLIST] = {};
    int indiceLibre;
    long int dniBorrar;
    int flag;
    int indiceDni;
    EPersona persona;

    while(seguir=='s')
    {
        system("cls");
        printf("\n       ---MENU---\n\n");

        printf(" 1 - Agregar persona\n");
        printf(" 2 - Borrar persona\n");
        printf(" 3 - Imprimir lista ordenada por  nombre\n");
        printf(" 4 - Imprimir grafico de edades\n");
        printf(" 5 - Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                indiceLibre = obtenerEspacioLibre(listaPersonas, TAMLIST);
                if (indiceLibre>=0)
                {
                    persona = ingresarPersona(TAM);
                    indiceDni = buscarPorDni(listaPersonas, TAMLIST, persona.dni);
                    if (indiceDni>=0)
                    {
                        printf("\nDNI repetido.");

                    }
                    else
                    {
                        listaPersonas[indiceLibre] = persona;
                    }

                }
                else
                {
                    printf("\nNo hay espacio en la lista de personas.");
                }

                printf("\n");
                system("pause");

                break;
            case 2:

                system("cls");

                do
                {
                    flag = getLongInt(&dniBorrar, "Ingrese el DNI de la persona que desea borrar de la lista: ", "DNI Invalido.", 0, 1147483647);
                }while(flag==-1);

                quitarPersonaDeLista(listaPersonas, TAMLIST, dniBorrar);
                system("pause");

                break;
            case 3:
                system("cls");

                ordenarListaPorNombre(listaPersonas, TAMLIST);
                imprimirLista(listaPersonas, TAMLIST);

                system("pause");

                break;
            case 4:
                system("cls");
                imprimirGraficoEdades(listaPersonas, TAMLIST);
                system("pause");

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
