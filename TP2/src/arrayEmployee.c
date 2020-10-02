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
#include "arrayEmployee.h"
#include "utn.h"

static int newIdEmployee(void);
static int initEmployees(Employee* list, int len);
static int newEmployee(Employee* list, int len);
static int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
static int findEmployeeById(Employee* list, int len,int id);
static int removeEmployee(Employee* list, int len, int id);
static int sortEmployees(Employee* list, int len, int order);
static int printEmployees(Employee* list, int length);
static int modifyEmployee(Employee* list, int len);
static int unsuscribeEmployee(Employee* list, int len);
static int salaryEmployees(Employee* list, int len);
static int reportEmployee(Employee* list, int len);
static int isArrayEmployeeIsEmpty (Employee* list, int len);

/** \brief Employees menu
 * Displays options for employees by console
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int menuEmployee(Employee* aEmployee)
{
	int retorno = -1;
	int option;
	int flagContinue = TRUE;
	int attempts = 2;

	printf("-----------------------------------\nXXXXXXX| SECCIÓN EMPLEADOS |XXXXXXX\n-----------------------------------\n");
	initEmployees(aEmployee, LONG_EMPLOYEE);
	do
	{
		utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> AGREGAR NUEVO EMPLEADO\n[2] -> MODIFICAR EMPLEADO\n[3] -> BAJA DE EMPLEADO\n[4] -> INFORMAR DATOS EMPLEADO\n[5] -> SALIR\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1);
		switch (option)
		{
		case 1:
			if(newEmployee(aEmployee,LONG_EMPLOYEE)==0)
			{
				printf("\n-----------------------------------\nXXXXXXX| EMPLEADO CARGADO |XXXXXXXX\n-----------------------------------\n");

			}else
			{
				printf("\n-----------------------------------\nXXXX| NO SE CARGÓ EL EMPLEADO |XXXX\n-----------------------------------\n");
			}
			break;
		case 2:
			if(isArrayEmployeeIsEmpty(aEmployee, LONG_EMPLOYEE)==0)
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
				attempts--;
				if(attempts <= 0)
				{
					printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
				}
			}
			break;
		case 3:
			if(isArrayEmployeeIsEmpty(aEmployee, LONG_EMPLOYEE)==0)
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
				attempts--;
				if(attempts <= 0)
				{
					printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
				}
			}
			break;
		case 4:
			if(isArrayEmployeeIsEmpty(aEmployee, LONG_EMPLOYEE)==0)
			{
				reportEmployee(aEmployee, LONG_EMPLOYEE);
			}else{
				printf("\n-----------------------------------\nXXX| NO HAY EMPLEADOS CARGADOS |XXX\n-----------------------------------\n");
				attempts--;
				if(attempts <= 0)
				{
					printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
				}
			}
			break;
		case 5:
			printf("\n-----------------------------------\nXXXXXXXX| CERRANDO SISTEMA |XXXXXXX\n-----------------------------------\n");
			flagContinue = FALSE;
			break;
		default:
			attempts--;
			if(attempts >= 0)
			{
				printf("XXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n");
			}else
			{
				printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
			}
			break;
		}
	}while(flagContinue == TRUE && attempts >= 0);
	return retorno;
}

/** \brief New ID.
 * Generates a new identity number.
 * \param (void)
 * \return int Return (ID), NewID.
 *
 */
static int newIdEmployee(void)
{
	static int id = 999;
	id = id+1;
	return id;
}

/** \brief To initialize all empty array positions.
 * this function put the flag (isEmpty) in TRUE in all and ID to 0.
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
		for(int i=0;i<=len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].id = 0;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Modify employees.
 * This function allows you to modify existing employee data. It has a menu of options.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int modifyEmployee(Employee* list, int len)
{
	int retorno = -1;
	int bufferId;
	int bufferIndex;
	int option;
	int flagContinue = TRUE;
	int attempts = 2;

	do
	{
		if(utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL EMPLEADO -----", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2000, 1000)==0)
		{
			bufferIndex = findEmployeeById(list, LONG_EMPLOYEE, bufferId);
			if(bufferIndex >= 0)
			{
				do
				{
					printf("\n------ EMPLEADO A MODIFICAR -------\n\n[NOMBRE] ---> %s\n[APELLIDO] -> %s\n[SALARIO] --> %.2f\n[SECTOR] ---> %d\n[ID] -------> %d\n[INDEX] ----> %d\n",list[bufferIndex].name,list[bufferIndex].lastName,list[bufferIndex].salary,list[bufferIndex].sector, list[bufferIndex].id,bufferIndex);
					if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> MODIFICAR NOMBRE\n[2] -> MODIFICAR APELLIDO\n[3] -> MODIFICAR SALARIO\n[4] -> MODIFICAR SECTOR\n[5] -> ATRAS\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1)==0)
					{
						switch (option)
						{
						case 1:
							if (utn_getChar(list[bufferIndex].name, LONG_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
							{
								strupr(list[bufferIndex].name);
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
								strupr(list[bufferIndex].lastName);
								printf("\n-----------------------------------\nXXXXXXX| APELLIDO CARGADO |XXXXXXXX\n-----------------------------------\n");
								retorno = 0;
							}else
							{
								printf("\n-----------------------------------\nXXXX| NO SE CARGÓ EL APELLIDO |XXXX\n-----------------------------------\n");
							}
							break;
						case 3:
							if (utn_getFloat(&list[bufferIndex].salary, 10, 2, "\n--------- INGRESE SALARIO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 1)==0)
							{
								printf("\n-----------------------------------\nXXXXXXXX| SALARIO CARGADO |XXXXXXXX\n-----------------------------------\n");
								retorno = 0;
							}else
							{
								printf("\n-----------------------------------\nXXXXX| NO SE CARGÓ EL SALARIO |XXXX\n-----------------------------------\n");
							}
							break;
						case 4:
							if (utn_getInt(&list[bufferIndex].sector, 10, 2, "\n--------- INGRESE SECTOR ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 32676, 1)==0)
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
					}else
					{
						attempts--;
					}
				}while(attempts > 0 && flagContinue == TRUE);
			}else
			{
				printf("\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\n-----------------------------------\n");
				attempts--;
			}
		}else if(attempts > 0)
		{
			printf("\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\n-----------------------------------\n");
			attempts--;
		}else
		{
			printf("\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\nXXX|    NO HAY MÁS INTENTOS    |XXX\n-----------------------------------");
			attempts--;
		}
	}while(flagContinue == TRUE && attempts >= 0 && retorno -1);
	return retorno;
}

/** \brief Search for an empty index.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
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

/** \brief New employee.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int newEmployee(Employee* list, int len)
{
	int retorno = -1;
	int id;
	Employee bufferArrray;

	if (serchIndexEmpty(list, LONG_EMPLOYEE) >= 0 &&
		utn_getChar(bufferArrray.name, LONG_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getChar(bufferArrray.lastName, LONG_LASTNAME, "\n-------- INGRESE APELLIDO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getFloat(&bufferArrray.salary, 50, 2, "\n--------- INGRESE SALARIO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 1)==0 &&
		utn_getInt(&bufferArrray.sector, 50, 2, "\n--------- INGRESE SECTOR ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 1)==0)
	{
		id = newIdEmployee();
		strupr(bufferArrray.name);
		strupr(bufferArrray.lastName);
		if (addEmployee(list,LONG_EMPLOYEE,id,bufferArrray.name,bufferArrray.lastName,bufferArrray.salary,bufferArrray.sector)==0)
		{
			printf("\n----------- ID EMPLEADO -----------\n> %d\n", id);
			retorno = 0;
		}
	}else if(serchIndexEmpty(list, LONG_EMPLOYEE) == -1){
			printf("-----------------------------------\n");
			printf("XXXXXX| NO HAY ESPACIO PARA |XXXXXX\n");
			printf("XXXXXX|  NUEVOS EMPLEADOS   |XXXXXX\n");
			printf("-----------------------------------\n\n");
			retorno = -2;
	}
	return retorno;
}

/** \brief Add in a existing list of employees the values received as parameters.
 * in the first empty position.
 * \param list* employee, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number employee.
 * \param char name[], Name of the employee.
 * \param char lastName[], LastName of the employee.
 * \param float salary, Employee salary.
 * \param int sector, Employee sector.
 * \return int Return (-1) if Error - (0) if Ok
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
 * \param Employee* list, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number employee.
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
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

/** \brief Disable employee.
 * This function receives the structure to disable a user by ID number.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int unsuscribeEmployee(Employee* list, int len)
{
	int retorno = -1;
	int bufferId;
	if((utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL EMPLEADO -----", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2000, 999)==0) && (removeEmployee(list, LONG_EMPLOYEE, bufferId)==0))
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * This function changes the value of the isEmpty field to disable the employee.
 * \param Employee* list, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number employee.
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

/** \brief Employee information.
 * This function provides a list of employees alphabetically ordered ascending or descending and informs the salaries.
 * It has a menu of options.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int reportEmployee(Employee* list, int len)
{
	int retorno = -1;
	int option;

	if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> LISTADO DE EMPLEADOS\n[2] -> INFORMACIÓN DE SALARIOS\n[3] -> ATRAS\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 3, 1)==0)
	{

		switch (option)
		{
		case 1:
			if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> ORDEN ASCENDENTE\n[2] -> ORDEN DESCENDENTE\n[3] -> ATRAS\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 3, 1)==0)
			{
				switch (option)
				{
				case 1:

					sortEmployees(list, LONG_EMPLOYEE, 1);
					printEmployees(list, LONG_EMPLOYEE);
					retorno = 0;
					break;
				case 2:
					sortEmployees(list, LONG_EMPLOYEE, 0);
					printEmployees(list, LONG_EMPLOYEE);
					retorno = 0;
					break;
				case 3:
					retorno = 0;
					break;
				}
			}
			break;
		case 2:
			salaryEmployees(list,LONG_EMPLOYEE);
			retorno = 0;
			break;
		case 3:
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/** \brief Employee salary.
 * This function calculates the total, average salaries of the employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int salaryEmployees(Employee* list, int len)
{
	int retorno =-1;
	int index;
	float totalSalary = 0;
	float averageSalary = 0;
	int counterEmployees = 0;
	int counterEmployeesAverage = 0;

	if(list != NULL && len > 0)
	{
		for(index=0 ; index <= len  ; index++)
		{
			if(list[index].isEmpty == FALSE)
			{
				totalSalary += list[index].salary;
				counterEmployees++;
			}
		}
		averageSalary = totalSalary / counterEmployees;
		for(index=0 ; index <= len  ; index++)
		{
			if(list[index].isEmpty == FALSE && list[index].salary > averageSalary)
			{
				counterEmployeesAverage++;
			}
		}
		if(counterEmployees > 0)
		{
			printf("\n--------------------------------------------------------------------------------------------");
			printf("\n|| --[SALARIO TOTAL]-- || ---[SALARIO PROMEDIO]--- || --[EMPLEADOS ARRIBA DEL PROMEDIO]-- ||");
			printf("\n--------------------------------------------------------------------------------------------");
			printf("\n||   %15.2f   ||    %18.2f    ||                  %4d               ||",totalSalary,averageSalary,counterEmployeesAverage);
			printf("\n--------------------------------------------------------------------------------------------\n");
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees,  *
 * This function receives the order of the arguments indicates the order UP or DOWN
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int index;
	int flagSort = 0;
	Employee bufferEmployee;

	if(list != NULL && len > 0)
	{
		while(flagSort==0)
		{
		flagSort=1;
			for(index=0 ; index<(len-1)  ; index++)
			{
				if((strcmp(list[index].lastName, list[index+1].lastName) < 0 && order == 0) || ((strcmp(list[index].lastName, list[index+1].lastName) > 0) && order == 1) || ((strcmp(list[index].lastName, list[index+1].lastName) == 0 && list[index].sector < list[index+1].sector) && order == 0) || ((strcmp(list[index].lastName, list[index+1].lastName) == 0 && list[index].sector > list[index+1].sector) && order == 1))
				{
					bufferEmployee = list[index];
					list[index] = list[index+1];
					list[index+1] = bufferEmployee;
					flagSort=0;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Employee print
 * This function prints the list of active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("\n---------------------------------------------------------------------------------------------");
		printf("\n|| --[ID]-- || ------[NOMBRE]------ || -----[APELLIDO]----- || --[SALARIO]-- || -[SECTOR]- ||");
		printf("\n---------------------------------------------------------------------------------------------");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n|| > %d   || %-20s || %-20s || %13.2f ||   %7d  ||", list[i].id, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
		printf("\n---------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}

/** \brief Empty employee list
 * This function searches the structure for active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int isArrayEmployeeIsEmpty (Employee* list, int len)
{
	int i;
	int retorno = 1;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
