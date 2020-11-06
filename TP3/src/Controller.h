/*
 ============================================================================
 Name        : TP3
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo práctico Nº3
 ============================================================================
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#define MSG_START   "---------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXX| INICIANDO PROGRAMA |XXXXXXXXXXXXXXXXXXXXXXXXXXX\n---------------------------------------------------------------------------\n"
#define MSG_OFF   "\n---------------------------------------------------------------------------\nXXXXXXXXXXXXXXXXXXXXXXXXXX| APAGANDO PROGRAMA |XXXXXXXXXXXXXXXXXXXXXXXXXXXX\n---------------------------------------------------------------------------\n"
#define MSG_OPTION_MODIFY  "\n---[ SELECCIONE UNA OPCIÓN ]-----------------------------------------------\n[1] -> MODIFICAR NOMBRE\n[2] -> MODIFICAR HORAS TRABAJADAS\n[3] -> MODIFICAR SUELDO\n[0] -> ATRAS\n\n[OPCIÓN SELECCIONADA]"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_findById(LinkedList* pArrayListEmployee, int id, int* index);

#endif /* CONTROLLER_H_ */

