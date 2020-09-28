/*
 ============================================================================
 Name        : TP2.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo préctico 2
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_

int utn_sortArrayInt(int* pArray, int len);
int utn_printArrayInt(int* pArray, int len);
int utn_getInt(int *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getFloat(float *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getChar (char* pArray, int len, char* msg, char* msgError, int attempts);

#endif /* UTN_H_ */
