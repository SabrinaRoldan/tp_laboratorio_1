#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int menu(int* opcion)
{
    system("cls");
    printf("        ***  Menu de opciones  ***\n\n");
    printf("  1- Cargar los datos de los empleados desde un archivo de texto\n");
    printf("  2- Cargar los datos de los empleados desde un archivo binario\n");
    printf("  3- Alta de empleado\n");
    printf("  4- Modificar datos de empleado\n");
    printf("  5- Baja de empleado\n");
    printf("  6- Listar empleados\n");
    printf("  7- Ordenar empleados\n");
    printf("  8- Guardar los datos de los empleados en un archivo de texto\n");
    printf("  9- Guardar los datos de los empleados en un archivo binario\n");
    printf(" 10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",opcion);

    return *opcion;

}

Employee* employee_new()
{
    Employee* nuevoEmpleado=(Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre,"");
        nuevoEmpleado->horasTrabajadas=0;
        nuevoEmpleado->sueldo=0;
    }

    return nuevoEmpleado;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado=employee_new();

    if(nuevoEmpleado!=NULL)
    {
        if(!(employee_setId(nuevoEmpleado,atoi(idStr)) &&
           employee_setNombre(nuevoEmpleado,nombreStr) &&
           employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr)) &&
           employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))
             )
           )
        {
            free(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }
    }

    return nuevoEmpleado;
}

void employee_delete(Employee* empleado)
{
    if(empleado!=NULL)
    {
        free(empleado);
    }
}

int employee_setId(Employee* this,int id)
{
    int retorno=0;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL && strlen(nombre)>=2 && strlen(nombre)<=128)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }

    return retorno;
}

int mostrarEmpleado(Employee* this)
{
    int retorno=0;

    if(this!=NULL)
    {
      printf("%4d  %20s             %4d      %6d\n"
           ,this->id
           ,this->nombre
           ,this->horasTrabajadas
           ,this->sueldo);
        retorno=1;
    }

    return retorno;
}

int employee_compareId(void* employee1, void* employee2)
{
    int retorno=0;

    Employee* emp1=NULL;
    Employee* emp2=NULL;

    if(employee1!=NULL && employee2!=NULL)
    {
        emp1=(Employee*) employee1;
        emp2=(Employee*) employee2;

        if(emp1->id>emp2->id)
        {
            retorno=-1;
        }
        else if(emp1->id<emp2->id)
        {
            retorno=1;
        }
    }
    return retorno;
}

int employee_compareNombre(void* employee1, void* employee2)
{
    int retorno=0;

    Employee* emp1=NULL;
    Employee* emp2=NULL;

    if(employee1!=NULL && employee2!=NULL)
    {
        emp1=(Employee*) employee1;
        emp2=(Employee*) employee2;

        if(strcmp(emp1->nombre,emp2->nombre)>0)
        {
            retorno=-1;
        }
        else if(strcmp(emp1->nombre,emp2->nombre)<0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int employee_compareHorasTrabajadas(void* employee1, void* employee2)
{
    int retorno=0;

    Employee* emp1=NULL;
    Employee* emp2=NULL;

    if(employee1!=NULL && employee2!=NULL)
    {
        emp1=(Employee*) employee1;
        emp2=(Employee*) employee2;

        if(emp1->horasTrabajadas>emp2->horasTrabajadas)
        {
            retorno=-1;
        }
        else if(emp1->horasTrabajadas<emp2->horasTrabajadas)
        {
            retorno=1;
        }
    }
    return retorno;
}

int employee_compareSueldo(void* employee1, void* employee2)
{
    int retorno=0;

    Employee* emp1=NULL;
    Employee* emp2=NULL;

    if(employee1!=NULL && employee2!=NULL)
    {
        emp1=(Employee*) employee1;
        emp2=(Employee*) employee2;

        if(emp1->sueldo>emp2->sueldo)
        {
            retorno=-1;
        }
        else if(emp1->sueldo<emp2->sueldo)
        {
            retorno=1;
        }
    }
    return retorno;
}
