#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"

#define MO 10
#define STR 50
#define STRLONG 500


int main()
{
    EMovie lista[MO];
    char seguir='s';
    int opcion=0;
    int flag;

    char pageName [STR]={"movies.html"};
    inicializarMovies(lista, MO);
    harcodearListaMovie(lista);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Agregar pelicula\n");
        printf(" 2- Borrar pelicula\n");
        printf(" 3- Generar pagina web\n");
        printf(" 4- Salir\n\n");

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.", 1, 4);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                system("cls");
                generarPagina(lista, pageName, MO);
                printf("\n La pagina se genero exitosamente.\n\n ");
                system("pause");
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
