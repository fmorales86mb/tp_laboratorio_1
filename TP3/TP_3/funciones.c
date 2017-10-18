#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"

int agregarPelicula(EMovie lista[], int sizeMo, char fileName[])
{
    int retorno = 1;
    EMovie movie;

    int indice = buscarIndiceLibre(lista, sizeMo);
    if (indice!=-1)
    {
        movie = pedirMovie();

        if (movie.id != -1)
        {
            movie.id = buscarIdLibre(lista, sizeMo);
            lista[indice] = movie;
            if (guardarLista(lista, MO, fileName)==0)
            {
                retorno = 0;
                printf("\n La pelicula no se pudo guardar correctamente.\n");
            }
            else
            {
                printf("\n Pelicula guardada.\n");
            }
        }
    }
    else
    {
        retorno = 0;
        printf("\n No hay espacio en la lista de peliculas.\n\n");
    }

    return retorno;
}

int borrarPelicula(EMovie lista[], int sizeMo, char fileName[])
{
    int i;
    int id;
    int flag;
    int chances = 0;
    int retorno = -1;

    listarPeliculas(lista, sizeMo);

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
}

int modificarPelicula (EMovie lista[], int sizeMo, char fileName[])
{
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

    return 0;
}

int generarPagina(EMovie lista[], char nombre[], int sizeMo)
{
    int retorno;
    int i;
    char strPuntaje[STR];
    char strDuracion[STR];
    FILE *archivo;
    char htmlInicio[STRLONG] = {"<!DOCTYPE html><html lang='en'><head> <meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>"};
    char htmlFin[STRLONG] = {"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>"};
    char htmlArticle[STRLONG];

    archivo = fopen(nombre, "w");
    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;
    }
    else
    {
        fprintf(archivo, htmlInicio);

        for(i=0; i<sizeMo; i++)
        {
            if (lista[i].id != -1)
            {
                itoa(lista[i].puntaje, strPuntaje,10);
                itoa(lista[i].duracion, strDuracion,10);
                generarHtmlArticle(htmlArticle, lista[i].linkImagen, lista[i].titulo, lista[i].genero, strPuntaje, strDuracion, lista[i].descripcion);
                fprintf(archivo, htmlArticle);
            }
        }

        fprintf(archivo, htmlFin);
        retorno = 1;
    }

    fclose(archivo);

    return retorno;
}

void generarHtmlArticle(char* htmlArticle, char urlImagen[], char titulo[], char genero[], char puntaje[], char duracion[], char sinopsis[])
{
    char htmlArticleBase[STRLONG] = {"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %s</li><li>Duracion: %s</li></ul><p>%s</p></article>"};
    char htmlArticleCompleto[STRLONG];

    sprintf(htmlArticleCompleto, htmlArticleBase, urlImagen, titulo, genero, puntaje, duracion, sinopsis);

    strcpy(htmlArticle, htmlArticleCompleto);
}

void inicializarMovies (EMovie lista [], int sizeMo)
{
    int i;
    for(i=0; i<sizeMo; i++)
    {
        lista[i].id = -1;
        strcpy(lista[i].titulo, "");
        strcpy(lista[i].genero, "");
        lista[i].duracion = 0;
        strcpy(lista[i].descripcion, "");
        lista[i].puntaje = 0;
        strcpy(lista[i].linkImagen, "");
    }
}

EMovie pedirMovie ()
{
    int flag;
    EMovie movie;
    int chances = 0;

    movie.id=0;
    printf("\n Ingrese datos de la pelicula: \n\n");
    do
    {
        flag = getString(movie.titulo, " Titulo: ", " Titulo invalido.", 1, STR);
        chances++;
    }while (flag == -1 && chances<3);

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie.genero, " Genero: ", " Genero invalido.", 1, STR);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = pedirInt(&movie.duracion, " Duracion (minutos): ", " Duracion invalida.", 1, 800);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie.descripcion, " Descripcion: ", " Descripcion invalida.", 1, STRLONG);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = pedirInt(&movie.puntaje, " Puntaje (1 a 10): ", " Puntaje invalido.", 1, 10);
        }while (flag == -1 && chances<3);
    }

    if(chances <3)
    {
        chances = 0;
        do
        {
            flag = getString(movie.linkImagen, " Link a la imagen: ", " Link a la imagen invalido.", 1, STRLONG);
        }while (flag == -1 && chances<3);
    }

    if (chances==3)
    {
        movie.id=-1;
    }

    return movie;
}

int buscarIndiceLibre (EMovie lista[], int size)
{
    int i;
    int indice = -1;

    for (i=0; i<size; i++)
    {
        if(lista[i].id==-1)
        {
            indice=i;
            break;
        }
    }

    return indice;
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

int levantarLista(EMovie lista[], int sizeMo, char nombre[])
{
    int retorno;
    int i;
    int cant;
    FILE * archivo;

    archivo = fopen(nombre, "rb");
    if (archivo == NULL)
    {
        printf("\n El archivo no puede ser abierto.\n");
        retorno = 0;
    }
    else
    {

        for (i=0; !feof(archivo) && i<sizeMo; i++)
        {
            cant = fread(&lista[i], sizeof(EMovie), 1, archivo);
            if(cant!=1)
            {
                if(feof(archivo))
                {
                    break; // llegó al final del archivo.
                }
                else
                {
                    printf("\n No se leyo correctamente un registro.\n");
                    retorno=0;
                    break; // error en la lectura.
                }
            }

            retorno=1; // Lecturas correctas.
        }
    }

    fclose(archivo);

    return retorno;
}

int guardarLista(EMovie lista[], int sizeMo, char nombre[])
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
        for(i=0; i<sizeMo; i++)
        {
            cant = fwrite(&lista[i], sizeof(EMovie), 1, archivo);
            if (cant != 1)
            {
                printf("\n No se leyo correctamente un registro.\n");
                retorno = 0;
                break;
            }
        }
    }

    fclose(archivo);

    return retorno;
}

void listarPeliculas(EMovie lista[], int sizeMo)
{
    int i;

    printf("\n ID \t Titulo \t Genero \t Duracion \t Puntaje \t \n\n");

    for(i=0; i<sizeMo; i++)
    {
        if(lista[i].id>0)
        {
            printf(" %d \t %s \t %s \t %d \t %d \n", lista[i].id ,
                   lista[i].titulo , lista[i].genero , lista[i].duracion , lista[i].puntaje);
        }
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
