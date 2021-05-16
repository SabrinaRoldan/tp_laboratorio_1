#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main()
{
	setbuf(stdout,NULL);

    Employee empleados[TAM];
    char seguir='s';
    int opcion;
    int proximoId=1;

    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int order;
    int id;
    int flagEmpleadoExistente=0;

    initEmployees(empleados,TAM);

    do
    {
        system("cls");
        printf("        Sistema de Empleados\n\n");
        printf(" 1- Alta empleado\n");
        printf(" 2- Modificar empleado\n");
        printf(" 3- Baja empleado\n");
        printf(" 4- Informes\n");
        printf(" 5- Salir\n\n");

        printf("Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            if(!addEmployee(empleados,TAM,&proximoId,name,lastName,salary,sector))
            {
                printf("Alta exitosa!\n");
                flagEmpleadoExistente=1;
            }
            else
            {
                printf("Error al dar de alta al empleado\n");
            }
            break;

        case 2:
            if(flagEmpleadoExistente)
            {
                if(modifyEmployee(empleados,TAM,id,name,lastName,salary,sector))
                {
                    printf("Modificacion exitosa!\n");
                }
                else
                {
                    printf("Error al modificar empleado\n");
                }
            }
            else
            {
                printf("No existe ningun empleado en el sistema para realizar la consulta.\n");
            }

            break;

        case 3:
            if(flagEmpleadoExistente)
            {
                if(removeEmployee(empleados,TAM,id))
                {
                    printf("Baja exitosa!\n");
                }
                else
                {
                    printf("Error al dar de baja al empleado\n");
                }
            }
            else
            {
                printf("No existe ningun empleado en el sistema para realizar la consulta.\n");
            }
            break;

        case 4:
            if(flagEmpleadoExistente)
            {
                system("cls");

                switch(menuInformes())
                {
                    case 1:
                        system("cls");
                        sortEmployees(empleados,TAM,order);
                        printEmployees(empleados,TAM);
                        break;

                    case 2:
                        system("cls");
                        calculateSalary(empleados,TAM);
                        break;
                }

            }
            else
            {
                printf("No existe ningun empleado en el sistema para realizar la consulta.\n");
            }
            break;

        case 5:
            seguir='n';
            break;

        default:
            printf("Opcion invalida\n");
            fflush(stdin);
            break;
        }
        system("pause");


    }while(seguir=='s');

    return 0;
}
