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
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Loads employee data from data.csv file (binary mode).
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		FILE* fp = fopen(path,"r");
		if (fp != NULL)
		{
			parser_EmployeeFromText(fp, pArrayListEmployee);

			retorno = 0;
		}
		fclose(fp);
    }
	return retorno;
}

/** \brief Loads employee data from data.bin file (binary mode).
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		FILE* fp = fopen(path,"rb");
		if (fp != NULL)
		{
			retorno = parser_EmployeeFromBinary(fp, pArrayListEmployee);
		}
		fclose(fp);
    }
	return retorno;
}

/** \brief Add employee
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
    if(pArrayListEmployee!=NULL)
    {
    	ll_add(pArrayListEmployee, employee_add());
    	retorno = 0;
    }
	return retorno;
}

/** \brief Find Employee
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int, Get the ID
 * \return int*, Returns the index by pointer
 * \return int (-1) if ERROR (0) if OK *
 *
 */
int controller_findById(LinkedList* pArrayListEmployee, int id, int* index)
{
	Employee* bufferEmployee;
	int retorno = -1;
	int bufferId;
	int len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
    	for(int i=1;i<len;i++)
    	{
    		bufferEmployee = ll_get(pArrayListEmployee, i);
    		if(bufferEmployee != NULL && !employee_getId(bufferEmployee, &bufferId) &&  bufferId == id)
    		{
    			*index = i;
    			retorno = 0;
    			break;
    		}
    	}
    }
	return retorno;
}


/** \brief Modify employee specific
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK *
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* bufferEmployee;
	char bufferName[LONG_NAME];
	int bufferHours;
	float bufferSalary;
	int retorno = -1;
	int bufferId;
	int bufferIndex;
	int option;
	int flagContinue = TRUE;
	int attempts = 2;
    if(pArrayListEmployee!=NULL)
    {
		do
		{
			if(utn_getInt(&bufferId, 50, 2, MSG_ID, MSG_OPTION_ERROR, 2000, 0)==0)
			{
				if(!controller_findById(pArrayListEmployee, bufferId, &bufferIndex))
				{
					do
					{
						bufferEmployee = ll_get(pArrayListEmployee, bufferIndex);
						printf(MSG_PRINT_EMPLOYEE);
						employee_print(bufferEmployee);
						printf(MSG_PRINT_OUT);
						if(utn_getInt(&option, 2, 2, MSG_OPTION_MODIFY, MSG_OPTION_ERROR, 3, 0)==0)
						{
							switch (option)
							{
							case 1:
								if (utn_getName(bufferName, LONG_NAME,MSG_NAME, MSG_OPTION_ERROR, 2)==0)
								{
									strupr(bufferName);
									employee_setNombre(bufferEmployee, bufferName);
									ll_set(pArrayListEmployee, bufferIndex, bufferEmployee);
									retorno = 0;
								}else
								{
									printf(MSG_NAME_FAIL);
								}
								break;

							case 2:
								if (utn_getInt(&bufferHours, 50, 2, MSG_HOURS, MSG_OPTION_ERROR, SHRT_MAX, 0)==0)
								{
									employee_setHorasTrabajadas(bufferEmployee, bufferHours);
									ll_set(pArrayListEmployee, bufferIndex, bufferEmployee);
									printf(MSG_HOURS_OK);
									retorno = 0;
								}else
								{
									printf(MSG_HOURS_FAIL);
								}
								break;
							case 3:
								if (utn_getFloat(&bufferSalary, 50, 2, MSG_SALARY, MSG_OPTION_ERROR, INT_MAX, 0)==0)
								{
									employee_setSueldo(bufferEmployee, bufferSalary);
									ll_set(pArrayListEmployee, bufferIndex, bufferEmployee);
									printf(MSG_SALARY_OK);
									retorno = 0;
								}else
								{
									printf(MSG_SALARY_FAIL);
								}
								break;
							case 0:
								flagContinue = FALSE;
								break;
							}
						}else
						{
							attempts--;
						}
						}while(attempts >= 0 && flagContinue == TRUE && retorno == 0);
				}else
				{
					printf(MSG_ID_FAIL);
					attempts--;
				}
			}else
			{
				flagContinue = FALSE;
			}
		}while(flagContinue == TRUE && attempts >= 0 && retorno -1);
    }
	return retorno;
}

/** \brief Remove employee
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* bufferEmployee;
	int retorno = -1;
	int bufferIndex;
	int bufferId;
	int option;
	int attempts = 2;
	if(pArrayListEmployee != NULL)
	{
		do
		{
			if(utn_getInt(&bufferId, 50, 2, MSG_ID, MSG_OPTION_ERROR, 2000, 0)==0)
			{
				if(!controller_findById(pArrayListEmployee, bufferId, &bufferIndex))
				{
					bufferEmployee = ll_get(pArrayListEmployee, bufferIndex);
					if(bufferEmployee != NULL)
					{
						printf(MSG_PRINT_EMPLOYEE);
						employee_print(bufferEmployee);
						printf(MSG_PRINT_OUT);
						if((utn_getInt(&option, 50, 2, MSG_OPTION_REMOVE, MSG_OPTION_ERROR, 2, 1)==0) && option == 1)
						{
							ll_remove(pArrayListEmployee, bufferIndex);
							employee_delete(bufferEmployee);
							retorno = 0;
						}else
						{
							break;
						}
					}
				}else
				{
					printf(MSG_ID_FAIL);
					attempts--;
				}
			}
		}while(attempts >= 0 && retorno == -1);
	}
	return retorno;
}

/** \brief Prints employee's list
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retornar=-1;
    int len = ll_len(pArrayListEmployee);
    Employee* bufferEmp;
    if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
    	printf(MSG_PRINT_EMPLOYEE);
        for(int i=1; i<len;i++)
        {
            bufferEmp = ll_get(pArrayListEmployee, i);
            employee_print(bufferEmp);
            retornar=0;
        }
    	printf(MSG_PRINT_OUT);
    }
    return retornar;
}

/** \brief Sort employee's list
 *
 * \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 * \return int (-1) if ERROR (0) if OK
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int option;
    if (pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee) && !utn_getInt(&option, 50, 2, MSG_OPTION_SORT, MSG_OPTION_ERROR, 1, 0))
	{
			retorno = ll_sort(pArrayListEmployee, employee_compareName, option);
    }
    return retorno;
}

/** \brief Save employee data in the file data.csv (text mode)
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee *pEmpleado;
    int retorno = -1;
    int length = ll_len(pArrayListEmployee);
    char bufferName[LONG_NAME];
    int bufferId;
    int bufferHours;
    float bufferSalary;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path, "w");
        if (pFile != NULL)
        {
        	fprintf(pFile,"ID,NOMBRE,HORAS TRABAJADAS,SALARIO\n");
            for (int i = 1 ; i < length ; i++)
            {
                pEmpleado = ll_get(pArrayListEmployee, i);
                if( !employee_getId(pEmpleado, &bufferId) &&
                    !employee_getNombre(pEmpleado, bufferName) &&
                    !employee_getHorasTrabajadas(pEmpleado, &bufferHours) &&
                    !employee_getSueldo(pEmpleado, &bufferSalary))
                {
                    fprintf(pFile,"%d,%s,%d,%f\n", bufferId, bufferName, bufferHours, bufferSalary);
                    retorno = 0;
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Save employee data in the file data.bin (binary mode)
 *
 *  \param char* path, File path
 *  \param LinkedList* pArrayListEmployee, Pointer to LinkedList
 *  \return int (-1) if ERROR (0) if OK
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee *pEmpleado;
    int retorno = -1;
    int length = ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if (pFile != NULL){
            retorno = 0;
            for (int i = 0 ; i < length ; i++){
                pEmpleado = ll_get(pArrayListEmployee, i);
                fwrite(pEmpleado, sizeof(Employee), 1, pFile);
            }
        }
    }
    fclose(pFile);
    return retorno;
}
