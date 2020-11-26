/*
 ============================================================================
 Name        : TP3
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo práctico Nº3
 ============================================================================
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeId(FILE* pFile);

#endif /* SRC_PARSER_H_ */
