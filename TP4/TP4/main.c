#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"

#define STR 50
#define STRLONG 1000
#define FILE_NAME "File.dat"
#define FILE_NAME_BACKUP "File_copy.dat"

int main() {
    ArrayList* lista;
    lista = al_newArrayList();
    char seguir='s';
    int opcion=0;
    int flag;

    // aca inicializamos el proximo id para que sea cero por que la lista esta vacia.
    proximo_id = 0;
    levantarLista(lista, FILE_NAME);

    while(seguir=='s')
    {
        system("cls");
        printf("\n\t--MENU--\n");
        printf("\n 1- Agregar pelicula.\n"); //ok
        printf(" 2- Borrar pelicula.\n"); //ok
        printf(" 3- Modificar pelicula.\n"); //ok
        printf(" 4- Ordenar lista de peliculas.\n");
        printf(" 5- Lista de peliculas.\n"); //ok
        printf(" 6- Vaciar lista.\n"); //ok
        printf(" 7- Backup de la lista.\n"); //ok
        printf(" 8- Crear sublista.\n"); //ok
        printf(" 9- *\n");
        printf(" 10- *\n");
        printf(" 11- *\n");
        printf(" 12- Salir.\n\n"); //ok

        do
        {
            flag = pedirInt(&opcion, " Elija una opcion: ", " Ingreso un valor incorrecto.",1 , 12);
        } while(flag == -1);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(lista, FILE_NAME);
                system("pause");
                break;
            case 2:
                system("cls");
                borrarPelicula(lista, FILE_NAME);
                break;
            case 3:
                system("cls");
                modificarPelicula(lista, FILE_NAME);
                break;
            case 4:
                system("cls");
                listarPeliculas(lista);
                ordenarLista(lista, FILE_NAME, comparaElementos, 1);
                system("pause");
               break;
            case 5:
                system("cls");
                listarPeliculas(lista);
                system("pause");
                break;
            case 6:
                system("cls");
                clearList(lista, FILE_NAME);
                system("pause");
                break;
            case 7:
                system("cls");
                copiarLista(lista, FILE_NAME_BACKUP, sizeof(EMovie));
                system("pause");
                break;
            case 8:
                system("cls");
                crearSublista(lista, "subList.dat", sizeof(EMovie));
                system("pause");
                break;
            case 9:
                system("cls");
                //listarPeliculas(lista);
                system("pause");
                break;
            case 10:
                system("cls");
                //listarPeliculas(lista);
                system("pause");
                break;
            case 11:
                system("cls");
                //listarPeliculas(lista);
                system("pause");
                break;
            case 12:
                //guardarLista (lista, FILE_NAME);
                seguir = 'n';
                break;
        }
    }

    return 0;
}
