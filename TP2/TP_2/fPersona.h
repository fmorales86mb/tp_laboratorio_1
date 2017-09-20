#ifndef FPERSONA_H_INCLUDED
#define FPERSONA_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int tam, int dni);

/**
 * Pide los datos del struct EPersona al usuario.
 * @param tamaño del array nombre.
 * @return devuelve un struct EPersona con los datos ingresados por el usuario.
 */
EPersona ingresarPersona (int tam);



#endif // FPERSONA_H_INCLUDED
