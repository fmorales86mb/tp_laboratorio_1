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

int agregarPelicula(ArrayList *lista, char* fileName)
{
    int retorno = 1;
    EMovie* movie = NULL;
    movie = newEMovie();

    if (movie!=NULL)
    {
        if (pedirMovie (movie) != 0)
        {
            // Aca tenemos la pelicula cargada entonces la agregamos a la lista
            lista->add (lista, movie);
            guardarLista(lista, fileName, sizeof(EMovie));
        }
        else
        {
            retorno = 0;
        }
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int borrarPelicula(ArrayList* lista, char* fileName)
{
    int i;
    int id;
    int flag;
    int chances = 0;
    int retorno = -1;
    EMovie* movie;

    listarPeliculas(lista);

    do
    {
        flag = pedirInt(&id, " Ingrese el ID de la pelicula que desea borrar: ", " ID invalido.", 1 , proximo_id);
        chances++;
    } while(flag == -1 && chances<3);

    if (chances<3)
    {
        retorno = 0;
        for (i=0; i<lista->len(lista); i++)
        {
            movie = lista->get(lista, i);
            if (movie->id == id)
            {
                if (lista->remove(lista, i)==0)
                {
                    retorno = 1;
                }
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
            guardarLista(lista, fileName, sizeof(EMovie));
            break;
        default:
            printf("\n Error.\n");
            break;
    }

    system("pause");

    return retorno;
}

int modificarPelicula (ArrayList* lista, char* fileName)
{
    int i;
    int id;
    int flag;
    int chances = 0;
    int retorno = 0;
    EMovie* movie;

    listarPeliculas(lista);

    do
    {
        flag = pedirInt(&id, " Ingrese el ID de la pelicula que desea modificar: ", " ID invalido.", 1 , proximo_id);
        chances++;
    } while(flag == -1 && chances<3);

    if (chances<3)
    {
        retorno = 1;
        for (i=0; i<lista->len(lista); i++)
        {
            movie = lista->get(lista, i);
            if (movie->id == id)
            {
                retorno = 2;
                pedirMovie(movie);
                movie->id = id;
                lista->set(lista, i, movie);
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
            guardarLista(lista, fileName, sizeof(EMovie));
        default:
            printf("\n Error.\n");
            break;
    }
    system("pause");
    return 0;
}

int pedirMovie (EMovie *movie)
{
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

int levantarLista(ArrayList* lista, char* nombre)
{
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

int pisarArchivo(ArrayList *lista, char* nombre, int sizeOfStruct)
{
    int i;
    int cant;
    int retorno = 0;
    FILE *archivo;

    archivo = fopen(nombre, "wb");

    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;

    }
    else
    {
        retorno = 1;

        //printf("\nstr: %d\nobj: %d", sizeof(EMovie), sizeOfStruct);

        for(i=0; i<lista->len (lista); i++)
        {
            cant = fwrite(lista->get(lista, i), sizeOfStruct, 1, archivo);

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

void listarPeliculas(ArrayList *lista)
{
    EMovie *movie;
    int i;

    printf("\n Nro   ID   Titulo  Genero   Duracion   Puntaje  \n\n");

    for(i=0; i<lista->len(lista); i++) {
        movie = lista->get(lista, i);

    printf("   %d      %d      %s       %s       %d        %d \n",i+1, movie->id ,
                   movie->titulo , movie->genero , movie->duracion , movie->puntaje);
    }

    printf("\n");
}

int clearList (ArrayList* lista, char* fileName)
{
    int ret = 0;

    if(lista->clear(lista)==0)
    {
        ret = 1;
        printf("\n Lista vaciada.\n");
        guardarLista(lista, fileName, sizeof(EMovie));
    }

    return ret;
}

int copiarLista (ArrayList* lista, char* fileName2, int sizeOfStruct)
{
    int ret = 0;

    ArrayList* cloneList = lista->clone(lista);

    if (cloneList != NULL)
    {
        if(guardarLista(cloneList, fileName2, sizeOfStruct))
        {
            ret =1;
        }
    }
    return ret;
}

int crearSublista (ArrayList* lista, char* fileName2, int sizeOfStruct)
{
    int ret = 0;
    int flag;
    int desde;
    int hasta;

    // entro si hay elementos en la lista
    if(lista->isEmpty(lista)==0)
    {
        listarPeliculas(lista);

        printf("\n -- Crear Sublista --\n\n");
        do
        {
            flag = pedirInt(&desde, " Desde indice: ", " Ingreso un valor incorrecto.",1 , lista->len(lista));
        } while(flag == -1);

        do
        {
            flag = pedirInt(&hasta, " Hasta indice: ", " Ingreso un valor incorrecto.",desde , lista->len(lista));
        } while(flag == -1);

        ArrayList* subList = lista->subList(lista, desde-1, hasta-1);

        if (subList != NULL)
        {
            if(guardarLista(subList, fileName2, sizeOfStruct))
            {
                ret =1;
            }
        }
    }

    return ret;
}

int ordenarLista (ArrayList* lista, char* fileName, int (*pFunc)(void* ,void*), int order )
{
    int ret = 0;

    if (lista->sort(lista, pFunc, order) == 0)
    {
        if (guardarLista(lista, fileName, sizeof(EMovie)))
        {
            ret = 1;
            listarPeliculas(lista);
        }
    }

    return ret;
}

int guardarLista (ArrayList* lista, char* fileName, int sizeOfStruct)
{
    int retorno = 1;

    if (pisarArchivo(lista, fileName, sizeOfStruct)==0)
    {
        retorno = 0;
        printf("\n El archivo no se pudo actualizar correctamente.\n\n");
    }
    else
    {
        printf("\n Archivo actualizado.\n\n");
    }
    return retorno;
}

    // funcion de comparacion
    int comparaElementos(void* elementoA, void* elementoB)
    {
        if(((EMovie*)elementoA)->puntaje > ((EMovie*)elementoB)->puntaje)
        {
            return 1;
        }
        if(((EMovie*)elementoA)->puntaje < ((EMovie*)elementoB)->puntaje)
        {
            return -1;
        }
        return 0;
    }
