#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

int initEmployees(Employee* list, int len)
{
    for(int i=0;i<len;i++)
    {
        list[i].isEmpty=1;
    }

    return 0;
}

int addEmployee(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector)
{
    int retorno=1;
    int indice=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
       {
           if(list[i].isEmpty==1)
           {
               indice=i;
               break;
           }
       }
    }

    if(list!=NULL && len>0 && id!=NULL)
    {
        system("cls");
        printf("        Alta Empleado\n\n");

        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            list[indice].id=*id;

            printf("Id: %d\n",list[indice].id);

            if(!utn_getName("Ingrese el nombre del empleado: ","Error. ",3,52,4,name))
            {
                printf("Error al cargar el nombre.\n");
                return -1;
            }
            strcpy(list[indice].name,name);

            if(!utn_getName("Ingrese el apellido del empleado: ","Error. ",3,52,4,lastName))
            {
                printf("Error al cargar el apellido.\n");
                return -1;
            }
            strcpy(list[indice].lastName,lastName);

            if(!utn_getFloat("Ingrese el sueldo: ","Error.",1,20,0,100000,4,&salary))
            {
                printf("Error al cargar el sueldo.\n");
                return -1;
            }
            list[indice].salary=salary;

            printf("\n\n---------Sectores---------\n");
            printf("500- Sistemas\n");
            printf("501- RRHH\n");
            printf("502- Legales\n");
            printf("503- Contabilidad\n");
            printf("504- Centas\n");
            printf("505- Marketing\n\n");

            if(!utn_getUnsignedInt("Ingrese el sector: ","Error.",2,4,500,505,4,&sector))
            {
                printf("Error al cargar el sector.\n");
                return -1;
            }
            list[indice].sector=sector;

            printf("\n\n");

            list[indice].isEmpty=0;

            (*id)++;

            retorno=0;
        }
    }

    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int indice=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
       {
           if(!list[i].isEmpty && list[i].id==id)
           {
               indice=i;
               break;
           }
       }
    }
    return indice;
}

int removeEmployee(Employee* list, int len, int id)
{
    int retorno=0;
    int indice;
    char confirma;

    system("cls");
    printf("        Baja Empleado\n");
    printEmployees(list,len);
    printf("Ingrese id: ");
    scanf("%d",&id);

    indice=findEmployeeById(list,len,id);

    if(indice==-1)
    {
        printf("No existe un empleado con el id: %d\n", id);
    }
    else
    {
        printEmployees(&list[indice],len);
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            list[indice].isEmpty=1;
            retorno=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;

    utn_getUnsignedInt("***Orden de la lista a mostrar***\n\n1- Ascendente\n2- Descendente\n\n"
                       "Ingrese la opcion deseada: ","Error. ",1,2,1,2,4,&order);

    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(order==1)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0 || list[i].sector>list[j].sector)
                {
                    auxEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxEmpleado;
                }
            }
            if(order==2)
            {
                if(strcmp(list[i].lastName,list[j].lastName)<0 || list[i].sector<list[j].sector)
                {
                    auxEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxEmpleado;
                }
            }

        }
    }

    return 0;
}

int printEmployees(Employee* list, int length)
{
    int flag=1;

    printf("\n ------------------------------------------------------------------------------------------------\n");
    printf("                                Lista de Empleados\n");
    printf("\tId\t   Nombre                Apellido        Salario         Sector");
    printf("\n ------------------------------------------------------------------------------------------------\n");

    for(int i=0;i<length;i++)
    {
        if(!list[i].isEmpty)
        {
            printf("\t%4d\t%10s\t\t%10s\t%6.2f\t    %d \n"
                    ,list[i].id
                    ,list[i].name
                    ,list[i].lastName
                    ,list[i].salary
                    ,list[i].sector
                    );
                    flag=0;
        }
    }
    if(flag)
    {
        printf("No hay empleados en la lista");
    }

    printf("\n\n");

    return 0;
}


int modifyEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno=0;
    int indice;
    int opcion;
    char confirma;

    system("cls");
    printf("        Modificar Empleado\n");
    printEmployees(list,len);
    printf("Ingrese id: ");
    scanf("%d",&id);

    indice=findEmployeeById(list,len,id);

    if(indice==-1)
    {
        printf("No existe un empleado con el id: %d\n", id);
    }
    else
    {
        printEmployees(&list[indice],len);
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {

            printf("        Opciones a modificar:\n\n");
            printf("1- Nombre\n");
            printf("2- Apellido\n");
            printf("3- Salario\n");
            printf("4- Sector\n\n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    if(!utn_getName("Ingrese el nombre del empleado: ","Error. ",3,52,4,name))
                    {
                        printf("Error al cargar el nombre.\n");
                        return -1;
                    }
                    strcpy(list[indice].name,name);
                    break;

                case 2:
                    if(!utn_getName("Ingrese el apellido del empleado: ","Error. ",3,52,4,lastName))
                    {
                        printf("Error al cargar el apellido.\n");
                        return -1;
                    }
                    strcpy(list[indice].lastName,lastName);
                    break;

                case 3:
                    if(!utn_getFloat("Ingrese el sueldo: ","Error.",1,20,0,100000,4,&salary))
                    {
                        printf("Error al cargar el sueldo.\n");
                        return -1;
                    }
                    list[indice].salary=salary;
                    break;
                case 4:
                    printf("\n\n---------Sectores---------\n");
                    printf("500- Sistemas\n");
                    printf("501- RRHH\n");
                    printf("502- Legales\n");
                    printf("503- Contabilidad\n");
                    printf("504- Centas\n");
                    printf("505- Marketing\n\n");

                    if(!utn_getUnsignedInt("Ingrese el sector: ","Error.",2,4,500,505,4,&sector))
                    {
                        printf("Error al cargar el sector.\n");
                        return -1;
                    }
                    list[indice].sector=sector;
                    break;

                default:
                    printf("Opcion no valida\n");
                    break;
            }

            retorno=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario\n");
        }
    }

    return retorno;
}

void calculateSalary(Employee* list,int len)
{
    int indice;
    int acumuladorEmpleados=0;
    float total=0;
    float promedio=0;


    system("cls");
    printf("          Informe Sueldos\n\n");

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            total+=list[i].salary;
            indice=i+1;
        }
    }

    promedio=total/indice;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0 && list[i].salary>promedio)
        {
            acumuladorEmpleados=acumuladorEmpleados+1;
        }
    }

    printf("Total de los sueldos: $%.2f\n\n",total);
    printf("Promedio de sueldos: $%.2f\n\n",promedio);
    printf("El total de empleados que superan el salario promedio es: %d\n\n",acumuladorEmpleados);

}

int menuInformes()
{
    int opcion;

    utn_getUnsignedInt("   ***INFORMES***\n\n1- Listados\n2- Salarios\nIngrese la opcion deseada: "
                       ,"Error. ",1,2,1,2,4,&opcion);

    return opcion;

}
