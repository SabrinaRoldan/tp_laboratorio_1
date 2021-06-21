#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int menu(int* opcion);

/** \brief                          Crea un nuevo empleado.
 *
 * \return Employee*                Retorna un empleado.
 *
 */
Employee* employee_new();

/** \brief                          Crea nuevos parametros para el empleado casteados a string.
 *
 * \param idStr char*               Id de empleado.
 * \param nombreStr char*           Nombre del empleado.
 * \param horasTrabajadasStr char*  Horas trabajadas del empleado.
 * \param sueldoStr char*           Sueldo del empleado.
 * \return Employee*                Retorna un empleado.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief                          Elimina un empleado.
 *
 * \param empleado Employee*        Estructura Empleado.
 * \return void                     No retorna valores.
 *
 */
void employee_delete(Employee* empleado);

/** \brief                          Setter de Id de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param id int                    Id de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_setId(Employee* this,int id);

/** \brief                          Getter de Id de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param id int                    Id de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief                          Setter de nombre de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param nombre char*              Nombre de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief                          Getter de nombre de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param nombre char*              Nombre de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief                          Setter de las horas trabajadas de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param horasTrabajadas int       Horas trabajadas de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief                          Getter de las horas trabajadas de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param horasTrabajadas int       Horas trabajadas de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief                          Setter de sueldo de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param sueldo int                Sueldo de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief                          Getter de sueldo de empleado.
 *
 * \param this Employee*            Estructura empleado.
 * \param sueldo int                Sueldo de empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief                          Muestra el empleado con sus valores.
 *
 * \param this Employee*            Estructura empleado.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int mostrarEmpleado(Employee* this);

/** \brief                          Compara Ids de empleados.
 *
 * \param employee1 void*           Primer empleado a comparar.
 * \param employee2 void*           Segundo empleado a comparar.
 * \return int                      Retorna -1 si el 1er empleado es mayor al segundo.
 *
 */
int employee_compareId(void* employee1, void* employee2);

/** \brief                          Compara Nombres de empleados.
 *
 * \param employee1 void*           Primer empleado a comparar.
 * \param employee2 void*           Segundo empleado a comparar.
 * \return int                      Retorna -1 si el 1er empleado es mayor al segundo.
 *
 */
int employee_compareNombre(void* employee1, void* employee2);

/** \brief                          Compara Horas Trabajadas de empleados.
 *
 * \param employee1 void*           Primer empleado a comparar.
 * \param employee2 void*           Segundo empleado a comparar.
 * \return int                      Retorna -1 si el 1er empleado es mayor al segundo.
 *
 */
int employee_compareHorasTrabajadas(void* employee1, void* employee2);

/** \brief                          Compara Sueldos de empleados.
 *
 * \param employee1 void*           Primer empleado a comparar.
 * \param employee2 void*           Segundo empleado a comparar.
 * \return int                      Retorna -1 si el 1er empleado es mayor al segundo.
 *
 */
int employee_compareSueldo(void* employee1, void* employee2);


#endif // employee_H_INCLUDED
