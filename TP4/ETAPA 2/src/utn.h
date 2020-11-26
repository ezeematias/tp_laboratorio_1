/*
 ============================================================================
 Name        : PRIMER_PARCIAL_LABO1
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Primer Parcial Laboratorio 1
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_
#define TRUE 1
#define FALSE 0
#define NO_MORE_ATTEMPTS "\n---[ NO HAY MÁS REINTENTOS ]-----------------------------------------------\n"
#define MSG_OPTION_MENU  "\n---[ SELECCIONE UNA OPCIÓN ]-----------------------------------------------\n[1] -> CARGAR DATOS EN MODO TEXTO\n[2] -> CARGAR DATOS EN MODO BINARIO\n[3] -> ALTA DE EMPLEADO\n[4] -> MODIFICAR EMPLEADO\n[5] -> BAJA DE EMPLEADO\n[6] -> LISTAR EMPLEADOS\n[7] -> ORDENAR EMPLEADOS\n[8] -> GUARDAR DATOS EN MODO TEXTO\n[9] -> GUARDAR DATOS EN MODO BINARIO\n[0] -> SALIR\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_REMOVE  "\n---[ CONFIRMAR ELIMINACIÓN ]-----------------------------------------------\n[1] -> SI\n[2] -> NO\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_SAVE  "\n---------------------------------------------------------------------------\n-----------[ NO SE GUARDARON LOS CAMBIOS, ¿DESEA GUARDARLOS? ]-------------\n---------------------------------------------------------------------------\n[1] -> SI\n[0] -> NO\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_SORT  "\n---[ SELECCIONE UNA OPCIÓN ]-----------------------------------------------\n[1] -> ASCENDENTE [A-Z]\n[0] -> DESCENDENTE [Z-A]\n\n[OPCIÓN SELECCIONADA]"
#define MSG_OPTION_ERROR "\n---[ |XXX| ERROR |XXX| ]---------------------------------------------------\n"

int utn_sortArrayInt(int* pArray, int len);
int utn_printArrayInt(int* pArray, int len);
int utn_getInt(int *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getFloat(float *pArray, int len, int attempts, char* msg, char* msgError, int max, int min);
int utn_getName (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getAddress (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getEmail (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getCuit (char* pArray, int len, char* msg, char* msgError, int attempts);
int utn_getString (char* pArray, int len, char* msg, char* msgError, int attempts);

#endif /* UTN_H_ */
