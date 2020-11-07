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
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option;
    int attempts = 2;
    int flagLoad = FALSE;
    int flagSaveText = FALSE;
    int flagSaveBin = FALSE;
    int flagModify = FALSE;

    LinkedList* listaEmpleados = ll_newLinkedList();
    printf(MSG_START);
    do{
    	utn_getInt(&option, 3, attempts, MSG_OPTION_MENU,MSG_OPTION_ERROR, 10, 0);
        switch(option)
        {
            case 1:
                if(flagLoad == FALSE && !controller_loadFromText("data.csv",listaEmpleados))
                {
                	flagLoad = TRUE;
                	printf(MSG_LOAD_OK);
                }else
                {
                	printf(MSG_LOAD_FAIL);
                }
                break;
            case 2:
                if(flagLoad == FALSE && !controller_loadFromBinary("data.bin",listaEmpleados))
                {
                	flagLoad = TRUE;
                	printf(MSG_LOAD_OK);
                }else
                {
                	printf(MSG_LOAD_FAIL);
                }
                break;
            case 3:
            	if(flagLoad == TRUE && !controller_addEmployee(listaEmpleados))
                {
            		flagModify = TRUE;
                	printf(MSG_ADD_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_ADD_FAIL);
                }
                break;
            case 4:
                if(flagLoad == TRUE && !controller_editEmployee(listaEmpleados))
                {
            		flagModify = TRUE;
                	printf(MSG_EDIT_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_EDIT_FAIL);
                }
                break;
            case 5:
                if(flagLoad == TRUE && !controller_removeEmployee(listaEmpleados))
                {
            		flagModify = TRUE;
                	printf(MSG_REMOVE_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_REMOVE_FAIL);
                }
                break;
            case 6:
                if(flagLoad == TRUE && !controller_ListEmployee(listaEmpleados))
                {
                	printf(MSG_LIST_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_LIST_FAIL);
                }
                break;
            case 7:
                if(flagLoad == TRUE && !controller_sortEmployee(listaEmpleados))
                {
            		flagModify = TRUE;
                	printf(MSG_SORT_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_SORT_FAIL);
                }
                break;
            case 8:
                if(flagLoad == TRUE && !controller_saveAsText("data.csv",listaEmpleados))
                {
                	flagSaveText = TRUE;
                	printf(MSG_SAVE_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_SAVE_FAIL);
                }
                break;
            case 9:
                if(flagLoad == TRUE && !controller_saveAsBinary("data.bin",listaEmpleados))
                {
                	flagSaveBin = TRUE;
                	printf(MSG_SAVE_OK);
                }else if (flagLoad == FALSE)
                {
                	printf(MSG_FLAGLOAD_FAIL);
                }else
                {
                	printf(MSG_SAVE_FAIL);
                }
                break;
            case 0:
            	if(flagModify == FALSE)
            	{
					option = 10;
            	}else if (flagSaveBin == FALSE && flagSaveText == FALSE && !utn_getInt(&option, 3, attempts, MSG_OPTION_SAVE,MSG_OPTION_ERROR, 1, 0))
            	{
                    if(option == 1 && !controller_saveAsBinary("data.bin",listaEmpleados) && !controller_saveAsText("data.csv",listaEmpleados))
                    {
                    	printf(MSG_SAVE_OK);
                    	option = 10;
                    }else if (option == 0)
                    {
                    	option = 10;
                    }else
					{
						printf(MSG_SAVE_FAIL);
					}
            	}

                break;
        }
    }while(option != 10);
	printf(MSG_OFF);
	ll_deleteLinkedList(listaEmpleados);
    return 0;
}

