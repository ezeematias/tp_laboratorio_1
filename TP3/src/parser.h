/*
 ============================================================================
 Name        : TP3
 Author      : Un�a, Ezequiel Mat�as
 Version     :
 Copyright   :
 Description : Trabajo pr�ctico N�3
 ============================================================================
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeId(FILE* pFile);

#endif /* SRC_PARSER_H_ */
