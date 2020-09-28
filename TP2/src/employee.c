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
#include <string.h>
#include <limits.h>
#include "employee.h"
#include "utn.h"

static int newIdEmployee(void);
static int menuEmployee(Employee* aEmployee);
static int initEmployees(Employee* list, int len);
static int newEmployee(Employee* list, int len);
static int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
static int findEmployeeById(Employee* list, int len,int id);
static int removeEmployee(Employee* list, int len, int id);
static int sortEmployees(Employee* list, int len, int order);
static int printEmployees(Employee* list, int length);
static int modifyEmployee(Employee* list, int len);
static int unsuscribeEmployee(Employee* list, int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int employee_start (void)
{
	int retorno = -1;
	Employee listEmployee[LONG_EMPLOYEE];
	menuEmployee(listEmployee);
	return retorno;
}

static int menuEmployee(Employee* aEmployee)
{
	int retorno = -1;
	int option;
	int flagFirstEmployee = TRUE;
	int flagContinue = TRUE;
	int attemps = 2;
	printf("-----------------------------------\nXXXXXXX| SECCIÓN EMPLEADOS |XXXXXXX\n-----------------------------------\n");
	initEmployees(aEmployee, LONG_EMPLOYEE);
	do
	{
		utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> AGREGAR NUEVO EMPLEADO\n[2] -> MODIFICAR EMPLEADO\n[3] -> BAJA DE EMPLEADO\n[4] -> INFORMAR DATOS EMPLEADO\n[5] -> SALIR\n\n------- OPCIÓN SELECCIONADA -------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1);
		switch (option)
		{
		case 1:
			if(newEmployee(aEmployee,LONG_EMPLOYEE)==0)
			{
				printf("\n-----------------------------------\nXXXXXXX| EMPLEADO CARGADO |XXXXXXXX\n-----------------------------------\n");
				flagFirstEmployee = FALSE;
			}else
			{
				printf("\n-----------------------------------\nXXXX| NO SE CARGÓ EL EMPLEADO |XXXX\n-----------------------------------\n");
			}
			break;
		case 2:
			if(flagFirstEmployee == FALSE)
			{
				if(modifyEmployee(aEmployee,LONG_EMPLOYEE)==0)
				{
					printf("\n-----------------------------------\nXXXXXXX| EMPLEADO CARGADO |XXXXXXXX\n-----------------------------------\n");
				}else
				{
					printf("\n-----------------------------------\nXXXX| NO SE CARGÓ EL EMPLEADO |XXXX\n-----------------------------------\n");
				}

			}else{
				printf("\n-----------------------------------\nXXX| NO HAY EMPLEADOS CARGADOS |XXX\n-----------------------------------\n");
				attemps--;
			}
			break;
		case 3:
			if(flagFirstEmployee == FALSE)
			{
				if(unsuscribeEmployee(aEmployee, LONG_EMPLOYEE)==0)
				{
					printf("\n-----------------------------------\nXXXXX| EMPLEADO DADO DE BAJA |XXXXX\n-----------------------------------\n");
				}else
				{
					printf("\n-----------------------------------\nXXXXXXX| NO SE DIÓ DE BAJA |XXXXXXX\n-----------------------------------\n");
				}

			}else{
				printf("\n-----------------------------------\nXXX| NO HAY EMPLEADOS CARGADOS |XXX\n-----------------------------------\n");
				attemps--;
			}
			break;
		case 4:
			if(flagFirstEmployee == FALSE)
			{
				//INFORMAR
				// CASE 1 - EMPLEADOS ALTAS
				printEmployees(aEmployee, LONG_EMPLOYEE);
				// CASE 2 - PROMEDIOS - VER CONSIGNA
			}else{
				printf("\n-----------------------------------\nXXX| NO HAY EMPLEADOS CARGADOS |XXX\n-----------------------------------\n");
				attemps--;
			}
			break;
		case 5:
			//SALIR
			printf("\n-----------------------------------\nXXXXXXXX| CERRANDO SISTEMA |XXXXXXX\n-----------------------------------\n");
			flagContinue = FALSE;
			break;
		default:
			attemps--;
			if(attemps >= 0)
			{
				printf("XXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n");
			}else
			{
				printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA |XXXXXX\n-----------------------------------\n");
			}
			break;
		}
	}while(flagContinue == TRUE && attemps >= 0);
	return retorno;
}

static int newIdEmployee(void)
{
	static int id = 999;
	id = id+1;
	return id;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].id = 0;
		}
		retorno = 0;
	}
	return retorno;
}

static int modifyEmployee(Employee* list, int len)
{
	int retorno = -1;
	int bufferId;
	int bufferIndex;
	int option;
	int flagContinue = TRUE;

	if(utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL EMPLEADO -----\n", "NO ES UNA OPCIÓN VÁLIDA\n", 5, 1)==0 && findEmployeeById(list, LONG_EMPLOYEE, bufferId) >= 0)
	{
		bufferIndex = findEmployeeById(list, LONG_EMPLOYEE, bufferId);
		printf("\n------ EMPLEADO A MODIFICAR -------\n\n[NOMBRE] ---> %s\n[APELLIDO] -> %s\n[SALARIO] --> %.2f\n[SECTOR] ---> %d\n[ID] -------> %d\n[INDEX] ----> %d\n",list[bufferIndex].name,list[bufferIndex].lastName,list[bufferIndex].salary,list[bufferIndex].sector, list[bufferIndex].id,bufferIndex);
		do
		{
			if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> MODIFICAR NOMBRE\n[2] -> MODIFICAR APELLIDO\n[3] -> MODIFICAR SALARIO\n[4] -> MODIFICAR SECTOR\n[5] -> SALIR\n", "NO ES UNA OPCIÓN VÁLIDA\n", 5, 1)==0)
			{
				switch (option)
				{
				case 1:
					if (utn_getChar(list[bufferIndex].name, LONG_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
					{
						printf("\n-----------------------------------\nXXXXXXXX| NOMBRE CARGADO |XXXXXXXXX\n-----------------------------------\n");
						retorno = 0;
					}else
					{
						printf("\n-----------------------------------\nXXXXX| NO SE CARGÓ EL NOMBRE |XXXXX\n-----------------------------------\n");
					}
					break;
				case 2:
					if (utn_getChar(list[bufferIndex].lastName, LONG_LASTNAME, "\n-------- INGRESE APELLIDO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
					{
						printf("\n-----------------------------------\nXXXXXXX| APELLIDO CARGADO |XXXXXXXX\n-----------------------------------\n");
						retorno = 0;
					}else
					{
						printf("\n-----------------------------------\nXXXX| NO SE CARGÓ EL APELLIDO |XXXX\n-----------------------------------\n");
					}
					break;
				case 3:
					if (utn_getFloat(&list[bufferIndex].salary, 10, 2, "\n--------- INGRESE SALARIO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 0)==0)
					{
						printf("\n-----------------------------------\nXXXXXXXX| SALARIO CARGADO |XXXXXXXX\n-----------------------------------\n");
						retorno = 0;
					}else
					{
						printf("\n-----------------------------------\nXXXXX| NO SE CARGÓ EL SALARIO |XXXX\n-----------------------------------\n");
					}
					break;
				case 4:
					if (utn_getInt(&list[bufferIndex].sector, 10, 2, "\n--------- INGRESE SECTOR ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 20, 1)==0)
					{
						printf("\n-----------------------------------\nXXXXXXXX| SECTOR CARGADO |XXXXXXXXX\n-----------------------------------\n");
						retorno = 0;
					}else
					{
						printf("\n-----------------------------------\nXXXXX| NO SE CARGÓ EL SECTOR |XXXXX\n-----------------------------------\n");
					}
					break;
				case 5:
					flagContinue = FALSE;
					break;
				}
			}

		}while(flagContinue == TRUE && list[bufferIndex].isEmpty == FALSE);

	}else
	{
		printf("\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\n-----------------------------------\n");
	}
	return retorno;
}

static int serchIndexEmpty(Employee* list, int len)
{
	int retornar = -1;
	if(list != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE && list[i].id == 0)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}

static int newEmployee(Employee* list, int len)
{
	int retorno = -1;
	int id;
	Employee bufferArrray;
	// ALOJAR LSO DATOS EN BUFFERS Y PEDIR EL INDICE RECIEN DENTRO DEL ADD PARA EVITAR ESTO: -----------

	if (utn_getChar(bufferArrray.name, LONG_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getChar(bufferArrray.lastName, LONG_LASTNAME, "\n-------- INGRESE APELLIDO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getFloat(&bufferArrray.salary, 50, 2, "\n--------- INGRESE SALARIO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 0)==0 &&
		utn_getInt(&bufferArrray.sector, 50, 2, "\n--------- INGRESE SECTOR ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 1)==0)
	{
		id = newIdEmployee();
		if (addEmployee(list,LONG_EMPLOYEE,id,bufferArrray.name,bufferArrray.lastName,bufferArrray.salary,bufferArrray.sector)==0)
		{
			printf("\n----------- ID EMPLEADO -----------\n> %d\n", id);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
static int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int index;
	if(list != NULL && len>0)
	{
		index = serchIndexEmpty(list, LONG_EMPLOYEE);
		list[index].id = id;
		strncpy(list[index].name, name, LONG_NAME);
		strncpy(list[index].lastName, lastName, LONG_LASTNAME);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found] /// CONSULTAR EL NULL ///
 *
 */
static int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(list[i].id == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

static int unsuscribeEmployee(Employee* list, int len)
{
	int retorno = -1;
	int bufferId;
	if(utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL EMPLEADO -----\n", "NO ES UNA OPCIÓN VÁLIDA\n", 5, 1)==0 && removeEmployee(list, LONG_EMPLOYEE, bufferId)==0)
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
static int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int index;
	index = findEmployeeById(list, LONG_EMPLOYEE, id);
	if(index > -1)
	{
		list[index].isEmpty = TRUE;
		printf("\n----- EMPLEADO DADO DE BAJAR ------\n\n[NOMBRE] ---> %s\n[APELLIDO] -> %s\n[SALARIO] --> %.2f\n[SECTOR] ---> %d\n[ID] -------> %d\n[INDEX] ----> %d\n",list[index].name,list[index].lastName,list[index].salary,list[index].sector, list[index].id,index);
		retorno = 0;
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;

	return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
static int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n[NOMBRE] ---> %s\n[APELLIDO] -> %s\n[SALARIO] --> %.2f\n[SECTOR] ---> %d\n[ID] -------> %d\n[INDEX] ----> %d\n",list[i].name,list[i].lastName,list[i].salary,list[i].sector, list[i].id,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}

