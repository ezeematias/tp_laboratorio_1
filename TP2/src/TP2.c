/*
 ============================================================================
 Name        : TP2.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo práctico 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployee.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	Employee listEmployee[LONG_EMPLOYEE];
	menuEmployee(listEmployee);
	return EXIT_SUCCESS;
}
