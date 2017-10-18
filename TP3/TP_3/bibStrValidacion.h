#ifndef BIBSTRVALIDACION_H_INCLUDED
#define BIBSTRVALIDACION_H_INCLUDED

/**
* \brief Solicita un n�mero entero (positivo o negativo) al usuario y lo valida.
* \param numero. Puntero a la variable donde se cargar� el numero ingresado en caso de ser v�lido.
* \param mje Es el mensaje a ser mostrado
* \param emje Es el mensaje a ser mostrado en caso de error
* \param minimo. M�nimo valor v�lido.
* \param maximo. M�ximo valor v�lido.
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int pedirInt (int* numero, char mje[], char emje[], int minimo, int maximo);

/**
* \brief Solicita un string al usuario y valida que sean s�lo letras y espacios.
* \param cadena. Puntero a la variable donde se cargar� el string ingresado en caso de ser v�lido.
* \param mje Es el mensaje a ser mostrado
* \param emje Es el mensaje a ser mostrado en caso de error
* \param minimo. M�nimo valor v�lido de length.
* \param maximo. M�ximo valor v�lido de length.
* \return Si obtuvo el string [0] si no [-1]
*
*/
int pedirStrLetras (char cadena[], char mje[], char emje[], int minimo, int maximo);

/**
* \brief Solicita un n�mero float (positivo o negativo) al usuario y lo valida.
* \param numero. Puntero a la variable donde se cargar� el numero ingresado en caso de ser v�lido.
* \param mje Es el mensaje a ser mostrado
* \param emje Es el mensaje a ser mostrado en caso de error
* \param minimo. M�nimo valor v�lido.
* \param maximo. M�ximo valor v�lido.
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int pedirFloat (float* numero, char mje[], char emje[], float minimo, float maximo);

#endif // BIBSTRVALIDACION_H_INCLUDED
