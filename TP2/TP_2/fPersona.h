#ifndef FPERSONA_H_INCLUDED
#define FPERSONA_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

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
int buscarPorDni(EPersona lista[], int tam, long int dni);

/**
 * Pide los datos del struct EPersona al usuario.
 * @param tama�o del array nombre.
 * @return devuelve un struct EPersona con los datos ingresados por el usuario.
 */
EPersona ingresarPersona (int strTam);

/**
 * Borrado l�gico en array de EPersona segun dni.
 * @param array de EPersona
 * @param tama�o del array.
 * @param dni de la persona a borrar.
 */
void quitarPersonaDeLista(EPersona lista[], int tam, long int dni);

/**
 * Ordena lista por nombre alfab�tico.
 * @param array de EPersona
 * @param tama�o del array.
 */
void ordenarListaPorNombre(EPersona lista[], int tam);

/**
 * Imprime lista de Epersona.
 * @param array de EPersona
 * @param tama�o del array.
 */
void imprimirLista (EPersona lista[], int tam);

/**
 * Imprime gr�fico de edades.
 * @param array de EPersona
 * @param tama�o del array.
 */
void imprimirGraficoEdades (EPersona lista[], int tam);



#endif // FPERSONA_H_INCLUDED
