#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"

#define MO 50
#define STR 50
#define STRLONG 500

/*
El sistema va a levantar los datos del archivo y pasarlos a la lista.
Se va a trabajar con lista de estructura (abm).
El usuario va a tener una opción para guardar los cambios en el archivo.
*/
int main()
{
    EMovie lista[MO];
    char seguir='s';
    int opcion=0;
    int flag;

    char pageName [STR]={"movies.html"};
    char fileName [STR]={"File.dat"};
    inicializarMovies(lista, MO);
    //harcodearListaMovie(lista);
    levantarLista(lista, MO, fileName);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Agregar pelicula.\n");
        printf(" 2- Borrar pelicula.\n");
        printf(" 3- Generar pagina web.\n");
        printf(" 4- Guardar cambios en un archivo.\n");
        printf(" 5- Lista de peliculas.\n");
        printf(" 6- Salir.\n\n");

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.",1 , 6);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(lista, MO);
                break;
            case 2:
                system("cls");
                borrarPelicula(lista, MO);
                break;
            case 3:
                system("cls");
                generarPagina(lista, pageName, MO);
                printf("\n La pagina se genero exitosamente.\n\n ");
                system("pause");
               break;
            case 4:
                if (guardarLista(lista, MO, fileName)==0)
                {
                    printf("\n La lista no se pudo guardar correctamente.\n");
                }
                else
                {
                    printf("\n Lista guardada.\n");
                }
                system("pause");
                break;
            case 5:
                system("cls");
                listarPeliculas(lista, MO);
                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
