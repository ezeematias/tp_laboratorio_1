/*
 ============================================================================
 Name        : UTN.H
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Bibioteca "utn-h"
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_

int myGets(char* pArray, int len);
int utn_sortArrayInt(int* pArray, int len);
int utn_printArrayInt(int* pArray, int len);
int utn_getInt(int *pArray, int len, int attemps, char* msg, char* msgError, int max, int min);
int utn_getFloat(float *pArray, int len, int attemps, char* msg, char* msgError, int max, int min);
int utn_getChar (char* pArray, int len, char* msg, char* msgError, int attemps);
int utn_myGets(char *array, int lenght);


#endif /* UTN_H_ */
