/*
 ============================================================================
 Name        : segundo_parcial.c
 Author      : Ezequiel Unía
 Version     :
 Copyright   : Copyright
 Description : Segundo parcial Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;
	this = (LinkedList*) malloc (sizeof(LinkedList));
	if(this!=NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	  int returnAux = -1;
	  if(this != NULL)
	  {
	  	returnAux = this->size;
	  }
	  return returnAux;;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodeReturn = NULL;
	int len = ll_len(this);
    if(this != NULL && nodeIndex > -1 && len > nodeIndex)
    {
		nodeReturn = this->pFirstNode;
    	for(int i=0;i<nodeIndex;i++)
    	{
			nodeReturn = nodeReturn->pNextNode;
    	}
    }
	return nodeReturn;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* lastNode;
	int returnAux = -1;
    if(this!=NULL && nodeIndex > -1 && newNode != NULL)
    {
    	newNode->pElement = pElement;
    	if(nodeIndex ==0)
    	{
    		newNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = newNode;
    	}else
    	{
			lastNode = getNode(this, nodeIndex-1);
    		newNode->pNextNode = lastNode->pNextNode;
    		lastNode->pNextNode = newNode;
    	}
    	this->size++;
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    if(this != NULL && len > -1)
    {
		addNode(this, len, pElement);
		returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodeReturn = NULL;
	int len = ll_len(this);
    if(this != NULL && index > -1 && index < len)
    {
		nodeReturn = getNode(this, index);
		if(nodeReturn != NULL)
		{
			returnAux = nodeReturn->pElement;
		}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodeReturn = NULL;
	int len = ll_len(this);
    if(this != NULL && index > -1 && index < len)
    {
		nodeReturn = getNode(this, index);
		if(nodeReturn != NULL)
		{
			nodeReturn->pElement = pElement;
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeReturn = NULL;
    Node* lastNode = NULL;
	int len = ll_len(this);
    if(this != NULL && index > -1 && index < len)
    {
		nodeReturn = getNode(this, index);
    	if(nodeReturn != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = nodeReturn->pNextNode;
			}else
			{
				lastNode = getNode(this, index-1);
				lastNode->pNextNode = nodeReturn->pNextNode;
			}
			free(nodeReturn);
			returnAux = 0;
			this->size--;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
	int len = ll_len(this);
    if(this != NULL && len > -1)
    {
		for(int i=0; i<len; i++)
		{
			ll_remove(this, i);
		}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* nodeReturn = NULL;
	int len = ll_len(this);
    if(this != NULL && len > 0)
    {
    	for(int i=0; i < len; i++)
    	{
			nodeReturn = ll_get(this, i);
			if(nodeReturn == pElement)
			{
				returnAux = i;
				break;
			}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(this->pFirstNode == NULL && this->size == 0)
    	{
			returnAux = 1;
    	}else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    if(this != NULL && index <= len && index > -1)
    {
		if(!addNode(this, index, pElement))
		{
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* nodeReturn = NULL;
	int len = ll_len(this);
    if(this != NULL && index > -1 && index < len)
    {
    	nodeReturn = ll_get(this, index);
		if(nodeReturn != NULL)
		{
			returnAux = nodeReturn;
			ll_remove(this, index);
		}
    }
	return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indexElement = -1;
    if(this != NULL)
    {
    	indexElement = ll_indexOf(this, pElement);
    	if(indexElement >=0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* nodeReturn=NULL;
    int len = ll_len(this2);
    if(this!=NULL && this2!=NULL)
    {
    	returnAux=1;
    	for(int i=0;i < len;i++)
    	{
    		nodeReturn = ll_get(this2, i);
			if(!ll_contains(this, nodeReturn))
			{
				returnAux=0;
				break;
			}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* bufferElement = NULL;
    int len = ll_len(this);
    if(this != NULL && from > -1 && to > -1 && from <= to && to <= len)
    {
		cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
			for(int i = from; i < to; i++)
			{
				bufferElement = ll_get(this, i);
				if(bufferElement != NULL)
				{
					ll_add(cloneArray, bufferElement);
				}
			}
    	}
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    if(this != NULL)
    {
    	cloneArray =ll_subList(this, 0, len);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flagSort = 0;
    void* auxA = NULL;
    void* auxB = NULL;
    int len = ll_len(this);
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
		while(flagSort == 0)
		{
			flagSort = 1;
			for(int i = 0; i < len-1; i++)
			{
				auxA = ll_get(this,i);
				auxB = ll_get(this,i+1);
				if((auxA != NULL && auxB != NULL) && ((pFunc(auxA,auxB) > 0 && order == 1) || (pFunc(auxA,auxB) < 0 && order == 0)))
				{
					ll_set(this, i, auxB);
					ll_set(this, i+1, auxA);
					flagSort = 0;
				}
			}
		}
		returnAux = 0;
    }
    return returnAux;
}

/** \brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*,void*),void* pElement)
{
    int returnAux = -1;
    int length = ll_len(this);
    void* auxElement;
    if(this != NULL)
    {
        for(int i = 0 ; i < length ; i++)
        {
            auxElement = ll_get(this, i);
            if(pFunc(auxElement, pElement) == 0)
            {
            	returnAux = 0;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*,void*),void* pElement)
{
	int len = ll_len(this);
	void* aux = NULL;
	LinkedList* newList = ll_newLinkedList();

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0;i < len;i++)
		{
			aux = ll_get(this, i);
			if(pFunc(aux,pElement)==0) // Puede ser == 0 / == 1 dependiendo de la función criterio
			{
				ll_add(newList, aux);
			}
		}
	}
	return newList;
}

// Reduce - Reduce / Reduce una lista a un número Tienen que ser dos, una INT otra FLOAT

int ll_reduceInt (LinkedList* this, int (*pFunc)(void*,void*),void* pElement) // llaman a una función que devuelven un valor y lo acumulamos ( LA SUMA DE ALGO // ACUMULADOR)
{
	int accReturn = 0;
	void* aux = NULL;
	int len = ll_len(this);
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0 ; i < len ; i++)
		{
			aux = ll_get(this, i);
			accReturn += pFunc(aux,pElement);
		}
	}
	return accReturn;
}

float ll_reduceFloat (LinkedList* this, float (*pFunc)(void*)) // llaman a una función que devuelven un valor y lo acumulamos ( LA SUMA DE ALGO // ACUMULADOR)
{
	float accReturn = 0;
	void* aux = NULL;
	int len = ll_len(this);
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0 ; i < len ; i++)
		{
			aux = ll_get(this, i);
			accReturn += pFunc(aux);
		}
	}
	return accReturn;
}

/** \brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_mapOld(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux = -1;
    int length = ll_len(this);
    void* auxElement;
    if(this != NULL)
    {
        for(int i = 0 ; i < length ; i++)
        {
            auxElement = ll_get(this, i);
            if(!pFunc(auxElement))
            {
            	printf("PIOLA");
            }else
            {
            	printf("NAAAH PIOLA");
            }
        }
    }
    return returnAux;
}

// Filter  - Filtrar / Eliminar elementos de un arrayList en función
int ll_filterOld(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux = -1;
	int len = ll_len(this);
	void* aux = NULL;
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0;i < len;i++)
		{
			aux = ll_get(this, i);
			if(!pFunc(aux)) // Puede ser == 0 / == 1 dependiendo de la función criterio
			{
				ll_remove(this, i);
				i--;
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int ll_reduceIntOld (LinkedList* this, int (*pFunc)(void*)) // llaman a una función que devuelven un valor y lo acumulamos ( LA SUMA DE ALGO // ACUMULADOR)
{
	int accReturn = 0;
	void* aux = NULL;
	int len = ll_len(this);
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0 ; i < len ; i++)
		{
			aux = ll_get(this, i);
			accReturn += pFunc(aux);
		}
	}
	return accReturn;
}
