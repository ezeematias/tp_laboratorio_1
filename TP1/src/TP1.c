/*
 ============================================================================
 Name        : TP1.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	float primerNumeroIngresado;
	float segundoNumeroIngresado;
	float resultadoOperacion;
	double resultadoOperacionFactorial;
	int continuar = 1;
	int reintentos = 3;

	printf("---------------------------------\n-- BIENVENIDO A LA CALCULADORA --\n---------------------------------\n");
	do
	{
		if(utn_getNumbreFloat(&primerNumeroIngresado, "\n----- INGRESE PRIMER NÚMERO -----", "XXXXXX|  DATO NO VÁLIDO  |XXXXXXX", -32767, 32767, reintentos)==0)
		{
			if (utn_getNumbreFloat(&segundoNumeroIngresado, "\n----- INGRESE SEGUNDO NÚMERO ----", "XXXXXX|  DATO NO VÁLIDO  |XXXXXXX", -32767, 32767, reintentos)==0)
				{
					printf("\n----- OPERADORES INGRESADOS -----\n 1ro - %.2f   ||  2do - %.2f",primerNumeroIngresado,segundoNumeroIngresado);
					utn_cal_Menu(&resultadoOperacion, primerNumeroIngresado, segundoNumeroIngresado, reintentos,&resultadoOperacionFactorial,&continuar);
					if(continuar == 1)
					{
						utn_cal_Confirm(&continuar, reintentos);
					}
				}
		}
	}while (continuar == 1);

	return EXIT_SUCCESS;
}
