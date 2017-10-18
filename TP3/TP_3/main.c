#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"

#define MO 50
#define STR 50
#define STRLONG 1000
#define FILE_NAME "File.dat"
#define PAGE_NAME "movies.html"

int main()
{
    EMovie lista[MO];
    char seguir='s';
    int opcion=0;
    int flag;

    inicializarMovies(lista, MO);
    //harcodearListaMovie(lista);
    levantarLista(lista, MO, FILE_NAME);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Agregar pelicula.\n");
        printf(" 2- Borrar pelicula.\n");
        printf(" 3- Modificar pelicula.\n");
        printf(" 4- Generar pagina web.\n");
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
                agregarPelicula(lista, MO, FILE_NAME);
                system("pause");
                break;
            case 2:
                system("cls");
                borrarPelicula(lista, MO, FILE_NAME);
                break;
            case 3:
                system("cls");
                modificarPelicula(lista, MO, FILE_NAME);
               break;
            case 4:
                system("cls");
                generarPagina(lista, PAGE_NAME, MO);
                printf("\n La pagina se genero exitosamente.\n\n ");
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
