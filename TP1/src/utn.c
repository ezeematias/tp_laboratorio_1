/*
 * utn.c
 *
 *  Created on: 5 sept. 2020
 *      Author: Unía, Ezequiel Matías
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
 * \brief Solicita un entero al usuario
 * \param int* pNumeroIngresado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param char* mensaje, Es el mensaje para ser mostrado al usuario.
 * \param char* mensajeError, Es el mensaje de error a ser mostrado al usuario.
 * \param int minimo, valor minimo admitido
 * \param int maximo, valor maximo admitido
 * \param int reintentos, Cantidad de oportunidades para ingresar el dato
 * \return (-1) Error / (0) Ok
 */
int utn_getNumber (int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno =-1;
	int numeroIngresado;
	int resultadoScanf;

	if(pNumeroIngresado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0 &&  maximo >= minimo)
	{

		while(reintentos > 0)
		{
			printf("%s\n> ", mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d", &numeroIngresado);

			if (resultadoScanf == 1 && numeroIngresado >= minimo && numeroIngresado <= maximo)
			{
				*pNumeroIngresado = numeroIngresado;
				retorno = 0;
				break;
			}else
			{
				reintentos--;
				if (reintentos > 0)
				{
					printf("%s\n", mensajeError);
				}
			}
		}
		if(reintentos == 0)
		{
			printf("----- NO HAY MÁS REINTENTOS -----");
		}
	}

	return retorno;
}

/**
 * \brief Solicita un flotante al usuario
 * \param float* pNumeroFloatIngresado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param char* mensaje, Es el mensaje para ser mostrado al usuario
 * \param char* mensajeError, Es el mensaje de error a ser mostrado al usuario.
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) Error / (0) Ok
 */
int utn_getNumbreFloat (float* pNumeroFloatIngresado,  char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float numeroFloatIngresado;
	int resultadoScanf;

	if(pNumeroFloatIngresado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0 &&  maximo >= minimo)
	{
		while (reintentos > 0)
		{
			printf("%s\n> ", mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%f", &numeroFloatIngresado);

			if (resultadoScanf == 1 && numeroFloatIngresado >= minimo && numeroFloatIngresado <= maximo)
			{
				*pNumeroFloatIngresado = numeroFloatIngresado;
				retorno = 0;
				break;
			}else
			{
				reintentos--;
				if (reintentos > 0)
				{
					printf("%s\n ", mensajeError);
				}
			}
		}
		if(reintentos == 0)
		{
			printf("----- NO HAY MÁS REINTENTOS -----");
		}
	}
	return retorno;
}

/**
 * \brief Solicita un caracter al usuario
 * \param char* pLetraIngresada, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario.
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato.
 * \return (-1) Error / (0) Ok
 */
int utn_getChar (char* pLetraIngresada, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char letraIngresada;
	int resultadoScanf = 0;

	if(pLetraIngresada != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		while (reintentos >= 0)
		{
			printf("%s\n> ", mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%c", &letraIngresada);
			if (resultadoScanf == 1)
			{
				*pLetraIngresada = letraIngresada;
				retorno = 0;
				break;
			}else
			{
				reintentos--;
				if (reintentos > 0)
				{
					printf("%s\n> ", mensajeError);
				}else if(reintentos <= 0)
				{
					printf("----- NO HAY MÁS REINTENTOS -----");
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Realiza la suma entre dos operadores ingresados.
 * \param float* pResultadoSuma, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param float operador1, Valor del primer operador.
 * \param float operador2, Valor del segundo operador.
 * \return (-1) Error / (0) Ok
 */
int utn_suma (float* pResultadoSuma, float operador1, float operador2)
{
	int retorno = -1;

	if (pResultadoSuma != NULL)
	{
		*pResultadoSuma = operador1 + operador2;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Realiza la resta entre dos operadores ingresados.
 * \param float* pResultadoResta, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param float operador1, Valor del primer operador.
 * \param float operador2, Valor del segundo operador.
 * \return (-1) Error / (0) Ok
 */
int utn_resta (float* pResultadoResta, float operador1, float operador2)
{
	int retorno = -1;

	if (pResultadoResta != NULL)
	{
		*pResultadoResta = operador1 - operador2;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Realiza la multiplicación entre dos operadores ingresados.
 * \param float* pResultadoMultiplicacion, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param float operador1, Valor del primer operador.
 * \param float operador2, Valor del segundo operador.
 * \return (-1) Error / (0) Ok
 */
int utn_multiplicacion (float* pResultadoMultiplicacion, float operador1, float operador2)
{
	int retorno = -1;

	if (pResultadoMultiplicacion != NULL)
	{
		*pResultadoMultiplicacion = operador1 * operador2;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Realiza la división entre dos operadores ingresados.
 * \param float* pResultadoDivision, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param float operador1, Valor del primer operador.
 * \param float operador2, Valor del segundo operador.
 * \return (-1) Error / (0) Ok
 */
int utn_division (float* pResultadoDivision, float operador1, float operador2)
{
	int retorno = -1;

	if (pResultadoDivision != NULL)
	{
		if (operador2 != 0)
		{
		*pResultadoDivision = operador1 / operador2;
		retorno = 0;
		}else
		{
			printf("--- DIVISOR NO PUEDE SER CERO ---\n");
		}
	}

	return retorno;
}

/**
 * \brief Realiza la factorización de un operando..
 * \param float* pResultadoFactorial, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param float operador1, Valor del operador.
 * \return (-1) Error / (0) Ok
 */
int utn_factorial (double *pResultadoFactorial, float operador)
{
	int retorno = -1;
	double resultadoFactorial = 1;
	int multiplicador;

	if(pResultadoFactorial != NULL)
	{
		if(operador == (int)operador)
		{
			if(operador > 0)
			{
				for (multiplicador = operador; multiplicador > 0; multiplicador--)
				{
				resultadoFactorial *= multiplicador;
				}
				retorno = 0;
				*pResultadoFactorial = resultadoFactorial;

			}else if (operador == 0)
			{
				*pResultadoFactorial = 1;
				retorno = 0;
			}else
			{
				printf("- OPERADOR NO DEBE SER NEGATIVO -\n");
			}
		}else
		{
			printf("- OPERADOR NO DEBE SER FLOTANTE -\n");
		}
	}
	return retorno;
}
/*\brief Es el menú de la calculadora.
* \param float *pResultadoOperacion, puntero al espacio de memoria donde se dejara el valor obtenido.
 * \param float operador1, Valor del primer operador.
 * \param float operador2, Valor del segundo operador.
* \param int reintentos, cantidad de oportunidades para ingresar el dato.
* \param double *pResultadoOperacionFactorial, puntero al espacio de memoria donde se dejara el valor obtenido.
* \param int *pContinuar, puntero al espacio de memoria donde se dejara el valor obtenido.
*/
int utn_cal_Menu (float *pResultadoOperacion, float operador1, float operador2, int reintentos, double *pResultadoOperacionFactorial, int *pContinuar)
{
	int retorno = -1;
	char opcionIngresada;

	do
	{
		if (utn_getChar(&opcionIngresada, "\n---------------------------------\n---- SELECCIÓNE LA OPERACIÓN ----\n------ QUE DESEA REALIZAR -------\n---------------------------------\n\n- [S] - Para SUMAR\n- [R] - Para RESTAR\n- [M] - Para MULTIPLICAR\n- [D] - Para DIVIDIR\n- [F] - Para FACTORIZAR\n- [E] - Para EXIT\n\n---- SELECCIÓNE LA OPERACIÓN ----","XXXXXX|  DATO NO VÁLIDO  |XXXXXXX", 2) == 0)
		{
			if (opcionIngresada == 'S' || opcionIngresada == 'R' || opcionIngresada == 'M' || opcionIngresada == 'D' || opcionIngresada == 'F' || opcionIngresada == 'E')
			{
				switch (opcionIngresada)
					{
					case 'S':
						if(utn_suma(pResultadoOperacion, operador1, operador2)==0)
						{
							printf("\n[RESULTADO] \n> %.2f\n\n", *pResultadoOperacion);
							retorno = 0;
						}
						break;

					case 'R':
						if(utn_resta(pResultadoOperacion, operador1, operador2)==0)
						{
							printf("\n[RESULTADO] \n> %.2f\n\n", *pResultadoOperacion);
							retorno = 0;
						}
						break;

					case 'M':
						if(utn_multiplicacion(pResultadoOperacion, operador1, operador2)==0)
						{
							printf("\n[RESULTADO] \n> %.2f\n\n", *pResultadoOperacion);
							retorno = 0;
						}
						break;

					case 'D':
						if(utn_division(pResultadoOperacion, operador1, operador2)==0)
						{
							printf("\n[RESULTADO] \n> %.2f\n\n", *pResultadoOperacion);
							retorno = 0;
						}
						break;

					case 'F':
						if(utn_factorial(pResultadoOperacionFactorial, operador1)==0)
						{
							printf("\n[RESULTADO PRIMER OPERADOR] \n> %.0f\n", *pResultadoOperacionFactorial);
							retorno = 0;
						}
						if(utn_factorial(pResultadoOperacionFactorial, operador2)==0)
						{
							printf("\n[RESULTADO SEGUNDO OPERADOR] \n> %.0f\n", *pResultadoOperacionFactorial);
							retorno = 0;
						}
						break;

					case 'E':
						printf("\n---------------------------------\n------ APAGANDO EL SISTEMA ------\n---------------------------------");
						*pContinuar = 0;
						break;
					}
			}else
			{
				printf("\n- [%c] - NO ES OPCIÓN DEL MENÚ\n", opcionIngresada);
				reintentos --;
				if (reintentos <= 0)
				{
					printf("\n----- NO HAY MÁS REINTENTOS -----");
				}
			}
		}

	}while (reintentos <=0 );

	return retorno;
}

/**
 * \brief Realiza la factorización de un operando..
 * \char* pContinuar, puntero al espacio de memoria donde se dejara el valor obtenido
* \param int reintentos, cantidad de oportunidades para ingresar el dato.
 * \return (-1) Error / (0) Ok
 */
int utn_cal_Confirm (int* pContinuar, int reintentos)
{
	int retorno = -1;
	char opcionIngresada;

	do
	{
		utn_getChar(&opcionIngresada, "\n---------------------------------\n---- SELECCIÓNE LA OPERACIÓN ----\n------ QUE DESEA REALIZAR -------\n---------------------------------\n\n[S] - Para CONTINUAR\n[N] - Para SALIR","\nOpción no válida, Re-Ingrese:", 2);

		switch (opcionIngresada)
		{
			case 'N':
				*pContinuar = 0;
				retorno = 0;
				reintentos = -1;
				printf("\n---------------------------------\n------ APAGANDO EL SISTEMA ------\n---------------------------------");
				break;

			case 'S':
				retorno = 1;
				break;
			default:
				reintentos--;
		}

	}while(reintentos >=0);

	return retorno;
}
