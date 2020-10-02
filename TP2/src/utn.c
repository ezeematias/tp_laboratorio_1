/*
 ============================================================================
 Name        : TP2.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo préctico 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "utn.h"

static int myGets(char* pArray, int len);
static int isNumber(char* pArray);
static int isName(char* pArray);

/**
 * \brief Lee los datos ingresados por consola y graba en un array.
 * \param int *pArray, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param int len, La longitud del array.
 * \return (-1) Error / (0) Ok
 */
static int myGets(char* pArray, int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0 && fgets(pArray, len, stdin))
	{
		fflush(stdin);
		if (pArray[strlen(pArray) - 1] == '\n' && pArray[0] != '\n')
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
int utn_getInt(int *pArray, int len, int attempts, char* msg, char* msgError, int max, int min)
{
	int retorno = -1;
	char bufferString[len];
	int bufferInt;
	if(msg != NULL && msgError != NULL && pArray != NULL && attempts >= 0 && max >= min)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isNumber(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt <= max)
				{
					*pArray = bufferInt;
					retorno = 0;
					break;
				}
			}
			if (attempts > 0)
			{
				attempts--;
				printf("%s\n", msgError);
			}else
			{
				attempts--;
				printf("----- [NO HAY MÁS REINTENTOS] -----\n");
			}
		}while(attempts >= 0);
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
int utn_getChar (char* pArray, int len, char* msg, char* msgError, int attempts)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attempts >= 0)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isName(bufferString) == 1)
			{
				strncpy(pArray, bufferString, len);
				retorno = 0;
				break;
			}else if (attempts > 0)
			{
				attempts--;
				printf("%s\n", msgError);
			}else
			{
				printf("----- [NO HAY MÁS REINTENTOS] -----\n");
				break;
			}
		}while (attempts >= 0);
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
int utn_getFloat(float *pArray, int len, int attempts, char* msg, char* msgError, int max, int min)
{
	int retorno = -1;
	char bufferString[len];
	float bufferFloat;

	if(msg != NULL && msgError != NULL && pArray != NULL && attempts >= 0 && max >= min)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isNumber(bufferString) == 1)
			{
				bufferFloat = atof(bufferString);
				if(bufferFloat >= min && bufferFloat <= max)
				{
					*pArray = bufferFloat;
					retorno = 0;
				}else
				{
					if (attempts > 0)
					{
						printf("%s\n", msgError);
					}else if(attempts < 0)
					{
						printf("----- [NO HAY MÁS REINTENTOS] -----\n");
					}
				}
				break;
			}else if (attempts > 0)
			{
				attempts--;
				printf("%s\n", msgError);
			}else
			{
				printf("----- [NO HAY MÁS REINTENTOS] -----\n");
				break;
			}
		}while(attempts >= 0);
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
		retorno = 0;
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
			printf("[DEBUG] Indice: %d\nValor: %d\n",i,pArray[i]);
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
static int isName(char* pArray)
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
	int counterDot = 0;
	if(pArray[0] == '-')
	{
		i = 1;
	}
	for( ; pArray[i] != '\0' ; i++)
	{
		if(pArray[i] == '.')
		{
			counterDot++;
		}
		if((counterDot > 1) || ((pArray[i] > '9' || pArray[i] < '0') && pArray[i] != '.'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
