#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int resizeDown(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements =(void**) malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add; // Agrega un elemento al final de la lista - ok
            this->len=al_len; // Cantidad de elementos - ok
            this->set=al_set; // Pone un elemento dado en un determinado índice - ok
            this->remove=al_remove; // Remueve un determinado elemento (usar el contract) - ok
            this->clear=al_clear; // Remueve todos los elementos de la lista - ok
            this->clone=al_clone; // Copia la lista en otro arrayList - ok
            this->get=al_get; // Devuelve el elemento de un determinado indice - ok
            this->contains=al_contains; // chequea que exista o no un determinado elemento
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty; // T, F si la lista està vacìa. - ok
            this->pop=al_pop;
            this->subList=al_subList; // sub lista desde indice hasta indice - ok
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList; //Borra el arrayList (ver)
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement) {
    int returnAux = -1;

    if (this != NULL && pElement != NULL) {
        returnAux = 0;

        // Si el tamano no alcanza lo tratamos de redimensionar
        if(this->size >= this->reservedSize){
            returnAux = resizeUp(this);
        }

        // Si pudimos redimencionarlo o no hizo falta, agretamos el elemento
        if(returnAux == 0){
            //this->pElements[this->size] = pElement;
            *(this->pElements+this->size) = pElement;
            this->size++;
        }
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = 0;
        free(this);
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this) {
    int returnAux = -1;

    if (this != NULL) {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if (this!= NULL && index>=0 && index<this->size)
    {
        returnAux = *(this->pElements+index);
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if (this != NULL && pElement != NULL)
    {
        returnAux = 0;

        for (i=0; i<this->size; i++)
        {
            if(pElement == *(this->pElements+i))
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if (this !=NULL && pElement != NULL && index>=0 && index<this->size)
    {
        returnAux = 0;
        *(this->pElements+index) = pElement;
    }

    return returnAux;

    return 0;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    //printf("\nEN REMOVE\n");
    //printf("ARRAY: %p + INDEX %d\n", this, index);
    if(this!=NULL && index>=0 && index<this->size)
    {
        for (i=index; i<(this->size)-1;i++)
        {
            *(this->pElements+i) = *(this->pElements+(i+1));
        }

        resizeDown(this);

        this->size--;
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    int i = 0;

    if(this != NULL)
    {
        returnAux = 0;
        while (i<this->size)
        {
            // no hago verificaciones porque ya las realicè
            this->remove(this, i);
        }
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this!=NULL)
    {
        returnAux = al_newArrayList();
        if (returnAux!=NULL)
        {
            for(i=0; i<this->size; i++)
            {
                //no chequeo lo que devuelve porque ya hice las verificaciones que repite la función.
                returnAux->add(returnAux, *(this->pElements+i));
            }
        }
    }

    return returnAux;
}


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!= NULL && index>=0 && index<=this->size)
    {
        returnAux = 0;

        if (index == this->size)
        {
            returnAux = this->add(this, pElement);
        }

        else if (expand(this, index) == 0)
        {
            // agrego el elemento en el indice
            this->set(this, index, pElement);
        }
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement!=NULL)
    {
        for(i=0; i<this->size; i++)
        {
            if (*(this->pElements+i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        // si está vacio
        if (this->size == 0)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    int i;
    printf("EN POP\n");
    printf("ARRAY: %p + INDEX %d", this, index);
    if(this!=NULL && index>=0 && index<this->size)
    {
        returnAux = *(this->pElements+index);
        //printEmployee(returnAux);
        //printf(" I: %d\n",index);
        i=this->remove(this, index);
        printf("%d", i);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;
    int i;

    if (this!=NULL &&
        from >=0 && from <this->size &&
        to >=0 && to <=this->size &&
        from<to)
    {
        returnAux = al_newArrayList();
        if (returnAux!=NULL)
        {
            for(i=from; i<to; i++) //INCLUSIVE FROM
            {
                //no chequeo lo que devuelve porque ya hice las verificaciones que repite la función.
                returnAux->add(returnAux, *(this->pElements+i));
            }
        }
    }

    return returnAux ;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i;
    int j;
    int flag = 0;

    // chequeo que todos los elementos de this2 estén contenidos en this
    if(this!=NULL && this2!=NULL)
    {
        returnAux = 1;

        // busco un elemento que no compartan las listas
        for(i=0; i<this2->size; i++)
        {
            for(j=0; j<this->size; j++)
            {
                flag = 1;
                if (*(this2->pElements+i) == *(this->pElements+j))
                {
                    flag = 0;
                    break;
                }
            }

            //Caso de elemento en this2 que no está en this
            if (flag == 1)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * pFunc return [1] if a>b, [-1] if a<b, [0] if a=b
 * \param order int  [1] indicate UP(ascendente) - [0] indicate DOWN (descendente)
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
    int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* aux;
    int i;
    int j;
    int comp;

    if (this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        returnAux = 0;
/*
        for(i=0; i<this->size-2; i++)
        {
            for(j=i+1; j<this->size-1; j++)
            {
*/
         for(i=0; i < this->size-1; i++) {
            for(j=i+1; j < this->size ; j++) {
                // i < j
                comp = pFunc(*(this->pElements+i), *(this->pElements+j));

                // orden desendente
                if (order == 1) {
                    // si el salario de i > el salario de j ->  es decendente, no hacemos nada.
                    // sino lo damos vuelta
                    if (comp > 0) {
                        aux = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = aux;
                    }

                // orden ascendente
                } else {
                    // si el salario de i > el salario de j ->  lo damos vuelta
                    // sino no hacemos nada
                    if (comp< 0) {
                        aux = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = aux;
                    }
                }
/*
                if ((comp == 1 && order == 1) || (comp == -1 && order == 0))
                {
                    aux = this->pElements[i];
                    this->pElements[i] = this->pElements[j];
                    this->pElements[j] = aux;
                }
*/
            }
        }
    }

    return returnAux;
        }


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** punteroAux;

    if(this!=NULL)
    {
        // Estamos pidiendo mas memoria
        punteroAux = (void**) realloc (this->pElements, sizeof (void*) * (this->reservedSize + AL_INCREMENT));

        // si obtuvimos mas memoria entonces actualizamos todo
        if(punteroAux != NULL){
            this->pElements = punteroAux;   // Actualizamos el puntero al nuevo bloque de memoria que obtuvimos
            this->reservedSize += AL_INCREMENT; // Guardamos el nuevo tama;o
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Decrement the number of elements in pList to size+AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    int i;

    if (this!=NULL)
    {
        returnAux = 0;
        for (i = this->size; this->reservedSize - this->size > AL_INCREMENT; i--)
        {
            free(this->pElements[i]);
        }
    }

    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if (this != NULL && index >=0 && index < this->size)
    {
        returnAux = 0;

        if(this->size == this->reservedSize)
        {
            returnAux = resizeUp(this);
        }

        for(i = (this->size-1); i>=index ;i--)
        {
            *(this->pElements+(i+1)) = *(this->pElements+i);
        }

        this->size++;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}
