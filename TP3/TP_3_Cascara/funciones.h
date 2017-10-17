#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 10
#define STR 50
#define STRLONG 500

typedef struct{
    int id;
    char titulo[STR];
    char genero[STR];
    int duracion;
    char descripcion[STRLONG];
    int puntaje;
    char linkImagen[STRLONG];
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie lista[], int sizeMo);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 *  @param sizeMo el tamaño de la lista.
 */
int generarPagina(EMovie lista[], char nombre[], int sizeMo);

void generarHtmlArticle(char* htmlArticle, char urlImagen[], char titulo[], char genero[], char puntaje[], char duracion[], char sinopsis[]);

void harcodearListaMovie(EMovie lista[]);

void inicializarMovies (EMovie lista [], int sizeMo);

EMovie pedirMovie ();

int buscarIndiceLibre (EMovie lista[], int size);

int buscarIdLibre (EMovie lista[], int size);

int levantarLista(EMovie lista[], int sizeMo, char nombre[]);

int guardarLista(EMovie lista[], int sizeMo, char nombre[]);

#endif // FUNCIONES_H_INCLUDED
