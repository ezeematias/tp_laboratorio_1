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
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parser employee data from data.csv file (text mode).
 *
 *  \param FILE* pFile, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char bufferId[1024];
	char bufferNombre[1024];
	char bufferHorasTrabajadas[1024];
	char bufferSueldo[1024];
	Employee* bufferEmployee;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		do
		{
		if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo)==4)
		{
			strupr(bufferNombre);
			bufferEmployee = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
			ll_add(pArrayListEmployee, bufferEmployee);
			retorno = 0;
		}
		}while(feof(pFile)==0);
	}
    return retorno;
}

/** \brief Parser employee data from data.bin file (binary mode).
 *
 *  \param FILE* pFile, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* bufferEmp;
    int retorno=-1;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        ll_clear(pArrayListEmployee);
        do
        {
            bufferEmp = employee_new();
            if( fread(bufferEmp,sizeof(Employee),1,pFile)==1 )
            {
                ll_add(pArrayListEmployee, bufferEmp);
                retorno=0;
            }
            else
            {
                employee_delete(bufferEmp);
            }
        }while(feof(pFile)==0);
    }
    return retorno;
}

/** \brief Parser ID data from data.csv file (text mode).
 *
 * \param FILE* pFile, File path
 * \return int (-1) if ERROR (0) if OK
 *
 */
int parser_EmployeeId(FILE* pFile)
{
	int retorno = -1;
	char bufferId[55];
	do
	{
		if (fscanf(pFile,"%s",bufferId)==1)
		{
			retorno = atoi(bufferId);
		}
	}while(feof(pFile)==0);
    return retorno;
}
