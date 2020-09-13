/*
 * utn.h
 *
 *  Created on: 5 sept. 2020
 *      Author: Unía, Ezequiel Matías
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumber (int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumbreFloat (float* pNumeroFloatIngresado,  char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getChar (char* pNombreIngresado, char* mensaje, char* mensajeError, int reintentos);
int utn_suma (float* pResultadoSuma, float operador1, float operador2);
int utn_resta (float* pResultadoResta, float operador1, float operador2);
int utn_multiplicacion (float* pResultadoMultiplicacion, float operador1, float operador2);
int utn_division (float* pResultadoDivision, float operador1, float operador2);
int utn_factorial (double *pResultadoFactorial, float operador);
int utn_cal_Menu (float *pResultadoOperacion, float operador1, float operador2, int reintentos, double *pResultadoOperacionFactorial, int *pContinuar);
int utn_cal_Confirm (int* pContinuar, int reintentos);

#endif /* UTN_H_ */
