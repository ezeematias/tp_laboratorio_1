/*
 ============================================================================
 Name        : TP2.c
 Author      : Un�a, Ezequiel Mat�as
 Version     :
 Copyright   :
 Description : Trabajo pr�ctico 2
 ============================================================================
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_
#define TRUE 1
#define FALSE 0
#define LONG_NAME 51
#define LONG_LASTNAME 51
#define LONG_EMPLOYEE 1000

struct
{
 int id;
 char name[LONG_NAME];
 char lastName[LONG_LASTNAME];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int menuEmployee(Employee* aEmployee);

#endif /* ARRAYEMPLOYEE_H_ */
