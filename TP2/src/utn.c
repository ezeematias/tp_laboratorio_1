/*
 ============================================================================
 Name        : UTN.C
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Bibioteca "utn-c"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "utn.h"

static int isNumber(char* pArray);
static int isString(char* pArray);

/**
 * \brief Lee los datos ingresados por consola y graba en un array.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \return (-1) Error / (0) Ok
 */
int myGets(char* pArray, int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0 && fgets(pArray, len, stdin))
	{
		fflush(stdin);
		if (pArray[strlen(pArray) - 1] == '\n')
		{
			pArray[strlen(pArray) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Se pide por consola un número entero al usuario.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \param int attemps, Los reintentos que se le darán al usuario.
 * \param char* msg, Mensaje que se le muestra al usuario.
 * \param char* msgError, Mensaje de ERROR que se le muestra al usuario..
 * \param int max, Número máximo permitido.
 * \param int min, Número minimo permitido.
 * \return (-1) Error / (0) Ok
 */
int utn_getInt(int *pArray, int len, int attemps, char* msg, char* msgError, int max, int min)
{
	int retorno = -1;
	char bufferString[len];

	if(msg != NULL && msgError != NULL && pArray != NULL && attemps >= 0 && max >= min)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, len) == 0 && isNumber(bufferString) == 1)
			{
				retorno = 0;
				*pArray = atoi(bufferString);
				break;
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un caracter al usuario
 * \param char* pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \param char* msg, Es el mensaje a ser mostrado al usuario.
 * \param char* msgError, Es el mensaje de error a ser mostrado al usuario
 * \param int attemps, cantidad de oportunidades para ingresar el dato.
 * \return (-1) Error / (0) Ok
 */
int utn_getChar (char* pArray, int len, char* msg, char* msgError, int attemps)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attemps >= 0)
	{
		while (attemps >= 0)
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isString(bufferString) == 1)
			{
				strncpy(pArray, bufferString, len);
				retorno = 0;
				break;
			}else
			{
				attemps--;
				if (attemps > 0)
				{
					printf("%s\n> ", msgError);
				}else if(attemps < 0)
				{
					printf("----- NO HAY MÁS REINTENTOS -----");
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Se pide por consola un número flotante al usuario.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \param int attemps, Los reintentos que se le darán al usuario.
 * \param char* msg, Mensaje que se le muestra al usuario.
 * \param char* msgError, Mensaje de ERROR que se le muestra al usuario.
 * \param int max, Número máximo permitido.
 * \param int min, Número minimo permitido.
 * \return (-1) Error / (0) Ok
 */
int utn_getFloat(float *pArray, int len, int attemps, char* msg, char* msgError, int max, int min)
{
	int retorno = -1;
	char bufferString[len];

	if(msg != NULL && msgError != NULL && pArray != NULL && attemps >= 0 && max >= min)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, len) == 0 && isNumber(bufferString) == 1)
			{
				retorno = 0;
				*pArray = atoi(bufferString);
				break;
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}

/**
 * \brief Ordena una array de números enteros
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \return (-1) Error / (0) Ok
 */
int utn_sortArrayInt(int* pArray, int len)
{
	int retorno = -1;
	int index;
	int flagSort = 0;
	int aux;

	if(pArray != NULL && len > 0)
	{
		while(flagSort==0)
		{
		flagSort=1;
			for(index=0 ; index<(len-1)  ; index++)
			{
				if(pArray[index] > pArray[index+1])
				{
					aux = pArray[index];
					pArray[index] = pArray[index+1];
					pArray[index+1] = aux;
					flagSort=0;
				}
			}
		}
		retorno = -0;
	}
	return retorno;
}

/**
 * \brief Imprime un array de números enteros.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \return (-1) Error / (0) Ok
 */
int utn_printArrayInt(int* pArray, int len)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && len > 0)
	{
		for (i = 0;i<len;i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n",i,pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Verifica que el array sea solamente de letras.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (0) FALSE / (1) TRUE
 */
static int isString(char* pArray)
{
	int retorno = 1;
	int i;

	if(pArray != NULL)
	{
		for (i = 0;pArray[i] != '\0';i++)
		{
			if ((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] < 'A' || pArray[i] > 'Z') && pArray[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica que el array sea solamente números.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (0) FALSE / (1) TRUE
 */
static int isNumber(char* pArray)
{
	int retorno = 1;
	int i = 0;

	if(pArray[0] == '-')
	{
		i = 1;
	}

	for( ; pArray[i] != '\0' ; i++)
	{
		if(pArray[i] > '9' || pArray[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

