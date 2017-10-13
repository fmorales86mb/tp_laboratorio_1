#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "bibStrValidacion.h"
#include "validacionStr.h"
#include "input.h"

int agregarPelicula(EMovie movie)
{
    int retorno = 0;
    EMovie movie;

    movie = pedirMovie();

    if (movie.id != -1)
    {

    }

    return retorno;
}



int borrarPelicula(EMovie movie)
{
    return 0;
}

void generarPagina(EMovie lista[], char nombre[], int sizeMo)
{
    int i;
    char strPuntaje[STR];
    char strDuracion[STR];
    FILE *archivo;
    char htmlInicio[STRLONG] = {"<!DOCTYPE html><html lang='en'><head> <meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>"};
    char htmlFin[STRLONG] = {"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>"};
    char htmlArticle[STRLONG];

    archivo = fopen(nombre, "w");
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

    fclose(archivo);
}

void generarHtmlArticle(char* htmlArticle, char urlImagen[], char titulo[], char genero[], char puntaje[], char duracion[], char sinopsis[])
{
    char htmlArticleBase[STRLONG] = {"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %s</li><li>Duracion: %s</li></ul><p>%s</p></article>"};
    char htmlArticleCompleto[STRLONG];

    sprintf(htmlArticleCompleto, htmlArticleBase, urlImagen, titulo, genero, puntaje, duracion, sinopsis);

    strcpy(htmlArticle, htmlArticleCompleto);
}

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
            flag = pedirInt(&movie.duracion, " Duracion: ", " Duracion invalida.", 1, STR);
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
            flag = pedirInt(&movie.puntaje, " Puntaje: ", " Puntaje invalido.", 1, STR);
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

    if (chances<3)
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
