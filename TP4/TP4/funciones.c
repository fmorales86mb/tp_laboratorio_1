#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"
#include "ArrayList.h"

EMovie* newEMovie (void)
{
    EMovie* returnAux;
    returnAux = (EMovie*)malloc(sizeof(EMovie));

    if(returnAux !=NULL)
    {
       returnAux->id = proximo_id;
       strcpy(returnAux->descripcion, "");
       strcpy(returnAux->genero, "");
       strcpy(returnAux->titulo, "");
       returnAux->puntaje = 0;
       returnAux->duracion = 0;

       proximo_id++;
    }
    return returnAux;
}

int agregarPelicula(ArrayList *lista) {
    int retorno = 1;
    EMovie* movie = NULL;
    movie = newEMovie();

    if (movie!=NULL) {
        if (pedirMovie (movie) != 0) {
            // Aca tenemos la pelicula cargada entoncesla agregamos a la lista
            lista->add (lista, movie);

        } else {
            retorno = 0;
        }

    } else {
        retorno = 0;
    }

    return retorno;
}

int borrarPelicula(EMovie lista[], int sizeMo, char fileName[])
{
    /*
    int i;
    int id;
    int flag;
    int chances = 0;
    int retorno = -1;

    listarPeliculas(lista);

    do
    {
        flag = pedirInt(&id, " Ingrese el ID de la pelicula que desea borrar: ", " ID invalido.", 1 , buscarIdLibre(lista, sizeMo));
        chances++;
    } while(flag == -1 && chances<3);

    if (chances<3)
    {
        retorno = 0;
        for (i=0; i<sizeMo; i++)
        {
            if (lista[i].id == id)
            {
                lista[i].id = -1;
                retorno = 1;
                break;
            }
        }
    }

    switch (retorno)
    {
        case -1:
            break;
        case 0:
            printf("\n ID no encontrado.\n");
            break;
        case 1:
            if (guardarLista(lista, MO, fileName)==0)
            {
                retorno=0;
                printf("\n La pelicula no se pudo borrar correctamente.\n");
            }
            else
            {
                printf("\n Pelicula borrada.\n");
            }
            break;
        default:
            printf("\n Error.\n");
            break;
    }

    system("pause");

    return retorno;
*/
    return 1;
}

int modificarPelicula (EMovie lista[], int sizeMo, char fileName[])
{
    /*
    int i;
    int id;
    int flag;
    int chances = 0;
    int retorno = 0;
    EMovie movie;


    listarPeliculas(lista, sizeMo);

    do
    {
        flag = pedirInt(&id, " Ingrese el ID de la pelicula que desea modificar: ", " ID invalido.", 1 , buscarIdLibre(lista, sizeMo));
        chances++;
    } while(flag == -1 && chances<3);

    if (chances<3)
    {
        retorno = 1;
        for (i=0; i<sizeMo; i++)
        {
            if (lista[i].id == id)
            {
                retorno = 2;
                movie = pedirMovie();
                movie.id = id;
                lista[i] = movie;
                break;
            }
        }
    }

    switch (retorno)
    {
        case 0:
            break;
        case 1:
            printf("\n ID no encontrado.\n");
            break;
        case 2:
            if (guardarLista(lista, MO, fileName)==0)
            {
                retorno = 0;
                printf("\n La pelicula no se pudo guardar correctamente.\n");
            }
            else
            {
                printf("\n Pelicula Modificada.\n");
            }
            break;
        default:
            printf("\n Error.\n");
            break;
    }
    system("pause");
*/
    return 0;
}


int pedirMovie (EMovie *movie) {
    int flag;
    int chances = 0;

    printf("\n Ingrese datos de la pelicula: \n\n");
    do
    {
        flag = getString(movie->titulo, " Titulo: ", " Titulo invalido.", 1, STR);
        chances++;
    }while (flag == -1 && chances<3);

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie->genero, " Genero: ", " Genero invalido.", 1, STR);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = pedirInt(&movie->duracion, " Duracion (minutos): ", " Duracion invalida.", 1, 800);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie->descripcion, " Descripcion: ", " Descripcion invalida.", 1, STRLONG);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = pedirInt(&movie->puntaje, " Puntaje (1 a 10): ", " Puntaje invalido.", 1, 10);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie->linkImagen, " Link a la imagen: ", " Link a la imagen invalido.", 1, STRLONG);
        }while (flag == -1 && chances<3);
    }

    return 1;
}


int buscarIdLibre (EMovie lista[], int size)
{
    int i;
    int id = -1;
    int maximo;

    for (i=0; i<size; i++)
    {
        if(i==0 || lista[i].id > maximo)
        {
            maximo = lista[i].id;
        }
    }

    if (maximo==-1) // caso en el que la lista está vacía
    {
        id = maximo+2;
    }
    else
    {
        id = maximo+1;
    }

    return id;
}

int levantarLista(ArrayList* lista, char* nombre) {
    int retorno;
    int i;
    int cant;
    int maximo = 0;
    EMovie *item;
    FILE * archivo;

    retorno = 1;
    // Intentamos abrir o crear un archivo.
    archivo = fopen(nombre, "rb");
    if (archivo == NULL)
    {
        archivo = fopen(nombre, "wb");
        if (archivo == NULL) {
            retorno = 0;
        }
    }

    // Si tenemos el archivo seguimos.
    if (retorno != 0) {
        // recorre el archivo del principioo hasta el final
        for (i=0; !feof(archivo); i++) {
            // Item apunta a una posicion de memoria donde entra un emovie
            item = (EMovie *) malloc (sizeof (EMovie));
            if (item == NULL) {
                retorno = 0;
                break;
            }

            // Leemos un registro del archivo y lo copiamos en la memoria apuntada por item
            cant = fread (item, sizeof(EMovie), 1, archivo);
            if (cant != 1){
                retorno = 0;
                break;
            }

            // Actualizamos el maximo
            if (item->id > maximo || i==0) {
                maximo = item->id;
            }

            // Si llegamos aca (por que no salio por ningun brake lo agreamos a la lista
            lista->add (lista, item);
        }

        // actualizamos proximo_id
        proximo_id = maximo + 1;

        fclose(archivo);
    }

    return retorno;
}

int guardarLista(ArrayList *lista, char nombre[]) {
    int i;
    int cant;
    int retorno = 0;
    FILE *archivo;

    archivo = fopen(nombre, "wb");
    if (archivo == NULL){
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;

    } else {
        retorno = 1;

        for(i=0; i<lista->len (lista); i++) {
            cant = fwrite(lista->get(lista, i), sizeof(EMovie), 1, archivo);

            if (cant != 1) {
                printf("\n No pudo escribir correctamente un registro.\n");
                retorno = 0;
                break;
            }
        }
    }

    fclose(archivo);

    return retorno;
}

void listarPeliculas(ArrayList *lista) {
    EMovie *movie;
    int i;

    printf("\n ID \t Titulo \t Genero \t Duracion \t Puntaje \t \n\n");

    for(i=0; i<lista->len(lista); i++) {
        movie = lista->get(lista, i);

        printf(" %d \t %s \t %s \t %d \t %d \n", movie->id ,
                   movie->titulo , movie->genero , movie->duracion , movie->puntaje);
    }

    printf("\n");
}

/*
void harcodearListaMovie(EMovie lista[])
{
    int i;

    int id[2]={1,2};
    char titulo[2][STR]={{"peli1"},{"peli2"}};
    char genero[2][STR]={{"accion"},{"drama"}};
    int duracion[2]={123, 156};
    char descripcion[2][STRLONG]={{"saraza"},{"sarlanga"}};
    int puntaje[2]={10, 5};
    char linkImagen[2][STRLONG]={{"http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg"},{"https://images-na.ssl-images-amazon.com/images/M/MV5BMjZiNzIxNTQtNDc5Zi00YWY1LThkMTctMDgzYjY4YjI1YmQyL2ltYWdlL2ltYWdlXkEyXkFqcGdeQXVyNjU0OTQ0OTY@._V1_UY190_CR2,0,128,190_AL_.jpg"}};

    for(i=0; i<2; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].titulo, titulo[i]);
        strcpy(lista[i].genero, genero[i]);
        lista[i].duracion = duracion[i];
        strcpy(lista[i].descripcion, descripcion[i]);
        lista[i].puntaje = puntaje[i];
        strcpy(lista[i].linkImagen, linkImagen[i]);
    }
}
*/
