/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "utn.h"

static int myGets(char* pArray, int len);
static int isNumber(char* pArray);
static int isNumberFloat(char* pArray);
static int isName(char* pArray);
static int isAlphanumeric(char* pArray);
static int isEmail(char* pArray);
static int isCuit(char* pArray);
static int isText(char* pArray);

/**
 * \brief Read the data entered by the console and write to an array..
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
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
 * \brief The console prompts the user for an integer number.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param int attempts, The retries that will be given to the user.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int max, Max number allowed.
 * \param int min, Min number allowed.
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
				printf(NO_MORE_ATTEMPTS);
			}
		}while(attempts >= 0);
	}
	return retorno;
}

/**
 * \brief The user is asked for the name.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int attempts, The retries that will be given to the user.
 * \return (-1) Error / (0) Ok
 */
int utn_getName (char* pArray, int len, char* msg, char* msgError, int attempts)
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
				printf(NO_MORE_ATTEMPTS);
				break;
			}
		}while (attempts >= 0);
	}
	return retorno;
}

/**
 * \brief The user is asked for the address.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int attempts, The retries that will be given to the user.
 * \return (-1) Error / (0) Ok
 */
int utn_getAddress (char* pArray, int len, char* msg, char* msgError, int attempts)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attempts >= 0)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isAlphanumeric(bufferString) == 1)
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
				printf(NO_MORE_ATTEMPTS);
				break;
			}
		}while (attempts >= 0);
	}
	return retorno;
}

/**
 * \brief The user is asked for the address.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int attempts, The retries that will be given to the user.
 * \return (-1) Error / (0) Ok
 */
int utn_getString (char* pArray, int len, char* msg, char* msgError, int attempts)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attempts >= 0)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isText(bufferString) == 1)
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
				printf(NO_MORE_ATTEMPTS);
				break;
			}
		}while (attempts >= 0);
	}
	return retorno;
}

/**
 * \brief The user is asked for the e-mails.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int attempts, The retries that will be given to the user.
 * \return (-1) Error / (0) Ok
 */
int utn_getEmail (char* pArray, int len, char* msg, char* msgError, int attempts)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attempts >= 0)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isEmail(bufferString) == 1)
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
				printf(NO_MORE_ATTEMPTS);
				break;
			}
		}while (attempts >= 0);
	}
	return retorno;
}

/**
 * \brief The user is asked for the CUIT.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int attempts, The retries that will be given to the user.
 * \return (-1) Error / (0) Ok
 */
int utn_getCuit (char* pArray, int len, char* msg, char* msgError, int attempts)
{
	int retorno = -1;
	char bufferString[len];

	if(pArray != NULL && msg != NULL && msgError != NULL && attempts >= 0)
	{
		do
		{
			printf("%s\n> ", msg);
			if(myGets(bufferString, len) == 0 && isCuit(bufferString) == 1)
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
				printf(NO_MORE_ATTEMPTS);
				break;
			}
		}while (attempts >= 0);
	}
	return retorno;
}

/**
 * \brief The user is prompted for a floating number by console.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
 * \param int attempts, The retries that will be given to the user.
 * \param char* msg, Message displayed to the user.
 * \param char* msgError, Message ERROR displayed to the user.
 * \param int max, Max number allowed.
 * \param int min, Min number allowed.
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
			if(myGets(bufferString, len) == 0 && isNumberFloat(bufferString) == 1)
			{
				bufferFloat = atof(bufferString);
				if(bufferFloat >= min && bufferFloat <= max)
				{
					*pArray = bufferFloat;
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
				printf(NO_MORE_ATTEMPTS);
			}

		}while(attempts >= 0);
	}
	return retorno;
}

/**
 * \brief Sort an array of integers.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
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
 * \brief Print an array of integers.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \param int len, The length of the array.
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
 * \brief Verify that the array is only letters.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
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
 * \brief Verify that the array is only numbers..
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
static int isNumberFloat(char* pArray)
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

/**
 * \brief Verify that the array is only numbers..
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
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

/**
 * \brief Verify that the array is only letters and numbers.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
static int isAlphanumeric(char* pArray)
{
	int retorno = 1;
	int i;

	if(pArray != NULL)
	{
		for (i = 0;pArray[i] != '\0';i++)
		{
			if ((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] < 'A' || pArray[i] > 'Z') && (pArray[i] != ' ') && (pArray[i] > '9' || pArray[i] < '0'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verify that the array is only letters and numbers.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
static int isText(char* pArray)
{
	int retorno = 1;
	int i;

	if(pArray != NULL)
	{
		for (i = 0;pArray[i] != '\0';i++)
		{
			if ((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] < 'A' || pArray[i] > 'Z') && (pArray[i] != ' ') && (pArray[i] != '.') && (pArray[i] != ',') && (pArray[i] != '!') && (pArray[i] != '?') && (pArray[i] != '¡') && (pArray[i] != '¿') && (pArray[i] != '/') && (pArray[i] != '*') && (pArray[i] != '+') && (pArray[i] != '-') && (pArray[i] != '#') && (pArray[i] != '@') && (pArray[i] != '=') && (pArray[i] != '(') && (pArray[i] != ')') && (pArray[i] != '%') && (pArray[i] != '$') && (pArray[i] > '9' || pArray[i] < '0'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verify that the array is only letters, numbers and symbols.
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
static int isEmail(char* pArray)
{
	int retorno = 1;
	int i;

	if(pArray != NULL)
	{
		for (i = 0;pArray[i] != '\0';i++)
		{
			if ((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] != '-') && (pArray[i] > '9' || pArray[i] < '0') && (pArray[i] != '_') && (pArray[i] != '@'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verify that the array is only numbers por CUIT..
 * \param int *pArray, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
static int isCuit(char* pArray)
{
	int retorno;
	int i = 0;
	int counterDash = 0;
	if(pArray[2] == '-' && pArray[11] == '-' && pArray[12] != '\0')
	{
		retorno = 1;
		for( ; pArray[i] != '\0' ; i++)
		{
			if(pArray[i] == '-')
			{
				counterDash++;
			}
			if((counterDash > 2) || ((pArray[i] > '9' || pArray[i] < '0') && pArray[i] != '-'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
