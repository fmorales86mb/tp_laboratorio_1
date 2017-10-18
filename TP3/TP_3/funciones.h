#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MO 50
#define STR 50
#define STRLONG 1000

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
 *  Agrega una pelicula al archivo binario y a la lista
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param fileName, nombre del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie lista[], int sizeMo, char fileName[]);

/**
 *  Borra una pelicula del archivo binario y de la lista
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param fileName, nombre del archivo binario
 *  @return retorna 1 si pudo eliminar la pelicula. -1 o 0 si no pudo
 */
int borrarPelicula(EMovie lista[], int sizeMo, char fileName[]);

/**
 *  Modifica una pelicula del archivo binario y de la lista
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param fileName, nombre del archivo binario
 *  @return retorna 2 si pudo eliminar la pelicula. 1 o 0 si no pudo
 */
int modificarPelicula (EMovie lista[], int sizeMo, char fileName[]);

/**
 *  Genera el archivo HTML con la lista de las peliculas
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param nombre, nombre del archivo html
 *  @return retorna 1 si pudo generar la pagina o 0 si no pudo
 */
int generarPagina(EMovie lista[], char nombre[], int sizeMo);

/**
 *  Genera el código HTML con los datos de una pelicula
 *  @param htmlArticle, dirección de memoria de la cadena donde se guarda el codigo generado
 *  @param urlImage, url de la imagen de la pelicula
 *  @param titulo, título de la pelicula
 *  @param genero, género de la pelicula
 *  @param puntaje, puntaje de la pelicula
 *  @param duracion, duración de la pelicula
 *  @param sinopsis, descripción de la pelicula
 */
void generarHtmlArticle(char* htmlArticle, char urlImagen[], char titulo[], char genero[], char puntaje[], char duracion[], char sinopsis[]);

/**
 *  Inicializa los elementos del array de EMovie
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 */
void inicializarMovies (EMovie lista [], int sizeMo);

/**
 *  Genera un elemento EMovie con los datos ingresados por el usuario.
 *  @return retorna EMovie con id = 0 si pudo generar la pelicula o con id = -1 si no pudo.
 */
EMovie pedirMovie ();

/**
 *  Busca un indice libre en el array de peliculas.
 *  @param lista, array de EMovie
 *  @param size, tamaño del array
 *  @return retorna el indice encontrado o -1 si no pudo
 */
int buscarIndiceLibre (EMovie lista[], int size);

/**
 *  Busca un id libre en el array de peliculas.
 *  @param lista, array de EMovie
 *  @param size, tamaño del array
 *  @return retorna el id encontrado o -1 si no pudo
 */
int buscarIdLibre (EMovie lista[], int size);

/**
 *  Carga el array de peliculas con los datos del archivo binario
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param nombre, nombre del archivo binario.
 *  @return retorna 1 si carga correctamente la lista, o 0 si no pudo
 */
int levantarLista(EMovie lista[], int sizeMo, char nombre[]);

/**
 *  Guarda en el archivo binario la lista de Emovie
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 *  @param nombre, nombre del archivo binario.
 *  @return retorna 1 si guardó correctamente la lista, o 0 si no pudo
 */
int guardarLista(EMovie lista[], int sizeMo, char nombre[]);


/**
 *  Muestra por consola el listado de peliculas.
 *  @param lista, array de EMovie
 *  @param sizeMo, tamaño del array
 */
void listarPeliculas(EMovie lista[], int sizeMo);

//void harcodearListaMovie(EMovie lista[]);

#endif // FUNCIONES_H_INCLUDED
