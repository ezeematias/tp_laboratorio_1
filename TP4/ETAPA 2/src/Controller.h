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
#define MSG_LOAD_OK 	"\n---[ LISTA CARGADA CORRECTAMENTE ]-----------------------------------------\n"
#define MSG_LOAD_FAIL   "\n---[ ERROR AL CARGAR LA LISTA ]--------------------------------------------\n"
#define MSG_ADD_OK	 	"\n---[ EMPLEADO CARGADO CORRECTAMENTE ]--------------------------------------\n"
#define MSG_ADD_FAIL    "\n---[ ERROR AL CARGAR EL EMPLEADO ]-----------------------------------------\n"
#define MSG_EDIT_OK	 	"\n---[ EMPLEADO EDITADO CORRECTAMENTE ]--------------------------------------\n"
#define MSG_EDIT_FAIL   "\n---[ ERROR AL EDITAR EL EMPLEADO ]-----------------------------------------\n"
#define MSG_REMOVE_OK 	"\n---[ EMPLEADO ELIMINADO CORRECTAMENTE ]------------------------------------\n"
#define MSG_REMOVE_FAIL "\n---[ NO SE PUDO ELIMINAR AL EMPLEADO ]-------------------------------------\n"
#define MSG_LIST_OK 	"------------------[ FIN DEL LISTADO DE EMPLEADOS ]-------------------------\n---------------------------------------------------------------------------\n"
#define MSG_LIST_FAIL 	"\n---[ NO SE PUDO MOSTRAR LA LISTA DE EMPLEADOS ]----------------------------\n"
#define MSG_SORT_OK 	"\n---[ SE ORDENARON LOS EMPLEADOS CORRECTAMENTE ]----------------------------\n"
#define MSG_SORT_FAIL   "\n---[ NO SE PUDO ORDENAR A LOS EMPLEADOS ]----------------------------------\n"
#define MSG_SAVE_OK 	"\n---[ SE GUARDÓ LA LISTA CORRECTAMENTE ]------------------------------------\n"
#define MSG_SAVE_FAIL   	"\n---[ NO SE PUDO GUARDAR LA LISTA ]-----------------------------------------\n"
#define MSG_FLAGLOAD_FAIL   "\n---[ PRIMERO DEBE CARGAR UNA LISTA DE DATOS ]------------------------------\n"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_findById(LinkedList* pArrayListEmployee, int id, int* index);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

#endif /* CONTROLLER_H_ */

