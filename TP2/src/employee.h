/*
 ============================================================================
 Name        : TP2.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo préctico 2
 ============================================================================
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
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

int employee_start (void);

#endif /* EMPLOYEE_H_ */
