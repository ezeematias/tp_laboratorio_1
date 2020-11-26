/*
 ============================================================================
 Name        : TP3
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo práctico Nº3
 ============================================================================
 */

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define LONG_NAME 51
#define BUFFER_SIZE 4096
#define MSG_NAME_OK 		   "\n---[ NOMBRE CARGADO CORRECTAMENTE ]----------------------------------------"
#define MSG_NAME_FAIL 		   "\n---[ NO SE PUDO CARGAR EL NOMBRE ]-----------------------------------------"
#define MSG_HOURS_OK 		   "\n---[ HORAS CARGADAS CORRECTAMENTE ]----------------------------------------"
#define MSG_HOURS_FAIL 		   "\n---[ NO SE PUDO CARGAR LAS HORAS ]-----------------------------------------"
#define MSG_SALARY_OK 		   "\n---[ SALARIO CARGADO CORRECTAMENTE ]---------------------------------------"
#define MSG_SALARY_FAIL 	   "\n---[ NO SE PUDO CARGAR EL SALARIO ]----------------------------------------"
#define MSG_NAME 		   "\n---[ INGRESE NOMBRE ]------------------------------------------------------"
#define MSG_HOURS 		   "\n---[ INGRESE HORAS TRABAJADAS ]--------------------------------------------"
#define MSG_SALARY 		   "\n---[ INGRESE SUELDO ]------------------------------------------------------"
#define MSG_ID 		  	   "\n---[ INGRESE ID ]----------------------------------------------------------"
#define MSG_ID_FAIL	  	   "\n---[ EL ID INGRESADO NO EXISTE ]-------------------------------------------\n"
#define MSG_PRINT_EMPLOYEE "\n---------------------------------------------------------------------------\n|| --[ID]-- || -------[NOMBRE]------- || --[HORAS]-- || ----[SUELDO]---- ||\n---------------------------------------------------------------------------"
#define MSG_PRINT "\n|| > %4d   ||    %-16s    ||   %7d   ||    %10.2f    ||"
#define MSG_PRINT_OUT "\n---------------------------------------------------------------------------\n"


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newWithParameters(int id, char* name, int workedHours, float salary);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

Employee* employee_add(void);
int employee_print(Employee* this);
int employee_newId(char* path);
int employee_saveId(char* path, int id);
int employee_compareName(void *thisA, void *thisB);

#endif // employee_H_INCLUDED
