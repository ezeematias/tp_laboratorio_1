/*
 ============================================================================
 Name        : TP3
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo práctico Nº3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"

/** \brief Search and create a memory space
 *
 *  \return pointer to dynamic memory.
 */
Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}

/** \brief New Employee whith parameters text.
 *
 * \param char* idStr, Get ID
 * \param char* nombreStr, Get Name
 * \param char* horasTrabajadasStr, Get Hours
 * \param char* sueldo, Get Salary.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* this = employee_new();
	if (!employee_setNombre(this,nombreStr) && !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) && !employee_setId(this, atoi(idStr)) && !employee_setSueldo(this, atof(sueldo)))
	{
		return this;
	}
	employee_delete(this);
	return NULL;
}

/** \brief New Employee whith parameters.
 *
 * \param char* idStr, Get ID
 * \param char* nombreStr, Get Name
 * \param char* horasTrabajadasStr, Get Hours
 * \param char* sueldo, Get Salary.
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Employee* employee_newWithParameters(int id, char* name, int workedHours, float salary)
{
    Employee* this = employee_new();
	if(this != NULL)
	{
		if( !employee_setId(this, id) &&
			!employee_setNombre(this, name) &&
			!employee_setHorasTrabajadas(this, workedHours) &&
			!employee_setSueldo(this, salary))
		{
			return this;
		}
	}
	employee_delete(this);
	return NULL;
}

/** \brief New ID. Read the ID from a text file
 *
 * \param char* path, File path
 * \return int Return (ID+1), NewID.
 *
 */
int employee_newId(char* path)
{
	FILE* pFile;
	int id;
	if(path != NULL)
	{
		pFile = fopen(path,"r");
		if (pFile != NULL)
		{
			id = parser_EmployeeId(pFile);
		}
		fclose(pFile);
	}
	return id+1;
}

/** \brief Save ID. Save a new identity number.
 *
 * \param char* path, File path
 * \param char* id, Get ID.
 * \return int Return (ID), NewID.
 *
 */
int employee_saveId(char* path, int id)
{
    FILE* pFile;
    int retorno = -1;

    if(path != NULL && id != -1)
    {
        pFile = fopen(path, "w");
        if (pFile != NULL)
        {
			fprintf(pFile,"%d\n", id);
			retorno = 0;
        }
		fclose(pFile);
    }
    return retorno;
}

/** \brief New Employee. This function looks for a space in the structure which is empty to be able to data.
 *
 * \param list Employee* Pointer to array of employees
 * \return int Return (NULL) if Error [Invalid length or NULL pointer] - (Employee*) if Ok
 *
 */
Employee* employee_add(void)
{
	Employee bufferArrray;
	Employee* bufferEmployee;
	int attempts = 2;
	if ( !utn_getName(bufferArrray.nombre, LONG_NAME, MSG_NAME, MSG_OPTION_ERROR, attempts) &&
		 !utn_getInt(&bufferArrray.horasTrabajadas, 10, attempts, MSG_HOURS, MSG_OPTION_ERROR, SHRT_MAX, 0) &&
		 !utn_getFloat(&bufferArrray.sueldo, 10, attempts, MSG_SALARY, MSG_OPTION_ERROR, INT_MAX, 0))
	{
		strupr(bufferArrray.nombre);
		bufferArrray.id = employee_newId("lastId.csv");
		employee_saveId("lastId.csv", bufferArrray.id);
		bufferEmployee = employee_newWithParameters(bufferArrray.id, bufferArrray.nombre, bufferArrray.horasTrabajadas, bufferArrray.sueldo);
	}
	return bufferEmployee;
}

/* \brief prints emplyee data
 *
 * \param Employee* this: pointer to employee
 * \return [-1] if error / [0] if ok
 */
int employee_print(Employee* this)
{
    int retorno=-1;
    char bufferName[LONG_NAME];
    int bufferId;
    int bufferHours;
    float bufferSalary;
    if(this!=NULL)
    {
        if( !employee_getId(this, &bufferId) &&
            !employee_getNombre(this, bufferName) &&
            !employee_getHorasTrabajadas(this, &bufferHours) &&
            !employee_getSueldo(this, &bufferSalary))
        {
            printf(MSG_PRINT, bufferId, bufferName, bufferHours, bufferSalary);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Delete a memory space
 *
 * \param Employee* this: pointer to employee
 *  \return (void)
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief Returns what is in the structure in the ID field.
 *
 * \param Employee* this: pointer to employee
 * \param char* id, Get ID.
 * \return int Return (ID) / [-1] if error.
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/** \brief Returns what is in the structure in the Name field.
 *
 * \param Employee* this: pointer to employee
 * \param char* nombre, Get Name.
 * \return [-1] if error / [0] if ok
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

/** \brief Returns what is in the structure in the hours field.
 *
 * \param Employee* this: pointer to employee
 * \param char* horasTrabajadas, Get hours.
 * \return [-1] if error / [0] if ok
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief Returns what is in the structure in the salary field.
 *
 * \param Employee* this: pointer to employee
 * \param float* sueldo, Get salary.
 * \return [-1] if error / [0] if ok
 *
 */
int employee_getSueldo(Employee* this,float* sueldo)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief Verify that the array is only letters.
 *
 * \param char* nombre, Pointer to the memory space where the obtained value will be left.
 * \return (0) FALSE / (1) TRUE
 */
int isValidNombre(char* nombre)
{
	int retorno = 1;
	int i;

	if(nombre != NULL)
	{
		for (i = 0;nombre[i] != '\0';i++)
		{
			if ((nombre[i] < 'a' || nombre[i] > 'z') && (nombre[i] < 'A' || nombre[i] > 'Z') && nombre[i] != ' ' && nombre[i] != '-')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/** \brief Load the name in the employee field and validate that the data is correct
 *
 * \param Employee* this: pointer to employee
 * \param char* nombre: pointer of the name to be set to an employee
 * \return [-1] if error / [0] if ok
 */
int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && isValidNombre(nombre) == 1)
	{
		strncpy(this->nombre,nombre,(int) sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

/** \brief Load the hours in the employee field and validate that the data is correct
 *
 * \param Employee* this: pointer to employee
 * \param char* horasTrabajadas: pointer of the hours to be set to an employee
 * \return [-1] if error / [0] if ok
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief Load the hours in the employee field and validate that the data is correct
 *
 * \param Employee* this: pointer to employee
 * \param float sueldo: pointer of the salary to be set to an employee
 * \return [-1] if error / [0] if ok
 */
int employee_setSueldo(Employee* this, float sueldo)
{
	int retorno = -1;
	if(this != NULL)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief Compares two names and returns a value indicating their order
 *
 * \param void *thisA: Name number one.
 * \param void *thisB: Name number two.
 * \return [-2] if error / [1] if is ascending. / [-1] If is descending. / [0] If is equal
 */
int employee_compareName(void *thisA, void *thisB)
{
    int retorno = -2;
    int answerStrcmp;
    char bufferNameA[BUFFER_SIZE];
    char bufferNameB[BUFFER_SIZE];
    employee_getNombre((Employee*) thisA, bufferNameA);
    employee_getNombre((Employee*) thisB, bufferNameB);
    if (thisA != NULL && thisB != NULL)
    {
        answerStrcmp = strcmp(bufferNameA, bufferNameB);
        if (answerStrcmp > 0)
        {
        	retorno = 1;
        } else if (answerStrcmp < 0)
        {
        	retorno = -1;
        } else
        {
        	retorno = 0;
        }
    }
    return retorno;
}
