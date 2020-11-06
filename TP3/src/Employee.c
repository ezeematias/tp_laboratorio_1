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


Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}

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

/** \brief New ID.
 * Generates a new identity number.
 * \param (void)
 * \return int Return (ID), NewID.
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

/** \brief Save ID.
 * Save a new identity number.
 * \param (void)
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

/** \brief New Employee.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
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

int employee_initEmployee(Employee* list[], int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i] = NULL;
		}
		retorno = 0;
	}
	return retorno;
}

void employee_delete(Employee* this)
{
	free(this);
}

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
